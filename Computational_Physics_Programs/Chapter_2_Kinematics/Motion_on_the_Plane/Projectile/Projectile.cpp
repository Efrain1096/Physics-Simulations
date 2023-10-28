<<<<<<< HEAD
<<<<<<< HEAD
/*Program to calculate and model a particle launched or shot at a an angle theta near the Earth's surface.*/
=======
/*  Program to calculate and model a particle launched or shot at a an angle theta near the Earth's surface.
=======
/*  Program to calculate and model a particle launched or shot at a an angle theta near the Earth's surface. Coriolis force is being ignored.
>>>>>>> 5933911 (Expanded a bit in the comments.)
    Using the equations of position and velocity for a particle in 2D motion:

        Initial x-velocity v_x(0) = v_0x = (Initial Velocity)*(Cos(Theta)) = v0_x*cos(theta)
        Initial y-velocity v_y(0) = v_0y = (Initial Velocity)*(Sin(Theta)) = v0_y*sin(theta)


        x-position = (Initial horizontal velocity) * (Time) = v0_x*t
        y-position = (Initial vertical velocity) * (Time) - 0.5*(Gravity)*(Time)^2 = v0_y*t - 0.5*g*t^2

        x-velocity = Initial horizontal velocity = v0_x
        y-velocity = Initial vertical velocity = v0_y - g*t

    The easiest way to plot and visualize the data in the DAT file is to set the Gnuplot terminal
    to the "dummy" plotting.

    It's amazing how simple yet useful some of these introductory trigonometric equations are when coded.

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#define PI 3.1415926535897932
#define g 9.81

int main()
{

    // Variable Declaration.

    double x0, y0, R, x, y, vx, vy, t, tf, dt;
    double theta, v0x, v0y, v0;
    string buff;

    // Ask user for input:

    cout << "# Enter v0, theta (in degrees): " << endl;
    cin >> v0 >> theta;

    cout << "# Enter tf, dt: " << endl;
    cin >> tf >> dt;

    cout << "# v0= " << v0 << " theta= " << theta << " degrees" << endl;
    cout << "# t0= " << 0.0 << " tf= " << tf << " dt= " << dt << endl;

    // Input validation.

    if (v0 <= 0.0)
    {
        cerr << "Initial velocity has to be greater than zero!";
        exit(1);
    }

    if (theta <= 0.0 || theta >= 90.0)
    {
        cerr << "Invalid value for launch angle theta!";
        exit(1);
    }

    theta = (PI / 180) * theta;
    v0x = v0 * cos(theta);
    v0y = v0 * sin(theta);

    cout << "# v0x= " << v0x << " v0y= " << v0y << endl;

    ofstream file("Projectile.dat");
    file.precision(17);

    // Computing the projectiles position and velocity:

    t = 0.0;

    while (t <= tf)
    {
        x = v0x * t;
        y = v0y * t - 0.5 * g * t * t;
        vx = v0x;
        vy = v0y - g * t;

        file << t << " " << x << " " << y << " " << vx << " " << vy << " " << endl;
        cout << t << " " << x << " " << y << " " << vx << " " << vy << " " << endl;
        t = t + dt;
    }
}
>>>>>>> 9d708b1 (Added more to the description at the top of the CPP program.)
