//
// Created by ann on 2024/5/25.
//
#include <stdio.h>
#include <string.h>

int main() {
    char cmp[] = "FSBBhKfIDirfZlEfVbaShZyKom";
    char v16[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char v10[] = "abcdefghijklmnopqrstuvwxyz";
    char v4[] = "0123456789+/-=!#&*()?;:*^%";
    char v3[] = "DABBZXQESVFRWNGTHYJUMKIOLPC";
    int len = strlen(cmp);
    int v22;
    char v1;

    for (int i = 0; i < len; i++) {
        for (int j = 32; j < 127; j++) {
            if (j - v3[i] <= 0) {
                continue;
            } else {
                v22 = j - v3[i];
                if (v22 > 25) {
                    if (v22 > 51) {
                        v1 = v4[v22 - 52];
                    } else {
                        v1 = v10[v22 - 26];
                    }
                    if (v1 == cmp[i]) {
                        printf("%c", j);
                        break;
                    }
                } else {
                    if (v16[v22] == cmp[i]) {
                        printf("%c", j);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
