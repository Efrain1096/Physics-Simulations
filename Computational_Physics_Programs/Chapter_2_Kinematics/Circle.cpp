/*  This program will simulate the trajectory of a particle moving on a circle
    with constant angular velocity.
    
    Equations of the particle's trajectory: x(t) = x0 + R*cos(omega*(t-t0))
                                            y(t) = y0 + R*sin(omega*(t-t0))

    Where the circle is centered at (x0, y0) and has a radius R with a constant velocity omega.
    The initial position of the particle at time t0 to be theta(t0) = 0.
    The circle's path trajectory is written to a file called "Cricle.dat". Of which, will then be plotted with Gnuplot manually by the user 
  */
#include <iostream> 
#include <fstream> // Needed for file creation and manipulation.
#include <cstdlib> // Needed for exit().
#include <string>
#include <cmath>

using namespace std;

#define PI 3.1415926535897932

int main()
{
    double x0, y0, R, x, y, vx, vy, t, t0, tf, dt;
    double theta, omega;

    string buffer;

    cout << "Separate the individual values by a space" << endl;

    // Prompt the user for input.

    cout << "Enter a decimal value for omega: " << endl;
    cin >> omega;
    getline(cin, buffer); // Store the input into into the buffer string

    cout << "Enter the value for the center of the circle (X0, y0) and radius R:" << endl;
    cin >> x0 >> y0 >> R;
    getline(cin, buffer);

    cout << "Enter the values for t0, tf and dt" << endl;
    cin >> t0 >> tf >> dt;
    getline(cin, buffer);

    cout << "Omega= " << omega << endl;
    cout << "x0= " << x0 << " y0= " << y0 << " R= " << R << endl;
    cout << "t0= " << t0 << " tf= " << tf << " dt= " << dt << endl;

    // Checking for valid input.

    if (R <= 0.0)
    {
        cerr << "Invalid value radius R. It's less than or equal to zero!" << endl;
        exit(EXIT_FAILURE);
    }

    if (omega <= 0.0)
    {
        cerr << "Invalid value for omega. It's less than or equal to zero!" << endl;
        exit(EXIT_FAILURE);
    }

    cout  << "T= " << 2.0*PI/omega << endl; // Period calculation

    ofstream myFile("Circle.dat"); // Output stream file object.
    myFile.precision(17); // Set the precision of the floating point number to 17 significant digits. The default is 6.

    //Now that the values have been stored and the period computed with said valid values, now to compute the trajectory path of the circle!

    t = t0;

    while(t <= tf)
    {
        theta = omega * (t-t0);
        x = x0 + R*cos(theta);
        y = y0 + R*sin(theta);
        vx = -omega*R*cos(theta);
        vy = omega*R*cos(theta);

        myFile << t << " " << x << " " << y << " " << vx << " " << vy << endl;

        t = t+dt;
    }
}