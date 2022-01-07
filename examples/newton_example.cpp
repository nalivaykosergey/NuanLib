#include <iostream>
#include <cmath>
#include <iomanip>
#include "../lib/interpolation/newton.hpp"

using std::cout, std::endl, std::setw;
using nuan::interpolation::newton_polynomial;

double function(double x);
double * division_into_segments(double a, double b, size_t segmentsNum);
double * y_values(const double *x, size_t size);
double delta_value(double interpolated, double func);


int main() {

    const int N = 10; // num of equal segments
    const double a = 0.0, b = 1.0; // segment [a, b]

    auto *x1 = division_into_segments(a, b, N);
    auto *y1 = y_values(x1, N + 1);

    const int M = N * 3;
    auto *x2 = division_into_segments(a,b,M);
    auto *y2 = y_values(x2, M + 1);
    auto *newton_values = new double[M + 1];
    auto *deltaValues = new double[M + 1];
    cout
            << setw(10)  << "x"
            << setw( 25) << "f(x)"
            << setw(25)  << "P_n(x)"
            << setw( 25) << "𝛿(x)"
            << endl;
    for(size_t i = 0; i<=M; i++) {
        newton_values[i] = newton_polynomial(x1, y1, N + 1, x2[i]);
        deltaValues[i] = delta_value(newton_values[i], y2[i]);
        cout
                << setw(10)   << x2[i]
                << setw( 25 ) << y2[i]
                << setw( 25 ) << newton_values[i]
                << setw( 25 ) << deltaValues[i]
                << endl;
    }
    cout<<endl;

    ///////////////////////     Clear heap           ////////////////////////
    delete [] x1;
    delete [] y1;
    delete [] x2;
    delete [] y2;
    delete [] newton_values;
    delete [] deltaValues;

}

/*
    Division of segment [a, b] into equal segments
*/
double * division_into_segments(double a, double b, size_t segmentsNum)
{
    auto *x = new double[segmentsNum + 1];
    double nStep = (b-a) / segmentsNum;
    x[0] = a;
    x[segmentsNum] = b;
    for(size_t i = 1; i < segmentsNum; i++)
        x[i] = x[i - 1] + nStep;
    return x;
}

/*
    Function computation
*/
double function(double x)
{
    return sin(x)*cos(x*x);
}

/*
    Evaluating a function for each of the arguments
*/
double * y_values(const double *x, size_t size)
{
    auto * y = new double[size];
    for(size_t i = 0; i<size; i++)
        y[i] = function(x[i]);
    return y;
}

/*
    Function delta_value return interpolation error
    interpolated - newton_polynomial value
    func - function value
*/
double delta_value(double interpolated, double func)
{
    return fabs(interpolated - func);
}