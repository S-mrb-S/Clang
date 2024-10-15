#include <stdio.h>
#include <stdlib.h>

#define ALLOCATE(type, size) (type *)malloc(sizeof(type) * (size))
#define FREE(ptr) do { free(ptr); ptr = NULL; } while(0)

int main() {
    int *arr = ALLOCATE(int, 10);

    for (int i = 0; i < 10; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }
    printf("n");

    FREE(arr);

    return 0;
}
