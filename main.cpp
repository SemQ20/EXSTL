#include "exutility.hpp"
#include <iostream>

 template<typename T>
using v_foo_v = decltype(std::declval<T&>().foo());

template<typename T>
using v_foo_i = decltype(std::declval<T&>().foo(std::declval<int>()));

template<typename T>
inline constexpr bool has_foo = is_detected_v<v_foo_v, T> && is_detected_v<v_foo_i, T>; 

struct S{
    void foo() {}
    void foo(int x) {}
};

struct nonesuch1{
    nonesuch1() = delete;
    nonesuch1(const nonesuch1&) = delete;
    nonesuch1(nonesuch1&&) = delete;
    nonesuch1& operator=(const nonesuch1&) = delete;
    nonesuch1& operator=(nonesuch1&&) = delete;
};

int 
main()
{
    std::queue<int> q;
    S s;
    std::boolalpha(std::cout);

    std::cout << estd::is_queue_v<decltype(q)> << '\n';
    std::cout << estd::is_iterable_v<decltype(q)> << '\n';
    std::cout << has_foo<decltype(s)> << '\n';
    std::cout << std::is_standard_layout<nonesuch1>::value << '\n';
    return 0;
}
