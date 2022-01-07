#ifndef NUMERICAL_ANALYSIS_LIB_INTEGRATION_ERROR_H
#define NUMERICAL_ANALYSIS_LIB_INTEGRATION_ERROR_H

#include <exception>

namespace nuan
{
    namespace errors
    {
        ///@brief Structure for throwing exceptions such as decision bounds error
        struct IntegrationRangeError : public std::exception
        {
            ///@brief Overridden method what
            const char * what () const noexcept override
            {
                return "Error when declaring the boundaries of integration\n";
            }
        };
    }

}



#endif