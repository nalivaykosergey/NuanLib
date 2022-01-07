#ifndef NUMERICAL_ANALYSIS_LIB_LRECTANGLE_INTEGRATION_HPP
#define NUMERICAL_ANALYSIS_LIB_LRECTANGLE_INTEGRATION_HPP

#include "integration_error.h"

namespace nuan {
    namespace integration
    {
        ///  @brief Numerical solution of the integrals using left rectangles
        ///  @tparam T   Any float-point type such as float, double or long double
        ///  @param func  integrand 
        ///  @param a start point
        ///  @param b end point
        ///  @param step the step of changing the variable x.
        ///  @return approximate integral value.
        ///   
        ///  @warning  Throws Integration_Range_Error exception when the a >= b.
        /// 
        ///  @see https://www.expii.com/t/left-right-and-midpoint-riemann-sums-244
        template<typename T>
        T left_rectangle(T (*func)(T), T a, T b, T step = 0.01)
        {
            if(a >= b)
                throw errors::IntegrationRangeError();
            T approximated_I = 0.0, x = a;
            while(x < b)
            {
                approximated_I += func(x);
                x += step;
            }
            return approximated_I*step;
        }
        /// \example left_rectangle_example.cpp
        /// This is an example of how to use the left_rectangle.
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