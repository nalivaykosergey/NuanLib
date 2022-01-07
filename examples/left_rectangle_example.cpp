#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "../lib/integration/left_rectangle.hpp"

using std::cout, std::endl, std::setw, std::vector;
using nuan::integration::left_rectangle;

long double f(long double x);
long double analytical_sol(long double x, long double a, long double b);

int main()
{
    int N;
    long double a = 0.0, b = M_PI_2, x, a_f_value;
    long double step = 0.001;
    
    long double solution = left_rectangle(f, a, b, step);
    x = a;

    cout << "Numerical solution of the integral"
            "using left rectangles:" << endl;
    cout.precision(20);
    cout <<
            setw(30) << "| approx_I |" <<
            setw(30)  << "| analytical_I |" <<
            setw(30) << "| δ |" <<
    endl;

    a_f_value = analytical_sol(x, a, b);
    cout <<
            setw(30) << solution <<
            setw(30)  << a_f_value<<
            setw(30) << fabs(solution - a_f_value) <<
    endl;
}

long double f(long double x)
{
    return sin(x);
}

long double analytical_sol(long double x, long double a, long double b)
{
    return -cos(b) + cos(a);
}