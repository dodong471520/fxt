// lidong
#if !defined  HAVE_THUE_MORSE_H__
#define       HAVE_THUE_MORSE_H__
// This file is part of the FXT library.
// Copyright (C) 2010, 2012, 2014 Joerg Arndt
// License: GNU General Public License version 3 or later,
// see the file COPYING.txt in the main directory.


#include "fxttypes.h"
#include "bits/parity.h"
#include "bits/bitsperlong.h"


class thue_morse
// Thue-Morse sequence
{
public:
    ulong k_;
    ulong tm_;

public:
    explicit thue_morse(ulong k=0)  { init(k); }
    ~thue_morse()  { ; }

    ulong init(ulong k=0)
    {
        k_ = k;
        tm_ = parity(k_);
        return tm_;
    }

    ulong data()  { return tm_; }

    ulong next()
    {
        const int len=16;
        // printf("\nk:%lu",k_);
        ulong x = k_ ^ (k_ + 1);
        // print_bin_l("\nx1 ",x,len);
        ++k_;
        x ^= x>>1;        // highest bit that changed with increment
#if BITS_PER_LONG > 32
        // print_bin_l("\nx2 ",x,len);
        x &= 0x5555555555555555UL;
#else
        x &= 0x55555555UL;
#endif
        // print_bin_l("\nx3 ",x,len);
        // print_bin_l("\ntm1 ",tm_,len);
        tm_ ^= ( x!=0 );  // change if highest changed bit was at even index
        // print_bin_l("\ntm2 ",tm_,len);
        // printf("\n");
        return tm_;
    }
};
// -------------------------


#endif  // !defined HAVE_THUE_MORSE_H__
