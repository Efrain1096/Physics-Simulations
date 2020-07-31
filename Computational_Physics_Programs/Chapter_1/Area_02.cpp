// A program to compute and store the area and circumference of 10 circles of ascending radius.

#include <iostream>
using namespace std;

int main()
{
    double PI = 3.1415926535897932;
    double R[10];
    double area, perimeter;
    R[0] = 3.0;
    
    for(int i = 1; i < 10; i++)
    {
        R[i] = R[i-1] + 1.0;
    }

    for(int i = 1; i < 10; i++)
    {
        perimeter = 2.0 * PI * R[i];
        area = PI * R[i] * R[i];
        
        cout << (i+1) << " R= " << R[i] << ", perimeter= " << perimeter;
        cout << (i+1) << " R= " << R[i] << ", area= " << area << endl;
    }
}