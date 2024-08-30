#include <stdio.h>
#include <omp.h>

#define FACTORIAL_N 10
#define FIBONACCI_N 20
#define ARRAY_SIZE 10

// Función para calcular el factorial de un número
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Función para generar la serie de Fibonacci hasta el n-ésimo término
void fibonacci(int n, long long* fib) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Función para encontrar el máximo en un arreglo
int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    long long factorial_result;
    long long fibonacci_series[FIBONACCI_N];
    int array[ARRAY_SIZE] = { 4, 9, 2, 7, 6, 8, 3, 1, 5, 0 };
    int max_in_array;

    // Iniciar el temporizador
    double start_time = omp_get_wtime();

#pragma omp parallel sections
    {
#pragma omp section
        {
            factorial_result = factorial(FACTORIAL_N);
        }

#pragma omp section
        {
            fibonacci(FIBONACCI_N, fibonacci_series);
        }

#pragma omp section
        {
            max_in_array = find_max(array, ARRAY_SIZE);
        }
    }

    // Detener el temporizador
    double end_time = omp_get_wtime();

    // Imprimir los resultados
    printf("Factorial de %d es: %lld\n", FACTORIAL_N, factorial_result);
    printf("Serie de Fibonacci hasta %d términos: ", FIBONACCI_N);
    for (int i = 0; i < FIBONACCI_N; i++) {
        printf("%lld ", fibonacci_series[i]);
    }
    printf("\n");
    printf("Máximo en el arreglo es: %d\n", max_in_array);
    printf("Tiempo de ejecución: %f segundos\n", end_time - start_time);

    return 0;
}
