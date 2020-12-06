/*  =========================================================
    A simple program to compute roots of a 2nd order polynomial. As well as practice writting in C++ and familiarize myself with it.

    Input: The coefficients of the polynomial separated by spaces.

    For example, suppose we want to compute the polynomial: x^2 - 4. 
    
    The input would be: 1 0 -4
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//  Prototype function declarations to calculate the discriminant
//  and the roots of the second degree polynomial function.
double calculateDiscriminant(double a, double b, double c);
void calculateRoots(double a, double b, double c, double &x_1, double &x_2);

int main()
{
    double a, b, c, D;
    double x_1, x_2;

    //  Prompt user to enter polynomial coefficient values
    cout << "Enter a, b, c: ";

    //  Read the input values separated by spaces from the user's keyboard
    cin >> a >> b >> c;

    cout << a << " " << b << " " << c << " " << endl;

    //  Need to validate the firstmost polynomial coefficient to
    //  check that the quafratic can be used for computations.
    if (a == 0.0)
    {
        cerr << "Error, a is equal to zero. Invalid second degree polynomial!";
        exit(EXIT_FAILURE); //
    }

    //  Compute the discriminant value.
    D = calculateDiscriminant(a, b, c);
    cout << "Discriminant: D=" << D << endl;

    /*  Then compute the roots or "zeroes" of the polynomial.
        But first, need to verify that the discriminant is valid in 
        order to do so. Need to check for the three possible cases:
        D=0 (double roots), D<0 (no real roots), and D>0 (distinct real roots).
    */

    if (D > 0.0)
    {
        calculateRoots(a, b, c, x_1, x_2);
        cout << "Roots of the polynomial inputted are: " << x_1 << " " << x_2 << endl;
    }
    else if (D == 0.0)
    {
        calculateRoots(a, b, c, x_1, x_2);
        cout << "Double Root: x_1= " << x_1 << endl;
    }
    else
    {
        cout << "No real roots" << endl;
        exit(EXIT_FAILURE);
    }
}

//  Function that computes and returns soon after the discriminant value.
double calculateDiscriminant(double a, double b, double c)
{
    return (b * b - 4.0 * a * c);
}

//  Function to then compute the roots
void calculateRoots(double a, double b, double c, double &x_1, double &x_2)
{
    double d;

    d = calculateDiscriminant(a, b, c);
    if (d >= 0.0)
    {
        d = sqrt(d);
    }
    else
    {
        cerr << "Roots cannot be computted! For the discriminant value is less than 0. D= " << d << endl;
        exit(EXIT_FAILURE);
    }

    x_1 = (-b + d) / (2.0 * a);
    x_2 = (-b - d) / (2.0 * a);
}
