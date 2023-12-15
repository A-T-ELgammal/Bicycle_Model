#include <iostream>
#include <vector>

#include "Bicycle_Model"

int main()
{
    BicycleModel bicycle(1.0);
    PositionController controller(0.1);

    double x = 0.0, y = 0.0, theta = 0.0;
    double x_d = 5.0, y_d = 5.0;
    double v = 1.0;

    for (int i = 0; i < 100; i++)
    {
        double delta = controller.compute(bicycle, x, y, theta, x_d, y_d);
        std::tie(x, y, theta) = bicycle.update(x, y, theta, v, delta);
        std::cout << "Position: (" << x << ", " << y << ", " << theta << ")" << std::endl;
    }

    return 0;
}
