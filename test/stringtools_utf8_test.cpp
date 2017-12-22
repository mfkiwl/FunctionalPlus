// Copyright 2015, Tobias Hermann and the FunctionalPlus contributors.
// https://github.com/Dobiasd/FunctionalPlus
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fplus/fplus.hpp>
#include <fplus/fwd.hpp>

#if !defined(_WIN32) || !defined(WIN32) //TODO: google says there is no UTF8 locale on Windows, is it so?
TEST_CASE("stringtools_test, to_lower/upper_case, utf8")
{
    using namespace fplus;
    const std::locale loc_utf8("ru_RU.utf8");
    auto lower = fwd::to_lower_case_loc(loc_utf8);
    auto upper = fwd::to_upper_case_loc(loc_utf8);
    REQUIRE_EQ(lower(std::wstring(L"cYrIlLiC 123&? КиРиЛлИцА")), std::wstring(L"cyrillic 123&? кириллица"));
    REQUIRE_EQ(lower(std::wstring(L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ")), std::wstring(L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя"));

    REQUIRE_EQ(upper(std::wstring(L"cYrIlLiC 123&? КиРиЛлИцА")), std::wstring(L"CYRILLIC 123&? КИРИЛЛИЦА"));
    REQUIRE_EQ(upper(std::wstring(L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя")), std::wstring(L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"));
    
    REQUIRE_EQ(lower(std::wstring(L"GrEeCe 123&? ΕλΛαΔα")), std::wstring(L"greece 123&? ελλαδα"));
    REQUIRE_EQ(lower(std::wstring(L"ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ")), std::wstring(L"αβγδεζηθικλμνξοπρστυφχψω"));

    REQUIRE_EQ(upper(std::wstring(L"GrEeCe 123&? ΕλΛαΔα")), std::wstring(L"GREECE 123&? ΕΛΛΑΔΑ"));
    REQUIRE_EQ(upper(std::wstring(L"αβγδεζηθικλμνξοπρστυφχψω")), std::wstring(L"ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ"));
}
#endif
