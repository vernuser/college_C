#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytesd(byte_pointer head, size_t len) {
    size_t i;
    for (i = len; i > 0; i--)
        printf("%.2x ", head[i - 1]);  // 使用%.2x来显示字节
    printf("\n");
}

void show_float(float x) {
    show_bytesd((byte_pointer)&x, sizeof(float));
}

void show_double(double x) {  // 参数类型应该是double
    show_bytesd((byte_pointer)&x, sizeof(double));
}

int main() {
    printf("输出单精度浮点数存储格式: \n");
    float a = 20.59375f;  // 使用f来明确表示float
    show_float(a);

    printf("输出双精度浮点数存储格式: \n");
    double b = 20.59375;
    show_double(b);

    return 0;
}