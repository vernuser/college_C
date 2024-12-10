#include <iostream>
#include <cstdlib> // 包含 <cstdlib> 以使用 srand() 和 rand()

#define DELTA 0x9e3779b9
#define MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (key[(p&3)^e] ^ z)))

using namespace std;

void btea(uint32_t *v, int n, uint32_t const key[4]) {
    uint32_t y, z, sum;
    unsigned p, rounds, e;
    if (n > 1) {          /* Coding Part */
        rounds = 6 + 52 / n;
        sum = 0;
        z = v[n - 1];
        do {
            sum -= DELTA;
            e = (sum >> 2) & 3;
            for (p = 0; p < n - 1; p++) {
                y = v[p + 1];
                z = v[p] += MX;
            }
            y = v[0];
            z = v[n - 1] += MX;
        } while (--rounds);
    } else if (n < -1) {  /* Decoding Part */
        n = -n;
        rounds = 6 + 52 / n;
        sum = rounds * DELTA;
        y = v[0];
        do {
            e = (sum >> 2) & 3;
            for (p = n - 1; p > 0; p--) {
                z = v[p - 1];
                y = v[p] -= MX;
            }
            z = v[n - 1];
            y = v[0] -= MX;
            sum -= DELTA;
        } while (--rounds);
    }
}

int main() {
    uint32_t key[4] = {0x12345678, 0x9ABCDEF0, 0xFEDCBA98, 0x76543210};
    uint32_t v[] = { 0x3881C7CA, 0x5AEA661A, 0xC0E1397D, 0x3C415BB1, 0xDC546CB9, 0x5DC6BE6 };
    btea(v, -6, key);

    // 构建字符串
    string a;
    for (int i = 0; i < 24; ++i ) {
        char c = (char)v[i];
        a += c;
    }

    int v16[24];
    srand(0x18u);
    for (int i = 0; i < 24; ++i ) {
        v16[i] = rand() % 10 + 48;
    }
    for (int k = 0; k < 24; ++k ) {
        a[k] ^= (v16[k] - 48);
    }
    for (int j = 0; j < 24; ++j ) {
        if ( j % 2 ) {
            a[j] -= 2;
        } else {
            a[j] += 3;
        }
    }

    cout << a << endl;
    return 0;
}
