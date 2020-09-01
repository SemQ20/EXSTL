#ifndef EXUTILITY_HPP
#define EXUTILITY_HPP

#include "detector.hpp"
#include <queue>


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

    template<typename T>
    inline constexpr auto is_iterable_v = is_detected_v<free_begin, T> && is_detected_v<free_end, T>;

    template<typename T>
    inline constexpr auto is_reverse_iterable_v = is_iterable_v<T> &&
                                              is_detected_v<free_rbegin, T> && 
                                              is_detected_v<free_rend, T>;
}

#endif