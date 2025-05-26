#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* El problema 3n + 1 dice:
        - Se te dara un numero n, para el cual:
            - Si n es PAR, haras n = n/2
            - Si n es IMPAR, haras n = 3n + 1
        - Realizaras estos pasos mientras n sea diferente de 1
        - Por cada paso, imprimiras el nuevo valor de n
        - Cuando n == 1, imprimiras la cantidad de veces que realizamos un paso
    */

    cout << "Ingresa el valor de n: ";
    int n; cin >> n; // Declaramos y leemos la variable 'n', nuestro numero inicial

    int contador = 0; // Declaramos la variable 'contador' con valor inicial 0
    while(n != 1){ // Mientras n sea diferente de 1...
        if(n % 2 == 0){ // Si n es PAR (divisible entre 2)
            n /= 2; // n = n/2
        }else{ // Si n es IMPAR (no divisible entre 2)
            n *= 3; // n = n*3 (3n)
            n++; // n = n + 1
        }
        cout << n << " "; // Imprimimos el valor de n despues de realizar este paso
        contador++; // Aumentamos el contador en 1
    }
    cout << endl << "Numero de pasos realizados: " << contador; // Imprimimos la cantidad de pasos que realizamos

    return 0;
}