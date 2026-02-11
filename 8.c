#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data d;

    d.i = 10;
    printf("Integer: %d\n", d.i);

    d.f = 5.5;
    printf("Float: %f\n", d.f);

    d.c = 'A';
    printf("Character: %c\n", d.c);

    printf("Size of union: %lu\n", sizeof(d));
    return 0;
}
