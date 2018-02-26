#include "bits/print-bin.h"
#include "bits/bit-isolate.h"
#include <stdio.h>
#include "bits/bithigh.h"
#include "bits/bit2pow.h"
#include "bits/bitcount.h"
#include "bits/ith-one-idx.h"
#include "bits/branchless.h"
#include "bits/bitcyclic-match.h"
#include "bits/bitcyclic-period.h"
#include "bits/bitperiodic.h"
#include "bits/bitcyclic-dist.h"
#include "bits/bitcyclic-xor.h"
#include "bits/revbin.h"
#include "bits/bitzip.h"
#include "bits/bitbutterfly.h"
#include "bits/graycode.h"
#include "bits/bitcombcolex.h"
#include "bits/bitsequency.h"
#include "bits/graypower.h"
#include "bits/bittransforms.h"
#include "bits/revgraycode.h"
#include "bits/bitrotate.h"
#include "bits/blue-fixed-points.h"
#include "bits/zerobyte.h"
#include "bits/bit2adic.h"

int main()
{
    ulong a=0B11;
    print_bin_l("\na:",a);
    print_bin_l("\ninv2adic:",inv2adic(a));
}
