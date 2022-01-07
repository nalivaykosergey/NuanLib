#ifndef NUMERICAL_ANALYSIS_LIB_TRAPEZOIDAL_INTEGRATION_HPP
#define NUMERICAL_ANALYSIS_LIB_TRAPEZOIDAL_INTEGRATION_HPP

#include "integration_error.h"

namespace nuan {
    namespace integration
    {
        ///  @brief Numerical solution of the integrals using trapezoidal rule.
        ///  @tparam T  Any float-point type such as float, double or long double
        ///  @param func  integrand 
        ///  @param a start point
        ///  @param b end point
        ///  @param step the step of changing the variable x.
        ///  @return approximate integral value.
        ///   
        ///  @warning  Throws Integration_Range_Error exception when the a >= b.
        /// 
        ///  @see https://en.wikipedia.org/wiki/Trapezoidal_rule
        template<typename T>
        T trapezoidal_rule(T (*func)(T), T a, T b, T step = 0.01)
        {
            if(a >= b)
                throw errors::IntegrationRangeError();
            double approximated_I,  x = a + step;
            approximated_I = (func(a) + func(b-step))/2.0;
            while(x < b)
            {
                approximated_I += func(x);
                x += step;
            }
            return approximated_I * step;
        }
        /// \example trapezoidal_rule_example.cpp
        /// This is an example of how to use the trapezoidal_rule.
        /// Suppose we have an integral:
        /// \f[
        /// \int_{0}^{\frac{\pi}{2}} \sin{x} \,dx
        /// \f]
        /// Analytical solution of the integral:
        /// \f[
        /// \int_{0}^{\frac{\pi}{2}} \sin{x} \,dx = -\cos{\frac{\pi}{2}} + \cos{0} = 1
        /// \f]
        /// Then the program that solves this problem and compares the deviation 
        /// between the analytical solution and the numerical solution has the form:
    }
}

#endif