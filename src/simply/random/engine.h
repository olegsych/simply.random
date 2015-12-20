#pragma once

#include <chrono>
#include <random>

namespace simply
{
    template <typename engine_type = std::default_random_engine>
    engine_type create_random_engine()
    {
        long long seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        return engine_type { static_cast<engine_type::result_type>(seed) };
    }
}
