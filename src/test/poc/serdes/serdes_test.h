//
// Created by Tyler on 9/3/2021.
//

#ifndef SIPHON_SERDES_TEST_H
#define SIPHON_SERDES_TEST_H

template<typename T>
class SerdesTest {
public:
    virtual const char* type() = 0;
    virtual const char* serialize(const std::vector<T>&) = 0;
    virtual void deserialize(const char*) = 0;
    virtual bool test(const std::vector<T>&) = 0;
};


#endif //SIPHON_SERDES_TEST_H
