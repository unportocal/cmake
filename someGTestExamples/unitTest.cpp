#include <string>
#include "Addition.hpp"
#include "Multiply.hpp"

#include <gtest/gtest.h>

TEST (addTest, positiveNos)
{
    ASSERT_EQ (22, twoValues(11,11));
}
