#include <stdio.h>
#include <time.h>

double factorial(double n)
{
    if (n <= 1) // Handles 0 and 1
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int n;
    clock_t start, end;

    printf("Enter a number: ");
    if(scanf("%d", &n) != 1) return 1;

    start = clock();
    double result = factorial((double)n);
    end = clock();

    // %g is the best choice for factorials; it keeps small numbers 
    // readable and automatically switches to 1.23e+10 for huge ones.
    printf("Factorial = %g\n", result); 
    printf("Execution Time = %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

//iteration vs recursion difference between --> exam question