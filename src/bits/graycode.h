// lidong
#if !defined HAVE_GRAYCODE_H__
#define      HAVE_GRAYCODE_H__
// This file is part of the FXT library.
// Copyright (C) 2010, 2012 Joerg Arndt
// License: GNU General Public License version 3 or later,
// see the file COPYING.txt in the main directory.

#include "fxttypes.h"
#include "bits/bitsperlong.h"
#include "bits/print-bin.h"
#include "fxtio.h"


static inline ulong gray_code(ulong x)
// Return the Gray code of x
// ('bit-wise derivative modulo 2')
// 10 -> 11
{
    return  x ^ (x>>1);
}
// -------------------------


static inline ulong inverse_gray_code(ulong x)
// inverse of gray_code()
// note: the returned value contains at each bit position
// the parity of all bits of the input left from it (incl. itself)
//
// 110 -> 010
{
// ----- VERSION 1 (integration modulo 2):
   // ulong h=1, r=0;
   // do
   // {
       // if ( x & 1 )  r^=h;
       // print_bin_l("\nh ",h);
       // print_bin_l("\nx ",x);
       // print_bin_l("\nr ",r);
       // printf("\n");
       // x >>= 1;
       // h = (h<<1)+1;
   // }
   // while ( x!=0 );
   // return r;

// ----- VERSION 2 (apply graycode BITS_PER_LONG-1 times):
//    ulong r = BITS_PER_LONG;
//    while ( --r )  x ^= x>>1;
//    return x;

// ----- VERSION 3 (use: gray ** BITSPERLONG == id):
    x ^= x>>1;  // gray ** 1
    // print_bin_l("\n1  ",x);
    x ^= x>>2;  // gray ** 2
    // print_bin_l("\n2  ",x);
    x ^= x>>4;  // gray ** 4
    // print_bin_l("\n4  ",x);
    x ^= x>>8;  // gray ** 8
    // print_bin_l("\n8  ",x);
    x ^= x>>16;  // gray ** 16
    // print_bin_l("\n16 ",x);
    // here: x = gray**31(input)
    // note: the statements can be reordered at will

#if  BITS_PER_LONG > 32
    x ^= x>>32;  // for 64bit words
    // print_bin_l("\n32 ",x);
#endif

    return  x;
}
// -------------------------


static inline ulong byte_gray_code(ulong x)
// Return the Gray code of bytes in parallel
// 0xffffffffffffffff -> 0x8080808080808080
{
#if  BITS_PER_LONG == 32
    return  x ^ ((x & 0xfefefefeUL)>>1);
#endif

#if  BITS_PER_LONG == 64
    return  x ^ ((x & 0xfefefefefefefefeUL)>>1);
#endif
}
// -------------------------

static inline ulong byte_inverse_gray_code(ulong x)
// Return the inverse Gray code of bytes in parallel
{
#if  BITS_PER_LONG == 32
    x ^= ((x & 0xfefefefeUL)>>1);
    x ^= ((x & 0xfcfcfcfcUL)>>2);
    x ^= ((x & 0xf0f0f0f0UL)>>4);
#endif

#if  BITS_PER_LONG == 64
    x ^= ((x & 0xfefefefefefefefeUL)>>1);
    x ^= ((x & 0xfcfcfcfcfcfcfcfcUL)>>2);
    x ^= ((x & 0xf0f0f0f0f0f0f0f0UL)>>4);
#endif

    return  x;
}
// -------------------------


#endif  // !defined HAVE_GRAYCODE_H__
