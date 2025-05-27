#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* El problema "Sumar elementos opuestos" dice:
        - Se te dara un numero par n, la cantidad de numeros que se te ingresaran
        - Se te daran n numeros, los numeros que tendras que guardar en un arreglo
        - Imprimiras la suma de cada par de numeros opuestos, es decir, la suma del 1er con el ultimo numero, el 2do con el penultimo, etc
    */

    cout << "Ingresa el valor de n: ";
    int n; cin >> n; // Declaramos y leemos la variable 'n', la cantidad de numeros que leeremos despues

    int nums[n]; // Declaramos un arreglo de n posiciones
    for(int i=0; i<n; i++){ // Creamos un for para leer los n numeros que necesitamos
        cout << "Ingresa el numero " << i+1 << ": "; // i+1 para efectos visuales (osea, mostrar de 1 a n, aunque realmente 'i' sea de 0 a n-1)
        cin >> nums[i]; // Leemos el valor de la posicion 'i'
    }

    for(int i=0; i<n/2; i++){ // Creamos un for que llegara hasta n/2, es decir, iterara la mitad del arreglo
        int suma = nums[i] + nums[n-i-1]; // Declaramos una variable 'suma' que guardara la suma del elemento 'i' mas el elemento 'n-i-1'
        cout << "Suma de las posiciones " << i << " y " << n-i-1 << ": " << suma << endl; // Imprimimos la suma correspondiente
    }

    /* ¿Que hacemos?:
        - Primero, leemos el valor de 'n', el numero de elementos que nos van a ingresar
        - Luego, definimos un arreglo de 'n' posiciones para guardar los 'n' numeros
        - Leemos cada numero y lo guardamos en su respectiva posicion del arreglo

        - Creamos un bucle for que va desde 0 hasta n/2, esto porque la ultima suma se realiza en la mitad del arreglo
        Ejemplo: [1, 3, 7, 4, 2, 9]
        Indices: [0, 1, 2, 3, 4, 5]
        Sumas: [0 y 5] = 10, [1 y 4] = 5, [2 y 3] = 11
        - Si nos damos cuenta, la ultima suma son las posiciones 2 y 3, y 6/2 = 3 (la mitad del arreglo)
        - Para cada suma, utilizamos la posicion 'i' y la posicion 'n-i-1'
        Ejemplos:
            - Para la posicion 0, n-i-1 = 6-0-1 = 5 [Posiciones 0 y 5]
            - Para la posicion 1, n-i-1 = 6-1-1 = 4 [Posiciones 1 y 4]
            - Para la posicion 2, n-i-1 = 6-2-1 = 3 [Posiciones 2 y 3]
    */

    return 0;
}