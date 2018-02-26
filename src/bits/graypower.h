// lidong
#if !defined  HAVE_GRAYPOWER_H__
#define       HAVE_GRAYPOWER_H__
// This file is part of the FXT library.
// Copyright (C) 2010 Joerg Arndt
// License: GNU General Public License version 3 or later,
// see the file COPYING.txt in the main directory.


#include "fxttypes.h"
#include "bits/bitsperlong.h"
#include "bits/print-bin.h"


static inline ulong gray_pow(ulong x, ulong e)
// Return (gray_code**e)(x)
// gray_pow(x, 1) == gray_code(x)
// gray_pow(x, BITS_PER_LONG-1) == inverse_gray_code(x)
// 1010,111 -> 1100
{
    e &= (BITS_PER_LONG-1);  // modulo BITS_PER_LONG
    ulong s = 1;
    while ( e )
    {
        // print_bin_l("\ne:",e);
        // print_bin_l("\ns:",s);
        // print_bin_l("\nx:",x);
        if ( e & 1 )  x ^= x >> s;  // gray ** s
        s <<= 1;
        e >>= 1;
    }
    return  x;
}
// -------------------------

static inline ulong inverse_gray_pow(ulong x, ulong e)
// Return (inverse_gray_code**(e))(x)
//   == (gray_code**(-e))(x)
// inverse_gray_pow(x, 1) == inverse_gray_code(x)
// inverse_gray_pow(x, BITS_PER_LONG-1) == gray_code(x)
// 1100,111 -> 1010
{
    return  gray_pow(x, -e);
}
// -------------------------



static inline ulong rev_gray_pow(ulong x, ulong e)
// Return (rev_gray_code**e)(x)
// rev_gray_pow(x, 1) == rev_gray_code(x)
// rev_gray_pow(x, BITS_PER_LONG-1) == inverse_rev_gray_code(x)
// 1010,111 -> 110_0000_0110
{
    e &= (BITS_PER_LONG-1);  // modulo BITS_PER_LONG
    ulong s = 1;
    while ( e )
    {
        if ( e & 1 )  x ^= x << s;  // rev_gray ** s
        s <<= 1;
        e >>= 1;
    }
    return  x;
}
// -------------------------


static inline ulong inverse_rev_gray_pow(ulong x, ulong e)
// Return (inverse_rev_gray_code**(e))(x)
//   == (rev_gray_code**(-e))(x)
// inverse_rev_gray_pow(x, 1) == inverse_rev_gray_code(x)
// inverse_rev_gray_pow(x, BITS_PER_LONG-1) == rev_gray_code(x)
// 110_0000_0110,111 -> 1010
{
    return  rev_gray_pow(x, -e);
}
// -------------------------


#endif  // !defined HAVE_GRAYPOWER_H__
