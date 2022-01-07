#ifndef NUMERICAL_ANALYSIS_LIB_NEWTON_POLYNOMIAL_HPP
#define NUMERICAL_ANALYSIS_LIB_NEWTON_POLYNOMIAL_HPP

template <typename T>
static T omega(const T *x, int size, int k, int i);
template <typename T>
static T get_coefficient(const T *x, const T *y, int size, int i);

namespace nuan {
    namespace interpolation
    {
        ///  @brief interpolation by Newton polynomials.
        ///  @tparam T   Any float-point type such as float, double or long double
        ///  @param x x-point array
        ///  @param y y-point array
        ///  @param size array size x and y
        ///  @param point x-value for interpolation
        ///  @param re_calc whether recalculation is required.
        ///  @return interpolated value.
        ///   
        ///  @warning  the size of the array x must be equal to the array y.
        /// 
        ///  @see https://en.wikipedia.org/wiki/Newton_polynomial
        template <typename T>
        T newton_polynomial(const T *x, const T *y, int size, T point, bool re_calc = false)
        {
            T P_n;
            T value;
            if(re_calc)
            {
                value = 1.0;
                P_n = point;
                for(int k = 0; k < size-1; k++)
                    value *= point - x[k];
                P_n += get_coefficient(x,y, size, (int)size-1) * value;
                return P_n;
            }
            else
            {
                P_n = y[0];
                for(int j = 1; j < size; j++) {
                    value = 1.0;
                    for (int k = 0; k < j; k++)
                        value *= (point - x[k]);
                    P_n += get_coefficient(x, y, size, j) * value;
                }
            }
            return P_n;
        }
        /// \example newton_example.cpp
        /// This is an example of how to use the newton_polynomial.
        /// Suppose we function:
        /// \f[
        /// y = \sin{x}*cos{x^2}
        /// \f]
        /// Then interpolation for this function can be implemented using the following program:

    }
}

template <typename T>
static T omega(const T *x, int size, int k, int i)
{
    T value;
    value = 1.0;
    for(int j = 0; j <= i; j++)
        if(k != j)
            value *= x[k] - x[j];
    return value;
}


template <typename T>
static T get_coefficient(const T *x, const T *y, int size, int i)
{
    if(i == 0)
        return y[0];
    T value;
    value = 0.0;
    for(int k = 0; k <= i; k++)
        value += y[k] / omega(x, size, k, i);
    return value;
}

#endif