#include <iostream>
#include <vector>

#include "Bicycle_Model"

using namespace std;

int main()
{
    BicycleModel bicycle(2.5, M_PI / 4, 0.1);
    vector<ModelParams> testCases = {
        make_tuple(0.0F, 0.0F, float(M_PI / 4), 5.0F, 2.0F, float(M_PI / 8)),
        make_tuple(1.0F, 2.0F, 0.0F, 3.0F, 1.0F, float(M_PI / 4)),
        make_tuple(-1.0F, -2.0F, float(M_PI / 2), 4.0F, -1.0F, float(-M_PI / 4))};

    for (const ModelParams &testCase : testCases)
    {
        const auto [x, y, theta, velocity, acceleration, steeringAngle] = testCase;
        const ModelParams updated = bicycle.update(x, y, theta, velocity, acceleration, steeringAngle);

        cout << "Updated x: " << get<0>(updated) << endl;
        cout << "Updated y: " << get<1>(updated) << endl;
        cout << "Updated theta: " << get<2>(updated) << endl;
        cout << "Updated velocity: " << get<3>(updated) << endl;
        cout << "Updated acceleration: " << get<4>(updated) << endl;
        cout << "Updated steeringAngle: " << get<5>(updated) << endl;
        cout << "==========================================" << endl;
    }

    return 0;
}
