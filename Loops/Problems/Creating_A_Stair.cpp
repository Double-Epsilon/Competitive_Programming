#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* El problema "Crear una escalera" dice:
        - Se te dara un numero n, el cual sera la cantidad de escalones que debe tener nuestra escalera
        - Deberas imprimir con asteriscos la escalera de tamaño n
    */

    cout << "Ingresa el valor de n: ";
    int n; cin >> n; // Declaramos y leemos la variable 'n', la cantidad de escalones

    for(int i=1; i<=n; i++){ // Creamos un bucle for, donde iniciamos en 1 y ejecutamos mientras 'i' sea menor o igual a 'n'
        for(int j=1; j<=i; j++){ // Creamos un segundo for, donde iniciamos en 1 y ejecutamos mientras 'j' sea menor o igual a 'i'
            cout << "*"; // Imprimimos un asterisco
        }
        cout << endl; // Imprimimos un salto de linea (fin del escalon i)
    }

    /* ¿Que hacemos?:
        - Primero, creamos un bucle for que se ejecutara desde 1 hasta 'n' (la cantidad de escalones)
        - Seguido, creamos un segundo bucle for que se ejecutara desde 1 hasta 'i' (el numero de escalon)
        - Imprimimos una cantidad de * igual al numero de escalon en el que estamos ('i')
        - Al terminar de imprimir la cantidad de * correspondiente, imprimimos un salto de linea para pasar al siguiente escalon

        Ejemplo donde n = 5:
        *
        **
        ***
        ****
        *****
    */

    return 0;
}