#include <iostream>
#include <omp.h>

#define N 10

int main() {
    int shared_var = 0;  // Variable compartida

    // Variable privada para cada hilo
    // Se declara aquí para que se inicialice en cada iteración
    int private_var = 0;

#pragma omp parallel shared(shared_var) private(private_var)
    {
#pragma omp for
        for (int i = 0; i < N; i++) {
            // Modificación de la variable compartida
            shared_var += 1;

            // Modificación de la variable privada
            private_var += 1;

            // Imprimir valores dentro del ciclo para ver la ejecución en paralelo
            std::cout << "Iteración " << i
                << ": shared_var = " << shared_var
                << ", private_var = " << private_var
                << ", Thread ID = " << omp_get_thread_num() << std::endl;
        }
    }

    // Imprimir valores finales después del ciclo
    std::cout << "Valor final de shared_var: " << shared_var << std::endl;
    std::cout << "Valor final de private_var: " << private_var << std::endl;

    return 0;
}
