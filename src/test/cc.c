#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 100

typedef struct
{
    void *pointers[MAX_ALLOCATIONS];
    int count;
} MemoryManager;

#define ALLOCATE(manager, type, size) allocate_memory(manager, sizeof(type) * (size))

#define Int(name, size) int *name = (int *)ALLOCATE(&manager, int, size)
#define Double(name, size) double *name = (double *)ALLOCATE(&manager, double, size)

#define FREE_ALL(manager) free_all(manager)

void *allocate_memory(MemoryManager *manager, size_t size)
{
    if (manager->count >= MAX_ALLOCATIONS)
    {
        fprintf(stderr, "Max allocations reached\n");
        return NULL;
    }
    void *ptr = malloc(size);
    if (ptr != NULL)
    {
        manager->pointers[manager->count++] = ptr;
    }
    return ptr;
}

void free_all(MemoryManager *manager)
{
    for (int i = 0; i < manager->count; i++)
    {
        free(manager->pointers[i]);
    }
    manager->count = 0; // Reset count after freeing
}

int main()
{
    MemoryManager manager = {.count = 0};

    Int(arr1, 10);
    Int(arr2, 5);
    Double(arr3, 3);

    if (arr1 == NULL || arr2 == NULL || arr3 == NULL)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        FREE_ALL(&manager);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 10; i++)
    {
        arr1[i] = i * 10;
        printf("%d ", arr1[i]);
    }
    printf("\n");

    FREE_ALL(&manager);

    return EXIT_SUCCESS;
}
