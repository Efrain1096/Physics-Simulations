/*
Refer to pages 75 to 78 in the textbook.
Summary: Program to compute the trajectory of a simple pendulum.


Gnuplot commands:

- set output 'parametricPlot.png'

- set terminal pngcairo size 1920, 1080 enhanced font 'Verdana,20'

- plot "SimplePendulum.dat" u 1:2 title "x(t)" w l, "SimplePendulum.dat" u 1:3 title "y(t)" w l, "SimplePendulum.dat" u 1:4 title "v_x(t)" w l, "SimplePendulum.dat" u 1:5 title "v_y(t)" w l, "SimplePendulum.dat" u 1:6 title "theta(t)" w l

The command above is incomplete. It needs the angular velocity portion to plot.

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

    double length, x, y, vx, vy, t, t0, tf, dt;
    double theta, theta0, dtheta_dt, omega;
    string buffer;

    // Ask input from user
    cout << "Enter length of pendulum: " << endl;
    cin >> length;
    getline(cin, buffer);

    cout << "Enter initial theta angle: " << endl;
    cin >> theta0;
    getline(cin, buffer);

    cout << "Enter t0, tf, dt: " << endl;
    cin >> t0 >> tf >> dt;
    getline(cin, buffer);

    cout << "length= " << length << " theta0= " << theta0 << endl;
    cout << "t0= " << t0 << " tf= " << tf << " dt= " << dt << endl;

    // Begin initializing equations and required values
    omega = sqrt(g/length);

    cout << "# omega= " << omega <<  " T= " << 2.0*PI/omega << endl;

    ofstream myFile("SimplePendulum.dat");
    myFile.precision(17);

    // Compute the trajectory using the above computed values
    t = t0;

    while( t <= tf)
    {
        theta = theta0*cos(omega*(t-t0));
        dtheta_dt = -omega*theta0*sin(omega*(t-t0));

        x = length*sin(theta);
        y = -length*cos(theta);

        vx = length*dtheta_dt*cos(theta);
        vy = length*dtheta_dt*sin(theta);

        myFile << t << " " << x << " " << y << " " << vx << " " << vy << " "
        << theta << dtheta_dt << endl;

        t = t + dt;
    }
    return 0;
}
