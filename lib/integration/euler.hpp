#ifndef NUMERICAL_ANALYSIS_LIB_EULER_INTEGRATION_HPP
#define NUMERICAL_ANALYSIS_LIB_EULER_INTEGRATION_HPP

#include "integration_error.h"
#include <vector>

namespace nuan {
    namespace integration
    {
        ///  @brief Numerical solution of the Cauchy problem by the Euler method
        ///  @tparam T   Any float-point type such as float, double or long double
        ///  @param diff_f  Function describing the Cauchy problem u' = f(u, x)
        ///  @param initial_value Initial condition at start point
        ///  @param a start point
        ///  @param b end point
        ///  @param step the step of changing the variable x.
        ///  @return solutions of the Cauchy problem represents as a vector.
        ///   
        ///  @warning  Throws Integration_Range_Error exception when the a >= b.
        ///  @see https://en.wikipedia.org/wiki/Cauchy_problem 
        ///  @see https://en.wikipedia.org/wiki/Euler_method
        template <typename T> 
        std::vector<T> euler_method(T (*diff_f)(T, T), T initial_value, T a, T b, T step = 0.01)
        {
            if(a >= b)
                throw errors::IntegrationRangeError();
            int num_segments = (b-a)/step + 1;
            T x = a;
            std::vector<T> y(num_segments);

            y[0] = initial_value;


            for(int i = 1; i < num_segments; i++, x += step)
                y[i] = y[i-1] + step*diff_f(y[i-1], x);
            return y;
        }
        
        /// \example euler_example.cpp
        /// This is an example of how to use the euler_method.
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