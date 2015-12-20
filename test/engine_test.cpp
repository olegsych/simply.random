#include <chrono>
#include <CppUnitTest.h>
#include <simply/assert.h>
#include <simply/random/engine.h>
#include <random>
#include <type_traits>

using namespace std;
using namespace std::chrono;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{
    TEST_CLASS(engine_test)
    {
        class test_engine
        {
        public:
            using result_type = unsigned;

            test_engine(unsigned seed)
            {
                this->seed = seed;
            }

            unsigned seed;
        };

    public:
        TEST_METHOD(create_random_engine_seeds_engine_with_current_time)
        {
            time_point<steady_clock> before { high_resolution_clock::now() };

            test_engine engine_type = create_random_engine<test_engine>();
            
            time_point<steady_clock> after { high_resolution_clock::now() };
            assert::is_true(engine_type.seed >= static_cast<unsigned>(before.time_since_epoch().count()));
            assert::is_true(engine_type.seed <= static_cast<unsigned>(after.time_since_epoch().count()));
        }

        TEST_METHOD(create_random_engine_returns_default_random_engine_by_default)
        {
            default_random_engine actual { create_random_engine() };
        }
    };
}