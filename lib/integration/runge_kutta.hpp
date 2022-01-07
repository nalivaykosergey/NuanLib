#ifndef NUMERICAL_ANALYSIS_LIB_RUNGE_KUTTA_INTEGRATION_HPP
#define NUMERICAL_ANALYSIS_LIB_RUNGE_KUTTA_INTEGRATION_HPP

#include "integration_error.h"
#include <vector>

namespace nuan {
    namespace integration
    {
        ///  @brief Numerical solution of the Cauchy problem by the Runge–Kutta method
        ///  @tparam T   Any float-point type such as float, double or long double
        ///  @param diff_f  Function describing the Cauchy problem u' = f(u, x)
        ///  @param initial_value Initial condition at start point
        ///  @param a start point
        ///  @param b end point
        ///  @param step the step of changing the variable x.
        ///  @return solutions of the Cauchy problem represents as a vector.
        ///   
        ///  @warning  Throws Integration_Range_Error exception when the a >= b.
        /// 
        ///  @see https://en.wikipedia.org/wiki/Cauchy_problem 
        ///  @see https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods
        template <typename T>
        std::vector<T> runge_kutta(T (*diff_f)(T, T), T initial_value, T a, T b, T step = 0.01)
        {
            if(a >= b)
                throw errors::IntegrationRangeError();
                
            int num_segments = (b-a)/step + 1;
            T x = a;
            T y_tmp;
            std::vector<T> y(num_segments);

            y[0] = initial_value;

            for(int i = 0; i < num_segments - 1; i++, x += step) {
                y_tmp = y[i] + diff_f(y[i], x)*step;
                y[i + 1] = y[i] + ( diff_f(y[i], x) + diff_f(y_tmp, x + step))/2.0 * step;
            }
            return y;
        }
        /// \example runge_kutta_example.cpp
        /// This is an example of how to use the runge_kutta.
        /// Suppose we have a Cauchy problem:
        /// \f[
        /// u' = \frac{1}{2} u + x, \ u(0) = 0, \ a = 0, \ b = 2
        /// \f]
        /// Analytical solution of the problem:
        /// \f[
        /// u(x) = -2 (x + 2) + 4 e^{\frac{1}{2}x}
        /// \f]
        /// Then the program that solves this problem and compares the deviation 
        /// between the analytical solution and the numerical solution has the form:
    }
}

#endif