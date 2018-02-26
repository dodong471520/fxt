// lidong
#if !defined HAVE_REVBIN_H__
#define      HAVE_REVBIN_H__
// This file is part of the FXT library.
// Copyright (C) 2010, 2012, 2013 Joerg Arndt
// License: GNU General Public License version 3 or later,
// see the file COPYING.txt in the main directory.

#include "bits/bitswap.h"
#include "bits/bitsperlong.h"
#include "bits/bitasm.h"

#include "fxttypes.h"


static inline ulong bswap(ulong x)
// Return word with reversed byte order.
// 0x10 -> 0x1000,0000,0000,0000
{
#ifdef BITS_USE_ASM
    x = asm_bswap(x);
#else
    x = bit_swap_8(x);
    x = bit_swap_16(x);
#if  BITS_PER_LONG >= 64
    x = bit_swap_32(x);
#endif
#endif  // def BITS_USE_ASM
    return x;
}
// -------------------------

static inline ulong revbin(ulong x)
// Return x with reversed bit order.
// 0x10 -> 0x800,0000,0000
{
#if 1
    x = bit_swap_1(x);
    x = bit_swap_2(x);
    x = bit_swap_4(x);
    x = bswap(x);
    return x;

#else  // version using dynamically generated masks:

    ulong s = BITS_PER_LONG >> 1;
    ulong m = ~0UL >> s;
    while ( s )
    {
        x = ( (x & m) << s ) ^ ( (x & (~m)) >> s );
        s >>= 1;
        m ^= (m<<s);
    }
    return  x;
#endif
}
// -------------------------

// bits/revbin-tab.cc:
extern const unsigned char revbin_tab[256];
// used by:
static inline ulong revbin_t(ulong x)
// Return x with reversed bit order.
// Table based version.
// 0x10 -> 0x800,0000,0000
{
#if 1  // unrolled version:
    ulong r      = revbin_tab[ x & 255 ];  x >>= 8;
    r <<= 8;  r |= revbin_tab[ x & 255 ];  x >>= 8;
    r <<= 8;  r |= revbin_tab[ x & 255 ];  x >>= 8;
#if BYTES_PER_LONG > 4
    r <<= 8;  r |= revbin_tab[ x & 255 ];  x >>= 8;
    r <<= 8;  r |= revbin_tab[ x & 255 ];  x >>= 8;
    r <<= 8;  r |= revbin_tab[ x & 255 ];  x >>= 8;
    r <<= 8;  r |= revbin_tab[ x & 255 ];  x >>= 8;
#endif
    r <<= 8;  r |= revbin_tab[ x ];

#else  // version with loop unrolled:

    ulong r = 0;
    for (ulong k=0; k<BYTES_PER_LONG; ++k)
    {
        r <<= 8;
        r |= revbin_tab[ x & 255 ];
        x >>= 8;
    }
#endif

    return r;
}
// -------------------------

static inline ulong revbin_t_le32(ulong x)
// Return x with reversed bit order.
// Table based version for lengths less or equal 32 bits.
// 0x10 -> 0x800,0000
{
    ulong r      = revbin_tab[ x & 255 ];  x >>= 8;
    r <<= 8;  r |= revbin_tab[ x & 255 ];  x >>= 8;
    r <<= 8;  r |= revbin_tab[ x & 255 ];  x >>= 8;
    r <<= 8;  r |= revbin_tab[ x ];
    return r;
}
// -------------------------

static inline ulong revbin_t_le16(ulong x)
// Return x with reversed bit order.
// Table based version for lengths less or equal 16 bits.
// 0x10 -> 0x800
{
    ulong r      = revbin_tab[ x & 255 ];  x >>= 8;
    r <<= 8;  r |= revbin_tab[ x ];
    return r;
}
// -------------------------



static inline ulong xrevbin(ulong a, ulong x)
// Symbolic power of revbin.
// 101011,11100 -> 1110100000000000
{
    x &= (BITS_PER_LONG-1);  // modulo BITS_PER_LONG
    ulong s = BITS_PER_LONG >> 1;
    ulong m = ~0UL >> s;
    while ( s )
    {
        if ( x & 1 )  a = ( (a & m) << s ) ^ ( (a & (~m)) >> s );
        x >>= 1;
        s >>= 1;
        m ^= (m<<s);
    }
    return  a;
}
// -------------------------



static inline ulong revbin(ulong x, ulong ldn)
// Return word with the ldn least significant bits
//   (i.e. bit_0 ... bit_{ldn-1})  of x reversed,
//   the other bits are set to zero.
//   00010000,8 -> 00001000
{
    return  revbin(x) >> (BITS_PER_LONG-ldn);

    // Bit-wise algorithm for small ldn:
//    ulong r = 0;
//    while ( ldn-- != 0 ) { r <<= 1; r += (x&1); x >>= 1; }
//    return  r;
}
// -------------------------



#endif  // !defined HAVE_REVBIN_H__
