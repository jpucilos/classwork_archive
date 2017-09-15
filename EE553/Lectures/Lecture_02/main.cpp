#include <iostream>
#include <cmath>
#include <random> // rand and srand is old junk
using namespace std;


void hello(){
    cout<<"hello"<<'\n';
}

void printDouble(int x){
    cout << x * 2;
}

//inline for optimization
//g++ -S for assembly code
inline double f(double x) {
    return x * x;
}

double hypot(double x, double y){
    return sqrt(x*x + y*y);
}

//Subtractive cancellation example, and type promotion
//int root3, root4
//cannot write double to an int!
double quadratic(double A, double B, double C, double& root1, double& root2){
    double disc = sqrt(B*B - 4*A*C);
    root1 = (-B - disc) / (2*A);
    root2 = (-B + disc) / (2*A);
}

//pass by reference
void polar2rect(double r, double theta, double& x, double& y){
    x = r * cos(theta);
    y = r * sin(theta);
}

//atan2 is much better than atan
void rect2polar(double x, double y, double& r, double& theta){
    r = sqrt(x*x+y*y)
    theta = atan2(y, x);
}

//functions passing arrays

int main(){
    //functions above
    hello();
    printDouble(3);
    //subtractive cancellation can destroy our entire answer
    double A = 1.0001, B = 2.00001, C = 1;
    int a = 1;
    int b = 1;
    int c;
    for (int i =0; i <10; i++){
        c = a + b;
        a = b;
        b = c;
    }
    //nested loops
    //"noaa wind chill chart"

    int x[3]; // x[0], x[1], x[2]; // unitialized!

    int c[3] = {1, 2, 3}; // acceptable
    int d[] = {1, 2, 3}; //also acceptable
    int e2[100] = {0}; //they are all zero!
    int e[100] = {5}; // They are all zero except e2[0];

    //Don't use macros ex. #define SIZE 200
    // use const int SIZE = 200;

    //notice how there's no curly brackets
    for(int i = 0; i < 100; i++)
        e[i] = 3;

    //multi-dimensional array
    int f[2][3] = {
        {5,4,3},
        {2,1,6}
    };
    //sizeof
    cout << sizeof(int) << '\n';
    cout << sizeof(char) << '\n'; //always 1 by definition
    cout << sizeof(f) << '\n'; // 24 bytes
    cout << sizeof(f[0]) << '\n'; // 12 bytes
}
