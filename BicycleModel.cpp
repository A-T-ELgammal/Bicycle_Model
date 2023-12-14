#include "Bicycle_Model"

BicycleModel::BicycleModel(const float wheelBase, const float maxSteeringAngle, const float deltaTime) : wheelBase{wheelBase}, maxSteeringAngle{maxSteeringAngle}, deltaTime{deltaTime} {}

ModelParams BicycleModel::update(const float x, const float y, const float theta, const float velocity, const float acceleration, float steeringAngle) const
{
    const float newVelocity = velocity + acceleration * deltaTime;

    steeringAngle = steeringAngle < -maxSteeringAngle
                        ? max(steeringAngle, -maxSteeringAngle)
                        : min(steeringAngle, maxSteeringAngle);

    const float angleVelocity = newVelocity * tan(steeringAngle) / wheelBase;

    const float newX = x + velocity * cos(theta) * deltaTime,
                newY = y + velocity * sin(theta) * deltaTime;

    const float calculatedTheta = theta + angleVelocity * deltaTime,
                newTheta = fmod(calculatedTheta, thetaMax);

    return make_tuple(newX, newY, newTheta, newVelocity, steeringAngle, angleVelocity);
}