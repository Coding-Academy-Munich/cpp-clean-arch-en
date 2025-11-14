// Copyright (c) 2023 Dr. Matthias Hölzl. All rights reserved.

#include "Utils.h"

namespace library::v2a {

Date MakeYearMonthDay(int year, unsigned int month, unsigned int day)
{
    return Date {static_cast<unsigned int>(year), month, day};
}
} // namespace library::v2a