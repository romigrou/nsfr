/*
 * This software is available under 2 licenses -- choose whichever you prefer.
 *
 * -------------------------------------------------------------------------------
 *
 * Copyright (c) 2023 Romain BAILLY
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * -------------------------------------------------------------------------------
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <https://unlicense.org/>
 */

#include <rmgr/nsfr.h>
#include <cassert>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>


using namespace rmgr::nsfr;


static unsigned g_testCount = 0;


template<typename T>
bool assert_spellout(int line, T value, unsigned options, const char* expectedName)
{
    ++g_testCount;
    std::string name = spell_out(value, options);
    if (name != expectedName)
    {
        fprintf(stderr, "%s(%d): %" PRIdMAX " was spelled out as \"%s\" instead of \"%s\"\n", __FILE__, line, intmax_t(value), name.c_str(), expectedName);
        return 0;
    }
    return 1;
}

#define ASSERT_SPELLOUT(value, options, expectedName) succeeded += assert_spellout(__LINE__, value, options, expectedName)


static unsigned test_cardinals_0_99(unsigned type)
{
    assert(type == CARDINAL || type == CARDINAL_AS_ORDINAL);

    unsigned succeeded = 0;

    ASSERT_SPELLOUT( 0, type|MASCULINE,          u8"zéro");
    ASSERT_SPELLOUT( 0, type|FEMININE,           u8"zéro");
    ASSERT_SPELLOUT( 1, type|MASCULINE,          u8"un");
    ASSERT_SPELLOUT( 1, type|FEMININE,           u8"une");
    ASSERT_SPELLOUT( 2, type|MASCULINE,          u8"deux");
    ASSERT_SPELLOUT( 2, type|FEMININE,           u8"deux");
    ASSERT_SPELLOUT( 3, type|MASCULINE,          u8"trois");
    ASSERT_SPELLOUT( 4, type|MASCULINE,          u8"quatre");
    ASSERT_SPELLOUT( 5, type|MASCULINE,          u8"cinq");
    ASSERT_SPELLOUT( 6, type|MASCULINE,          u8"six");
    ASSERT_SPELLOUT( 7, type|MASCULINE,          u8"sept");
    ASSERT_SPELLOUT( 8, type|MASCULINE,          u8"huit");
    ASSERT_SPELLOUT( 9, type|MASCULINE,          u8"neuf");
    ASSERT_SPELLOUT(10, type|MASCULINE,          u8"dix");

    ASSERT_SPELLOUT(11, type|MASCULINE,          u8"onze");
    ASSERT_SPELLOUT(12, type|MASCULINE,          u8"douze");
    ASSERT_SPELLOUT(13, type|MASCULINE,          u8"treize");
    ASSERT_SPELLOUT(14, type|MASCULINE,          u8"quatorze");
    ASSERT_SPELLOUT(15, type|MASCULINE,          u8"quinze");
    ASSERT_SPELLOUT(16, type|MASCULINE,          u8"seize");
    ASSERT_SPELLOUT(17, type|MASCULINE,          u8"dix-sept");
    ASSERT_SPELLOUT(18, type|MASCULINE,          u8"dix-huit");
    ASSERT_SPELLOUT(19, type|MASCULINE,          u8"dix-neuf");

    ASSERT_SPELLOUT(20, type|MASCULINE,          u8"vingt");
    ASSERT_SPELLOUT(21, type|MASCULINE,          u8"vingt et un");
    ASSERT_SPELLOUT(21, type|FEMININE,           u8"vingt et une");
    ASSERT_SPELLOUT(22, type|MASCULINE,          u8"vingt-deux");
    ASSERT_SPELLOUT(23, type|MASCULINE,          u8"vingt-trois");
    ASSERT_SPELLOUT(24, type|MASCULINE,          u8"vingt-quatre");
    ASSERT_SPELLOUT(25, type|MASCULINE,          u8"vingt-cinq");
    ASSERT_SPELLOUT(26, type|MASCULINE,          u8"vingt-six");
    ASSERT_SPELLOUT(27, type|MASCULINE,          u8"vingt-sept");
    ASSERT_SPELLOUT(28, type|MASCULINE,          u8"vingt-huit");
    ASSERT_SPELLOUT(29, type|MASCULINE,          u8"vingt-neuf");

    ASSERT_SPELLOUT(30, type|MASCULINE,          u8"trente");
    ASSERT_SPELLOUT(31, type|MASCULINE,          u8"trente et un");
    ASSERT_SPELLOUT(31, type|FEMININE,           u8"trente et une");
    ASSERT_SPELLOUT(32, type|MASCULINE,          u8"trente-deux");
    ASSERT_SPELLOUT(33, type|MASCULINE,          u8"trente-trois");
    ASSERT_SPELLOUT(34, type|MASCULINE,          u8"trente-quatre");
    ASSERT_SPELLOUT(35, type|MASCULINE,          u8"trente-cinq");
    ASSERT_SPELLOUT(36, type|MASCULINE,          u8"trente-six");
    ASSERT_SPELLOUT(37, type|MASCULINE,          u8"trente-sept");
    ASSERT_SPELLOUT(38, type|MASCULINE,          u8"trente-huit");
    ASSERT_SPELLOUT(39, type|MASCULINE,          u8"trente-neuf");

    ASSERT_SPELLOUT(40, type|MASCULINE,          u8"quarante");
    ASSERT_SPELLOUT(41, type|MASCULINE,          u8"quarante et un");
    ASSERT_SPELLOUT(41, type|FEMININE,           u8"quarante et une");
    ASSERT_SPELLOUT(42, type|MASCULINE,          u8"quarante-deux");
    ASSERT_SPELLOUT(43, type|MASCULINE,          u8"quarante-trois");
    ASSERT_SPELLOUT(44, type|MASCULINE,          u8"quarante-quatre");
    ASSERT_SPELLOUT(45, type|MASCULINE,          u8"quarante-cinq");
    ASSERT_SPELLOUT(46, type|MASCULINE,          u8"quarante-six");
    ASSERT_SPELLOUT(47, type|MASCULINE,          u8"quarante-sept");
    ASSERT_SPELLOUT(48, type|MASCULINE,          u8"quarante-huit");
    ASSERT_SPELLOUT(49, type|MASCULINE,          u8"quarante-neuf");

    ASSERT_SPELLOUT(50, type|MASCULINE,          u8"cinquante");
    ASSERT_SPELLOUT(51, type|MASCULINE,          u8"cinquante et un");
    ASSERT_SPELLOUT(51, type|FEMININE,           u8"cinquante et une");
    ASSERT_SPELLOUT(52, type|MASCULINE,          u8"cinquante-deux");
    ASSERT_SPELLOUT(53, type|MASCULINE,          u8"cinquante-trois");
    ASSERT_SPELLOUT(54, type|MASCULINE,          u8"cinquante-quatre");
    ASSERT_SPELLOUT(55, type|MASCULINE,          u8"cinquante-cinq");
    ASSERT_SPELLOUT(56, type|MASCULINE,          u8"cinquante-six");
    ASSERT_SPELLOUT(57, type|MASCULINE,          u8"cinquante-sept");
    ASSERT_SPELLOUT(58, type|MASCULINE,          u8"cinquante-huit");
    ASSERT_SPELLOUT(59, type|MASCULINE,          u8"cinquante-neuf");

    ASSERT_SPELLOUT(60, type|MASCULINE,          u8"soixante");
    ASSERT_SPELLOUT(61, type|MASCULINE,          u8"soixante et un");
    ASSERT_SPELLOUT(61, type|FEMININE,           u8"soixante et une");
    ASSERT_SPELLOUT(62, type|MASCULINE,          u8"soixante-deux");
    ASSERT_SPELLOUT(63, type|MASCULINE,          u8"soixante-trois");
    ASSERT_SPELLOUT(64, type|MASCULINE,          u8"soixante-quatre");
    ASSERT_SPELLOUT(65, type|MASCULINE,          u8"soixante-cinq");
    ASSERT_SPELLOUT(66, type|MASCULINE,          u8"soixante-six");
    ASSERT_SPELLOUT(67, type|MASCULINE,          u8"soixante-sept");
    ASSERT_SPELLOUT(68, type|MASCULINE,          u8"soixante-huit");
    ASSERT_SPELLOUT(69, type|MASCULINE,          u8"soixante-neuf");

    ASSERT_SPELLOUT(70, type|MASCULINE,          u8"soixante-dix");
    ASSERT_SPELLOUT(71, type|MASCULINE,          u8"soixante et onze");
    ASSERT_SPELLOUT(71, type|FEMININE,           u8"soixante et onze");
    ASSERT_SPELLOUT(72, type|MASCULINE,          u8"soixante-douze");
    ASSERT_SPELLOUT(73, type|MASCULINE,          u8"soixante-treize");
    ASSERT_SPELLOUT(74, type|MASCULINE,          u8"soixante-quatorze");
    ASSERT_SPELLOUT(75, type|MASCULINE,          u8"soixante-quinze");
    ASSERT_SPELLOUT(76, type|MASCULINE,          u8"soixante-seize");
    ASSERT_SPELLOUT(77, type|MASCULINE,          u8"soixante-dix-sept");
    ASSERT_SPELLOUT(78, type|MASCULINE,          u8"soixante-dix-huit");
    ASSERT_SPELLOUT(79, type|MASCULINE,          u8"soixante-dix-neuf");

    ASSERT_SPELLOUT(70, type|MASCULINE|SEPTANTE, u8"septante");
    ASSERT_SPELLOUT(71, type|MASCULINE|SEPTANTE, u8"septante et un");
    ASSERT_SPELLOUT(71, type|FEMININE |SEPTANTE, u8"septante et une");
    ASSERT_SPELLOUT(72, type|MASCULINE|SEPTANTE, u8"septante-deux");
    ASSERT_SPELLOUT(73, type|MASCULINE|SEPTANTE, u8"septante-trois");
    ASSERT_SPELLOUT(74, type|MASCULINE|SEPTANTE, u8"septante-quatre");
    ASSERT_SPELLOUT(75, type|MASCULINE|SEPTANTE, u8"septante-cinq");
    ASSERT_SPELLOUT(76, type|MASCULINE|SEPTANTE, u8"septante-six");
    ASSERT_SPELLOUT(77, type|MASCULINE|SEPTANTE, u8"septante-sept");
    ASSERT_SPELLOUT(78, type|MASCULINE|SEPTANTE, u8"septante-huit");
    ASSERT_SPELLOUT(79, type|MASCULINE|SEPTANTE, u8"septante-neuf");

    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(80, type|MASCULINE,      u8"quatre-vingt");
    else
        ASSERT_SPELLOUT(80, type|MASCULINE,      u8"quatre-vingts");
    ASSERT_SPELLOUT(81, type|MASCULINE,          u8"quatre-vingt-un");
    ASSERT_SPELLOUT(81, type|FEMININE ,          u8"quatre-vingt-une");
    ASSERT_SPELLOUT(82, type|MASCULINE,          u8"quatre-vingt-deux");
    ASSERT_SPELLOUT(83, type|MASCULINE,          u8"quatre-vingt-trois");
    ASSERT_SPELLOUT(84, type|MASCULINE,          u8"quatre-vingt-quatre");
    ASSERT_SPELLOUT(85, type|MASCULINE,          u8"quatre-vingt-cinq");
    ASSERT_SPELLOUT(86, type|MASCULINE,          u8"quatre-vingt-six");
    ASSERT_SPELLOUT(87, type|MASCULINE,          u8"quatre-vingt-sept");
    ASSERT_SPELLOUT(88, type|MASCULINE,          u8"quatre-vingt-huit");
    ASSERT_SPELLOUT(89, type|MASCULINE,          u8"quatre-vingt-neuf");

    ASSERT_SPELLOUT(80, type|MASCULINE|HUITANTE, u8"huitante");
    ASSERT_SPELLOUT(81, type|MASCULINE|HUITANTE, u8"huitante et un");
    ASSERT_SPELLOUT(81, type|FEMININE |HUITANTE, u8"huitante et une");
    ASSERT_SPELLOUT(82, type|MASCULINE|HUITANTE, u8"huitante-deux");
    ASSERT_SPELLOUT(83, type|MASCULINE|HUITANTE, u8"huitante-trois");
    ASSERT_SPELLOUT(84, type|MASCULINE|HUITANTE, u8"huitante-quatre");
    ASSERT_SPELLOUT(85, type|MASCULINE|HUITANTE, u8"huitante-cinq");
    ASSERT_SPELLOUT(86, type|MASCULINE|HUITANTE, u8"huitante-six");
    ASSERT_SPELLOUT(87, type|MASCULINE|HUITANTE, u8"huitante-sept");
    ASSERT_SPELLOUT(88, type|MASCULINE|HUITANTE, u8"huitante-huit");
    ASSERT_SPELLOUT(89, type|MASCULINE|HUITANTE, u8"huitante-neuf");

    ASSERT_SPELLOUT(80, type|MASCULINE|OCTANTE,  u8"octante");
    ASSERT_SPELLOUT(81, type|MASCULINE|OCTANTE,  u8"octante et un");
    ASSERT_SPELLOUT(81, type|FEMININE |OCTANTE,  u8"octante et une");
    ASSERT_SPELLOUT(82, type|MASCULINE|OCTANTE,  u8"octante-deux");
    ASSERT_SPELLOUT(83, type|MASCULINE|OCTANTE,  u8"octante-trois");
    ASSERT_SPELLOUT(84, type|MASCULINE|OCTANTE,  u8"octante-quatre");
    ASSERT_SPELLOUT(85, type|MASCULINE|OCTANTE,  u8"octante-cinq");
    ASSERT_SPELLOUT(86, type|MASCULINE|OCTANTE,  u8"octante-six");
    ASSERT_SPELLOUT(87, type|MASCULINE|OCTANTE,  u8"octante-sept");
    ASSERT_SPELLOUT(88, type|MASCULINE|OCTANTE,  u8"octante-huit");
    ASSERT_SPELLOUT(89, type|MASCULINE|OCTANTE,  u8"octante-neuf");

    ASSERT_SPELLOUT(90, type|MASCULINE,          u8"quatre-vingt-dix");
    ASSERT_SPELLOUT(91, type|MASCULINE,          u8"quatre-vingt-onze");
    ASSERT_SPELLOUT(91, type|FEMININE,           u8"quatre-vingt-onze");
    ASSERT_SPELLOUT(92, type|MASCULINE,          u8"quatre-vingt-douze");
    ASSERT_SPELLOUT(93, type|MASCULINE,          u8"quatre-vingt-treize");
    ASSERT_SPELLOUT(94, type|MASCULINE,          u8"quatre-vingt-quatorze");
    ASSERT_SPELLOUT(95, type|MASCULINE,          u8"quatre-vingt-quinze");
    ASSERT_SPELLOUT(96, type|MASCULINE,          u8"quatre-vingt-seize");
    ASSERT_SPELLOUT(97, type|MASCULINE,          u8"quatre-vingt-dix-sept");
    ASSERT_SPELLOUT(98, type|MASCULINE,          u8"quatre-vingt-dix-huit");
    ASSERT_SPELLOUT(99, type|MASCULINE,          u8"quatre-vingt-dix-neuf");

    ASSERT_SPELLOUT(90, type|MASCULINE|NONANTE,  u8"nonante");
    ASSERT_SPELLOUT(91, type|MASCULINE|NONANTE,  u8"nonante et un");
    ASSERT_SPELLOUT(91, type|FEMININE |NONANTE,  u8"nonante et une");
    ASSERT_SPELLOUT(92, type|MASCULINE|NONANTE,  u8"nonante-deux");
    ASSERT_SPELLOUT(93, type|MASCULINE|NONANTE,  u8"nonante-trois");
    ASSERT_SPELLOUT(94, type|MASCULINE|NONANTE,  u8"nonante-quatre");
    ASSERT_SPELLOUT(95, type|MASCULINE|NONANTE,  u8"nonante-cinq");
    ASSERT_SPELLOUT(96, type|MASCULINE|NONANTE,  u8"nonante-six");
    ASSERT_SPELLOUT(97, type|MASCULINE|NONANTE,  u8"nonante-sept");
    ASSERT_SPELLOUT(98, type|MASCULINE|NONANTE,  u8"nonante-huit");
    ASSERT_SPELLOUT(99, type|MASCULINE|NONANTE,  u8"nonante-neuf");

    return succeeded;
}


static unsigned test_ordinals_0_99()
{
    unsigned succeeded = 0;

    ASSERT_SPELLOUT( 0, ORDINAL|MASCULINE,          u8"zéroième");
    ASSERT_SPELLOUT( 0, ORDINAL|FEMININE,           u8"zéroième");
    ASSERT_SPELLOUT( 1, ORDINAL|MASCULINE,          u8"premier");
    ASSERT_SPELLOUT( 1, ORDINAL|FEMININE,           u8"première");
    ASSERT_SPELLOUT( 2, ORDINAL|SECOND|MASCULINE,   u8"second");
    ASSERT_SPELLOUT( 2, ORDINAL|SECOND|FEMININE,    u8"seconde");
    ASSERT_SPELLOUT( 3, ORDINAL|MASCULINE,          u8"troisième");
    ASSERT_SPELLOUT( 4, ORDINAL|MASCULINE,          u8"quatrième");
    ASSERT_SPELLOUT( 5, ORDINAL|MASCULINE,          u8"cinquième");
    ASSERT_SPELLOUT( 6, ORDINAL|MASCULINE,          u8"sixième");
    ASSERT_SPELLOUT( 7, ORDINAL|MASCULINE,          u8"septième");
    ASSERT_SPELLOUT( 8, ORDINAL|MASCULINE,          u8"huitième");
    ASSERT_SPELLOUT( 9, ORDINAL|MASCULINE,          u8"neuvième");
    ASSERT_SPELLOUT(10, ORDINAL|MASCULINE,          u8"dixième");

    ASSERT_SPELLOUT(11, ORDINAL|MASCULINE,          u8"onzième");
    ASSERT_SPELLOUT(12, ORDINAL|MASCULINE,          u8"douzième");
    ASSERT_SPELLOUT(13, ORDINAL|MASCULINE,          u8"treizième");
    ASSERT_SPELLOUT(14, ORDINAL|MASCULINE,          u8"quatorzième");
    ASSERT_SPELLOUT(15, ORDINAL|MASCULINE,          u8"quinzième");
    ASSERT_SPELLOUT(16, ORDINAL|MASCULINE,          u8"seizième");
    ASSERT_SPELLOUT(17, ORDINAL|MASCULINE,          u8"dix-septième");
    ASSERT_SPELLOUT(18, ORDINAL|MASCULINE,          u8"dix-huitième");
    ASSERT_SPELLOUT(19, ORDINAL|MASCULINE,          u8"dix-neuvième");

    ASSERT_SPELLOUT(20, ORDINAL|MASCULINE,          u8"vingtième");
    ASSERT_SPELLOUT(21, ORDINAL|MASCULINE,          u8"vingt et unième");
    ASSERT_SPELLOUT(21, ORDINAL|FEMININE,           u8"vingt et unième");
    ASSERT_SPELLOUT(22, ORDINAL|MASCULINE,          u8"vingt-deuxième");
    ASSERT_SPELLOUT(23, ORDINAL|MASCULINE,          u8"vingt-troisième");
    ASSERT_SPELLOUT(24, ORDINAL|MASCULINE,          u8"vingt-quatrième");
    ASSERT_SPELLOUT(25, ORDINAL|MASCULINE,          u8"vingt-cinquième");
    ASSERT_SPELLOUT(26, ORDINAL|MASCULINE,          u8"vingt-sixième");
    ASSERT_SPELLOUT(27, ORDINAL|MASCULINE,          u8"vingt-septième");
    ASSERT_SPELLOUT(28, ORDINAL|MASCULINE,          u8"vingt-huitième");
    ASSERT_SPELLOUT(29, ORDINAL|MASCULINE,          u8"vingt-neuvième");

    ASSERT_SPELLOUT(30, ORDINAL|MASCULINE,          u8"trentième");
    ASSERT_SPELLOUT(31, ORDINAL|MASCULINE,          u8"trente et unième");
    ASSERT_SPELLOUT(31, ORDINAL|FEMININE,           u8"trente et unième");
    ASSERT_SPELLOUT(32, ORDINAL|MASCULINE,          u8"trente-deuxième");
    ASSERT_SPELLOUT(33, ORDINAL|MASCULINE,          u8"trente-troisième");
    ASSERT_SPELLOUT(34, ORDINAL|MASCULINE,          u8"trente-quatrième");
    ASSERT_SPELLOUT(35, ORDINAL|MASCULINE,          u8"trente-cinquième");
    ASSERT_SPELLOUT(36, ORDINAL|MASCULINE,          u8"trente-sixième");
    ASSERT_SPELLOUT(37, ORDINAL|MASCULINE,          u8"trente-septième");
    ASSERT_SPELLOUT(38, ORDINAL|MASCULINE,          u8"trente-huitième");
    ASSERT_SPELLOUT(39, ORDINAL|MASCULINE,          u8"trente-neuvième");

    ASSERT_SPELLOUT(40, ORDINAL|MASCULINE,          u8"quarantième");
    ASSERT_SPELLOUT(41, ORDINAL|MASCULINE,          u8"quarante et unième");
    ASSERT_SPELLOUT(41, ORDINAL|FEMININE,           u8"quarante et unième");
    ASSERT_SPELLOUT(42, ORDINAL|MASCULINE,          u8"quarante-deuxième");
    ASSERT_SPELLOUT(43, ORDINAL|MASCULINE,          u8"quarante-troisième");
    ASSERT_SPELLOUT(44, ORDINAL|MASCULINE,          u8"quarante-quatrième");
    ASSERT_SPELLOUT(45, ORDINAL|MASCULINE,          u8"quarante-cinquième");
    ASSERT_SPELLOUT(46, ORDINAL|MASCULINE,          u8"quarante-sixième");
    ASSERT_SPELLOUT(47, ORDINAL|MASCULINE,          u8"quarante-septième");
    ASSERT_SPELLOUT(48, ORDINAL|MASCULINE,          u8"quarante-huitième");
    ASSERT_SPELLOUT(49, ORDINAL|MASCULINE,          u8"quarante-neuvième");

    ASSERT_SPELLOUT(50, ORDINAL|MASCULINE,          u8"cinquantième");
    ASSERT_SPELLOUT(51, ORDINAL|MASCULINE,          u8"cinquante et unième");
    ASSERT_SPELLOUT(51, ORDINAL|FEMININE,           u8"cinquante et unième");
    ASSERT_SPELLOUT(52, ORDINAL|MASCULINE,          u8"cinquante-deuxième");
    ASSERT_SPELLOUT(53, ORDINAL|MASCULINE,          u8"cinquante-troisième");
    ASSERT_SPELLOUT(54, ORDINAL|MASCULINE,          u8"cinquante-quatrième");
    ASSERT_SPELLOUT(55, ORDINAL|MASCULINE,          u8"cinquante-cinquième");
    ASSERT_SPELLOUT(56, ORDINAL|MASCULINE,          u8"cinquante-sixième");
    ASSERT_SPELLOUT(57, ORDINAL|MASCULINE,          u8"cinquante-septième");
    ASSERT_SPELLOUT(58, ORDINAL|MASCULINE,          u8"cinquante-huitième");
    ASSERT_SPELLOUT(59, ORDINAL|MASCULINE,          u8"cinquante-neuvième");

    ASSERT_SPELLOUT(60, ORDINAL|MASCULINE,          u8"soixantième");
    ASSERT_SPELLOUT(61, ORDINAL|MASCULINE,          u8"soixante et unième");
    ASSERT_SPELLOUT(61, ORDINAL|FEMININE,           u8"soixante et unième");
    ASSERT_SPELLOUT(62, ORDINAL|MASCULINE,          u8"soixante-deuxième");
    ASSERT_SPELLOUT(63, ORDINAL|MASCULINE,          u8"soixante-troisième");
    ASSERT_SPELLOUT(64, ORDINAL|MASCULINE,          u8"soixante-quatrième");
    ASSERT_SPELLOUT(65, ORDINAL|MASCULINE,          u8"soixante-cinquième");
    ASSERT_SPELLOUT(66, ORDINAL|MASCULINE,          u8"soixante-sixième");
    ASSERT_SPELLOUT(67, ORDINAL|MASCULINE,          u8"soixante-septième");
    ASSERT_SPELLOUT(68, ORDINAL|MASCULINE,          u8"soixante-huitième");
    ASSERT_SPELLOUT(69, ORDINAL|MASCULINE,          u8"soixante-neuvième");

    ASSERT_SPELLOUT(70, ORDINAL|MASCULINE,          u8"soixante-dixième");
    ASSERT_SPELLOUT(71, ORDINAL|MASCULINE,          u8"soixante et onzième");
    ASSERT_SPELLOUT(71, ORDINAL|FEMININE,           u8"soixante et onzième");
    ASSERT_SPELLOUT(72, ORDINAL|MASCULINE,          u8"soixante-douzième");
    ASSERT_SPELLOUT(73, ORDINAL|MASCULINE,          u8"soixante-treizième");
    ASSERT_SPELLOUT(74, ORDINAL|MASCULINE,          u8"soixante-quatorzième");
    ASSERT_SPELLOUT(75, ORDINAL|MASCULINE,          u8"soixante-quinzième");
    ASSERT_SPELLOUT(76, ORDINAL|MASCULINE,          u8"soixante-seizième");
    ASSERT_SPELLOUT(77, ORDINAL|MASCULINE,          u8"soixante-dix-septième");
    ASSERT_SPELLOUT(78, ORDINAL|MASCULINE,          u8"soixante-dix-huitième");
    ASSERT_SPELLOUT(79, ORDINAL|MASCULINE,          u8"soixante-dix-neuvième");

    ASSERT_SPELLOUT(70, ORDINAL|MASCULINE|SEPTANTE, u8"septantième");
    ASSERT_SPELLOUT(71, ORDINAL|MASCULINE|SEPTANTE, u8"septante et unième");
    ASSERT_SPELLOUT(71, ORDINAL|FEMININE |SEPTANTE, u8"septante et unième");
    ASSERT_SPELLOUT(72, ORDINAL|MASCULINE|SEPTANTE, u8"septante-deuxième");
    ASSERT_SPELLOUT(73, ORDINAL|MASCULINE|SEPTANTE, u8"septante-troisième");
    ASSERT_SPELLOUT(74, ORDINAL|MASCULINE|SEPTANTE, u8"septante-quatrième");
    ASSERT_SPELLOUT(75, ORDINAL|MASCULINE|SEPTANTE, u8"septante-cinquième");
    ASSERT_SPELLOUT(76, ORDINAL|MASCULINE|SEPTANTE, u8"septante-sixième");
    ASSERT_SPELLOUT(77, ORDINAL|MASCULINE|SEPTANTE, u8"septante-septième");
    ASSERT_SPELLOUT(78, ORDINAL|MASCULINE|SEPTANTE, u8"septante-huitième");
    ASSERT_SPELLOUT(79, ORDINAL|MASCULINE|SEPTANTE, u8"septante-neuvième");

    ASSERT_SPELLOUT(80, ORDINAL|MASCULINE,          u8"quatre-vingtième");
    ASSERT_SPELLOUT(81, ORDINAL|MASCULINE,          u8"quatre-vingt-unième");
    ASSERT_SPELLOUT(81, ORDINAL|FEMININE ,          u8"quatre-vingt-unième");
    ASSERT_SPELLOUT(82, ORDINAL|MASCULINE,          u8"quatre-vingt-deuxième");
    ASSERT_SPELLOUT(83, ORDINAL|MASCULINE,          u8"quatre-vingt-troisième");
    ASSERT_SPELLOUT(84, ORDINAL|MASCULINE,          u8"quatre-vingt-quatrième");
    ASSERT_SPELLOUT(85, ORDINAL|MASCULINE,          u8"quatre-vingt-cinquième");
    ASSERT_SPELLOUT(86, ORDINAL|MASCULINE,          u8"quatre-vingt-sixième");
    ASSERT_SPELLOUT(87, ORDINAL|MASCULINE,          u8"quatre-vingt-septième");
    ASSERT_SPELLOUT(88, ORDINAL|MASCULINE,          u8"quatre-vingt-huitième");
    ASSERT_SPELLOUT(89, ORDINAL|MASCULINE,          u8"quatre-vingt-neuvième");

    ASSERT_SPELLOUT(80, ORDINAL|MASCULINE|HUITANTE, u8"huitantième");
    ASSERT_SPELLOUT(81, ORDINAL|MASCULINE|HUITANTE, u8"huitante et unième");
    ASSERT_SPELLOUT(81, ORDINAL|FEMININE |HUITANTE, u8"huitante et unième");
    ASSERT_SPELLOUT(82, ORDINAL|MASCULINE|HUITANTE, u8"huitante-deuxième");
    ASSERT_SPELLOUT(83, ORDINAL|MASCULINE|HUITANTE, u8"huitante-troisième");
    ASSERT_SPELLOUT(84, ORDINAL|MASCULINE|HUITANTE, u8"huitante-quatrième");
    ASSERT_SPELLOUT(85, ORDINAL|MASCULINE|HUITANTE, u8"huitante-cinquième");
    ASSERT_SPELLOUT(86, ORDINAL|MASCULINE|HUITANTE, u8"huitante-sixième");
    ASSERT_SPELLOUT(87, ORDINAL|MASCULINE|HUITANTE, u8"huitante-septième");
    ASSERT_SPELLOUT(88, ORDINAL|MASCULINE|HUITANTE, u8"huitante-huitième");
    ASSERT_SPELLOUT(89, ORDINAL|MASCULINE|HUITANTE, u8"huitante-neuvième");

    ASSERT_SPELLOUT(80, ORDINAL|MASCULINE|OCTANTE,  u8"octantième");
    ASSERT_SPELLOUT(81, ORDINAL|MASCULINE|OCTANTE,  u8"octante et unième");
    ASSERT_SPELLOUT(81, ORDINAL|FEMININE |OCTANTE,  u8"octante et unième");
    ASSERT_SPELLOUT(82, ORDINAL|MASCULINE|OCTANTE,  u8"octante-deuxième");
    ASSERT_SPELLOUT(83, ORDINAL|MASCULINE|OCTANTE,  u8"octante-troisième");
    ASSERT_SPELLOUT(84, ORDINAL|MASCULINE|OCTANTE,  u8"octante-quatrième");
    ASSERT_SPELLOUT(85, ORDINAL|MASCULINE|OCTANTE,  u8"octante-cinquième");
    ASSERT_SPELLOUT(86, ORDINAL|MASCULINE|OCTANTE,  u8"octante-sixième");
    ASSERT_SPELLOUT(87, ORDINAL|MASCULINE|OCTANTE,  u8"octante-septième");
    ASSERT_SPELLOUT(88, ORDINAL|MASCULINE|OCTANTE,  u8"octante-huitième");
    ASSERT_SPELLOUT(89, ORDINAL|MASCULINE|OCTANTE,  u8"octante-neuvième");

    ASSERT_SPELLOUT(90, ORDINAL|MASCULINE,          u8"quatre-vingt-dixième");
    ASSERT_SPELLOUT(91, ORDINAL|MASCULINE,          u8"quatre-vingt-onzième");
    ASSERT_SPELLOUT(91, ORDINAL|FEMININE,           u8"quatre-vingt-onzième");
    ASSERT_SPELLOUT(92, ORDINAL|MASCULINE,          u8"quatre-vingt-douzième");
    ASSERT_SPELLOUT(93, ORDINAL|MASCULINE,          u8"quatre-vingt-treizième");
    ASSERT_SPELLOUT(94, ORDINAL|MASCULINE,          u8"quatre-vingt-quatorzième");
    ASSERT_SPELLOUT(95, ORDINAL|MASCULINE,          u8"quatre-vingt-quinzième");
    ASSERT_SPELLOUT(96, ORDINAL|MASCULINE,          u8"quatre-vingt-seizième");
    ASSERT_SPELLOUT(97, ORDINAL|MASCULINE,          u8"quatre-vingt-dix-septième");
    ASSERT_SPELLOUT(98, ORDINAL|MASCULINE,          u8"quatre-vingt-dix-huitième");
    ASSERT_SPELLOUT(99, ORDINAL|MASCULINE,          u8"quatre-vingt-dix-neuvième");

    ASSERT_SPELLOUT(90, ORDINAL|MASCULINE|NONANTE,  u8"nonantième");
    ASSERT_SPELLOUT(91, ORDINAL|MASCULINE|NONANTE,  u8"nonante et unième");
    ASSERT_SPELLOUT(91, ORDINAL|FEMININE |NONANTE,  u8"nonante et unième");
    ASSERT_SPELLOUT(92, ORDINAL|MASCULINE|NONANTE,  u8"nonante-deuxième");
    ASSERT_SPELLOUT(93, ORDINAL|MASCULINE|NONANTE,  u8"nonante-troisième");
    ASSERT_SPELLOUT(94, ORDINAL|MASCULINE|NONANTE,  u8"nonante-quatrième");
    ASSERT_SPELLOUT(95, ORDINAL|MASCULINE|NONANTE,  u8"nonante-cinquième");
    ASSERT_SPELLOUT(96, ORDINAL|MASCULINE|NONANTE,  u8"nonante-sixième");
    ASSERT_SPELLOUT(97, ORDINAL|MASCULINE|NONANTE,  u8"nonante-septième");
    ASSERT_SPELLOUT(98, ORDINAL|MASCULINE|NONANTE,  u8"nonante-huitième");
    ASSERT_SPELLOUT(99, ORDINAL|MASCULINE|NONANTE,  u8"nonante-neuvième");

    return succeeded;
}


static unsigned test_cardinals_100_999(unsigned type)
{
    unsigned succeeded = 0;

    ASSERT_SPELLOUT(100, type|MASCULINE,          u8"cent");
    ASSERT_SPELLOUT(101, type|MASCULINE,          u8"cent un");
    ASSERT_SPELLOUT(101, type|FEMININE,           u8"cent une");
    ASSERT_SPELLOUT(102, type|MASCULINE,          u8"cent deux");
    ASSERT_SPELLOUT(110, type|MASCULINE,          u8"cent dix");
    ASSERT_SPELLOUT(111, type|MASCULINE,          u8"cent onze");
    ASSERT_SPELLOUT(112, type|MASCULINE,          u8"cent douze");
    ASSERT_SPELLOUT(113, type|MASCULINE,          u8"cent treize");
    ASSERT_SPELLOUT(114, type|MASCULINE,          u8"cent quatorze");
    ASSERT_SPELLOUT(115, type|MASCULINE,          u8"cent quinze");
    ASSERT_SPELLOUT(116, type|MASCULINE,          u8"cent seize");
    ASSERT_SPELLOUT(117, type|MASCULINE,          u8"cent dix-sept");
    ASSERT_SPELLOUT(118, type|MASCULINE,          u8"cent dix-huit");
    ASSERT_SPELLOUT(119, type|MASCULINE,          u8"cent dix-neuf");
    ASSERT_SPELLOUT(120, type|MASCULINE,          u8"cent vingt");
    ASSERT_SPELLOUT(121, type|MASCULINE,          u8"cent vingt et un");
    ASSERT_SPELLOUT(121, type|FEMININE,           u8"cent vingt et une");
    ASSERT_SPELLOUT(122, type|MASCULINE,          u8"cent vingt-deux");
    ASSERT_SPELLOUT(170, type|MASCULINE,          u8"cent soixante-dix");
    ASSERT_SPELLOUT(171, type|MASCULINE,          u8"cent soixante et onze");
    ASSERT_SPELLOUT(171, type|FEMININE,           u8"cent soixante et onze");
    ASSERT_SPELLOUT(170, type|MASCULINE|SEPTANTE, u8"cent septante");
    ASSERT_SPELLOUT(171, type|MASCULINE|SEPTANTE, u8"cent septante et un");
    ASSERT_SPELLOUT(171, type|FEMININE |SEPTANTE, u8"cent septante et une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(180, type|MASCULINE,      u8"cent quatre-vingt");
    else
        ASSERT_SPELLOUT(180, type|MASCULINE,      u8"cent quatre-vingts");
    ASSERT_SPELLOUT(181, type|MASCULINE,          u8"cent quatre-vingt-un");
    ASSERT_SPELLOUT(181, type|FEMININE ,          u8"cent quatre-vingt-une");
    ASSERT_SPELLOUT(180, type|MASCULINE|HUITANTE, u8"cent huitante");
    ASSERT_SPELLOUT(181, type|MASCULINE|HUITANTE, u8"cent huitante et un");
    ASSERT_SPELLOUT(181, type|FEMININE |HUITANTE, u8"cent huitante et une");
    ASSERT_SPELLOUT(180, type|MASCULINE|OCTANTE,  u8"cent octante");
    ASSERT_SPELLOUT(181, type|MASCULINE|OCTANTE,  u8"cent octante et un");
    ASSERT_SPELLOUT(181, type|FEMININE |OCTANTE,  u8"cent octante et une");
    ASSERT_SPELLOUT(190, type|MASCULINE,          u8"cent quatre-vingt-dix");
    ASSERT_SPELLOUT(191, type|MASCULINE,          u8"cent quatre-vingt-onze");
    ASSERT_SPELLOUT(191, type|FEMININE,           u8"cent quatre-vingt-onze");
    ASSERT_SPELLOUT(199, type|MASCULINE,          u8"cent quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(190, type|MASCULINE|NONANTE,  u8"cent nonante");
    ASSERT_SPELLOUT(191, type|MASCULINE|NONANTE,  u8"cent nonante et un");
    ASSERT_SPELLOUT(191, type|FEMININE |NONANTE,  u8"cent nonante et une");
    ASSERT_SPELLOUT(199, type|MASCULINE|NONANTE,  u8"cent nonante-neuf");

    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(200, type|MASCULINE,      u8"deux cent");
    else
        ASSERT_SPELLOUT(200, type|MASCULINE,      u8"deux cents");
    ASSERT_SPELLOUT(201, type|MASCULINE,          u8"deux cent un");
    ASSERT_SPELLOUT(201, type|FEMININE,           u8"deux cent une");
    ASSERT_SPELLOUT(219, type|MASCULINE,          u8"deux cent dix-neuf");
    ASSERT_SPELLOUT(220, type|MASCULINE,          u8"deux cent vingt");
    ASSERT_SPELLOUT(221, type|MASCULINE,          u8"deux cent vingt et un");
    ASSERT_SPELLOUT(221, type|FEMININE,           u8"deux cent vingt et une");
    ASSERT_SPELLOUT(222, type|MASCULINE,          u8"deux cent vingt-deux");
    ASSERT_SPELLOUT(270, type|MASCULINE,          u8"deux cent soixante-dix");
    ASSERT_SPELLOUT(271, type|MASCULINE,          u8"deux cent soixante et onze");
    ASSERT_SPELLOUT(271, type|FEMININE,           u8"deux cent soixante et onze");
    ASSERT_SPELLOUT(270, type|MASCULINE|SEPTANTE, u8"deux cent septante");
    ASSERT_SPELLOUT(271, type|MASCULINE|SEPTANTE, u8"deux cent septante et un");
    ASSERT_SPELLOUT(271, type|FEMININE |SEPTANTE, u8"deux cent septante et une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(280, type|MASCULINE,      u8"deux cent quatre-vingt");
    else
        ASSERT_SPELLOUT(280, type|MASCULINE,      u8"deux cent quatre-vingts");
    ASSERT_SPELLOUT(281, type|MASCULINE,          u8"deux cent quatre-vingt-un");
    ASSERT_SPELLOUT(281, type|FEMININE ,          u8"deux cent quatre-vingt-une");
    ASSERT_SPELLOUT(280, type|MASCULINE|HUITANTE, u8"deux cent huitante");
    ASSERT_SPELLOUT(281, type|MASCULINE|HUITANTE, u8"deux cent huitante et un");
    ASSERT_SPELLOUT(281, type|FEMININE |HUITANTE, u8"deux cent huitante et une");
    ASSERT_SPELLOUT(280, type|MASCULINE|OCTANTE,  u8"deux cent octante");
    ASSERT_SPELLOUT(281, type|MASCULINE|OCTANTE,  u8"deux cent octante et un");
    ASSERT_SPELLOUT(281, type|FEMININE |OCTANTE,  u8"deux cent octante et une");
    ASSERT_SPELLOUT(290, type|MASCULINE,          u8"deux cent quatre-vingt-dix");
    ASSERT_SPELLOUT(291, type|MASCULINE,          u8"deux cent quatre-vingt-onze");
    ASSERT_SPELLOUT(291, type|FEMININE,           u8"deux cent quatre-vingt-onze");
    ASSERT_SPELLOUT(299, type|MASCULINE,          u8"deux cent quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(290, type|MASCULINE|NONANTE,  u8"deux cent nonante");
    ASSERT_SPELLOUT(291, type|MASCULINE|NONANTE,  u8"deux cent nonante et un");
    ASSERT_SPELLOUT(291, type|FEMININE |NONANTE,  u8"deux cent nonante et une");
    ASSERT_SPELLOUT(299, type|MASCULINE|NONANTE,  u8"deux cent nonante-neuf");

    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(900, type|MASCULINE,      u8"neuf cent");
    else
        ASSERT_SPELLOUT(900, type|MASCULINE,      u8"neuf cents");
    ASSERT_SPELLOUT(901, type|MASCULINE,          u8"neuf cent un");
    ASSERT_SPELLOUT(901, type|FEMININE,           u8"neuf cent une");
    ASSERT_SPELLOUT(919, type|MASCULINE,          u8"neuf cent dix-neuf");
    ASSERT_SPELLOUT(920, type|MASCULINE,          u8"neuf cent vingt");
    ASSERT_SPELLOUT(921, type|MASCULINE,          u8"neuf cent vingt et un");
    ASSERT_SPELLOUT(921, type|FEMININE,           u8"neuf cent vingt et une");
    ASSERT_SPELLOUT(922, type|MASCULINE,          u8"neuf cent vingt-deux");
    ASSERT_SPELLOUT(970, type|MASCULINE,          u8"neuf cent soixante-dix");
    ASSERT_SPELLOUT(971, type|MASCULINE,          u8"neuf cent soixante et onze");
    ASSERT_SPELLOUT(971, type|FEMININE,           u8"neuf cent soixante et onze");
    ASSERT_SPELLOUT(970, type|MASCULINE|SEPTANTE, u8"neuf cent septante");
    ASSERT_SPELLOUT(971, type|MASCULINE|SEPTANTE, u8"neuf cent septante et un");
    ASSERT_SPELLOUT(971, type|FEMININE |SEPTANTE, u8"neuf cent septante et une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(980, type|MASCULINE,      u8"neuf cent quatre-vingt");
    else
        ASSERT_SPELLOUT(980, type|MASCULINE,      u8"neuf cent quatre-vingts");
    ASSERT_SPELLOUT(981, type|MASCULINE,          u8"neuf cent quatre-vingt-un");
    ASSERT_SPELLOUT(981, type|FEMININE ,          u8"neuf cent quatre-vingt-une");
    ASSERT_SPELLOUT(980, type|MASCULINE|HUITANTE, u8"neuf cent huitante");
    ASSERT_SPELLOUT(981, type|MASCULINE|HUITANTE, u8"neuf cent huitante et un");
    ASSERT_SPELLOUT(981, type|FEMININE |HUITANTE, u8"neuf cent huitante et une");
    ASSERT_SPELLOUT(980, type|MASCULINE|OCTANTE,  u8"neuf cent octante");
    ASSERT_SPELLOUT(981, type|MASCULINE|OCTANTE,  u8"neuf cent octante et un");
    ASSERT_SPELLOUT(981, type|FEMININE |OCTANTE,  u8"neuf cent octante et une");
    ASSERT_SPELLOUT(990, type|MASCULINE,          u8"neuf cent quatre-vingt-dix");
    ASSERT_SPELLOUT(991, type|MASCULINE,          u8"neuf cent quatre-vingt-onze");
    ASSERT_SPELLOUT(991, type|FEMININE,           u8"neuf cent quatre-vingt-onze");
    ASSERT_SPELLOUT(999, type|MASCULINE,          u8"neuf cent quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(990, type|MASCULINE|NONANTE,  u8"neuf cent nonante");
    ASSERT_SPELLOUT(991, type|MASCULINE|NONANTE,  u8"neuf cent nonante et un");
    ASSERT_SPELLOUT(991, type|FEMININE |NONANTE,  u8"neuf cent nonante et une");
    ASSERT_SPELLOUT(999, type|MASCULINE|NONANTE,  u8"neuf cent nonante-neuf");

    return succeeded;
}


static unsigned test_ordinals_100_999(unsigned type)
{
    assert(type & ORDINAL);

    unsigned succeeded = 0;

    ASSERT_SPELLOUT(100, type,          u8"centième");
    ASSERT_SPELLOUT(101, type,          u8"cent unième");
    ASSERT_SPELLOUT(102, type,          u8"cent deuxième");
    ASSERT_SPELLOUT(110, type,          u8"cent dixième");
    ASSERT_SPELLOUT(111, type,          u8"cent onzième");
    ASSERT_SPELLOUT(112, type,          u8"cent douzième");
    ASSERT_SPELLOUT(113, type,          u8"cent treizième");
    ASSERT_SPELLOUT(114, type,          u8"cent quatorzième");
    ASSERT_SPELLOUT(115, type,          u8"cent quinzième");
    ASSERT_SPELLOUT(116, type,          u8"cent seizième");
    ASSERT_SPELLOUT(117, type,          u8"cent dix-septième");
    ASSERT_SPELLOUT(118, type,          u8"cent dix-huitième");
    ASSERT_SPELLOUT(119, type,          u8"cent dix-neuvième");
    ASSERT_SPELLOUT(120, type,          u8"cent vingtième");
    ASSERT_SPELLOUT(121, type,          u8"cent vingt et unième");
    ASSERT_SPELLOUT(122, type,          u8"cent vingt-deuxième");
    ASSERT_SPELLOUT(170, type,          u8"cent soixante-dixième");
    ASSERT_SPELLOUT(171, type,          u8"cent soixante et onzième");
    ASSERT_SPELLOUT(170, type|SEPTANTE, u8"cent septantième");
    ASSERT_SPELLOUT(171, type|SEPTANTE, u8"cent septante et unième");
    ASSERT_SPELLOUT(180, type,          u8"cent quatre-vingtième");
    ASSERT_SPELLOUT(181, type,          u8"cent quatre-vingt-unième");
    ASSERT_SPELLOUT(180, type|HUITANTE, u8"cent huitantième");
    ASSERT_SPELLOUT(181, type|HUITANTE, u8"cent huitante et unième");
    ASSERT_SPELLOUT(180, type|OCTANTE,  u8"cent octantième");
    ASSERT_SPELLOUT(181, type|OCTANTE,  u8"cent octante et unième");
    ASSERT_SPELLOUT(190, type,          u8"cent quatre-vingt-dixième");
    ASSERT_SPELLOUT(191, type,          u8"cent quatre-vingt-onzième");
    ASSERT_SPELLOUT(199, type,          u8"cent quatre-vingt-dix-neuvième");
    ASSERT_SPELLOUT(190, type|NONANTE,  u8"cent nonantième");
    ASSERT_SPELLOUT(191, type|NONANTE,  u8"cent nonante et unième");
    ASSERT_SPELLOUT(199, type|NONANTE,  u8"cent nonante-neuvième");

    ASSERT_SPELLOUT(200, type,          u8"deux centième");
    ASSERT_SPELLOUT(201, type,          u8"deux cent unième");
    ASSERT_SPELLOUT(219, type,          u8"deux cent dix-neuvième");
    ASSERT_SPELLOUT(220, type,          u8"deux cent vingtième");
    ASSERT_SPELLOUT(221, type,          u8"deux cent vingt et unième");
    ASSERT_SPELLOUT(222, type,          u8"deux cent vingt-deuxième");
    ASSERT_SPELLOUT(270, type,          u8"deux cent soixante-dixième");
    ASSERT_SPELLOUT(271, type,          u8"deux cent soixante et onzième");
    ASSERT_SPELLOUT(270, type|SEPTANTE, u8"deux cent septantième");
    ASSERT_SPELLOUT(271, type|SEPTANTE, u8"deux cent septante et unième");
    ASSERT_SPELLOUT(280, type,          u8"deux cent quatre-vingtième");
    ASSERT_SPELLOUT(281, type,          u8"deux cent quatre-vingt-unième");
    ASSERT_SPELLOUT(280, type|HUITANTE, u8"deux cent huitantième");
    ASSERT_SPELLOUT(281, type|HUITANTE, u8"deux cent huitante et unième");
    ASSERT_SPELLOUT(280, type|OCTANTE,  u8"deux cent octantième");
    ASSERT_SPELLOUT(281, type|OCTANTE,  u8"deux cent octante et unième");
    ASSERT_SPELLOUT(290, type,          u8"deux cent quatre-vingt-dixième");
    ASSERT_SPELLOUT(291, type,          u8"deux cent quatre-vingt-onzième");
    ASSERT_SPELLOUT(299, type,          u8"deux cent quatre-vingt-dix-neuvième");
    ASSERT_SPELLOUT(290, type|NONANTE,  u8"deux cent nonantième");
    ASSERT_SPELLOUT(291, type|NONANTE,  u8"deux cent nonante et unième");
    ASSERT_SPELLOUT(299, type|NONANTE,  u8"deux cent nonante-neuvième");

    ASSERT_SPELLOUT(900, type,          u8"neuf centième");
    ASSERT_SPELLOUT(901, type,          u8"neuf cent unième");
    ASSERT_SPELLOUT(919, type,          u8"neuf cent dix-neuvième");
    ASSERT_SPELLOUT(920, type,          u8"neuf cent vingtième");
    ASSERT_SPELLOUT(921, type,          u8"neuf cent vingt et unième");
    ASSERT_SPELLOUT(922, type,          u8"neuf cent vingt-deuxième");
    ASSERT_SPELLOUT(970, type,          u8"neuf cent soixante-dixième");
    ASSERT_SPELLOUT(971, type,          u8"neuf cent soixante et onzième");
    ASSERT_SPELLOUT(970, type|SEPTANTE, u8"neuf cent septantième");
    ASSERT_SPELLOUT(971, type|SEPTANTE, u8"neuf cent septante et unième");
    ASSERT_SPELLOUT(980, type,          u8"neuf cent quatre-vingtième");
    ASSERT_SPELLOUT(981, type,          u8"neuf cent quatre-vingt-unième");
    ASSERT_SPELLOUT(980, type|HUITANTE, u8"neuf cent huitantième");
    ASSERT_SPELLOUT(981, type|HUITANTE, u8"neuf cent huitante et unième");
    ASSERT_SPELLOUT(980, type|OCTANTE,  u8"neuf cent octantième");
    ASSERT_SPELLOUT(981, type|OCTANTE,  u8"neuf cent octante et unième");
    ASSERT_SPELLOUT(990, type,          u8"neuf cent quatre-vingt-dixième");
    ASSERT_SPELLOUT(991, type,          u8"neuf cent quatre-vingt-onzième");
    ASSERT_SPELLOUT(999, type,          u8"neuf cent quatre-vingt-dix-neuvième");
    ASSERT_SPELLOUT(990, type|NONANTE,  u8"neuf cent nonantième");
    ASSERT_SPELLOUT(991, type|NONANTE,  u8"neuf cent nonante et unième");
    ASSERT_SPELLOUT(999, type|NONANTE,  u8"neuf cent nonante-neuvième");

    return succeeded;
}


static unsigned test_cardinals_1000_999999(unsigned type)
{
    unsigned succeeded = 0;

    ASSERT_SPELLOUT(1000, type|MASCULINE,          u8"mille");
    ASSERT_SPELLOUT(1001, type|MASCULINE,          u8"mille un");
    ASSERT_SPELLOUT(1001, type|FEMININE,           u8"mille une");
    ASSERT_SPELLOUT(1002, type|FEMININE,           u8"mille deux");
    ASSERT_SPELLOUT(1019, type|MASCULINE,          u8"mille dix-neuf");
    ASSERT_SPELLOUT(1020, type|MASCULINE,          u8"mille vingt");
    ASSERT_SPELLOUT(1021, type|MASCULINE,          u8"mille vingt et un");
    ASSERT_SPELLOUT(1021, type|FEMININE,           u8"mille vingt et une");
    ASSERT_SPELLOUT(1022, type|MASCULINE,          u8"mille vingt-deux");
    ASSERT_SPELLOUT(1070, type|MASCULINE,          u8"mille soixante-dix");
    ASSERT_SPELLOUT(1071, type|MASCULINE,          u8"mille soixante et onze");
    ASSERT_SPELLOUT(1071, type|FEMININE,           u8"mille soixante et onze");
    ASSERT_SPELLOUT(1070, type|MASCULINE|SEPTANTE, u8"mille septante");
    ASSERT_SPELLOUT(1071, type|MASCULINE|SEPTANTE, u8"mille septante et un");
    ASSERT_SPELLOUT(1071, type|FEMININE |SEPTANTE, u8"mille septante et une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(1080, type|MASCULINE,      u8"mille quatre-vingt");
    else
        ASSERT_SPELLOUT(1080, type|MASCULINE,      u8"mille quatre-vingts");
    ASSERT_SPELLOUT(1081, type|MASCULINE,          u8"mille quatre-vingt-un");
    ASSERT_SPELLOUT(1081, type|FEMININE ,          u8"mille quatre-vingt-une");
    ASSERT_SPELLOUT(1080, type|MASCULINE|HUITANTE, u8"mille huitante");
    ASSERT_SPELLOUT(1081, type|MASCULINE|HUITANTE, u8"mille huitante et un");
    ASSERT_SPELLOUT(1081, type|FEMININE |HUITANTE, u8"mille huitante et une");
    ASSERT_SPELLOUT(1080, type|MASCULINE|OCTANTE,  u8"mille octante");
    ASSERT_SPELLOUT(1081, type|MASCULINE|OCTANTE,  u8"mille octante et un");
    ASSERT_SPELLOUT(1081, type|FEMININE |OCTANTE,  u8"mille octante et une");
    ASSERT_SPELLOUT(1090, type|MASCULINE,          u8"mille quatre-vingt-dix");
    ASSERT_SPELLOUT(1091, type|MASCULINE,          u8"mille quatre-vingt-onze");
    ASSERT_SPELLOUT(1091, type|FEMININE,           u8"mille quatre-vingt-onze");
    ASSERT_SPELLOUT(1099, type|MASCULINE,          u8"mille quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(1090, type|MASCULINE|NONANTE,  u8"mille nonante");
    ASSERT_SPELLOUT(1091, type|MASCULINE|NONANTE,  u8"mille nonante et un");
    ASSERT_SPELLOUT(1091, type|FEMININE |NONANTE,  u8"mille nonante et une");
    ASSERT_SPELLOUT(1099, type|MASCULINE|NONANTE,  u8"mille nonante-neuf");

    ASSERT_SPELLOUT(1000, type|MASCULINE,          u8"mille");
    ASSERT_SPELLOUT(1001, type|MASCULINE,          u8"mille un");
    ASSERT_SPELLOUT(1001, type|FEMININE,           u8"mille une");
    ASSERT_SPELLOUT(1002, type|FEMININE,           u8"mille deux");
    ASSERT_SPELLOUT(1019, type|MASCULINE,          u8"mille dix-neuf");
    ASSERT_SPELLOUT(1020, type|MASCULINE,          u8"mille vingt");
    ASSERT_SPELLOUT(1021, type|MASCULINE,          u8"mille vingt et un");
    ASSERT_SPELLOUT(1021, type|FEMININE,           u8"mille vingt et une");
    ASSERT_SPELLOUT(1022, type|MASCULINE,          u8"mille vingt-deux");
    ASSERT_SPELLOUT(1070, type|MASCULINE,          u8"mille soixante-dix");
    ASSERT_SPELLOUT(1071, type|MASCULINE,          u8"mille soixante et onze");
    ASSERT_SPELLOUT(1071, type|FEMININE,           u8"mille soixante et onze");
    ASSERT_SPELLOUT(1070, type|MASCULINE|SEPTANTE, u8"mille septante");
    ASSERT_SPELLOUT(1071, type|MASCULINE|SEPTANTE, u8"mille septante et un");
    ASSERT_SPELLOUT(1071, type|FEMININE |SEPTANTE, u8"mille septante et une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(1080, type|MASCULINE,      u8"mille quatre-vingt");
    else
        ASSERT_SPELLOUT(1080, type|MASCULINE,      u8"mille quatre-vingts");
    ASSERT_SPELLOUT(1081, type|MASCULINE,          u8"mille quatre-vingt-un");
    ASSERT_SPELLOUT(1081, type|FEMININE ,          u8"mille quatre-vingt-une");
    ASSERT_SPELLOUT(1080, type|MASCULINE|HUITANTE, u8"mille huitante");
    ASSERT_SPELLOUT(1081, type|MASCULINE|HUITANTE, u8"mille huitante et un");
    ASSERT_SPELLOUT(1081, type|FEMININE |HUITANTE, u8"mille huitante et une");
    ASSERT_SPELLOUT(1080, type|MASCULINE|OCTANTE,  u8"mille octante");
    ASSERT_SPELLOUT(1081, type|MASCULINE|OCTANTE,  u8"mille octante et un");
    ASSERT_SPELLOUT(1081, type|FEMININE |OCTANTE,  u8"mille octante et une");
    ASSERT_SPELLOUT(1090, type|MASCULINE,          u8"mille quatre-vingt-dix");
    ASSERT_SPELLOUT(1091, type|MASCULINE,          u8"mille quatre-vingt-onze");
    ASSERT_SPELLOUT(1091, type|FEMININE,           u8"mille quatre-vingt-onze");
    ASSERT_SPELLOUT(1099, type|MASCULINE,          u8"mille quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(1090, type|MASCULINE|NONANTE,  u8"mille nonante");
    ASSERT_SPELLOUT(1091, type|MASCULINE|NONANTE,  u8"mille nonante et un");
    ASSERT_SPELLOUT(1091, type|FEMININE |NONANTE,  u8"mille nonante et une");
    ASSERT_SPELLOUT(1099, type|MASCULINE|NONANTE,  u8"mille nonante-neuf");

    ASSERT_SPELLOUT(1100, type|MASCULINE,          u8"mille cent");
    ASSERT_SPELLOUT(1101, type|MASCULINE,          u8"mille cent un");
    ASSERT_SPELLOUT(1101, type|FEMININE,           u8"mille cent une");
    ASSERT_SPELLOUT(1102, type|FEMININE,           u8"mille cent deux");
    ASSERT_SPELLOUT(1119, type|MASCULINE,          u8"mille cent dix-neuf");
    ASSERT_SPELLOUT(1120, type|MASCULINE,          u8"mille cent vingt");
    ASSERT_SPELLOUT(1121, type|MASCULINE,          u8"mille cent vingt et un");
    ASSERT_SPELLOUT(1121, type|FEMININE,           u8"mille cent vingt et une");
    ASSERT_SPELLOUT(1122, type|MASCULINE,          u8"mille cent vingt-deux");
    ASSERT_SPELLOUT(1170, type|MASCULINE,          u8"mille cent soixante-dix");
    ASSERT_SPELLOUT(1171, type|MASCULINE,          u8"mille cent soixante et onze");
    ASSERT_SPELLOUT(1171, type|FEMININE,           u8"mille cent soixante et onze");
    ASSERT_SPELLOUT(1170, type|MASCULINE|SEPTANTE, u8"mille cent septante");
    ASSERT_SPELLOUT(1171, type|MASCULINE|SEPTANTE, u8"mille cent septante et un");
    ASSERT_SPELLOUT(1171, type|FEMININE |SEPTANTE, u8"mille cent septante et une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(1180, type|MASCULINE,      u8"mille cent quatre-vingt");
    else
        ASSERT_SPELLOUT(1180, type|MASCULINE,      u8"mille cent quatre-vingts");
    ASSERT_SPELLOUT(1181, type|MASCULINE,          u8"mille cent quatre-vingt-un");
    ASSERT_SPELLOUT(1181, type|FEMININE ,          u8"mille cent quatre-vingt-une");
    ASSERT_SPELLOUT(1180, type|MASCULINE|HUITANTE, u8"mille cent huitante");
    ASSERT_SPELLOUT(1181, type|MASCULINE|HUITANTE, u8"mille cent huitante et un");
    ASSERT_SPELLOUT(1181, type|FEMININE |HUITANTE, u8"mille cent huitante et une");
    ASSERT_SPELLOUT(1180, type|MASCULINE|OCTANTE,  u8"mille cent octante");
    ASSERT_SPELLOUT(1181, type|MASCULINE|OCTANTE,  u8"mille cent octante et un");
    ASSERT_SPELLOUT(1181, type|FEMININE |OCTANTE,  u8"mille cent octante et une");
    ASSERT_SPELLOUT(1190, type|MASCULINE,          u8"mille cent quatre-vingt-dix");
    ASSERT_SPELLOUT(1191, type|MASCULINE,          u8"mille cent quatre-vingt-onze");
    ASSERT_SPELLOUT(1191, type|FEMININE,           u8"mille cent quatre-vingt-onze");
    ASSERT_SPELLOUT(1199, type|MASCULINE,          u8"mille cent quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(1190, type|MASCULINE|NONANTE,  u8"mille cent nonante");
    ASSERT_SPELLOUT(1191, type|MASCULINE|NONANTE,  u8"mille cent nonante et un");
    ASSERT_SPELLOUT(1191, type|FEMININE |NONANTE,  u8"mille cent nonante et une");
    ASSERT_SPELLOUT(1199, type|MASCULINE|NONANTE,  u8"mille cent nonante-neuf");

    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(1100, type|CENT_1100_1999|MASCULINE,      u8"onze cent");
    else
        ASSERT_SPELLOUT(1100, type|CENT_1100_1999|MASCULINE,      u8"onze cents");
    ASSERT_SPELLOUT(1101, type|CENT_1100_1999|MASCULINE,          u8"onze cent un");
    ASSERT_SPELLOUT(1101, type|CENT_1100_1999|FEMININE,           u8"onze cent une");
    ASSERT_SPELLOUT(1102, type|CENT_1100_1999|FEMININE,           u8"onze cent deux");
    ASSERT_SPELLOUT(1119, type|CENT_1100_1999|MASCULINE,          u8"onze cent dix-neuf");
    ASSERT_SPELLOUT(1120, type|CENT_1100_1999|MASCULINE,          u8"onze cent vingt");
    ASSERT_SPELLOUT(1121, type|CENT_1100_1999|MASCULINE,          u8"onze cent vingt et un");
    ASSERT_SPELLOUT(1121, type|CENT_1100_1999|FEMININE,           u8"onze cent vingt et une");
    ASSERT_SPELLOUT(1122, type|CENT_1100_1999|MASCULINE,          u8"onze cent vingt-deux");
    ASSERT_SPELLOUT(1170, type|CENT_1100_1999|MASCULINE,          u8"onze cent soixante-dix");
    ASSERT_SPELLOUT(1171, type|CENT_1100_1999|MASCULINE,          u8"onze cent soixante et onze");
    ASSERT_SPELLOUT(1171, type|CENT_1100_1999|FEMININE,           u8"onze cent soixante et onze");
    ASSERT_SPELLOUT(1170, type|CENT_1100_1999|MASCULINE|SEPTANTE, u8"onze cent septante");
    ASSERT_SPELLOUT(1171, type|CENT_1100_1999|MASCULINE|SEPTANTE, u8"onze cent septante et un");
    ASSERT_SPELLOUT(1171, type|CENT_1100_1999|FEMININE |SEPTANTE, u8"onze cent septante et une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(1180, type|CENT_1100_1999|MASCULINE,      u8"onze cent quatre-vingt");
    else
        ASSERT_SPELLOUT(1180, type|CENT_1100_1999|MASCULINE,      u8"onze cent quatre-vingts");
    ASSERT_SPELLOUT(1181, type|CENT_1100_1999|MASCULINE,          u8"onze cent quatre-vingt-un");
    ASSERT_SPELLOUT(1181, type|CENT_1100_1999|FEMININE ,          u8"onze cent quatre-vingt-une");
    ASSERT_SPELLOUT(1180, type|CENT_1100_1999|MASCULINE|HUITANTE, u8"onze cent huitante");
    ASSERT_SPELLOUT(1181, type|CENT_1100_1999|MASCULINE|HUITANTE, u8"onze cent huitante et un");
    ASSERT_SPELLOUT(1181, type|CENT_1100_1999|FEMININE |HUITANTE, u8"onze cent huitante et une");
    ASSERT_SPELLOUT(1180, type|CENT_1100_1999|MASCULINE|OCTANTE,  u8"onze cent octante");
    ASSERT_SPELLOUT(1181, type|CENT_1100_1999|MASCULINE|OCTANTE,  u8"onze cent octante et un");
    ASSERT_SPELLOUT(1181, type|CENT_1100_1999|FEMININE |OCTANTE,  u8"onze cent octante et une");
    ASSERT_SPELLOUT(1190, type|CENT_1100_1999|MASCULINE,          u8"onze cent quatre-vingt-dix");
    ASSERT_SPELLOUT(1191, type|CENT_1100_1999|MASCULINE,          u8"onze cent quatre-vingt-onze");
    ASSERT_SPELLOUT(1191, type|CENT_1100_1999|FEMININE,           u8"onze cent quatre-vingt-onze");
    ASSERT_SPELLOUT(1199, type|CENT_1100_1999|MASCULINE,          u8"onze cent quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(1190, type|CENT_1100_1999|MASCULINE|NONANTE,  u8"onze cent nonante");
    ASSERT_SPELLOUT(1191, type|CENT_1100_1999|MASCULINE|NONANTE,  u8"onze cent nonante et un");
    ASSERT_SPELLOUT(1191, type|CENT_1100_1999|FEMININE |NONANTE,  u8"onze cent nonante et une");
    ASSERT_SPELLOUT(1199, type|CENT_1100_1999|MASCULINE|NONANTE,  u8"onze cent nonante-neuf");

    if (type & CARDINAL_AS_ORDINAL)
    {
        ASSERT_SPELLOUT(1100, type|CENT_1100_1999|MASCULINE, u8"onze cent");
        ASSERT_SPELLOUT(1200, type|CENT_1100_1999|MASCULINE, u8"douze cent");
        ASSERT_SPELLOUT(1300, type|CENT_1100_1999|MASCULINE, u8"treize cent");
        ASSERT_SPELLOUT(1400, type|CENT_1100_1999|MASCULINE, u8"quatorze cent");
        ASSERT_SPELLOUT(1500, type|CENT_1100_1999|MASCULINE, u8"quinze cent");
        ASSERT_SPELLOUT(1600, type|CENT_1100_1999|MASCULINE, u8"seize cent");
        ASSERT_SPELLOUT(1700, type|CENT_1100_1999|MASCULINE, u8"dix-sept cent");
        ASSERT_SPELLOUT(1800, type|CENT_1100_1999|MASCULINE, u8"dix-huit cent");
    }
    else
    {
        ASSERT_SPELLOUT(1100, type|CENT_1100_1999|MASCULINE, u8"onze cents");
        ASSERT_SPELLOUT(1200, type|CENT_1100_1999|MASCULINE, u8"douze cents");
        ASSERT_SPELLOUT(1300, type|CENT_1100_1999|MASCULINE, u8"treize cents");
        ASSERT_SPELLOUT(1400, type|CENT_1100_1999|MASCULINE, u8"quatorze cents");
        ASSERT_SPELLOUT(1500, type|CENT_1100_1999|MASCULINE, u8"quinze cents");
        ASSERT_SPELLOUT(1600, type|CENT_1100_1999|MASCULINE, u8"seize cents");
        ASSERT_SPELLOUT(1700, type|CENT_1100_1999|MASCULINE, u8"dix-sept cents");
        ASSERT_SPELLOUT(1800, type|CENT_1100_1999|MASCULINE, u8"dix-huit cents");
    }

    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(1900, type|MASCULINE,      u8"mille neuf cent");
    else
        ASSERT_SPELLOUT(1900, type|MASCULINE,      u8"mille neuf cents");
    ASSERT_SPELLOUT(1901, type|MASCULINE,          u8"mille neuf cent un");
    ASSERT_SPELLOUT(1901, type|FEMININE,           u8"mille neuf cent une");
    ASSERT_SPELLOUT(1902, type|FEMININE,           u8"mille neuf cent deux");
    ASSERT_SPELLOUT(1919, type|MASCULINE,          u8"mille neuf cent dix-neuf");
    ASSERT_SPELLOUT(1920, type|MASCULINE,          u8"mille neuf cent vingt");
    ASSERT_SPELLOUT(1921, type|MASCULINE,          u8"mille neuf cent vingt et un");
    ASSERT_SPELLOUT(1921, type|FEMININE,           u8"mille neuf cent vingt et une");
    ASSERT_SPELLOUT(1922, type|MASCULINE,          u8"mille neuf cent vingt-deux");
    ASSERT_SPELLOUT(1970, type|MASCULINE,          u8"mille neuf cent soixante-dix");
    ASSERT_SPELLOUT(1971, type|MASCULINE,          u8"mille neuf cent soixante et onze");
    ASSERT_SPELLOUT(1971, type|FEMININE,           u8"mille neuf cent soixante et onze");
    ASSERT_SPELLOUT(1970, type|MASCULINE|SEPTANTE, u8"mille neuf cent septante");
    ASSERT_SPELLOUT(1971, type|MASCULINE|SEPTANTE, u8"mille neuf cent septante et un");
    ASSERT_SPELLOUT(1971, type|FEMININE |SEPTANTE, u8"mille neuf cent septante et une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(1980, type|MASCULINE,      u8"mille neuf cent quatre-vingt");
    else
        ASSERT_SPELLOUT(1980, type|MASCULINE,      u8"mille neuf cent quatre-vingts");
    ASSERT_SPELLOUT(1981, type|MASCULINE,          u8"mille neuf cent quatre-vingt-un");
    ASSERT_SPELLOUT(1981, type|FEMININE ,          u8"mille neuf cent quatre-vingt-une");
    ASSERT_SPELLOUT(1980, type|MASCULINE|HUITANTE, u8"mille neuf cent huitante");
    ASSERT_SPELLOUT(1981, type|MASCULINE|HUITANTE, u8"mille neuf cent huitante et un");
    ASSERT_SPELLOUT(1981, type|FEMININE |HUITANTE, u8"mille neuf cent huitante et une");
    ASSERT_SPELLOUT(1980, type|MASCULINE|OCTANTE,  u8"mille neuf cent octante");
    ASSERT_SPELLOUT(1981, type|MASCULINE|OCTANTE,  u8"mille neuf cent octante et un");
    ASSERT_SPELLOUT(1981, type|FEMININE |OCTANTE,  u8"mille neuf cent octante et une");
    ASSERT_SPELLOUT(1990, type|MASCULINE,          u8"mille neuf cent quatre-vingt-dix");
    ASSERT_SPELLOUT(1991, type|MASCULINE,          u8"mille neuf cent quatre-vingt-onze");
    ASSERT_SPELLOUT(1991, type|FEMININE,           u8"mille neuf cent quatre-vingt-onze");
    ASSERT_SPELLOUT(1999, type|MASCULINE,          u8"mille neuf cent quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(1990, type|MASCULINE|NONANTE,  u8"mille neuf cent nonante");
    ASSERT_SPELLOUT(1991, type|MASCULINE|NONANTE,  u8"mille neuf cent nonante et un");
    ASSERT_SPELLOUT(1991, type|FEMININE |NONANTE,  u8"mille neuf cent nonante et une");
    ASSERT_SPELLOUT(1999, type|MASCULINE|NONANTE,  u8"mille neuf cent nonante-neuf");

    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(1900, type|CENT_1100_1999|MASCULINE,      u8"dix-neuf cent");
    else
        ASSERT_SPELLOUT(1900, type|CENT_1100_1999|MASCULINE,      u8"dix-neuf cents");
    ASSERT_SPELLOUT(1901, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent un");
    ASSERT_SPELLOUT(1901, type|CENT_1100_1999|FEMININE,           u8"dix-neuf cent une");
    ASSERT_SPELLOUT(1902, type|CENT_1100_1999|FEMININE,           u8"dix-neuf cent deux");
    ASSERT_SPELLOUT(1919, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent dix-neuf");
    ASSERT_SPELLOUT(1920, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent vingt");
    ASSERT_SPELLOUT(1921, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent vingt et un");
    ASSERT_SPELLOUT(1921, type|CENT_1100_1999|FEMININE,           u8"dix-neuf cent vingt et une");
    ASSERT_SPELLOUT(1922, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent vingt-deux");
    ASSERT_SPELLOUT(1970, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent soixante-dix");
    ASSERT_SPELLOUT(1971, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent soixante et onze");
    ASSERT_SPELLOUT(1971, type|CENT_1100_1999|FEMININE,           u8"dix-neuf cent soixante et onze");
    ASSERT_SPELLOUT(1970, type|CENT_1100_1999|MASCULINE|SEPTANTE, u8"dix-neuf cent septante");
    ASSERT_SPELLOUT(1971, type|CENT_1100_1999|MASCULINE|SEPTANTE, u8"dix-neuf cent septante et un");
    ASSERT_SPELLOUT(1971, type|CENT_1100_1999|FEMININE |SEPTANTE, u8"dix-neuf cent septante et une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT(1980, type|CENT_1100_1999|MASCULINE,      u8"dix-neuf cent quatre-vingt");
    else
        ASSERT_SPELLOUT(1980, type|CENT_1100_1999|MASCULINE,      u8"dix-neuf cent quatre-vingts");
    ASSERT_SPELLOUT(1981, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent quatre-vingt-un");
    ASSERT_SPELLOUT(1981, type|CENT_1100_1999|FEMININE ,          u8"dix-neuf cent quatre-vingt-une");
    ASSERT_SPELLOUT(1980, type|CENT_1100_1999|MASCULINE|HUITANTE, u8"dix-neuf cent huitante");
    ASSERT_SPELLOUT(1981, type|CENT_1100_1999|MASCULINE|HUITANTE, u8"dix-neuf cent huitante et un");
    ASSERT_SPELLOUT(1981, type|CENT_1100_1999|FEMININE |HUITANTE, u8"dix-neuf cent huitante et une");
    ASSERT_SPELLOUT(1980, type|CENT_1100_1999|MASCULINE|OCTANTE,  u8"dix-neuf cent octante");
    ASSERT_SPELLOUT(1981, type|CENT_1100_1999|MASCULINE|OCTANTE,  u8"dix-neuf cent octante et un");
    ASSERT_SPELLOUT(1981, type|CENT_1100_1999|FEMININE |OCTANTE,  u8"dix-neuf cent octante et une");
    ASSERT_SPELLOUT(1990, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent quatre-vingt-dix");
    ASSERT_SPELLOUT(1991, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent quatre-vingt-onze");
    ASSERT_SPELLOUT(1991, type|CENT_1100_1999|FEMININE,           u8"dix-neuf cent quatre-vingt-onze");
    ASSERT_SPELLOUT(1999, type|CENT_1100_1999|MASCULINE,          u8"dix-neuf cent quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(1990, type|CENT_1100_1999|MASCULINE|NONANTE,  u8"dix-neuf cent nonante");
    ASSERT_SPELLOUT(1991, type|CENT_1100_1999|MASCULINE|NONANTE,  u8"dix-neuf cent nonante et un");
    ASSERT_SPELLOUT(1991, type|CENT_1100_1999|FEMININE |NONANTE,  u8"dix-neuf cent nonante et une");
    ASSERT_SPELLOUT(1999, type|CENT_1100_1999|MASCULINE|NONANTE,  u8"dix-neuf cent nonante-neuf");

    ASSERT_SPELLOUT( 2000, type|MASCULINE,              u8"deux mille");
    ASSERT_SPELLOUT( 2001, type|MASCULINE,              u8"deux mille un");
    ASSERT_SPELLOUT( 2001, type|FEMININE,               u8"deux mille une");
    ASSERT_SPELLOUT( 3000, type|MASCULINE,              u8"trois mille");
    ASSERT_SPELLOUT( 4000, type|MASCULINE,              u8"quatre mille");
    ASSERT_SPELLOUT( 5000, type|MASCULINE,              u8"cinq mille");
    ASSERT_SPELLOUT( 6000, type|MASCULINE,              u8"six mille");
    ASSERT_SPELLOUT( 7000, type|MASCULINE,              u8"sept mille");
    ASSERT_SPELLOUT( 8000, type|MASCULINE,              u8"huit mille");
    ASSERT_SPELLOUT( 9000, type|MASCULINE,              u8"neuf mille");
    ASSERT_SPELLOUT(10000, type|MASCULINE,              u8"dix mille");
    ASSERT_SPELLOUT(11000, type|MASCULINE,              u8"onze mille");
    ASSERT_SPELLOUT(12000, type|MASCULINE,              u8"douze mille");
    ASSERT_SPELLOUT(13000, type|MASCULINE,              u8"treize mille");
    ASSERT_SPELLOUT(14000, type|MASCULINE,              u8"quatorze mille");
    ASSERT_SPELLOUT(15000, type|MASCULINE,              u8"quinze mille");
    ASSERT_SPELLOUT(16000, type|MASCULINE,              u8"seize mille");
    ASSERT_SPELLOUT(17000, type|MASCULINE,              u8"dix-sept mille");
    ASSERT_SPELLOUT(18000, type|MASCULINE,              u8"dix-huit mille");
    ASSERT_SPELLOUT(19000, type|MASCULINE,              u8"dix-neuf mille");
    ASSERT_SPELLOUT(20000, type|MASCULINE,              u8"vingt mille");
    ASSERT_SPELLOUT(30000, type|MASCULINE,              u8"trente mille");
    ASSERT_SPELLOUT(40000, type|MASCULINE,              u8"quarante mille");
    ASSERT_SPELLOUT(50000, type|MASCULINE,              u8"cinquante mille");
    ASSERT_SPELLOUT(60000, type|MASCULINE,              u8"soixante mille");
    ASSERT_SPELLOUT(70000, type|MASCULINE,              u8"soixante-dix mille");
    ASSERT_SPELLOUT(70000, type|MASCULINE|SEPTANTE,     u8"septante mille");
    ASSERT_SPELLOUT(80000, type|MASCULINE,              u8"quatre-vingt mille");
    ASSERT_SPELLOUT(80000, type|MASCULINE|HUITANTE,     u8"huitante mille");
    ASSERT_SPELLOUT(80000, type|MASCULINE|OCTANTE,      u8"octante mille");
    if (type & CARDINAL_AS_ORDINAL)
    {
        ASSERT_SPELLOUT(80200, type|MASCULINE,          u8"quatre-vingt mille deux cent");
        ASSERT_SPELLOUT(80200, type|MASCULINE|HUITANTE, u8"huitante mille deux cent");
        ASSERT_SPELLOUT(80200, type|MASCULINE|OCTANTE,  u8"octante mille deux cent");
    }
    else
    {
        ASSERT_SPELLOUT(80200, type|MASCULINE,          u8"quatre-vingt mille deux cents");
        ASSERT_SPELLOUT(80200, type|MASCULINE|HUITANTE, u8"huitante mille deux cents");
        ASSERT_SPELLOUT(80200, type|MASCULINE|OCTANTE,  u8"octante mille deux cents");
    }
    ASSERT_SPELLOUT(90000, type|MASCULINE,              u8"quatre-vingt-dix mille");
    ASSERT_SPELLOUT(90000, type|MASCULINE|NONANTE,      u8"nonante mille");
    ASSERT_SPELLOUT(99999, type|MASCULINE,              u8"quatre-vingt-dix-neuf mille neuf cent quatre-vingt-dix-neuf");
    ASSERT_SPELLOUT(99999, type|MASCULINE|NONANTE,      u8"nonante-neuf mille neuf cent nonante-neuf");

    ASSERT_SPELLOUT(100000, type|MASCULINE,             u8"cent mille");
    ASSERT_SPELLOUT(200000, type|MASCULINE,             u8"deux cent mille");
    ASSERT_SPELLOUT(300000, type|MASCULINE,             u8"trois cent mille");
    ASSERT_SPELLOUT(400000, type|MASCULINE,             u8"quatre cent mille");
    ASSERT_SPELLOUT(500000, type|MASCULINE,             u8"cinq cent mille");
    ASSERT_SPELLOUT(600000, type|MASCULINE,             u8"six cent mille");
    ASSERT_SPELLOUT(700000, type|MASCULINE,             u8"sept cent mille");
    ASSERT_SPELLOUT(800000, type|MASCULINE,             u8"huit cent mille");
    ASSERT_SPELLOUT(888777, type|MASCULINE,             u8"huit cent quatre-vingt-huit mille sept cent soixante-dix-sept");
    ASSERT_SPELLOUT(888777, type|MASCULINE|SWITZERLAND, u8"huit cent huitante-huit mille sept cent septante-sept");
    ASSERT_SPELLOUT(900000, type|MASCULINE,             u8"neuf cent mille");
    ASSERT_SPELLOUT(999999, type|MASCULINE|BELGIUM,     u8"neuf cent nonante-neuf mille neuf cent nonante-neuf");

    return succeeded;
}


static unsigned test_ordinals_1000_999999(unsigned type)
{
    assert(type & ORDINAL);

    unsigned succeeded = 0;

    ASSERT_SPELLOUT(1000, type,               u8"millième");
    ASSERT_SPELLOUT(1001, type,               u8"mille unième");
    ASSERT_SPELLOUT(1002, type,               u8"mille deuxième");
    ASSERT_SPELLOUT(1019, type,               u8"mille dix-neuvième");
    ASSERT_SPELLOUT(1020, type,               u8"mille vingtième");
    ASSERT_SPELLOUT(1021, type,               u8"mille vingt et unième");
    ASSERT_SPELLOUT(1022, type,               u8"mille vingt-deuxième");
    ASSERT_SPELLOUT(1070, type,               u8"mille soixante-dixième");
    ASSERT_SPELLOUT(1071, type,               u8"mille soixante et onzième");
    ASSERT_SPELLOUT(1070, type|SEPTANTE,      u8"mille septantième");
    ASSERT_SPELLOUT(1071, type|SEPTANTE,      u8"mille septante et unième");
    ASSERT_SPELLOUT(1080, type,               u8"mille quatre-vingtième");
    ASSERT_SPELLOUT(1081, type,               u8"mille quatre-vingt-unième");
    ASSERT_SPELLOUT(1080, type|HUITANTE,      u8"mille huitantième");
    ASSERT_SPELLOUT(1081, type|HUITANTE,      u8"mille huitante et unième");
    ASSERT_SPELLOUT(1080, type|OCTANTE,       u8"mille octantième");
    ASSERT_SPELLOUT(1081, type|OCTANTE,       u8"mille octante et unième");
    ASSERT_SPELLOUT(1090, type,               u8"mille quatre-vingt-dixième");
    ASSERT_SPELLOUT(1091, type,               u8"mille quatre-vingt-onzième");
    ASSERT_SPELLOUT(1099, type,               u8"mille quatre-vingt-dix-neuvième");
    ASSERT_SPELLOUT(1090, type|NONANTE,       u8"mille nonantième");
    ASSERT_SPELLOUT(1091, type|NONANTE,       u8"mille nonante et unième");
    ASSERT_SPELLOUT(1099, type|NONANTE,       u8"mille nonante-neuvième");

    ASSERT_SPELLOUT(1000, type,               u8"millième");
    ASSERT_SPELLOUT(1001, type,               u8"mille unième");
    ASSERT_SPELLOUT(1002, type,               u8"mille deuxième");
    ASSERT_SPELLOUT(1019, type,               u8"mille dix-neuvième");
    ASSERT_SPELLOUT(1020, type,               u8"mille vingtième");
    ASSERT_SPELLOUT(1021, type,               u8"mille vingt et unième");
    ASSERT_SPELLOUT(1022, type,               u8"mille vingt-deuxième");
    ASSERT_SPELLOUT(1070, type,               u8"mille soixante-dixième");
    ASSERT_SPELLOUT(1071, type,               u8"mille soixante et onzième");
    ASSERT_SPELLOUT(1070, type|SEPTANTE,      u8"mille septantième");
    ASSERT_SPELLOUT(1071, type|SEPTANTE,      u8"mille septante et unième");
    ASSERT_SPELLOUT(1080, type,               u8"mille quatre-vingtième");
    ASSERT_SPELLOUT(1081, type,               u8"mille quatre-vingt-unième");
    ASSERT_SPELLOUT(1080, type|HUITANTE,      u8"mille huitantième");
    ASSERT_SPELLOUT(1081, type|HUITANTE,      u8"mille huitante et unième");
    ASSERT_SPELLOUT(1080, type|OCTANTE,       u8"mille octantième");
    ASSERT_SPELLOUT(1081, type|OCTANTE,       u8"mille octante et unième");
    ASSERT_SPELLOUT(1090, type,               u8"mille quatre-vingt-dixième");
    ASSERT_SPELLOUT(1091, type,               u8"mille quatre-vingt-onzième");
    ASSERT_SPELLOUT(1099, type,               u8"mille quatre-vingt-dix-neuvième");
    ASSERT_SPELLOUT(1090, type|NONANTE,       u8"mille nonantième");
    ASSERT_SPELLOUT(1091, type|NONANTE,       u8"mille nonante et unième");
    ASSERT_SPELLOUT(1099, type|NONANTE,       u8"mille nonante-neuvième");

    ASSERT_SPELLOUT(1100, type,               u8"mille centième");
    ASSERT_SPELLOUT(1101, type,               u8"mille cent unième");
    ASSERT_SPELLOUT(1102, type,               u8"mille cent deuxième");
    ASSERT_SPELLOUT(1119, type,               u8"mille cent dix-neuvième");
    ASSERT_SPELLOUT(1120, type,               u8"mille cent vingtième");
    ASSERT_SPELLOUT(1121, type,               u8"mille cent vingt et unième");
    ASSERT_SPELLOUT(1122, type,               u8"mille cent vingt-deuxième");
    ASSERT_SPELLOUT(1170, type,               u8"mille cent soixante-dixième");
    ASSERT_SPELLOUT(1171, type,               u8"mille cent soixante et onzième");
    ASSERT_SPELLOUT(1170, type|SEPTANTE,      u8"mille cent septantième");
    ASSERT_SPELLOUT(1171, type|SEPTANTE,      u8"mille cent septante et unième");
    ASSERT_SPELLOUT(1180, type,               u8"mille cent quatre-vingtième");
    ASSERT_SPELLOUT(1181, type,               u8"mille cent quatre-vingt-unième");
    ASSERT_SPELLOUT(1180, type|HUITANTE,      u8"mille cent huitantième");
    ASSERT_SPELLOUT(1181, type|HUITANTE,      u8"mille cent huitante et unième");
    ASSERT_SPELLOUT(1180, type|OCTANTE,       u8"mille cent octantième");
    ASSERT_SPELLOUT(1181, type|OCTANTE,       u8"mille cent octante et unième");
    ASSERT_SPELLOUT(1190, type,               u8"mille cent quatre-vingt-dixième");
    ASSERT_SPELLOUT(1191, type,               u8"mille cent quatre-vingt-onzième");
    ASSERT_SPELLOUT(1199, type,               u8"mille cent quatre-vingt-dix-neuvième");
    ASSERT_SPELLOUT(1190, type|NONANTE,       u8"mille cent nonantième");
    ASSERT_SPELLOUT(1191, type|NONANTE,       u8"mille cent nonante et unième");
    ASSERT_SPELLOUT(1199, type|NONANTE,       u8"mille cent nonante-neuvième");

    ASSERT_SPELLOUT(1900, type,               u8"mille neuf centième");
    ASSERT_SPELLOUT(1901, type,               u8"mille neuf cent unième");
    ASSERT_SPELLOUT(1902, type,               u8"mille neuf cent deuxième");
    ASSERT_SPELLOUT(1919, type,               u8"mille neuf cent dix-neuvième");
    ASSERT_SPELLOUT(1920, type,               u8"mille neuf cent vingtième");
    ASSERT_SPELLOUT(1921, type,               u8"mille neuf cent vingt et unième");
    ASSERT_SPELLOUT(1922, type,               u8"mille neuf cent vingt-deuxième");
    ASSERT_SPELLOUT(1970, type,               u8"mille neuf cent soixante-dixième");
    ASSERT_SPELLOUT(1971, type,               u8"mille neuf cent soixante et onzième");
    ASSERT_SPELLOUT(1970, type|SEPTANTE,      u8"mille neuf cent septantième");
    ASSERT_SPELLOUT(1971, type|SEPTANTE,      u8"mille neuf cent septante et unième");
    ASSERT_SPELLOUT(1980, type,               u8"mille neuf cent quatre-vingtième");
    ASSERT_SPELLOUT(1981, type,               u8"mille neuf cent quatre-vingt-unième");
    ASSERT_SPELLOUT(1980, type|HUITANTE,      u8"mille neuf cent huitantième");
    ASSERT_SPELLOUT(1981, type|HUITANTE,      u8"mille neuf cent huitante et unième");
    ASSERT_SPELLOUT(1980, type|OCTANTE,       u8"mille neuf cent octantième");
    ASSERT_SPELLOUT(1981, type|OCTANTE,       u8"mille neuf cent octante et unième");
    ASSERT_SPELLOUT(1990, type,               u8"mille neuf cent quatre-vingt-dixième");
    ASSERT_SPELLOUT(1991, type,               u8"mille neuf cent quatre-vingt-onzième");
    ASSERT_SPELLOUT(1999, type,               u8"mille neuf cent quatre-vingt-dix-neuvième");
    ASSERT_SPELLOUT(1990, type|NONANTE,       u8"mille neuf cent nonantième");
    ASSERT_SPELLOUT(1991, type|NONANTE,       u8"mille neuf cent nonante et unième");
    ASSERT_SPELLOUT(1999, type|NONANTE,       u8"mille neuf cent nonante-neuvième");

    ASSERT_SPELLOUT( 2000, type,              u8"deux millième");
    ASSERT_SPELLOUT( 2001, type,              u8"deux mille unième");
    ASSERT_SPELLOUT( 3000, type,              u8"trois millième");
    ASSERT_SPELLOUT( 4000, type,              u8"quatre millième");
    ASSERT_SPELLOUT( 5000, type,              u8"cinq millième");
    ASSERT_SPELLOUT( 6000, type,              u8"six millième");
    ASSERT_SPELLOUT( 7000, type,              u8"sept millième");
    ASSERT_SPELLOUT( 8000, type,              u8"huit millième");
    ASSERT_SPELLOUT( 9000, type,              u8"neuf millième");
    ASSERT_SPELLOUT(10000, type,              u8"dix millième");
    ASSERT_SPELLOUT(11000, type,              u8"onze millième");
    ASSERT_SPELLOUT(12000, type,              u8"douze millième");
    ASSERT_SPELLOUT(13000, type,              u8"treize millième");
    ASSERT_SPELLOUT(14000, type,              u8"quatorze millième");
    ASSERT_SPELLOUT(15000, type,              u8"quinze millième");
    ASSERT_SPELLOUT(16000, type,              u8"seize millième");
    ASSERT_SPELLOUT(17000, type,              u8"dix-sept millième");
    ASSERT_SPELLOUT(18000, type,              u8"dix-huit millième");
    ASSERT_SPELLOUT(19000, type,              u8"dix-neuf millième");
    ASSERT_SPELLOUT(20000, type,              u8"vingt millième");
    ASSERT_SPELLOUT(30000, type,              u8"trente millième");
    ASSERT_SPELLOUT(40000, type,              u8"quarante millième");
    ASSERT_SPELLOUT(50000, type,              u8"cinquante millième");
    ASSERT_SPELLOUT(60000, type,              u8"soixante millième");
    ASSERT_SPELLOUT(70000, type,              u8"soixante-dix millième");
    ASSERT_SPELLOUT(70000, type|SEPTANTE,     u8"septante millième");
    ASSERT_SPELLOUT(80000, type,              u8"quatre-vingt millième");
    ASSERT_SPELLOUT(80000, type|HUITANTE,     u8"huitante millième");
    ASSERT_SPELLOUT(80000, type|OCTANTE,      u8"octante millième");
    ASSERT_SPELLOUT(80200, type,              u8"quatre-vingt mille deux centième");
    ASSERT_SPELLOUT(80200, type|HUITANTE,     u8"huitante mille deux centième");
    ASSERT_SPELLOUT(80200, type|OCTANTE,      u8"octante mille deux centième");
    ASSERT_SPELLOUT(90000, type,              u8"quatre-vingt-dix millième");
    ASSERT_SPELLOUT(90000, type|NONANTE,      u8"nonante millième");
    ASSERT_SPELLOUT(99999, type,              u8"quatre-vingt-dix-neuf mille neuf cent quatre-vingt-dix-neuvième");
    ASSERT_SPELLOUT(99999, type|NONANTE,      u8"nonante-neuf mille neuf cent nonante-neuvième");

    ASSERT_SPELLOUT(100000, type,             u8"cent millième");
    ASSERT_SPELLOUT(200000, type,             u8"deux cent millième");
    ASSERT_SPELLOUT(300000, type,             u8"trois cent millième");
    ASSERT_SPELLOUT(400000, type,             u8"quatre cent millième");
    ASSERT_SPELLOUT(500000, type,             u8"cinq cent millième");
    ASSERT_SPELLOUT(600000, type,             u8"six cent millième");
    ASSERT_SPELLOUT(700000, type,             u8"sept cent millième");
    ASSERT_SPELLOUT(800000, type,             u8"huit cent millième");
    ASSERT_SPELLOUT(888777, type,             u8"huit cent quatre-vingt-huit mille sept cent soixante-dix-septième");
    ASSERT_SPELLOUT(888777, type|SWITZERLAND, u8"huit cent huitante-huit mille sept cent septante-septième");
    ASSERT_SPELLOUT(900000, type,             u8"neuf cent millième");
    ASSERT_SPELLOUT(999999, type|BELGIUM,     u8"neuf cent nonante-neuf mille neuf cent nonante-neuvième");

    return succeeded;
}


static unsigned test_large_cardinals(unsigned type)
{
    unsigned succeeded = 0;

    ASSERT_SPELLOUT( 1000000, type|MASCULINE,     u8"un million");
    ASSERT_SPELLOUT( 1000001, type|MASCULINE,     u8"un million un");
    ASSERT_SPELLOUT( 1000001, type|FEMININE,      u8"un million une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT( 1000200, type|MASCULINE, u8"un million deux cent");
    else
        ASSERT_SPELLOUT( 1000200, type|MASCULINE, u8"un million deux cents");
    ASSERT_SPELLOUT( 1000201, type|FEMININE,      u8"un million deux cent une");
    ASSERT_SPELLOUT( 2000000, type|MASCULINE,     u8"deux millions");
    ASSERT_SPELLOUT( 2000001, type|MASCULINE,     u8"deux millions un");
    ASSERT_SPELLOUT( 2000001, type|FEMININE,      u8"deux millions une");
    if (type & CARDINAL_AS_ORDINAL)
        ASSERT_SPELLOUT( 2000200, type|MASCULINE, u8"deux millions deux cent");
    else
        ASSERT_SPELLOUT( 2000200, type|MASCULINE, u8"deux millions deux cents");
    ASSERT_SPELLOUT( 2000201, type|FEMININE,      u8"deux millions deux cent une");
    if (type & CARDINAL_AS_ORDINAL)
    {
        ASSERT_SPELLOUT(80000000, type|MASCULINE, u8"quatre-vingt millions");
        ASSERT_SPELLOUT(80000001, type|MASCULINE, u8"quatre-vingt millions un");
        ASSERT_SPELLOUT(80000001, type|FEMININE,  u8"quatre-vingt millions une");
        ASSERT_SPELLOUT(80000200, type|MASCULINE, u8"quatre-vingt millions deux cent");
        ASSERT_SPELLOUT(80000201, type|FEMININE,  u8"quatre-vingt millions deux cent une");
    }
    else
    {
        ASSERT_SPELLOUT(80000000, type|MASCULINE, u8"quatre-vingts millions");
        ASSERT_SPELLOUT(80000001, type|MASCULINE, u8"quatre-vingts millions un");
        ASSERT_SPELLOUT(80000001, type|FEMININE,  u8"quatre-vingts millions une");
        ASSERT_SPELLOUT(80000200, type|MASCULINE, u8"quatre-vingts millions deux cents");
        ASSERT_SPELLOUT(80000201, type|FEMININE,  u8"quatre-vingts millions deux cent une");
    }

    ASSERT_SPELLOUT(UINT32_MAX, type, u8"quatre milliards deux cent quatre-vingt-quatorze millions neuf cent soixante-sept mille deux cent quatre-vingt-quinze");
    ASSERT_SPELLOUT(UINT64_MAX, type, u8"dix-huit trillions quatre cent quarante-six billiards sept cent quarante-quatre billions soixante-treize milliards sept cent neuf millions cinq cent cinquante et un mille six cent quinze");

    return succeeded;
}


static unsigned test_large_ordinals(unsigned type)
{
    assert(type & ORDINAL);

    unsigned succeeded = 0;

    ASSERT_SPELLOUT( 1000000, type, u8"millionième");
    ASSERT_SPELLOUT( 1000001, type, u8"un million unième");
    ASSERT_SPELLOUT( 1000200, type, u8"un million deux centième");
    ASSERT_SPELLOUT( 1000201, type, u8"un million deux cent unième");
    ASSERT_SPELLOUT( 2000000, type, u8"deux millionième");
    ASSERT_SPELLOUT( 2000001, type, u8"deux millions unième");
    ASSERT_SPELLOUT( 2000200, type, u8"deux millions deux centième");
    ASSERT_SPELLOUT(80000000, type, u8"quatre-vingt millionième");
    ASSERT_SPELLOUT(80000001, type, u8"quatre-vingt millions unième");
    ASSERT_SPELLOUT(80000200, type, u8"quatre-vingt millions deux centième");
    ASSERT_SPELLOUT(80000201, type, u8"quatre-vingt millions deux cent unième");

    ASSERT_SPELLOUT(UINT64_C(1000000000000000000), type, u8"trillionième");
    ASSERT_SPELLOUT(UINT64_C(1000000000000000001), type, u8"un trillion unième");
    ASSERT_SPELLOUT(UINT64_C(1000000000000000200), type, u8"un trillion deux centième");
    ASSERT_SPELLOUT(UINT64_C(1000000000000000201), type, u8"un trillion deux cent unième");
    ASSERT_SPELLOUT(UINT64_C(2000000000000000000), type, u8"deux trillionième");
    ASSERT_SPELLOUT(UINT64_C(2000000000000000001), type, u8"deux trillions unième");
    ASSERT_SPELLOUT(UINT64_C(2000000000000000200), type, u8"deux trillions deux centième");
    ASSERT_SPELLOUT(UINT64_MAX,                    type, u8"dix-huit trillions quatre cent quarante-six billiards sept cent quarante-quatre billions soixante-treize milliards sept cent neuf millions cinq cent cinquante et un mille six cent quinzième");

    return succeeded;
}


static unsigned test_cardinals()
{
    unsigned succeeded = 0;
    succeeded += test_cardinals_0_99(CARDINAL);
    succeeded += test_cardinals_100_999(CARDINAL);
    succeeded += test_cardinals_1000_999999(CARDINAL);
    succeeded += test_large_cardinals(CARDINAL);
    return succeeded;
}


static unsigned test_cardinals_as_ordinals()
{
    unsigned succeeded = 0;
    succeeded += test_cardinals_0_99(CARDINAL_AS_ORDINAL);
    succeeded += test_cardinals_100_999(CARDINAL_AS_ORDINAL);
    succeeded += test_cardinals_1000_999999(CARDINAL_AS_ORDINAL);
    succeeded += test_large_cardinals(CARDINAL_AS_ORDINAL);
    return succeeded;
}


static unsigned test_ordinals()
{
    unsigned succeeded = 0;
    succeeded += test_ordinals_0_99();
    succeeded += test_ordinals_100_999(ORDINAL|MASCULINE);
    succeeded += test_ordinals_100_999(ORDINAL|FEMININE);
    succeeded += test_ordinals_1000_999999(ORDINAL|MASCULINE);
    succeeded += test_ordinals_1000_999999(ORDINAL|FEMININE);
    succeeded += test_large_ordinals(ORDINAL|MASCULINE);
    succeeded += test_large_ordinals(ORDINAL|FEMININE);
    return succeeded;
}


int main()
{
    unsigned succeeded = 0;
    succeeded += test_cardinals();
    succeeded += test_cardinals_as_ordinals();
    succeeded += test_ordinals();

    printf("Passed %u/%u tests\n", succeeded, g_testCount);
    return (succeeded == g_testCount) ? EXIT_SUCCESS : EXIT_FAILURE;
}
