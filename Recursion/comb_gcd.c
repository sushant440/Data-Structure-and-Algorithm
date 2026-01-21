#include <stdio.h>
#include <time.h>

int findGCD_ite(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findGCD_rec(int a, int b) {
    if (b == 0) return a;
    return findGCD_rec(b, a % b);
}

int main() {
    int num1, num2;
    clock_t start, end;
    double time_ite, time_rec;
    long iterations = 10000000; // 10 Million runs to see a difference

    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) return 1;

    // --- Benchmark Iteration ---
    start = clock();
//     for(long i = 0; i < iterations; i++) {
//       findGCD_ite(num1, num2);  
//  }
    findGCD_ite(num1, num2);
    end = clock();
    time_ite = ((double)(end - start)) / CLOCKS_PER_SEC;

    // --- Benchmark Recursion ---
    start = clock();
    // for(long i = 0; i < iterations; i++) {
    //     findGCD_rec(num1, num2);
    // }
    findGCD_rec(num1, num2);
    end = clock();
    time_rec = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nResults:\n");
    printf("GCD: %d\n", findGCD_ite(num1, num2));
    printf("Iteration Time: %f seconds\n", time_ite);
    printf("Recursion Time: %f seconds\n", time_rec);

    return 0;
}