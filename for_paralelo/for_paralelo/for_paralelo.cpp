#include <stdio.h>
#include <omp.h>

#define N 1000000

int main() {
    int suma = 0;
    double start_time, end_time;

    // Iniciar el temporizador
    start_time = omp_get_wtime();

#pragma omp parallel for reduction(+:suma)
    for (int i = 1; i <= N; i++) {
        suma += i;
    }

    // Detener el temporizador
    end_time = omp_get_wtime();

    // Imprimir el resultado y el tiempo de ejecución
    printf("La suma de los primeros %d números naturales es: %d\n", N, suma);
    printf("Tiempo de ejecución: %f segundos\n", end_time - start_time);

    return 0;
}
