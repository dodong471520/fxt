// lidong
#if !defined  HAVE_BITTRANSFORMS_H__
#define       HAVE_BITTRANSFORMS_H__
// This file is part of the FXT library.
// Copyright (C) 2010 Joerg Arndt
// License: GNU General Public License version 3 or later,
// see the file COPYING.txt in the main directory.

#include "fxttypes.h"
#include "bits/bitsperlong.h"
#include "bits/print-bin.h"
#include <stdio.h>


static inline ulong blue_code(ulong a)
// Self-inverse.
// range [0..2^k-1] is mapped onto itself
// work \prop log_2(BITS_PER_LONG)
//.
// With  B:=blue,  G:=gray,  I:=inverse_gray
//   G(B(G(B(a)))) == a
//   G(B(G(a)))    == B(a)
//   I(B(I(a)))    == B(a)
//   G(B(a))       == B(I(a))
//
// lidong : 
//        : Y Y = id 
//        : g ig = id
//        : S(k) S(-k) = id
//
//        : Y B = r Y , Y = r Y B , r = Y B Y
//        : g B = B ig ,g = B ig B, B = ig B ig,ig = B g B
//        : g(k) Y = Y S(k),g(k) = Y S(K) Y, Y = g(k) Y S(-K),S(k)=Y g(k) Y
//        : rg(k) B = B S(-k)
//
// #ig = inverse gray code
// #g(k) = gray code ,k bits
// #rg(k) = reverse gray code,k bits
// #S(k) = shift,k bits
// #r = revbin
//
// With  P:=parity
//   P(B(a)) == a % 2
//   1010 -> 1100
{
    ulong s = BITS_PER_LONG >> 1;
    ulong m = ~0UL << s;
    do
    {
        // print_bin_l("\nm ",m);
        // print_bin_l("\na ",a);
        // print_bin_l("\ns ",s);
        // printf("\n");
        a ^= ( (a&m) >> s );
        s >>= 1;
        m ^= (m>>s);
    }
    while ( s );
    return  a;
}
// -------------------------



static inline ulong yellow_code(ulong a)
// Self-inverse.
// work \prop log_2(BITS_PER_LONG)
//.
// With  Y:=yellow,  B:=blue,  r:=revbin
//   B(a) == Y(r(Y(a))) 
//   Y(a) == r(B(r(a)))
//   r(a) == Y(B(Y(a))) == B(Y(B(a)))
//
//
// With  P:=parity
//   P(Y(a)) == highest_one(a) == "sign(a)"
//   1010 -> 0010,0010,0010,0010,0010,0010,0010,0010,0010,0010,0010,0010,0010,0010,0010,0010
{
    ulong s = BITS_PER_LONG >> 1;
    ulong m = ~0UL >> s;
    do
    {
        a ^= ( (a&m) << s );
        s >>= 1;
        m ^= (m<<s);
    }
    while ( s );
    return  a;
}
// -------------------------


static inline ulong red_code(ulong a)
// work \prop log_2(BITS_PER_LONG)
// =^=  revbin( blue_code(a) );
// 1010 ->  0011,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000
{
    ulong s = BITS_PER_LONG >> 1;
    ulong m = ~0UL >> s;
    do
    {
        ulong u = a & m;
        ulong v = a ^ u;
        a = v ^ (u<<s);
        a ^= (v>>s);
        s >>= 1;
        m ^= (m<<s);
    }
    while ( s );
    return  a;
}
// -------------------------


static inline ulong green_code(ulong a)
// work \prop log_2(BITS_PER_LONG)
// =^=  revbin( yellow_code(a) );
// 1010 ->  0100,0100,0100,0100,0100,0100,0100,0100,0100,0100,0100,0100,0100,0100,0100,0100
{
    ulong s = BITS_PER_LONG >> 1;
    ulong m = ~0UL << s;
    do
    {
        ulong u = a & m;
        ulong v = a ^ u;
        a = v ^ (u>>s);
        a ^= (v<<s);
        s >>= 1;
        m ^= (m>>s);
    }
    while ( s );
    return  a;
}
// -------------------------


#endif  // !defined HAVE_BITTRANSFORMS_H__
