#include "exutility.hpp"
#include <iostream>

int 
main()
{
    std::queue<int> q;
    std::boolalpha(std::cout);
    std::cout<< estd::is_queue_v<decltype(q)> << '\n';
    return 0;
}
