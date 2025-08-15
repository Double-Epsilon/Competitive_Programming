#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

/* Longest Increasing Subsequence (LIS) Iterative Version:
    - Este codigo sigue la misma idea de una LIS normal, con la diferencia de que es más corto y evita recursión (dp iterativa)
    - La idea principal es ir iterando por cada elemento del arreglo sustituyendo o tomando cada valor

    - Si el elemento es mayor a todos los valores actuales, lo tomamos y lo agregamos al final
    - Si el elemento es menor o igual a algun valor actual, reemplazamos ese valor por el nuevo elemento

    - OJO: Este algortimo solo sirve para obtener el tamaño de la LIS, para obtener la secuencia hay que utilizar la dp recursiva
*/ 

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida

    int N; cin >> N; // Declaramos y leemos el valor de 'N'
    
    vector<int> A(N); // Declaramos el arreglo 'A' de 'N' posiciones
    for(int i=0; i<N; i++){
        cin >> A[i]; // Leemos los 'N' valores de 'A'
    }
    
    vector<int> dp; // Declaramos un vector 'dp', encargado de guardar el resultado de la LIS
    for(int val : A){ // Iteramos todos los elementos de 'A'
        // Para el elemento actual...
        auto it = lower_bound(dp.begin(), dp.end(), val); // Buscamos el primer valor mayor o igual al elemento

        // Si 'lower_bound' nos devuelve 'dp.end()'...
        if(it == dp.end()) dp.push_back(val); // Agregamos el elemento al final del vector (contribuye a la solucion)
        // En caso de que devuelva alguna posicion...
        else *it = val; // Cambiamos el valor actual de la posicion con el valor del elemento
    }

    cout << dp.size() << endl; // Imprimimos el tamaño de 'dp' (tamaño final de la LIS)

    return 0;
}

/* Ejemplo:
    n = 4
    a[n] = [3, 10, 2, 20, 22, 15]

    - 1ra iteracion:
        - 'dp' = []
        - 'val' = 3
        - 'it' = 'dp.end()' ('dp' esta vacio, por lo que 'lower_bound' siempre regresa '.end()')
        - "AGREGAMOS"
        - 'dp' = [3]
    
    - 2da iteracion:
        - 'dp' = [3]
        - 'val' = 10
        - 'it' = 'dp.end()' (no hay elementos mas grandes o iguales a 'val')
        - "AGREGAMOS"
        - 'dp' = [3, 10]
    
    - 3ra iteracion:
        - 'dp' = [3, 10]
        - 'val' = 2
        - 'it' = 'dp.begin()' (el 1er elemento de 'dp' es el 1er elemento mayor o igual a 'val')
        - "REEMPLAZAMOS"
        - 'dp' = [2, 10]
    
    - 4ta iteracion:
        - 'dp' = [2, 10]
        - 'val' = 20
        - 'it' = 'dp.end()' (no hay elementos mas grandes o iguales a 'val')
        - "AGREGAMOS"
        - 'dp' = [2, 10, 20]
    
    - 5ta iteracion:
        - 'dp' = [2, 10, 20]
        - 'val' = 22
        - 'it' = 'dp.end()' (no hay elementos mas grandes o iguales a 'val')
        - "AGREGAMOS"
        - 'dp' = [2, 10, 20, 22]
    
    - 6ta iteracion:
        - 'dp' = [2, 10, 20, 22]
        - 'val' = 15
        - 'it' = 'dp.begin() + 2' (el indice 2 de 'dp' es el 1er elemento mayor o igual a 'val')
        - "REEMPLAZAMOS"
        - 'dp' = [2, 10, 15, 22]
    
    - FINAL
        - 'dp' = [2, 10, 15, 22]
        - 'LIS' = 'dp.size()' = 4
        - (Toma en cuenta que la secuencia final de 'dp' NO es la secuencia correcta de 'LIS', este algoritmo solo devuelve el tamaño)
*/