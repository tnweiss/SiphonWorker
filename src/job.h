# ifndef Job

#include <vector>

class Job {
    public:
        virtual std::vector<void *> execute(std::vector<void *>);
};

# endif