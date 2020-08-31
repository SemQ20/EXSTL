#ifndef EXUTILITY_HPP
#define EXUTILITY_HPP

#include <type_traits>
#include <queue>
#include <iterator>

namespace estd{
    
    template<typename Container>
    struct is_queue{
        using value_type = typename Container::value_type;
        using true_type = typename std::queue<value_type>;
        static const bool value = std::is_same_v<Container, true_type>;
    };

    template<typename Container>
    inline constexpr bool is_queue_v = is_queue<Container>::value;


    template<typename Container>
    struct is_priority_queue{
        using value_type = typename Container::value_type;
        using true_type = typename std::priority_queue<value_type>;
        static const bool value = std::is_same_v<Container, true_type>;
    };

    template<typename Container>
    inline constexpr bool is_priority_queue_v = is_priority_queue<Container>::value;

    template<typename T, typename = void>
    struct is_iterable : std::false_type{};

    template<typename T>
    struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T&>())), 
                                    decltype(std::end(std::declval<T&>()))>> 
                                    : std::true_type {};

    template<typename T>
    inline constexpr bool is_iterable_v = is_iterable<T>::value;
}

#endif