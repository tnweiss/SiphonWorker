# ifndef Job

#include <vector>

class Filter {
    public:
        virtual bool execute(std::vector<void *>) = 0;
};

# endif