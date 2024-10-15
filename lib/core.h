// core.h

#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>

typedef int Int;

// Voids
typedef void fn;
typedef void Fn;
typedef void func;
typedef void Func;
typedef void function;
typedef void Function;

#define null ((fn*)0)
#define Null ((fn*)0)

#define MAX_ALLOCATIONS 100

typedef struct {
    fn *pointers[MAX_ALLOCATIONS];
    int count;
} MemoryManager;

#define ALLOCATE(manager, type, size) allocate_memory(manager, sizeof(type) * (size))

#define Int(name, size) int *name = (int*)ALLOCATE(&manager, int, size)
#define Double(name, size) double *name = (double*)ALLOCATE(&manager, double, size)

#define FREE_ALL(manager) free_all(manager)

// Function declarations
fn* allocate_memory(MemoryManager *manager, size_t size);
fn free_all(MemoryManager *manager);
fn error(const char *msg);
fn panic(const char *message);

#endif // CORE_H
