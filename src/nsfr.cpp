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


namespace rmgr { namespace nsfr
{

//=================================================================================================
// Data

// Table of cardinals up to 16
static char const* const g_cardinals[16] =
{
    "un",       "deux",     "trois",  "quatre",  //  1  2  3  4
    "cinq",     "six",      "sept",   "huit",    //  5  6  7  8
    "neuf",     "dix",      "onze",   "douze",   //  9 10 11 12
    "treize",   "quatorze", "quinze", "seize"    // 13 14 15 16
};

static const char g_zero[]        = {"z\xC3\xA9ro"};
static const char g_zeroieme[]    = {"z\xC3\xA9roi\xC3\xA8me"};
static const char g_oneFeminine[] = {"une"};

static const char g_space[] = {" "};
static char const* const g_joiners[2] = {"-", " et "};

// Table of ordinals up to 16
static char const* const g_ordinals[16] =
{
    "uni\xC3\xA8me",    "deuxi\xC3\xA8me",    "troisi\xC3\xA8me", "quatri\xC3\xA8me", //  1st  2nd  3rd  4th
    "cinqui\xC3\xA8me", "sixi\xC3\xA8me",     "septi\xC3\xA8me",  "huiti\xC3\xA8me",  //  5th  6th  7th  8th
    "neuvi\xC3\xA8me",  "dixi\xC3\xA8me",     "onzi\xC3\xA8me",   "douzi\xC3\xA8me",  //  9th 10th 11th 12th
    "treizi\xC3\xA8me", "quatorzi\xC3\xA8me", "quinzi\xC3\xA8me", "seizi\xC3\xA8me"   // 13th 14th 15th 16th
};

static char const* const g_first[2]        = {"premier", "premi\xC3\xA8re"};
static char const* const g_second[2]       = {"second",  "seconde"};
static const char        g_ordinalEnding[] = {"i\xC3\xA8me"};

// Table of cardinals for tens
static char const* const g_cardinalTens[9] =
{
    "dix",      "vingt",    "trente",   "quarante", "cinquante", // 10 20 30 40 50
    "soixante", "septante", "huitante", "nonante"                // 60 70 80 90
};

static const char g_quatreVingt[] = {"quatre-vingt"};
static const char g_octante[]     = {"octante"};

// Table of ordinals for tens
static char const* const g_ordinalsTens[9] =
{
    "dixi\xC3\xA8me",     "vingti\xC3\xA8me",    "trenti\xC3\xA8me",    // 10th 20th 30th
    "quaranti\xC3\xA8me", "cinquanti\xC3\xA8me", "soixanti\xC3\xA8me",  // 40th 50th 60th
    "septanti\xC3\xA8me", "huitanti\xC3\xA8me",  "nonanti\xC3\xA8me"    // 70th 80th 90th
};

static const char g_octanteOrdinal[] = {"octanti\xC3\xA8me"};


struct Numeral
{
    uintmax_t   value;     ///< The value
    const char* cardinal;
};

// Table of other numerals
static const Numeral g_numerals[] =
{
    {       100, "cent"},
    {      1000, "mille"},
    {   1000000, "million"},
    {1000000000, "milliard"},

// 64-bit values
#ifdef UINT64_C
    {UINT64_C(      1000000000000), "billion"},  // 10^12
    {UINT64_C(   1000000000000000), "billiard"}, // 10^15
    {UINT64_C(1000000000000000000), "trillion"}, // 10^18
#endif

// 128-bit values
#ifdef UINT128_C
    {UINT128_C(               1000000000000000000000), "trilliard"},    // 10^21
    {UINT128_C(            1000000000000000000000000), "quadrillion"},  // 10^24
    {UINT128_C(         1000000000000000000000000000), "quadrilliard"}, // 10^27
    {UINT128_C(      1000000000000000000000000000000), "quintillion"},  // 10^30
    {UINT128_C(   1000000000000000000000000000000000), "quintilliard"}, // 10^33
    {UINT128_C(1000000000000000000000000000000000000), "sextillion"},   // 10^36
    {UINT128_C(1000000000000000000000000000000000000), "sextilliard"},  // 10^39
#endif
};

static const char g_millieme[] = {"milli\xC3\xA8me"};


static const unsigned TYPE_MASK      = CARDINAL | ORDINAL | CARDINAL_AS_ORDINAL | ORDINAL_SUFFIX;
static const unsigned PLURAL_ALLOWED = 0x1000;

//=================================================================================================
// Formatting

/**
 * @brief Retrieves the names for values within [1;16]
 */
static const char* format_below17(unsigned value, unsigned options)
{
    assert(1<=value && value<=16);
    assert(((options & TYPE_MASK) == CARDINAL) || ((options & TYPE_MASK) == ORDINAL));

    if (options & ORDINAL)
        return g_ordinals[value-1];
    else if (value==1u && (options & FEMININE))
        return g_oneFeminine;
    else
        return g_cardinals[value-1];
}


/**
 * @brief Retrieves the names for tens units
 */
static const char* format_tens(unsigned tens, unsigned options)
{
    assert(1<=tens && tens<=9);
    assert(((options & TYPE_MASK) == CARDINAL) || ((options & TYPE_MASK) == ORDINAL));

    if (options & ORDINAL)
    {
        if (tens==8u && (options & OCTANTE))
            return g_octanteOrdinal;
        return g_ordinalsTens[tens-1];
    }
    else
    {
        if (tens==8u && (options & OCTANTE))
            return g_octante;
        return g_cardinalTens[tens-1];
    }
}


static void recursive_format(std::string& result, uintmax_t value, unsigned options);


/**
 * @brief Special handling of numbers between 70 and 99 for reference French
 */
void format70_99(std::string& result, unsigned value, unsigned options)
{
    assert(70<=value && value<=99);
    assert(((options & TYPE_MASK) == CARDINAL) || ((options & TYPE_MASK) == ORDINAL));

    if (value <= 79)              // 70-79 with a special case at 71
    {
        result += g_cardinalTens[5];       // Based on "soixante"
        result += g_joiners[value == 71u]; // 71 doesn't take an hyphen but "et" instead
        recursive_format(result, value-60, (options & ~PLURAL_ALLOWED));
    }
    else                         // 80-99
    {
        result += g_quatreVingt;
        if (value == 80u)
        {
            if (options & ORDINAL)              // Add the ordinal ending
                result += g_ordinalEnding;
            else if (options & PLURAL_ALLOWED)  // When allowed to, append the 's' for plural
                result += 's';
        }
        else
        {
            result += g_joiners[0];
            recursive_format(result, value-80, (options & ~PLURAL_ALLOWED));
        }
    }
}


/**
 * @brief Recursive formatting function
 *
 * @param aNumber        The number to format
 * @param aType          Format as a cardinal or an ordinal?
 * @param aGender        The gender the number is related to (masculine or feminine)
 * @param aPluralAllowed Is the plural form authorised? It is not when dealing with ordinals.
 * @param aResult        Where to store the resulting formatted text
 */
static void recursive_format(std::string& result, uintmax_t value, unsigned options)
{
    assert(((options & TYPE_MASK) == CARDINAL) || ((options & TYPE_MASK) == ORDINAL));

    if (value < 17u)                                     // 1 - 16
        result += format_below17(static_cast<unsigned>(value), options);
    else if (value < 100u)                               // 17 - 99
    {
        if (   (value <= 69u)
            || (value <= 79u && (options & SEPTANTE))
            || (value <= 89u && (options & (HUITANTE | OCTANTE)))
            || (options & NONANTE))
        {
            const unsigned tens = static_cast<unsigned>(value / 10u);
            const unsigned ones = static_cast<unsigned>(value % 10u);
            if (ones == 0u)
                result += format_tens(tens, options);
            else
            {
                result += format_tens(tens, ((options & ~TYPE_MASK) | CARDINAL));
                result += g_joiners[ones == 1u];
                result += format_below17(ones, options);
            }
        }
        else                                             // 70 - 99 for reference French
            format70_99(result, static_cast<unsigned>(value), options);
    }
    else                                                 // 100 - ...
    {
        const Numeral* numeral;
        // Force the use of "cent" for [1100; 1999]
        if ((options & CENT_1100_1999) && 1100<=value && value<=1999)
            numeral = &g_numerals[0];
        // Regular case: find the appropriate numeral
        else
        {
            const size_t numeralCount = sizeof(g_numerals) / sizeof(g_numerals[0]);
            size_t i = 0;
            while (i < numeralCount && g_numerals[i].value <= value)
                ++i;
            numeral = &g_numerals[i-1];
        }

        // Compute the multiplier & remainder
        const uintmax_t multiplier = value / numeral->value;
        const uintmax_t remainder  = value % numeral->value;

        // Check the numeral's properties
        const bool isNoun    = (numeral->value > 1000u && !((options & ORDINAL) && remainder==0u));
        const bool hasPlural = (numeral->value != 1000u);

        // Add the multiplier (if needed)
        if (multiplier>1u || isNoun)
        {
            unsigned newOptions = options & ~(TYPE_MASK | FEMININE); // Force masculine cardinal
            if (!isNoun)
                newOptions &= ~PLURAL_ALLOWED;
            recursive_format(result, multiplier, newOptions);
            result += g_space;
        }

        // The numeral itself (with the plural form if needed)
        if ((options & ORDINAL) && !remainder)
        {
            if (numeral->value == 1000u)
                result += g_millieme;
            else
            {
                result += numeral->cardinal;
                result += g_ordinalEnding;
            }
        }
        else
        {
            result += numeral->cardinal;
            if (multiplier>1u && (isNoun || ((options & PLURAL_ALLOWED) && hasPlural && !remainder)))
                result += 's';
        }

        // The remainder if any
        if (remainder)
        {
            result += g_space;
            recursive_format(result, remainder, options);
        }
    }
}


static void format(std::string& result, uintmax_t value, unsigned options)
{
    if (options & ORDINAL_SUFFIX)
    {
        if (value == 1u)
            result = (options & FEMININE) ? "re" : "er";
        else if (value==2u && (options & SECOND))
            result = (options & FEMININE) ? "de" : "d";
        else
            result = 'e';
    }
    else
    {
        // "huitante" overrides "octante"
        if (options & HUITANTE)
            options &= ~OCTANTE;

        if (value == 0u)
            result += (options & ORDINAL) ? g_zeroieme : g_zero;
        else if (value==1u && (options & ORDINAL))
            result += g_first[options & FEMININE];
        else if (value==2u && ((options & (ORDINAL | SECOND)) == (ORDINAL | SECOND)))
            result += g_second[options & FEMININE];
        else
        {
            unsigned newOptions = options;
            if ((options & TYPE_MASK) == CARDINAL)
                newOptions |= PLURAL_ALLOWED;
            else if (options & CARDINAL_AS_ORDINAL)
                newOptions = (newOptions & ~TYPE_MASK) | CARDINAL;
            recursive_format(result, value, newOptions);
        }
    }
}


static void format(std::string& result, intmax_t value, unsigned options)
{
    assert(!(value<0 && (options & (ORDINAL | ORDINAL_SUFFIX))));

    if (value < 0)
    {
        result += "moins ";
        value = -value;
    }

    format(result, static_cast<uintmax_t>(value), options);
}


//=================================================================================================
// API

std::string internal::spell_out(intmax_t value, unsigned options)
{
    std::string result;
    format(result, value, options);
    return result;
}


std::string internal::spell_out(uintmax_t value, unsigned options)
{
    std::string result;
    format(result, value, options);
    return result;
}


}} // namespace rmgr::nsfr
