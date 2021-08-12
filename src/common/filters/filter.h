# ifndef Job

#include <vector>
#include "boost/any.hpp"

class Filter {
    public:
        virtual bool execute(std::vector<boost::any>&) = 0;
};

# endif