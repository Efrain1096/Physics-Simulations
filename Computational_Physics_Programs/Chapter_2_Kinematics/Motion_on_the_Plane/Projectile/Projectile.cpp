
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


        Note: This is not a great medium for typing out equations... LaTex is something to consider in the future for 
        when I implement equations not in the textbook. 


        The difference here is providing the value for constant 'k'.

        WIP (I still haven't added the equations to the program for drag as of 2/26/25, to be continued...)


    The easiest way to plot and visualize the data in the DAT file is to set the Gnuplot terminal
    to the "dummy" plotting.

    It's amazing how simple yet useful some of these introductory trigonometric equations are when coded.



    INSTRUCTIONS TO PLOT PROJECTILE:

    1.Specify the output file name and file type: set output 'parametricPlot.png'
    2.Setup the window: set terminal pngcairo size 1280, 720 enhanced font 'Verdana,20'
    3. As a single line, type (or copy) the following: 


        plot "Projectile.dat" u 1:2 w l t "x(t)",
         "Projectile.dat" u 1:3 w l t "y(t)",
         "Projectile.dat" u 1:4 w l t "Vx(t)",
         "Projectile.dat" u 1:5 w l t "Vy(t)"

    Otherwise, what would need to be done is set the output again and replot, then set the output, replot, set outpot, rinse and repeat.
    I was pulling my hair out until I referred to "Circle.cpp" since I vaguely remembered something like this happening before.
    Putting it all in one line makes it all happen at once and the output only needs to be set one time. However, it's still not ideal, if
    for whatever reason, more and more functions have to be plotted. It doesn't scale well. This is something to look into later on.

    Also, 'u' 'w' 'l' 't' are just shortened for "using", "with", "lines", "title".

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

    double x0, y0, R, x, y, vx, vy, t, tf, dt, k, res;
    double theta, v0x, v0y, v0;
    string buff;

    // Ask user for input:

    cout << "# Enter k, v0, theta (in degrees): " << endl;
    cin >> k >> v0 >> theta;

    cout << "# Enter tf, dt: " << endl;
    cin >> tf >> dt;


    cout << "k = " << k << endl;
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

    theta = (PI/180)*theta;
    v0x = v0 * cos(theta);
    v0y = v0 * sin(theta);

    cout << "# v0x= " << v0x << " v0y= " << v0y << endl;

    ofstream file("Projectile.dat");
    file.precision(17);

    // Computing the projectiles position and velocity:

    t = 0.0;


    while (t <= tf)
    {

        /* For now, I'll put them here in a comment block. Eventually I'll make it where the user can choose if air resistance is wanted or not.
            At first, I thought that setting the constant 'k' to zero would be the solution to that. But then I looked at the equations more closely,
            undefined errors would pop up since k is the denominator for dividing gravity.
            x = v0x * t; 
            y = v0y * t - 0.5 * g * t * t;
            vx = v0x; 
            vy = v0y - g * t; 
        */
            
       

        x = (v0x*t)*(1.0 - exp(-k*t));
        y = (1.0/k)*(v0y+(g/k))*(1.0-exp(-k*t))-(g/k)*t;
        vx = v0x*exp(-k*t);
        vy = (v0y+(g/k))*exp(-k*t)-(g/k);

        file << t << " " << x << " " << y << " " << vx << " " << vy << " " << endl;
        cout << t << " " << x << " " << y << " " << vx << " " << vy << " " << endl;
        t = t + dt;
    }
}
