#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* El problema "Sacar promedio" dice:
        - Se te dara un numero n, la cantidad de numeros que se te ingresaran
        - Se te daran n numeros, los numeros de los que tendras que sacar el promedio
        - Imprimiras el valor promedio de todos los numeros que te ingresen

        - Recordemos que la formula del promedio es (v1 + v2 + ... + vn) / n
        - Donde:
            - 'v' es el valor 'i'
            - 'n' es el numero de elementos
    */

    cout << "Ingresa el valor de n: ";
    int n; cin >> n; // Declaramos y leemos la variable 'n', la cantidad de numeros que leeremos despues

    int nums[n]; // Declaramos un arreglo de n posiciones
    for(int i=0; i<n; i++){ // Creamos un for para leer los n numeros que necesitamos
        cout << "Ingresa el numero " << i+1 << ": "; // i+1 para efectos visuales (osea, mostrar de 1 a n, aunque realmente 'i' sea de 0 a n-1)
        cin >> nums[i]; // Leemos el valor de la posicion 'i'
    }

    float promedio = 0.0; // Declaramos una variable flotante con valor inicial 0.0 (esto debido a que el promedio puede ser decimal)
    for(int i=0; i<n; i++){ // Creamos un for para iterar los n elementos del arreglo
        promedio += nums[i]; // Sumamos a 'promedio' el valor de la posicion 'i'
    }

    promedio /= n; // Dividimos 'promedio' entre n
    cout << "El promedio final es: " << promedio; // Imprimimos el valor del promedio

    return 0;
}