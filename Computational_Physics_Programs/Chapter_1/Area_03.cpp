#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int N = 10;
    const double PI = 3.1415926535897932;
    double R[N];
    double area, perimeter;

    for(int i = 0; i < N; i++)
    {
        cout << "Enter radius of circle: ";
        cin >> R[i];
        cout << "i= " << (i+1) << "R(i)= " << R[i] << endl;
    }

    ofstream myfile("Area.DAT");

    for(int i = 0; i < N; i++)
    {
        perimeter = 2*PI*R[i];
        area = PI*R[i]*R[i];
        myfile << (i+1) << " R= " << R[i] << " perimeter= " << perimeter << endl;
        myfile << (i+1) << " R= " << R[i] << " area= " << area << endl;

    }
myfile.close();
}