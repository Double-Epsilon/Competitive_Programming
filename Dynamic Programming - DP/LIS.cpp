#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

/* Longest Increasing Subsequence (LIS):
    - Dada una secuencia de números, se debe encontrar la subsecuencia creciente mas larga posible
    - Se debe cumplir la condicion de que s[i] < s[i+1] (el elemento i debe ser estrictamente menor al elemento i+1)

    Ejemplos:
        - Entrada: n = 5, a[n] = [3, 10, 2, 1, 20]
        - Salida: 3
        - Explicacion: La subsecuencia creciente mas larga es [3, 10, 20]

        - Entrada: n = 3, a[n] = [30, 20, 10]
        - Salida: 1
        - Explicacion: La subsecuencia creciente mas larga es [30]. Tambien son posibles las subsecuencias [20] y [10]

        - Entrada: n = 8, a[n] = [10, 9, 2, 5, 3, 7, 101, 18]
        - Salida: 4
        - Explicacion: La subsecuencia creciente mas larga es [2, 5, 7, 101]. Tambien son posibles las subsecuencias [2, 5, 7, 18], [2, 3, 7, 101] y [2, 3, 7, 18]
*/

/* ¿Que haremos?:
    - La idea es buscar todas las posibles subsecuencias que cumplan la condicion de ser estrictamente crecientes
    - Para ello, partiremos en cada elemento y mediante un arbol recursivo calcularemos las posibles soluciones al problema
    - Es decir, para una secuencia de 4 elementos ([1, 2, 3, 4] por ejemplo), calcularemos 2 versiones de cada elemento (tomar o no tomar)
    - El arbol recursivo para el ejemplo anterior quedaria:
                    1
               /         \
              2           2
            /   \       /   \
           3     3     3     3
          / \   / \   / \   / \
         4   4 4   4 4   4 4   4
    ans: 1   2 2   3 2   3 3   4
        - Donde:
            - Tomar el camino de la izquierda significa NO tomar el elemento actual
            - Tomar el camino de la derecha significa SI tomar el elemento actual
            - En caso de llegar al ultimo elemento del arbol, siempre lo tomaremos
    - En este caso, la solución sería 4, con la subsecuencia [1, 2, 3, 4] como respuesta
    
    - Hay que tomar en cuenta que un elemento SOLO puede tomarse si el elemento anterior ES ESTRICTAMENTE MENOR
    - Por ejemplo, para una secuencia [1, 2, 5, 4], su arbol recursivo quedaria:
                    1
               /         \
              2           2
            /   \       /   \
           5     5     5     5
          / \   / \   / \   / \
         4     4     4     4
    ans: 1  1  2  2  2  2  3  3
    - Podemos notar que, en caso de llegar a '5':
        - Si NO tomamos '5' (camino de la izquierda), todavía podemos tomar '4', pues es estrictamente mayor a los elementos anteriores
        - Si SI tomamos '5' (camino de la derecha), termina el recorrido de ese arbol recursivo, pues los elementos que quedan ('4') NO son estrictamente mayores a '5'
    - En este caso, la solución sería 3, con las subsecuencias [1, 2, 4] o [1, 2, 5] como respuesta
*/

const int MAXN = 2501; // Cantidad maxima de elementos
const int MAX_VALUE = 1001; // Valor maximo de cada elemento
int n; // Cantidad de elementos
int a[MAXN]; // Arreglo para guardar los n elementos
int mem[MAXN][2 * MAX_VALUE]; // Matriz para la memoria (guardar los resultados ya calculados de las recursiones)
bool visitados[MAXN][2 * MAX_VALUE]; // Matriz para revisar si un elemento ya fue visitado o no (su arbol recursivo ya fue calculado o no)

// Funcion recursiva "LIS" (Longest Increasing Subsequence)
int lis(int pos, int anterior){ // 'pos' = posicion actual en el arreglo, 'anterior' = ultimo elemento tomado
    if(pos == n) return 0; // Si 'pos' es igual a 'n', retorna 0 (se terminaron los elementos)

    if(!visitados[pos][anterior]){ // Si no lo hemos visitado (no hemos calculado su arbol recursivo)...
        visitados[pos][anterior] = true; // Marcamos como visitado

        int ans = lis(pos+1, anterior); // Calculamos su arbol recursivo donde NO tomamos la posicion actual (camino a la izquierda)

        if(a[pos] > anterior){ // Si el elemento en la posicion actual es mayor al ultimo elemento tomado... (estrictamente mayor)
            ans = max(ans, lis(pos+1, a[pos]) + 1); // Calculamos su arbol recursivo donde SI tomamos la posicion actual (camino a la derecha)
            // Comparamos los resultados (arboles recursivos 0 y 1 (izquierda y derecha)) y nos quedamos con el que tenga una mayor solucion
        }

        mem[pos][anterior] = ans; // Guardamos la mejor respuesta de este elemento
    }

    return mem[pos][anterior]; // Retornamos la respuesta almacenada en la memoria (mejor respuesta para este elemento)
}

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida

    cin >> n; // Leemos el valor de 'n'
    for(int i=0; i<n; i++){
        cin >> a[i]; // Leemos los 'n' valores del arreglo 'a'
        a[i] += MAX_VALUE; // Sumamos a cada valor el valor maximo (solo en caso de que hayan valores negativos para volverlos positivos)
    }

    cout << lis(0, 0); // Imprimimos el resultado final de 'LIS' iniciando en la posicion 0 y con valor inicial 0
    
    return 0;
}

/* Ejemplo:
    n = 4
    a[n] = [3, 10, 2, 20]

    - Elemento actual: '3'
        - NO TOMAR:
            - Elemento actual: '10'
            - Subsecuencia actual: []
                - NO TOMAR:
                    - Elemento actual: '2'
                    - Subsecuencia actual: []
                        - NO TOMAR:
                                - Elemento actual: '20' (ultimo elemento)
                                - Subsecuencia actual: []
                                    - SI TOMAR (unica opcion, pues ans.size() == 0):
                                        - Subsecuencia final: [20]
                        - SI TOMAR:
                                - Elemento actual: '20' (ultimo elemento)
                                - Subsecuencia actual: [2]
                                    - NO TOMAR:
                                        - Subsecuencia final: [2]
                                    - SI TOMAR:
                                        - Subsecuencia final: [2, 20]
                - SI TOMAR:
                    - Elemento actual: '2'
                    - Subsecuencia actual: [10]
                        - NO TOMAR (unica opcion, pues 2 < 10):
                                - Elemento actual: '20' (ultimo elemento)
                                - Subsecuencia actual: [10]
                                    - NO TOMAR:
                                        - Subsecuencia final: [10]
                                    - SI TOMAR:
                                        - Subsecuencia final: [10, 20]
        - SI TOMAR:
            - Elemento actual: '10'
            - Subsecuencia actual: [3]
                - NO TOMAR:
                    - Elemento actual: '2'
                    - Subsecuencia actual: [3]
                        - NO TOMAR (unica opcion, pues 2 < 3):
                                - Elemento actual: '20' (ultimo elemento)
                                - Subsecuencia actual: [3]
                                    - NO TOMAR:
                                        - Subsecuencia final: [3]
                                    - SI TOMAR:
                                        - Subsecuencia final: [3, 20]
                - SI TOMAR:
                    - Elemento actual: '2'
                    - Subsecuencia actual: [3, 10]
                        - NO TOMAR (unica opcion, pues 2 < 10):
                                - Elemento actual: '20' (ultimo elemento)
                                - Subsecuencia actual: [3, 10]
                                    - NO TOMAR:
                                        - Subsecuencia final: [3, 10]
                                    - SI TOMAR:
                                        - Subsecuencia final: [3, 10, 20]
    
    - Subsecuencias finales:
        - [3]         (ans = 1)
        - [3, 10]     (ans = 2)
        - [3, 10, 20] (ans = 3) <- Mayor
        - [3, 20]     (ans = 2)
        - [10]        (ans = 1)
        - [10, 20]    (ans = 2)
        - [2]         (ans = 1)
        - [2, 20]     (ans = 2)
        - [20]        (ans = 1)
    - Mayor subsecuencia: [3, 10, 20] (ans = 3)
*/