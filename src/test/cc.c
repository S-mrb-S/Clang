#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 100

typedef struct {
    void *pointers[MAX_ALLOCATIONS];
    int count;
} MemoryManager;

#define ALLOCATE(manager, type, size) allocate_memory(manager, sizeof(type) * (size))
#define DEFINE_AND_ALLOCATE(manager, type, name, size) type *name = ALLOCATE(manager, type, size)
#define FREE_ALL(manager) free_all(manager)

void* allocate_memory(MemoryManager *manager, size_t size) {
    if (manager->count >= MAX_ALLOCATIONS) {
        fprintf(stderr, "Max allocations reached\n");
        return NULL;
    }
    void *ptr = malloc(size);
    if (ptr != NULL) {
        manager->pointers[manager->count++] = ptr;
    }
    return ptr;
}

void free_all(MemoryManager *manager) {
    for (int i = 0; i < manager->count; i++) {
        free(manager->pointers[i]);
    }
    manager->count = 0;  // Reset count after freeing
}

int main() {
    MemoryManager manager = { .count = 0 };

    // استفاده از ماکروی شخصی‌سازی شده برای تخصیص و تعریف متغیرها
    DEFINE_AND_ALLOCATE(&manager, int, arr1, 10);  // تخصیص حافظه برای آرایه arr1
    DEFINE_AND_ALLOCATE(&manager, int, arr2, 5);   // تخصیص حافظه برای آرایه arr2
    DEFINE_AND_ALLOCATE(&manager, double, arr3, 3); // تخصیص حافظه برای آرایه arr3

    if (arr1 == NULL || arr2 == NULL || arr3 == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        FREE_ALL(&manager);  // Make sure to free all before exiting
        return EXIT_FAILURE;
    }

    // مقداردهی به آرایه arr1
    for (int i = 0; i < 10; i++) {
        arr1[i] = i * 10;
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // آزادسازی تمام تخصیص‌های حافظه
    FREE_ALL(&manager);

    return EXIT_SUCCESS;
}
