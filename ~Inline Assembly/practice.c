#include <stdio.h>
#include <time.h>
long factorial(long n)
{
long result;
__asm__ volatile (
"mov $1, %0 \n\t" // result = 1
"test %1, %1 \n\t" // if (n == 0)
"jz 2f \n\t" // jump to end
"1: \n\t"
"imul %1, %0 \n\t" // result *= n
"dec %1 \n\t" // n--
"jnz 1b \n\t" // loop if n != 0
"2: \n\t"
: "+r"(result), "+r"(n)
:
: "cc"
);
return result;
}

int add(int a, int b){
    // adds a and b
    __asm__ volatile (
        "add %1, %0"
        :"+r"(a)
        :"r"(b)
        );
    return a;
}
long power(long a, long b){
    // gives a^b
    long result = 1;
    if (b<1) return result;
    __asm__ volatile(
        "1: \n\t"
        "imul %1, %0 \n\t"
        "dec %2 \n\t"
        "jnz 1b \n\t"
        :"+r"(result)
        :"r"(a), "r"(b)
        : "cc"
    );
    return result;
}

long fibonacci_asm(long n){
    // gives nth fabonacci number
    if (n==1) return 0;
    if (n==2) return 1;
    long a = 0, b = 1, num;
    __asm__ volatile(
        "mov %2, %0 \n\t"
        "sub $2, %3 \n\t"
        "1: \n\t"
        "mov %2, %0 \n\t"
        "add %1, %0 \n\t"
        "mov %2, %1 \n\t"
        "mov %0, %2 \n\t"
        "dec %3 \n\t"
        "jnz 1b \n\t"
        :"+r"(num), "+r"(a), "+r"(b), "+r"(n)
        :
        :"cc"
    );
    return num;
}

long fibonacci_c(long n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    long a = 0, b = 1, num;
    for (long i = 3; i <= n; i++) {
        num = a + b;
        a = b;
        b = num;
    }
    return num;
}


void fabonacci_time_comparison() {
    long n = 70;

    clock_t start_c = clock();
    long result_c = fibonacci_c(n);
    clock_t end_c = clock();
    double time_c = (double)(end_c - start_c) / CLOCKS_PER_SEC;
    
    clock_t start_asm = clock();
    long result_asm = fibonacci_asm(n);
    clock_t end_asm = clock();
    double time_asm = (double)(end_asm - start_asm) / CLOCKS_PER_SEC;
    
    printf("C Fibonacci result: %ld\n", result_c);
    printf("Assembly Fibonacci result: %ld\n", result_asm);
    printf("C function time: %f seconds\n", time_c);
    printf("Assembly function time: %f seconds\n", time_asm);
}

int max(int a, int b){
    __asm__ volatile(
        "cmp %0, %1 \n\t"
        "jle 1f \n\t"
        "mov %1, %0 \n\t"
        "1: \n\t"
        :"+r"(a)
        :"r"(b)
        :"cc"
    );
    return a;
}

int main(){
    printf("%d", max(20, -30));
    return 0;
}