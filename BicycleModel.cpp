#include "Bicycle_Model"

using namespace std;

BicycleModel::BicycleModel(const float wheelBase, const float maxSteeringAngle, const float deltaTime) : wheelBase{wheelBase}, maxSteeringAngle{maxSteeringAngle}, deltaTime{deltaTime} {}

ModelParams BicycleModel::update(const float x, const float y, const float theta, const float velocity, const float acceleration, float steeringAngle)
{
    float newVelocity = velocity + acceleration * deltaTime;

    if (steeringAngle > maxSteeringAngle)
        steeringAngle = maxSteeringAngle;
    if (steeringAngle < -maxSteeringAngle)
        steeringAngle = -maxSteeringAngle;

    float angleVelocity = newVelocity * tan(steeringAngle) / wheelBase;

    float newX = x + velocity * cos(theta) * deltaTime,
          newY = y + velocity * sin(theta) * deltaTime;

    float thetaMax = 2 * M_PI,
          calculatedTheta = theta + angleVelocity * deltaTime,
          newTheta = fmod(calculatedTheta, thetaMax);

    return make_tuple(newX, newY, newTheta, newVelocity, steeringAngle, angleVelocity);
}