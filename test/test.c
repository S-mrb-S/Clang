#include <stdio.h>
#include <stdarg.h>

// ساختار برای نگهداری متغیرها
typedef struct {
    int var1;
    int var2;
} Variables;

// تابع برای چاپ اطلاعات
void print_values(const char *file, int line, Variables vars) {
    printf("File: %s, Line: %d\n", file, line);
    printf("Value of var1: %d\n", vars.var1);
    printf("Value of var2: %d\n", vars.var2);
}

// ماکرو برای استفاده آسان
#define PRINT_VALUES(vars) print_values(__FILE__, __LINE__, vars)

int main() {
    Variables vars = {5, 10};  // تعریف و مقداردهی به ساختار

    // استفاده از ماکرو برای چاپ مقادیر
    PRINT_VALUES(vars); // صدا زدن ماکرو بدون پارامتر جداگانه

    return 0;
}
