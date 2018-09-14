#include <iostream>
#include <unordered_set>
#include <fstream>

using namespace std;
unordered_set<int> primes = {0x2, 0x3, 0x1003, 0x5, 0x805, 0x7, 0x1807, 0xb, 0xd, 0x100f, 0x80f, 0x11, 0x2011, 0x13,
                             0x1813, 0x815, 0x17, 0x201b, 0x181d, 0x1d, 0x101f, 0x1f, 0x1021, 0x821, 0x823, 0x201d,
                             0x25, 0x1025, 0x2027, 0x827, 0x29, 0x2029, 0x2b, 0x102b, 0x202d, 0x829, 0x2f, 0x2033,
                             0x833, 0x35, 0x1835, 0x1837, 0x1039, 0x183b, 0x3b, 0x3d, 0x103d, 0x83f, 0x103f, 0x841,
                             0x1843, 0x43, 0x2047, 0x47, 0x1849, 0x49, 0x204d, 0x184d, 0x4f, 0x851, 0x2051, 0x53, 0x853,
                             0x1855, 0x1051, 0x859, 0x59, 0x85d, 0x85f, 0x205f, 0x61, 0x2063, 0x65, 0x2065, 0x1867,
                             0x67, 0x1069, 0x869, 0x6b, 0x2069, 0x6d, 0x871, 0x1871, 0x1073, 0x71, 0x2077, 0x1877,
                             0x1079, 0x107b, 0x207d, 0x187d, 0x187f, 0x7f, 0x83, 0x883, 0x1085, 0x1885, 0x1087, 0x89,
                             0x2089, 0x8b, 0x188f, 0x1091, 0x1093, 0x95, 0x97, 0x89b, 0x189b, 0x109d, 0x9d, 0x89f,
                             0x189d, 0x20a1, 0xa3, 0x10a3, 0x8a5, 0x10a5, 0x18a7, 0xa7, 0x20ab, 0x8ad, 0xad, 0x10af,
                             0x18ad, 0x10b1, 0x20b1, 0xb3, 0x18b3, 0xb5, 0x20b9, 0x18b9, 0x10bb, 0x8bd, 0xbf, 0x8bf,
                             0x18c1, 0xc1, 0x8c3, 0x20c3, 0x20c5, 0xc5, 0x18c7, 0xc7, 0x10c9, 0x10c1, 0x8cb, 0x18d1,
                             0xd3, 0x18d7, 0x18d9, 0x8db, 0x8dd, 0xdf, 0x18df, 0x8e1, 0xe3, 0x20e3, 0x18e5, 0xe5,
                             0x20e7, 0x10e7, 0x8e9, 0xe9, 0x18eb, 0x20ed, 0xef, 0x8ef, 0xf1, 0x10f1, 0x10f3, 0x20ef,
                             0x18f5, 0x8f5, 0x8f9, 0x1fff, 0x20fb, 0x18fd, 0x10fd, 0x20ff, 0xfb, 0x101, 0x1105, 0x905,
                             0x107, 0x907, 0x110b, 0x10d, 0x210d, 0x10f, 0x2113, 0x1915, 0x1115, 0x115, 0x119, 0x11b,
                             0x191b, 0x91d, 0x923, 0x925, 0x125, 0x1127, 0x92b, 0x112d, 0x92f, 0x1931, 0x133, 0x1933,
                             0x935, 0x2135, 0x137, 0x139, 0x1139, 0x13d, 0x2141, 0x943, 0x1145, 0x1945, 0x1147, 0x2149,
                             0x949, 0x14b, 0x1949, 0x94d, 0x94f, 0x214f, 0x1951, 0x151, 0x955, 0x2159, 0x1159, 0x195b,
                             0x15b, 0x15d, 0x215b, 0x115f, 0x95f, 0x161, 0x215f, 0x1163, 0x167, 0x1169, 0x96b, 0x116f,
                             0x16f, 0x971, 0x2173, 0x175, 0x977, 0x1979, 0x17b, 0x217d, 0x17f, 0x1981, 0x1181, 0x1183,
                             0x2185, 0x185, 0x985, 0x989, 0x18d, 0x118d, 0x98f, 0x191, 0x1993, 0x2195, 0x2197, 0x1997,
                             0x1999, 0x199, 0x119b, 0x99b, 0x21a1, 0x11a1, 0x1a3, 0x19a3, 0x1a5, 0x11a5, 0x11a7, 0x9a3,
                             0x19a9, 0x9a9, 0x19ab, 0x11ab, 0x9ad, 0x1af, 0x21af, 0x1b1, 0x19b1, 0x21b3, 0x19b5, 0x21b5,
                             0x1b7, 0x1bb, 0x21c1, 0x1c1, 0x11c3, 0x11c5, 0x21c7, 0x19c7, 0x1c9, 0x9c7, 0x1cd, 0x1cf,
                             0x19cf, 0x11d1, 0x1d3, 0x21d7, 0x11d7, 0x9d9, 0x19db, 0x21dd, 0x1df, 0x9e3, 0x21e5, 0x1e7,
                             0x11e7, 0x21e9, 0x1eb, 0x9eb, 0x19ed, 0x11ef, 0x9ef, 0x21f1, 0x1f3, 0x11f5, 0x9f5, 0x9f7,
                             0x1f7, 0x21f5, 0x11fb, 0x21fb, 0x9fd, 0x1fd, 0x19fd, 0x1a03, 0x2203, 0x1a05, 0x2209, 0x209,
                             0x20b, 0x120d, 0x220f, 0x1a11, 0xa13, 0x1a17, 0x221b, 0x21d, 0x121d, 0xa1f, 0x121f, 0xa21,
                             0x1a21, 0x223, 0x1223, 0x2225, 0x1a23, 0x2221, 0x1229, 0x222b, 0x122b, 0x22d, 0x1a2d,
                             0x1a2f, 0xa31, 0x1231, 0x233, 0x2231, 0x1a35, 0x1237, 0xa39, 0x2239, 0x23b, 0x239, 0xa3d,
                             0x1a3f, 0x1241, 0x241, 0x1247, 0xa49, 0x224b, 0x24b, 0x1a4d, 0x224f, 0x1a51, 0x251, 0x1253,
                             0x257, 0xa57, 0x259, 0x25f, 0x125f, 0xa61, 0xa63, 0x2263, 0x265, 0xa67, 0x2267, 0x1a69,
                             0x269, 0x1a6b, 0x26b, 0xa6f, 0x1271, 0x1273, 0x2273, 0x2275, 0xa75, 0x277, 0x1279, 0xa7b,
                             0x1a7b, 0x127d, 0x1a7d, 0x227f, 0xa7f, 0x281, 0xa81, 0x283, 0xa85, 0x2285, 0x2287, 0x287,
                             0x1a89, 0x1a87, 0xa8b, 0x28d, 0x128f, 0x2291, 0xa93, 0x1a93, 0x295, 0x293, 0xa97, 0x1297,
                             0xa99, 0x229d, 0xa9f, 0x229f, 0x2a1, 0x22a3, 0x2a5, 0x1aa7, 0xaa9, 0xaab, 0x2ab, 0x1aad,
                             0x1aab, 0x12af, 0x1ab1, 0x2b3, 0x12b3, 0xab5, 0x12b5, 0x22b7, 0x1ab9, 0x12b9, 0x2bd, 0xabd,
                             0x12bf, 0x22bd, 0x12c1, 0xac1, 0x2c5, 0x1ac9, 0x12cd, 0xacf, 0x1acf, 0x12d1, 0x2cf, 0x1ad5,
                             0x2d7, 0x1ad7, 0xad9, 0x22db, 0x2dd, 0x12df, 0x22e1, 0x1ae3, 0x2e3, 0x22e5, 0xae5, 0xae7,
                             0x2e7, 0xaed, 0x22ed, 0x2ef, 0xaf1, 0x1af3, 0xaf3, 0x2f5, 0x22f7, 0x2f9, 0x1afb, 0x12fd,
                             0x1aff, 0x301, 0xb03, 0x2303, 0x1b05, 0x305, 0x1307, 0x2309, 0x230b, 0x130d, 0xb11, 0x313,
                             0xb15, 0x1319, 0xb1b, 0x31d, 0xb23, 0x1b23, 0x1b25, 0x1327, 0x2327, 0xb29, 0x329, 0x32b,
                             0x2329, 0xb2d, 0x132d, 0x232f, 0x1b2f, 0x1b31, 0x2333, 0x335, 0x2335, 0x1b37, 0x337,
                             0x1337, 0x1b3b, 0x33b, 0x33d, 0xb3f, 0x1b41, 0x1343, 0x1345, 0x2345, 0x1b47, 0xb47, 0x1349,
                             0x347, 0x1b4f, 0x134f, 0x2351, 0xb51, 0x2353, 0x355, 0x1b55, 0xb57, 0x1357, 0x359, 0x2359,
                             0x35b, 0x1b59, 0xb5d, 0x135d, 0x35f, 0x2363, 0x1b65, 0xb65, 0x1367, 0x1369, 0x1b6b, 0x236b,
                             0x36d, 0x136d, 0xb6f, 0x371, 0x373, 0x1b73, 0x377, 0xb7b, 0x137b, 0x1b7f, 0x1381, 0x2383,
                             0x1b83, 0x1387, 0xb89, 0x138b, 0x38b, 0xb8d, 0x38f, 0x238f, 0x1391, 0x1b91, 0xb93, 0x1393,
                             0x2395, 0x397, 0xb99, 0xb9b, 0x139d, 0x1b9d, 0x139f, 0x3a1, 0x23a7, 0x1ba7, 0x3a9, 0x23ad,
                             0x3ad, 0x13af, 0x23b1, 0x3b3, 0xbb7, 0x3b9, 0xbb9, 0x13bb, 0x23bf, 0x1bbf, 0xbc3, 0x13c3,
                             0x1bc5, 0x23c5, 0x3c7, 0x23c9, 0xbcb, 0x3cb, 0xbcf, 0x3d1, 0x1bd1, 0x13d5, 0x23d5, 0x1bd7,
                             0x3d7, 0x1bd9, 0x13d9, 0x23dd, 0xbdd, 0x13df, 0x3df, 0xbe1, 0x23e3, 0x3e5, 0xbe9, 0x13eb,
                             0x13ed, 0x1bef, 0x23ef, 0x3f1, 0x13f3, 0x23f3, 0xbf5, 0x3f5, 0x1bf7, 0x13f9, 0x23f9, 0xbfb,
                             0x3fb, 0x3fd, 0x13ff, 0x2405, 0xc07, 0x407, 0x1c09, 0x409, 0xc0b, 0x240b, 0x40f, 0xc11,
                             0x1c13, 0x2417, 0x1c19, 0x2419, 0x141b, 0x41b, 0x419, 0x1421, 0xc25, 0x425, 0x427, 0x1c27,
                             0x2429, 0x1c2b, 0x1c2d, 0x42d, 0xc2f, 0x142f, 0xc31, 0x1433, 0x1c33, 0x143b, 0x1c3d,
                             0x243d, 0x43f, 0xc41, 0x2441, 0x443, 0x2443, 0x445, 0x1445, 0x1c45, 0x449, 0x1c4b, 0x244d,
                             0x144d, 0x44f, 0x1c4f, 0x1c55, 0x455, 0x1459, 0xc5b, 0x45d, 0x245f, 0xc5f, 0xc61, 0x463,
                             0x2467, 0x469, 0x146b, 0x246b, 0xc6d, 0x146f, 0x1471, 0xc73, 0x1c73, 0x1475, 0xc77, 0x2479,
                             0x247d, 0x247f, 0x47f, 0x481, 0x1c81, 0xc83, 0x2485, 0xc89, 0x1c8b, 0x48b, 0x148d, 0x1c8d,
                             0xc91, 0x493, 0xc95, 0x1499, 0x1c99, 0x249b, 0xc9d, 0x49d, 0x149f, 0x14a1, 0x24a1, 0x1ca3,
                             0x4a3, 0x1ca5, 0x4a9, 0x24af, 0x4b1, 0x14b1, 0xcb3, 0xcb5, 0x1cb5, 0x14b7, 0x1cb7, 0xcb9,
                             0x24b5, 0xcbb, 0x24bb, 0x4bd, 0x14bd, 0x4c1, 0x24c5, 0x4c7, 0xcc7, 0x1cc9, 0x14cb, 0x24cb,
                             0x4cd, 0x24cd, 0x4cf, 0x14d5, 0x4d5, 0x24d7, 0x24d9, 0x24dd, 0x24df, 0x1ce1, 0x4e1, 0x14e3,
                             0xce3, 0xce5, 0x14e7, 0xceb, 0x4eb, 0xcf1, 0x1cf3, 0x24f5, 0x24f7, 0xcf7, 0x1cf9, 0x24fb,
                             0xcfb, 0x4fd, 0x4ff, 0xd01, 0x2501, 0xd03, 0x503, 0x1505, 0x2507, 0x1d09, 0x509, 0x150b,
                             0x50b, 0xd0f, 0x1511, 0x511, 0xd13, 0x2513, 0x515, 0x1517, 0x517, 0x2519, 0x1d1b, 0x51b,
                             0xd1f, 0x151f, 0xd21, 0x1d21, 0x1d23, 0x1525, 0x2527, 0x527, 0x529, 0x1529, 0x152b, 0xd2b,
                             0xd2d, 0x52f, 0x2531, 0x1d35, 0x1537, 0x1d39, 0xd3d, 0x153d, 0x1d3f, 0xd3f, 0x1541, 0x1d41,
                             0x1543, 0x2543, 0x253d, 0x1549, 0x1d4b, 0x254b, 0xd4f, 0x254f, 0x551, 0x1d53, 0xd55, 0x557,
                             0x1d5d, 0x55d, 0x155f, 0x1d63, 0x565, 0x1565, 0x1567, 0xd69, 0x1d69, 0x156b, 0x1d71,
                             0x2573, 0x1d75, 0x577, 0xd79, 0x1d7b, 0x157d, 0x1d7d, 0x157f, 0xd81, 0x581, 0x1583, 0x2581,
                             0xd85, 0xd87, 0x1d87, 0x1d89, 0xd8b, 0x258d, 0xd8d, 0x58f, 0x158f, 0x1591, 0x2593, 0x593,
                             0x595, 0x1d95, 0x1597, 0x2597, 0x1d99, 0x599, 0x159b, 0x259d, 0x1d9f, 0x259f, 0x59f, 0xda3,
                             0x1da5, 0x1da7, 0x5a7, 0xdab, 0x5ab, 0x5ad, 0x25ab, 0x25b1, 0x5b3, 0x1db3, 0x15b5, 0xdb7,
                             0x1db7, 0x15bb, 0xdbd, 0x25bd, 0x5bf, 0x15c1, 0x15c5, 0x1dc5, 0xdc7, 0x5c9, 0xdc9, 0x5cb,
                             0x25cd, 0x15cd, 0x5cf, 0xdcd, 0x25cf, 0x5d1, 0xdd3, 0x5d5, 0xdd5, 0x1dd7, 0x15d7, 0x25d9,
                             0xddb, 0x1ddb, 0x5db, 0x25e1, 0x1de1, 0xde5, 0x5e7, 0xde7, 0x5f3, 0xdf3, 0x1df5, 0x15f7,
                             0x25f7, 0x25f9, 0x1df9, 0x5fb, 0xdfd, 0xdff, 0x1e01, 0x2605, 0x607, 0x1607, 0xe09, 0x1609,
                             0x260b, 0x1e0b, 0x60d, 0x1e07, 0x160f, 0x260f, 0x611, 0x1e13, 0x1613, 0x1615, 0x2615,
                             0x617, 0xe17, 0x1619, 0x1e17, 0x161b, 0xe1d, 0x61f, 0xe21, 0x623, 0x1625, 0x1e25, 0xe27,
                             0x2627, 0x2629, 0x1e2b, 0x62b, 0x62f, 0xe2f, 0x1e2f, 0x1633, 0x2635, 0xe35, 0x1639, 0xe3b,
                             0x263b, 0x63d, 0x163d, 0x263f, 0x1e3d, 0x641, 0x1645, 0x647, 0x1e49, 0x649, 0xe4b, 0x264b,
                             0x1e4d, 0x64d, 0x1e4f, 0x164f, 0x2653, 0x653, 0x655, 0x1655, 0xe57, 0xe59, 0x2659, 0x65b,
                             0xe5d, 0x2665, 0x665, 0x1669, 0x2669, 0xe6b, 0x1e6d, 0x166d, 0x166f, 0x266f, 0xe71, 0x1e71,
                             0x1675, 0xe75, 0x679, 0x267b, 0xe7d, 0x67f, 0x2681, 0x683, 0x2683, 0x685, 0xe87, 0x1e89,
                             0x1e8f, 0xe8f, 0x268f, 0x1693, 0x1e95, 0xe95, 0x1697, 0xe9b, 0x269b, 0x69d, 0x169f, 0x269f,
                             0x1ea1, 0x6a1, 0x6a3, 0x16a9, 0x1ead, 0x26ad, 0x16af, 0x6ad, 0xeb1, 0x26b3, 0x16b5, 0xeb7,
                             0x6b9, 0xeb9, 0x6bb, 0x1ebb, 0x16bd, 0x1ec1, 0x16c3, 0x26c3, 0x1ec5, 0x6c5, 0x1ec7, 0xec3,
                             0x26c9, 0x1ecb, 0x26cb, 0x6cd, 0x16cf, 0xed1, 0x6d3, 0x16d3, 0xed5, 0x26d5, 0x16d9, 0x6d9,
                             0x16db, 0xedb, 0x26dd, 0x1edd, 0x6df, 0x16e1, 0x1ee3, 0x16e5, 0x16eb, 0xeed, 0x16ed, 0xeef,
                             0x26ef, 0x6f1, 0x1eef, 0x26f5, 0x16f7, 0x6f7, 0x16f9, 0xef9, 0x6fb, 0x1ef7, 0x1efd, 0x6fd,
                             0x1f01, 0xf07, 0x959, 0x709, 0x1709, 0xf0b, 0x1f0d, 0xf0d, 0x1f0f, 0x170f, 0x713, 0xf17,
                             0x1f1b, 0x71f, 0x1723, 0xf25, 0x727, 0x1727, 0xf29, 0xf31, 0x1733, 0x737, 0x1f39, 0x1741,
                             0xf43, 0x745, 0xf47, 0x1f49, 0x74b, 0x1f4b, 0xf4d, 0xf4f, 0x74f, 0x751, 0x1f51, 0xf53,
                             0x755, 0x757, 0xf59, 0xf5b, 0x175d, 0x761, 0x1763, 0x1f67, 0xf67, 0xf6b, 0x76d, 0x773,
                             0x1f75, 0x1777, 0x779, 0x177b, 0x1f7b, 0xf7f, 0x1f85, 0x78b, 0x78d, 0x178d, 0x1f91, 0x1795,
                             0xf95, 0x1f97, 0x1f99, 0x179b, 0x79d, 0x1f9d, 0x79f, 0x179f, 0xfa1, 0xfa3, 0x1fa5, 0x17a5,
                             0xfa7, 0xfad, 0x1faf, 0x17b3, 0xfb3, 0xfb5, 0x7b5, 0x1fb5, 0x17b9, 0xfbb, 0x7bb, 0x1fbb,
                             0x17bf, 0x7c3, 0x7c9, 0x17c9, 0x17cb, 0x7cd, 0x7cf, 0xfd1, 0xfd3, 0x1fd3, 0x17d5, 0x7d3,
                             0xfd9, 0x7db, 0x7e1, 0x1fe1, 0x17e1, 0x1fe7, 0x17e9, 0xfe9, 0x7eb, 0x1feb, 0x7ed, 0xfef,
                             0x1ff3, 0x17f3, 0x17f5, 0x7f7, 0xffb, 0xffd, 0x17ff};

bool is_prime(int n) {
    return primes.find(n) != primes.end();
}

int main() {
    ifstream in("input.txt");
    int test_case;
    for (in >> test_case; 0 < test_case; test_case--) {
        int n;
        in >> n;
        for (int k = n / 2; 1 < k; k--) {
            if (is_prime(k) && is_prime(n - k)) {
                cout << k << ' ' << n - k << endl;
                break;
            }
        }
    }
    return 0;
}