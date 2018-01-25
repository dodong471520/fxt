#if !defined  HAVE_CENTERED_ARRAY2D_H__
#define       HAVE_CENTERED_ARRAY2D_H__
// This file is part of the FXT library.
// Copyright (C) 2017 Joerg Arndt
// License: GNU General Public License version 3 or later,
// see the file COPYING.txt in the main directory.


#include "ds/vector2d.h"
#include "ds/point2d.h"
#include "ds/array2d.h"
#include "fxttypes.h"


template <typename Type>
class centered_array2d
// Centered 2-dimensional array from array2d<Type>,
// using point2d<long> or vector2d<long> for coordinates.
// Valid cells are in the range [ +-k , +-k ].
{
    typedef point2d<long> Pnt;
    typedef vector2d<long> Vec;

private:
    long k;
    array2d<Type> A;

public:

public:
    explicit centered_array2d(long ck)
        : k(ck),
          A( 2*k + 1,  2*k + 1 )
    { ; }

    ~centered_array2d()  {;}

    const Type & operator [] (const Vec & V)  const
    {
        return  A[ (ulong)( V.x() + k ) ][ (ulong)( V.y() + k ) ];
    }

    Type & operator [] (const Vec & V)
    {
//        const long x = V.x(),  y = V.y();
        return  A[ (ulong)( V.x() + k ) ][ (ulong)( V.y() + k ) ];
    }


    const Type & operator [] (const Pnt & P)  const
    {
        return  operator [] ( P.as_vector() );
    }

    Type & operator [] (const Pnt & P)
    {
        return  operator [] ( P.as_vector() );
    }

    void null()  { A.null(); }
};
// -------------------------


#endif // !defined HAVE_CENTERED_ARRAY2D_H__
