#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "../lib/integration/runge_kutta.hpp"

using std::cout, std::endl, std::setw, std::vector;
using nuan::integration::runge_kutta;


long double f(long double y, long double x);
long double analytical_sol(long double x);

int main()
{
    int N;
    long double a = 0.0, b = 2.0, x, a_f_value;
    long double step = 0.25, initial_value = 0.0;
    
    vector<long double> solution = runge_kutta(f, initial_value, a, b, step);
    N = solution.size();
    x = a;

    cout << "Numerical solution of the Cauchy"
            "problem by the Runge-Kutta method:" << endl;
    cout.precision(20);
    cout <<
             setw(30)  << "| x |" <<
             setw(30) << "| approx_y |" <<
             setw(30)  << "| analytical_y |" <<
             setw(30) << "| δ |" <<
    endl;

        for(int i = 0; i < N; i++, x+= step)
        {
            a_f_value = analytical_sol(x);
            cout <<
                 setw(30)  << x <<
                 setw(30) << solution[i] <<
                 setw(30)  << a_f_value<<
                 setw(30) << fabs(solution[i] - a_f_value) <<
                 endl;
        }
    
}

long double f(long double y, long double x)
{
    return 0.5 * y + x;
}

long double analytical_sol(long double x)
{
    return -2 * (x + 2) + 4 * pow(M_E, 0.5 * x);
}