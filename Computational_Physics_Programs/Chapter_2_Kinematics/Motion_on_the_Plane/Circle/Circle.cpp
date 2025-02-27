/*  
    This program will simulate the trajectory of a particle moving on a circle
    with constant angular velocity. Refer to the textbook, pages 63-75.
    
    Equations of the particle's trajectory: x(t) = x0 + R*cos(omega*(t-t0))
                                            y(t) = y0 + R*sin(omega*(t-t0))

    Where the circle is centered at (x0, y0) and has a radius R with a constant velocity omega.
    The initial position of the particle at time t0 to be theta(t0) = 0.
    The circle's path trajectory is written to a file called "Cricle.dat". Of which, will then be plotted with Gnuplot manually by the user 
  
    DIRECTIONS TO MAKE A PNG PLOT OF THE Circle.dat FILE:

    The example commands used are to make a png plot of the theta value at each second.

    1. First, we want to set the output file's name and file type: set output 'fileName.fileType'. Invoke the Gnuplot terminal, then enter the following:
    set output 'circlePlot.png'

    2. Then, set the terminal plotting mode, the plot dimensions, and the font of the plot's labels:
    set terminal terminal_plot_mode size pixel_width,pixel-length enhanced font 'font_of_choosing,font_size'

    Example: set terminal pngcairo size 350, 262 enhanced font 'Verdana,10'

    3. Finally we can proceed to plot the Circle.dat file created from running this program. Using the following commands:
    x0 = 1; y0 = 1 
    plot "Circle.dat" using 1:(atan2($3-y0,$2-x0)) with lines title "theta(t)",pi, -pi

    If the above example commands are used, a png file will be created in the working directory named "circlePlot". Which can be clicked on and viewed.
    It will be a simple plot of the value of the angle theta in radians for the y-axis and the seconds computed for the x-axis.

    DIRECTIONS FOR PLOTTING THE PARAMETRIC EQUATIONS x(t) and y(t):

    Similar as the instructions above for plotting the theta values, but with a few differences since it involves having two functions on the same plot.

    1.Specify the output file name and file type: set output 'parametricPlot.png'
    2.Setup the window: set terminal pngcairo size 1920, 1080 enhanced font 'Verdana,20'
    3.Plot x(t): plot "Circle.dat" using 1:2 with lines title "x(t)"
    4.Specify again the file name and file type. Repeat step 1.
    5.Plot y(t) on the same window with replot: replot "Circle.dat" using 1:3 with lines title "y(t)"

   

    ################################################################
    WORK IN PROGRESS TO REFINE AND POLISH INSTRUCTIONS!!!

    I've yet to figure out how to run the animate GNU file.


    #################################################################
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
