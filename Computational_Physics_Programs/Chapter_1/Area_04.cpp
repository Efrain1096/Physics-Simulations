#include <iostream>
#include <fstream>
using namespace std;

const double PI = 3.1415926535897932;
void areaOfCircle(const double &radius, double &circumference, double &area);

int main()
{
    const int N = 10;
    double radiusArray[N];
    double area, perimeter;
    int i;

    for(i = 0; i < N; i++)
    {
        cout << "Enter a value for the radius of circle " << i+1 << " :"; 
        cin >> radiusArray[i];
        cout << "i= " << (i+1) << "R(i)= " << radiusArray[i] << endl;
    }

    ofstream myfile("Area.DAT");

    for(int i = 0; i < N; i++)
    {
        areaOfCircle(radiusArray[i], perimeter, area);
        myfile << (i+1) << " R= " << radiusArray[i] << " perimeter= " << perimeter << endl;
        myfile << (i+1) << " R= " << radiusArray[i] << " area= " << area << endl;
    }
myfile.close();

}

void areaOfCircle(const double &radius, double &circumference, double &area)
{
    circumference = 2*PI*radius;
    area = 2*PI*radius*radius;
}