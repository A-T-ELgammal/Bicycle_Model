#include <iostream>
#include <vector>
#include <cassert>
#include "Data"

#include "Bicycle_Model"

using namespace std;

int main()
{
    BicycleModel bicycle(2.5, M_PI / 4, 0.1);

    for (int i = 0; i < testCases.size(); i++)
    {
        auto [x, y, theta, velocity, acceleration, steeringAngle] = testCases[i];

        auto [unewX, unewY, unewTheta, unewVelocity, usteeringAngle, uangleVelocity] = bicycle.update(x, y, theta, velocity, acceleration, steeringAngle);

        auto [expectedX, expectedY, expectedTheta, expectedVelocity, expectedsteeringAngle, expectedangleVelocity] = testCases[i];

        if (unewVelocity == expectedX)
            cout << "true";

        // assert(unewVelocity == expectedX);
        // assert(uangleVelocity == expectedY);
        // assert(unewX == expectedTheta);
        // assert(unewY == expectedVelocity);
        // assert(unewTheta == expectedsteeringAngle);
        // assert(unewTheta == expectedangleVelocity);

        // cout << "Test Case: "
        //      << "ux: " << unewX << ", "
        //      << "uy: " << unewY << ", "
        //      << "utheta: " << unewTheta << ", "
        //      << "uvelocity: " << unewVelocity << ", "
        //      << "usteeringAngle: " << usteeringAngle << ", "
        //      << "uacceleration: " << uangleVelocity << endl;
    }
    return 0;
}
