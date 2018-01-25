#if !defined  HAVE_CENTERED_ARRAY3D_H__
#define       HAVE_CENTERED_ARRAY3D_H__
// This file is part of the FXT library.
// Copyright (C) 2017 Joerg Arndt
// License: GNU General Public License version 3 or later,
// see the file COPYING.txt in the main directory.


#include "ds/vector3d.h"
#include "ds/point3d.h"
#include "ds/array3d.h"
#include "fxttypes.h"


template <typename Type>
class centered_array3d
// Centered 2-dimensional array from array3d<Type>,
// using point3d<long> or vector3d<long> for coordinates.
// Valid cells are in the range [ +-k , +-k , +-k ].
{
    typedef point3d<long> Pnt;
    typedef vector3d<long> Vec;

private:
    long k;
    array3d<Type> A;

public:

public:
    explicit centered_array3d(long ck)
        : k(ck),
          A( 2*k + 1,  2*k + 1, 2*k + 1 )
    { ; }

    ~centered_array3d()  {;}

    const Type & operator [] (const Vec & V)  const
    {
        return  A[ (ulong)( V.x() + k ) ][ (ulong)( V.y() + k ) ][ (ulong)( V.z() + k ) ];
    }

    Type & operator [] (const Vec & V)
    {
//        const long x = V.x(),  y = V.y();
        return  A[ (ulong)( V.x() + k ) ][ (ulong)( V.y() + k ) ][ (ulong)( V.z() + k ) ];
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


#endif // !defined HAVE_CENTERED_ARRAY3D_H__
