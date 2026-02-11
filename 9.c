#include <stdio.h>

struct TestStruct {
    int i;
    float f;
    char c;
};

union TestUnion {
    int i;
    float f;
    char c;
};

int main() {
    printf("Size of Structure: %lu\n", sizeof(struct TestStruct));
    printf("Size of Union: %lu\n", sizeof(union TestUnion));
    return 0;
}
