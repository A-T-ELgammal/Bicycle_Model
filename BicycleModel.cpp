#include "Bicycle_Model"

double BicycleModel::confineDeltaAngle(const double delta) const
{
    return max(-thetaMax, min(delta, thetaMax));
}

States BicycleModel::update(const double x, const double y, const double theta, const double v, const double delta) const
{
    const double deltaTheta = v * tan(confineDeltaAngle(delta)) / L,
                 deltaX = v * cos(theta + deltaTheta),
                 deltaY = v * sin(theta + deltaTheta),
                 updatedX = x + deltaX,
                 updatedY = y + deltaY,
                 updatedTheta = theta + deltaTheta;
    return make_tuple(updatedX, updatedY, updatedTheta);
}

double PositionController::compute(const BicycleModel &model, const double x, const double y, const double theta, const double x_d, const double y_d) const
{
    const double newTheta = atan2(y_d - y, x_d - x),
                 error = newTheta - theta,
                 delta = model.confineDeltaAngle(Kp * error);
    return delta;
}
