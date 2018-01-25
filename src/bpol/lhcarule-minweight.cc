// This file is part of the FXT library.
// Copyright (C) 2010, 2012 Joerg Arndt
// License: GNU General Public License version 3 or later,
// see the file COPYING.txt in the main directory.

// generated file

#include "array-len.h"
#include "fxttypes.h"
#include "bits/bitsperlong.h"

#define R1(n, s1)     (1UL<<s1)
#define R2(n, s1, s2)  (1UL<<s1) | (1UL<<s2)
extern const ulong minweight_lhca_rule[]= {
// LHCA rules of minimum weight that lead to maximal period.
    0,  // (empty)
    R1(  1,  0),
    R1(  2,  0),
    R1(  3,  0),
    R2(  4,  0, 2),
    R1(  5,  0),
    R1(  6,  0),
    R1(  7,  2),
    R2(  8,  1, 2),
    R1(  9,  0),
    R2( 10,  1, 6),
    R1( 11,  0),
    R2( 12,  2, 6),
    R1( 13,  4),
    R1( 14,  0),
    R1( 15,  2),
    R2( 16,  0, 14),
    R1( 17,  4),
    R2( 18,  0, 16),
    R1( 19,  2),
    R2( 20,  1, 2),
    R2( 21,  0, 9),
    R1( 22,  4),
    R1( 23,  0),
    R2( 24,  7, 11),
    R1( 25,  8),
    R1( 26,  0),
    R2( 27,  0, 19),
    R1( 28,  2),
    R1( 29,  0),
    R1( 30,  0),
    R1( 31,  10),
    R2( 32,  0, 14),

#if  ( BITS_PER_LONG > 32 )
    R1( 33,  0),
    R2( 34,  0, 18),
    R1( 35,  0),
    R1( 36,  5),
    R1( 37,  8),
    R1( 38,  6),
    R1( 39,  0),
    R1( 40,  7),
    R1( 41,  0),
    R1( 42,  18),
    R1( 43,  2),
    R2( 44,  3, 25),
    R1( 45,  8),
    R2( 46,  1, 9),
    R1( 47,  12),
    R1( 48,  14),
    R2( 49,  0, 9),
    R1( 50,  10),
    R1( 51,  0),
    R2( 52,  1, 28),
    R1( 53,  0),
    R1( 54,  8),
    R1( 55,  16),
    R2( 56,  3, 13),
    R1( 57,  8),
    R1( 58,  16),
    R2( 59,  3, 14),
    R2( 60,  1, 37),
    R2( 61,  0, 9),
    R1( 62,  4),
    R1( 63,  30),
    R2( 64,  2, 4),

#if 0
    R1( 65,  0),
    R2( 66,  0, 18),
    R1( 67,  14),
    R1( 68,  7),
    R1( 69,  0),
    R2( 70,  0, 36),
    R1( 71,  16),
    R2( 72,  5, 54),
    R1( 73,  8),
    R1( 74,  0),
    R1( 75,  6),
    R2( 76,  1, 21),
    R2( 77,  2, 43),
    R2( 78,  0, 40),
    R1( 79,  8),
    R2( 80,  0, 70),
    R1( 81,  0),
    R2( 82,  0, 68),
    R1( 83,  0),
    R1( 84,  35),
    R2( 85,  0, 45),
    R1( 86,  0),
    R1( 87,  12),
    R1( 88,  4),
    R1( 89,  0),
    R1( 90,  0),
    R1( 91,  14),
    R2( 92,  2, 70),
    R1( 93,  32),
    R1( 94,  41),
    R1( 95,  0),
    R1( 96,  5),
    R2( 97,  0, 81),
    R1( 98,  7),
    R1( 99,  12),
    R2(100,  0, 66),
    R2(101,  0, 19),
    R1(102,  32),
    R1(103,  14),
    R2(104,  1, 39),
    R1(105,  0),
    R1(106,  29),
    R1(107,  18),
    R2(108,  0, 34),
    R2(109,  0, 3),
    R1(110,  12),
    R1(111,  26),
    R2(112,  1, 4),
    R1(113,  0),
    R1(114,  21),
    R1(115,  40),
    R1(116,  15),
    R1(117,  32),
    R1(118,  29),
    R1(119,  0),
    R2(120,  2, 72),
    R1(121,  44),
    R1(122,  13),
    R1(123,  50),
    R1(124,  20),
    R1(125,  12),
    R1(126,  39),
    R1(127,  14),
    R2(128,  0, 28),
    R1(129,  48),
    R2(130,  0, 26),
    R1(131,  0),
    R1(132,  17),
    R2(133,  0, 3),
    R1(134,  25),
    R1(135,  0),
    R2(136,  0, 96),
    R2(137,  0, 131),
    R1(138,  27),
    R1(139,  10),
    R1(140,  7),
    R1(141,  24),
    R1(142,  4),
    R1(143,  34),
    R1(144,  12),
    R2(145,  0, 45),
    R1(146,  0),
    R2(147,  0, 135),
    R1(148,  7),
    R2(149,  0, 107),
    R2(150,  1, 101),
    R1(151,  26),
    R1(152,  39),
    R1(153,  12),
    R1(154,  65),
    R1(155,  0),
    R2(156,  1, 23),
    R1(157,  32),
    R1(158,  0),
    R1(159,  60),
    R2(160,  0, 150),
    R2(161,  0, 115),
    R1(162,  72),
    R2(163,  0, 23),
    R1(164,  25),
    R2(165,  2, 129),
    R1(166,  71),
    R2(167,  0, 59),
    R2(168,  0, 112),
    R1(169,  80),
    R1(170,  21),
    R1(171,  36),
    R1(172,  2),
    R1(173,  0),
    R1(174,  15),
    R2(175,  1, 70),
    R2(176,  0, 44),
    R2(177,  0, 21),
    R2(178,  0, 78),
    R1(179,  0),
    R1(180,  18),
    R1(181,  80),
    R1(182,  33),
    R1(183,  0),
    R2(184,  1, 162),
    R1(185,  60),
    R2(186,  0, 124),
    R1(187,  44),
    R2(188,  1, 9),
    R1(189,  0),
    R2(190,  1, 7),
    R1(191,  0),
    R2(192,  2, 110),
    R1(193,  8),
    R1(194,  13),
    R1(195,  18),
    R1(196,  31),
    R1(197,  64),
    R2(198,  0, 144),
    R1(199,  40),
    R1(200,  10),
    R2(201,  0, 25),
    R1(202,  23),
    R1(203,  6),
    R2(204,  0, 102),
    R1(205,  56),
    R2(206,  0, 70),
    R2(207,  0, 129),
    R1(208,  73),
    R1(209,  0),
    R1(210,  0),
    R1(211,  16),
    R2(212,  1, 168),
    R2(213,  0, 55),
    R1(214,  58),
    R1(215,  28),
    R2(216,  3, 25),
    R1(217,  52),
    R1(218,  49),
    R1(219,  48),
    R1(220,  46),
    R1(221,  0),
    R2(222,  1, 11),
    R1(223,  8),
    R1(224,  63),
    R1(225,  32),
    R2(226,  0, 32),
    R1(227,  108),
    R1(228,  5),
    R1(229,  20),
    R1(230,  0),
    R1(231,  0),
    R1(232,  92),
    R1(233,  0),
    R2(234,  0, 144),
    R1(235,  68),
    R1(236,  60),
    R1(237,  32),
    R1(238,  34),
    R1(239,  0),
    R2(240,  2, 6),
    R2(241,  0, 161),
    R1(242,  3),
    R1(243,  0),
    R2(244,  1, 48),
    R1(245,  0),
    R1(246,  39),
    R2(247,  0, 101),
    R2(248,  0, 184),
    R1(249,  80),
    R2(250,  0, 216),
    R1(251,  0),
    R2(252,  3, 30),
    R1(253,  92),
    R1(254,  0),
    R1(255,  54),
    R2(256,  0, 126),
    R1(257,  48),
    R2(258,  0, 180),
    R1(259,  20),
    R2(260,  3, 88),
    R1(261,  0),
    R2(262,  2, 188),
    R1(263,  94),
    R2(264,  1, 172),
    R1(265,  68),
    R1(266,  45),
    R1(267,  102),
    R2(268,  0, 72),
    R2(269,  0, 209),
    R1(270,  80),
    R1(271,  4),
    R2(272,  2, 108),
    R1(273,  0),
    R2(274,  1, 28),
    R1(275,  102),
    R1(276,  80),
    R2(277,  0, 71),
    R1(278,  43),
    R1(279,  68),
    R2(280,  1, 46),
    R1(281,  0),
    R2(282,  2, 18),
    R1(283,  34),
    R1(284,  48),
    R2(285,  0, 207),
    R2(286,  1, 166),
    R1(287,  108),
    R2(288,  0, 60),
    R1(289,  100),
    R1(290,  111),
    R1(291,  96),
    R1(292,  4),
    R1(293,  0),
    R2(294,  0, 78),
    R1(295,  56),
    R1(296,  1),
    R2(297,  2, 83),
    R1(298,  110),
    R1(299,  0),
    R2(300,  0, 250),
    R1(301,  80),
    R2(302,  1, 104),
    R1(303,  0),
    R2(304,  3, 129),
    R1(305,  72),
    R1(306,  0),
    R1(307,  122),
    R1(308,  13),
    R1(309,  0),
    R2(310,  0, 42),
    R1(311,  6),
    R2(312,  0, 294),
    R1(313,  56),
    R2(314,  2, 40),
    R1(315,  122),
    R2(316,  0, 24),
    R2(317,  1, 126),
    R1(318,  15),
    R1(319,  20),
    R2(320,  2, 78),
    R1(321,  96),
    R2(322,  1, 73),
    R1(323,  0),
    R1(324,  18),
    R1(325,  32),
    R1(326,  0),
    R1(327,  24),
    R1(328,  79),
    R1(329,  0),
    R1(330,  0),
    R1(331,  20),
    R2(332,  0, 64),
    R2(333,  0, 51),
    R1(334,  103),
    R2(335,  0, 11),
    R2(336,  3, 34),
    R2(337,  0, 99),
    R2(338,  0, 40),
    R2(339,  1, 8),
    R2(340,  1, 36),
    R1(341,  144),
    R1(342,  68),
    R1(343,  98),
    R1(344,  12),
    R1(345,  48),
    R1(346,  31),
    R1(347,  12),
    R2(348,  0, 24),
    R1(349,  116),
    R2(350,  1, 62),
    R2(351,  0, 63),
    R2(352,  0, 144),
    R1(353,  96),
    R1(354,  23),
    R1(355,  68),
    R1(356,  39),
    R1(357,  72),
    R1(358,  8),
    R1(359,  0),
    R2(360,  0, 96),
    R2(361,  0, 281),
    R2(362,  1, 153),
    R1(363,  50),
    R1(364,  26),
    R1(365,  84),
    R2(366,  0, 64),
    R1(367,  92),
    R1(368,  138),
    R2(369,  0, 73),
    R1(370,  74),
    R1(371,  0),
    R2(372,  0, 256),
    R1(373,  4),
    R2(374,  1, 312),
    R1(375,  0),
    R1(376,  61),
    R1(377,  148),
    R2(378,  1, 11),
    R1(379,  32),
    R2(380,  3, 101),
    R2(381,  0, 43),
    R1(382,  137),
    R1(383,  76),
    R2(384,  0, 214),
    R1(385,  160),
    R1(386,  0),
    R2(387,  0, 175),
    R2(388,  0, 338),
    R1(389,  88),
    R2(390,  1, 55),
    R2(391,  0, 251),
    R1(392,  172),
    R1(393,  32),
    R1(394,  58),
    R2(395,  0, 85),
    R2(396,  0, 112),
    R1(397,  112),
    R1(398,  0),
    R1(399,  60),
    R1(400,  197),
    R1(401,  184),
    R1(402,  153),
    R1(403,  178),
    R1(404,  67),
    R1(405,  116),
    R1(406,  115),
    R1(407,  94),
    R2(408,  1, 238),
    R2(409,  3, 96),
    R2(410,  2, 180),
    R1(411,  0),
    R1(412,  184),
    R1(413,  0),
    R2(414,  3, 136),
    R2(415,  0, 275),
    R2(416,  0, 218),
    R1(417,  128),
    R1(418,  35),
    R1(419,  0),
    R2(420,  0, 322),
    R2(421,  0, 107),
    R2(422,  0, 20),
    R2(423,  1, 220),
    R2(424,  1, 79),
    R1(425,  36),
    R1(426,  0),
    R2(427,  1, 90),
    R1(428,  183),
    R1(429,  0),
    R2(430,  2, 92),
    R1(431,  0),
    R2(432,  0, 48),
    R1(433,  44),
    R1(434,  85),
    R2(435,  1, 280),
    R1(436,  16),
    R1(437,  4),
    R1(438,  186),
    R1(439,  170),
    R2(440,  3, 134),
    R1(441,  0),
    R1(442,  137),
    R1(443,  0),
    R1(444,  183),
    R1(445,  196),
    R2(446,  0, 442),
    R1(447,  222),
    R2(448,  0, 152),
    R1(449,  208),
    R2(450,  1, 136),
    R1(451,  10),
    R1(452,  28),
    R1(453,  0),
    R1(454,  17),
    R1(455,  30),
    R2(456,  1, 208),
    R2(457,  0, 219),
    R1(458,  90),
    R1(459,  18),
    R1(460,  31),
    R2(461,  0, 89),
    R1(462,  137),
    R1(463,  32),
    R1(464,  81),
    R2(465,  0, 201),
    R1(466,  89),
    R1(467,  94),
    R2(468,  1, 377),
    R1(469,  112),
    R1(470,  0),
    R2(471,  1, 184),
    R2(472,  1, 211),
    R1(473,  0),
    R1(474,  60),
    R1(475,  44),
    R1(476,  24),
    R2(477,  0, 265),
    R1(478,  85),
    R2(479,  0, 139),
    R2(480,  7, 238),
    R1(481,  224),
    R2(482,  0, 284),
    R1(483,  0),
    R2(484,  2, 236),
    R2(485,  0, 271),
    R2(486,  0, 180),
    R1(487,  158),
    R1(488,  187),
    R1(489,  108),
    R2(490,  1, 286),
    R1(491,  0),
    R1(492,  14),
    R2(493,  0, 183),
    R2(494,  1, 2),
    R1(495,  0),
    R2(496,  2, 68),
    R2(497,  0, 199),
    R1(498,  62),
    R2(499,  0, 173),
    R2(500,  1, 77),
#endif  // 0
#endif  // ( BITS_PER_LONG > 32 )
    0  // (end)
};
// -------------------------
#undef R1
#undef R2


extern const ulong minweight_lhca_rule_len = ARRAY_LEN(minweight_lhca_rule);
