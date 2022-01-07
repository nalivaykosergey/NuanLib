#ifndef NUMERICAL_ANALYSIS_LIB_LAGRANGE_POLYNOMIAL_HPP
#define NUMERICAL_ANALYSIS_LIB_LAGRANGE_POLYNOMIAL_HPP


namespace nuan 
{
    namespace interpolation
    {
    ///  @brief interpolation by Lagrange polynomials.
    ///  @tparam T   Any float-point type such as float, double or long double
    ///  @param x x-point array
    ///  @param y y-point array
    ///  @param size array size x and y
    ///  @param point x-value for interpolation.
    ///  @return interpolated value.
    ///   
    ///  @warning  the size of the array x must be equal to the array y.
    /// 
    ///  @see https://en.wikipedia.org/wiki/Lagrange_polynomial
    template <typename T>
        T lagrange_polynomial(const T * x, const T *y, int size, T point)
        {
            T l = 0.0, q;

            for(int i = 0; i<size; i++)
            {
                q = 1.0;
                for(int j = 0; j<size; j++)
                {
                    if(j != i)
                        q = q*(point - x[j]) / (x[i] - x[j]);
                }
                l += y[i]*q;
            }
            return l;
        }
        /// \example lagrange_example.cpp
        /// This is an example of how to use the lagrange_polynomial.
        /// Suppose we function:
        /// \f[
        /// y = \sin{x}*cos{x^2}
        /// \f]
        /// Then interpolation for this function can be implemented using the following program:
    }
}

#endif