// lidong
#if !defined  HAVE_GRSNEGATIVE_H__
#define       HAVE_GRSNEGATIVE_H__
// This file is part of the FXT library.
// Copyright (C) 2010, 2011 Joerg Arndt
// License: GNU General Public License version 3 or later,
// see the file COPYING.txt in the main directory.

#include "fxttypes.h"
#include "bits/parity.h"
#include "bits/bitsperlong.h"


static inline ulong grs_negative_q(ulong x)
// Return whether the Golay-Rudin-Shapiro sequence
// (OEIS sequence A020985) is negative for index x
// Return 1 for x =
//  3,6,11,12,13,15,19,22,24,25,26,30,35,38,43,44,45,47,48,49,
//  50,52,53,55,59,60,61,63,67,70,75,76,77,79,83,86,88,89,90,94,
//  96,97,98,100,101,103,104,105,106,110,115,118,120,121,122,
//  126,131,134,139,140, ...
//
// Algorithm: count bit pairs modulo 2
// 111 -> 2 -> 0, 1111 -> 3 -> 1
//
//  5 -> 0
//  6 -> 1
{
    return  parity( x & (x>>1) );
}
// -------------------------


static inline ulong grs_next(ulong k, ulong g)
// With g == grs_negative_q(k), compute grs_negative_q(k+1).
// 4,0 -> 0
// 5,0 -> 1
{
#if BITS_PER_LONG > 32
    const ulong cm = 0x5555555555555554UL;  // 64-bit version
#else
    const ulong cm = 0x55555554UL;
#endif
    const int len=16;
    // printf("\nk:%lu,g:%lu",k,g);
    // print_bin_l("\nk ",k,len);
    ulong h = ~k;  h &= -h;  // == lowest_zero(k);
    // print_bin_l("\nh ",h,len);
    // print_bin_l("\nm ",cm,len);
    g ^= ( ((h&cm) ^ ((k>>1)&h)) !=0 );
    // print_bin_l("\n3 ",h&cm,len);
    // print_bin_l("\n4 ",(k>>1)&h,len);
    // print_bin_l("\n5 ",(h&cm)^((k>>1)&h),len);
    // printf("\ng:%lu",g);
    // printf("\n");
    return  g;
}
// -------------------------


#endif  // !defined HAVE_GRSNEGATIVE_H__
