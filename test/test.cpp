#include <iostream>

class Variables {
public:
    int var1;
    int var2;

    // سازنده پیش‌فرض
    Variables() : var1(0), var2(0) {}

    // سازنده برای دریافت یک مقدار تنها
    Variables(int v) : var1(v), var2(0) {
        print_values();
    }

    // عملگر تبدیل برای تبدیل int به Variables
    Variables& operator=(int value) {
        var1 = value;
        var2 = 0; // یا می‌توانید مقدار دیگری به var2 اختصاص دهید
        print_values();
        return *this;
    }

    // تابع برای چاپ اطلاعات
    void print_values() const {
        std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl;
        std::cout << "Value of var1: " << var1 << std::endl;
        std::cout << "Value of var2: " << var2 << std::endl;
    }
};

int main() {
    // ایجاد شیء و ارسال یک مقدار
    Variables vars = 8;  // تعریف شیء با سازنده پیش‌فرض
    vars = 5;       // تخصیص مقدار 5 به var1

    return 0;
}
