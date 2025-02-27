
/*Program to calculate and model a particle launched or shot at a an angle theta near the Earth's surface.*/
/*  Program to calculate and model a particle launched or shot at a an angle theta near the Earth's surface.
=======
/*  Program to calculate and model a particle launched or shot at a an angle theta near the Earth's surface. Coriolis force is being ignored.

    Using the equations of position and velocity for a particle in 2D motion:


        Initial conditions:
        Initial x-velocity v_x(0) = v_0x = (Initial Velocity)*(Cos(Theta)) = v0_x*cos(theta)
        Initial y-velocity v_y(0) = v_0y = (Initial Velocity)*(Sin(Theta)) = v0_y*sin(theta)

        Kinematic equations:
        x-position: (Initial horizontal velocity) * (Time) = v0_x*t
        y-position: (Initial vertical velocity) * (Time) - 0.5*(Gravity)*(Time)^2 = v0_y*t - 0.5*g*t^2

        x-velocity: Initial horizontal velocity = v0_x
        y-velocity: Initial vertical velocity = v0_y - g*t

        Air resistance: 
        F = -mkv, where 

        a_x = dv_x/dt = -k * v_x
        a_y = dv_y/dt = -k * v_y - g

        with the initial conditions specified above, 

        v_x(t) = v0_x * e^(-kt) 
        v_y(t) = (v0_y + g/k)e^(-kt) - g/k

        x(t) = v0_x/k * (1 - e^(-kt))
        y(t) = 1/k * (v0_y + g/k) * (1 - e^(-kt)) - g/k * t

        The difference here is providing the value for constant 'k'.

        WIP (I still haven't added the equations for drag as of 2/26/25, to be continued...)


    The easiest way to plot and visualize the data in the DAT file is to set the Gnuplot terminal
    to the "dummy" plotting.

    It's amazing how simple yet useful some of these introductory trigonometric equations are when coded.



    INSTRUCTIONS TO PLOT PROJECTILE:
        As a single line, type (or copy) the following: 


        plot "Projectile.dat" using 1:2 w l t "x(t)",
        plot "Projectile.dat" using 1:3 w l t "y(t)",
        plot "Projectile.dat" using 1:4 w l t "Vx(t)",
        plot "Projectile.dat" using 1:5 w l t "Vy(t)"

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
