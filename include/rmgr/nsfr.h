/*
 * Copyright (c) 2020, Romain Bailly
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef RMGR_NSFR_H
#define RMGR_NSFR_H


#include <string>


/**
 * @namespace rmgr
 * @brief The root namespace for all my projects
 */

/**
 * @namespace rmgr::nsfr
 * @brief Namespace that contains all things related to number spelling in French
 */

namespace rmgr { namespace nsfr
{


/**
 * @defgroup RmgrNsfrOptions
 * @{
 */


/**
 * @defgroup RmgrNsfrOptionsGender
 * @{
 */
const unsigned MASCULINE = 0;
const unsigned FEMININE  = 1;
/** @} */


/**
 * @defgroup  // RmgrNsfrOptionsType
 * @{
 */
const unsigned CARDINAL             = 0;    ///< Render the number as a cardinal (i.e. a number used to count things: "80 pages")
const unsigned ORDINAL              = 0x02; ///< Render the number as an ordinal (i.e. a number used for the position of a thing: "80e page")
const unsigned CARDINAL_AS_ORDINAL  = 0x04; ///< Render the number as a cardinal used as an ordinal (e.g. "page 80")
const unsigned ORDINAL_SUFFIX       = 0x08; ///< Doesn't render the number, just returns this ordinal suffix (e.g. 3 yields "e", which is the suffix for "3e")
const unsigned SECOND               = 0x10; ///< Use "second" instead of "deuxieme"
/** @} */


/**
 * @defgroup  // RmgrNsfrOptionsVariants
 */
const unsigned SEPTANTE       = 0x020; ///< Render 70 as "septante" instead of "soixante-dix"
const unsigned HUITANTE       = 0x080; ///< Render 80 as "huitante" instead of "quatre-vingts"
const unsigned OCTANTE        = 0x040; ///< Render 80 as "octante"  instead of "quatre-vingts"
const unsigned NONANTE        = 0x100; ///< Render 70 as "nonante"  instead of "quatre-vingt-dix"
const unsigned CENT_1100_1999 = 0x200; ///< Use only "cent" instead of "mille" for numbers between 1100 and 1999
const unsigned FRANCE         = 0;                             ///< Use the French  way for 70, 80 and 90
const unsigned BELGIUM        = SEPTANTE | NONANTE;            ///< Use the Belgian way for 70, 80 and 90
const unsigned SWITZERLAND    = SEPTANTE | HUITANTE | NONANTE; ///< Use the Swiss   way for 70, 80 and 90
/** @} */

/** @} */ // RmgrNsfrOptions


//=================================================================================================

/** @cond RmgrNsfrInternal */
namespace internal
{
    std::string spell_out(intmax_t  value, unsigned options);
    std::string spell_out(uintmax_t value, unsigned options);
}
/** @endcond */


inline std::string spell_out(char               value, unsigned options=0) {return internal::spell_out( intmax_t(value), options);}
inline std::string spell_out(signed   char      value, unsigned options=0) {return internal::spell_out( intmax_t(value), options);}
inline std::string spell_out(unsigned char      value, unsigned options=0) {return internal::spell_out(uintmax_t(value), options);}
inline std::string spell_out(signed   short     value, unsigned options=0) {return internal::spell_out( intmax_t(value), options);}
inline std::string spell_out(unsigned short     value, unsigned options=0) {return internal::spell_out(uintmax_t(value), options);}
inline std::string spell_out(signed   int       value, unsigned options=0) {return internal::spell_out( intmax_t(value), options);}
inline std::string spell_out(unsigned int       value, unsigned options=0) {return internal::spell_out(uintmax_t(value), options);}
inline std::string spell_out(signed   long      value, unsigned options=0) {return internal::spell_out( intmax_t(value), options);}
inline std::string spell_out(unsigned long      value, unsigned options=0) {return internal::spell_out(uintmax_t(value), options);}
inline std::string spell_out(signed   long long value, unsigned options=0) {return internal::spell_out( intmax_t(value), options);}
inline std::string spell_out(unsigned long long value, unsigned options=0) {return internal::spell_out(uintmax_t(value), options);}


}} // namespace rmgr::nsfr


#endif // RMGR_NSFR_H
