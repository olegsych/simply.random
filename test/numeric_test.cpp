#include <chrono>
#include <CppUnitTest.h>
#include <limits>
#include <random>
#include <simply/assert.h>
#include <simply/random.h>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace simply
{		
	TEST_CLASS(numeric_test)
	{
        template <typename t>
        struct test_engine
        {
            using result_type = t;

            result_type value;

            static constexpr result_type min()
            {
                return numeric_limits<result_type>::min();
            }

            static constexpr result_type max()
            {
                return numeric_limits<result_type>::max();
            }

            result_type operator()()
            {
                return value;
            }
        };

    public:
        TEST_METHOD(random_integral_returns_value_produced_by_engine)
        {
            test_engine<unsigned> engine_type { 42 };

            unsigned actual = random<unsigned>(numeric_limits<unsigned>::min(), numeric_limits<unsigned>::max(), engine_type);

            assert::is_equal(engine_type.value, actual);
        }

        TEST_METHOD(random_integral_returns_value_between_specified_min_and_max)
        {
            unsigned expected { 42 };

            unsigned actual { random<unsigned>(expected, expected) };

            assert::is_equal(expected, actual);
        }

        TEST_METHOD(random_integral_returns_negative_and_positive_numbers)
        {
            assert::is_true(0 > random<int>(-10, -1));
            assert::is_true(0 < random<int>(1, 10));
        }

        TEST_METHOD(random_integral_returns_values_between_min_and_max_of_the_given_type)
        {
            int actual = random<int>();
            
            assert::is_true(numeric_limits<int>::min() < actual); // Weak assertion
            assert::is_true(numeric_limits<int>::max() > actual);
        }

        TEST_METHOD(random_floating_point_returns_value_produced_by_engine)
        {
            test_engine<double> engine_type { 42 };

            double actual = random<double>(numeric_limits<double>::min(), numeric_limits<double>::max(), engine_type);

            assert::is_equal(engine_type.value, actual);
        }

        TEST_METHOD(random_floating_point_returns_value_between_specified_min_and_max)
        {
            double min { 42 };
            double max { 43 };

            double actual = random<double>(min, max);

            assert::is_true(min <= actual && actual <= max);
        }

        TEST_METHOD(random_floating_point_returns_negative_and_positive_numbers)
        {
            assert::is_true(0 > random<double>(-10, -1));
            assert::is_true(0 < random<double>(1, 10));
        }

        TEST_METHOD(random_floating_point_returns_values_between_min_and_max_of_the_given_type)
        {
            double actual = random<double>();

            assert::is_true(numeric_limits<double>::min() < actual); // Weak assertion
            assert::is_true(numeric_limits<double>::max() > actual);
        }
	};
}