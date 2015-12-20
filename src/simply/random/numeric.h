#pragma once

#include <limits>
#include <random>
#include <simply/random/engine.h>
#include <type_traits>

namespace simply 
{
    template <typename value_type, typename engine_type = std::default_random_engine>
    typename std::enable_if<std::is_integral<value_type>::value, value_type>::type
    random(
        value_type min = std::numeric_limits<value_type>::min(), 
        value_type max = std::numeric_limits<value_type>::max(), 
        engine_type& engine = create_random_engine<engine_type>())
    {
        std::uniform_int_distribution<value_type> distribution { min, max };
        return distribution(engine);
    }

    template <typename value_type, typename engine_type = std::default_random_engine>
    typename std::enable_if<std::is_floating_point<value_type>::value, value_type>::type
    random(
        value_type min = std::numeric_limits<value_type>::min(), 
        value_type max = std::numeric_limits<value_type>::max(), 
        engine_type& engine = create_random_engine<engine_type>())
    {
        std::uniform_real_distribution<value_type> distribution { min, max };
        return distribution(engine);
    }
}
