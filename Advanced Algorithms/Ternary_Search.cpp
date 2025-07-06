#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::
#define ll long long // Definir 'll' para 'long long'

/* Ternary Search (Busqueda Ternaria):
    - Cuando queremos encontrar el valor que mejor cumple una cierta condicion en un conjunto de datos ordenados, la forma mas eficiente de encontrarlo es con una Busqueda Binaria
    - La busqueda binaria, en pocas palabras, divide la informacion en 2 bloques con el fin de agilizar la busqueda eliminando un bloque completo por iteracion
    - Aunque esta tecnica es muy eficiente, solo funciona para ocasiones donde los datos unicamente incrementan o disminuyen, mas no ambos (funciones lineales)
    - Cuando tenemos datos que pueden incrementar y disminuir progresivamente (funciones no lineales), utilizamos en su lugar una busqueda ternaria

    - La busqueda ternaria es un algoritmo de busqueda que se utiliza para encontrar el valor que mejor cumple una cierta condicion en un conjunto de datos semiordenados
    - Es utilizada cuando los datos pueden aumentar y disminuir conforme los recorremos (matematicamente, estariamos hablando de una funcion no lineal)
    - Funciona segun el mismo principio de dividir los datos en bloques, con la diferencia de que esta vez dividiremos los datos en tres partes en lugar de dos
    - La idea basica es reducir el espacio de busqueda comparando el valor objetivo con los dos puntos que dividen a los datos en 3 bloques
*/

/* ¿Cuando utilizar la busqueda ternaria?:
    - Cuando tienes una lista ordenada muy grande y necesitas encontrar la posicion de un valor especifico (practicamente una situacion donde una binaria seria algo lenta)
    - Cuando necesitas encontrar el valor maximo o minimo de una funcion no lineal
    - Cuando tienes que evaluar una expresion cuadratica, cubica, etc. (no lineal)
*/

/* ¿Como funciona la busqueda ternaria?:
    - Para explicarlo, emplearemos el caso en el que queremos encontrar un dato especifico, aunque cambiara un poco dependiendo el uso que le queramos dar
    - El concepto consiste en dividir los datos en tres segmentos iguales y determinar en cual se encuentra el elemento clave
    - Funciona de forma similar a una busqueda binaria, con la particularidad de reducir la complejidad temporal al dividir los datos en tres partes en lugar de dos
    - Estos son los pasos para ejecutar una busqueda ternaria:
        1. Inicializacion:
            - Se establecen dos punteros (izquierda y derecha), que apuntan inicialmente al 1er y ultimo elemento del espacio de busqueda
        2. Dividir el espacio de busqueda:
            - Se divide el espacio de busqueda mediante dos puntos medios ('mid1' y 'mid2') que dividiran el espacio de busqueda actual en tres partes iguales (aprox.):
                - mid1 = l + (r - l)/3 
                - mid2 = r - (r - l)/3
                    - Donde:
                        - 'mid1' = Puntero indicando el 1er corte que divide los datos entre el 1er y 2do tercio
                        - 'mid2' = Puntero indicando el 2do corte que divide los datos entre el 2do y 3er tercio
                        - 'l' = Puntero indicando el punto actual mas a la izquierda del rango de busqueda (El 1er valor inicialmente)
                        - 'r' = Puntero indicando el punto actual mas a la derecha del rango de busqueda (El ultimo valor inicialmente)
                    - La formula para 'mid1' es equivalente a iniciar en el punto mas a la izquierda y sumarle un tercio de la cantidad actual de valores en el rango
                    - La formula para 'mid2' es equivalente a iniciar en el punto mas a la derecha y restarle un tercio de la cantidad actual de valores en el rango
            - Los datos ahora estan divididos en [izquierda -> medio1], [medio1 -> medio2] y [medio2 -> derecha]
        3. Comparacion con el objetivo:
            - Si el objetivo es igual al elemento en 'mid1' o 'mid2' , la busqueda es exitosa y se devuelve el indice
            - Si el objetivo es menor que el elemento en 'mid1', actualizamos el puntero derecho a 'mid1 - 1'
            - Si el objetivo es mayor que el elemento en 'mid2', actualizamos el puntero izquierdo a 'mid2 + 1'
            - Si el objetivo esta entre los elementos 'mid1' y 'mid2', actualizamos el puntero izquierdo a 'mid1 + 1' y el puntero derecho a 'mid2 - 1'
        4. Repetir o concluir
            - Repetimos el proceso con el espacio de busqueda reducido hasta encontrar el objetivo o hasta que el espacio de busqueda quede vacio
            - Si el espacio de busqueda esta vacio y no se encuentra el objetivo, devolvemos un valor que indica que el objetivo no existe (generalmente '-1')
*/

// 'ternarySearch': Funcion para buscar el valor 'k' dentro del conjunto de datos 'vec' mediante una busqueda ternaria
int ternarySearch(int izq, int der, int obj, vector<int> vec){ // 'izq' = puntero izquierdo, 'der' = puntero derecho, 'obj' = valor objetivo, 'vec' = conjunto de datos
    if(der >= izq){ // Si 'der' es mayor o igual a 'izq' (no se han arrebasado)...

        int mid1 = izq + (der - izq) / 3; // Calculamos la posicion del puntero medio 1 ('mid1')
        int mid2 = der - (der - izq) / 3; // Calculamos la posicion del puntero medio 2 ('mid2')

        // Revisamos si el valor que buscamos se encuentra en alguna de las mitades, en caso de que si, retornamos el puntero respectivo
        if(vec[mid1] == obj) return mid1;
        if(vec[mid2] == obj) return mid2;

        // Revisamos en que bloque se encuentra 'obj' para asi eliminar los otros 2
        if(obj < vec[mid1]){ // Si 'obj' es menor al valor en la posicion de 'mid1'...
            return ternarySearch(izq, mid1 - 1, obj, vec); // Recorremos 'der' hacia 'mid1' (nos quedamos con el 1er bloque y eliminamos el 2do y 3er bloque)
        }else if (obj > vec[mid2]){ // Si 'obj' es mayor al valor en la posicion de 'mid2'...
            return ternarySearch(mid2 + 1, der, obj, vec); // Recorremos 'izq' hacia 'mid2' (nos quedamos con el 3er bloque y eliminamos el 1er y 2do bloque)
        }else{ // Si 'obj' no se encuntra ni en el 1er ni 3er bloque...
            return ternarySearch(mid1 + 1, mid2 - 1, obj, vec); // Recorremos 'izq' hacia 'mid1' y 'der' hacia 'mid2' (nos quedamos con el 2do bloque y eliminamos el 1er y 3er bloque)
        }
    }

    return -1; // En caso de haber arrebasado 'izq' a 'der, significa que 'obj' no se encuentra en 'vec', por lo que retornamos '-1'
}

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida

    int n; cin >> n; // Leemos la cantidad de datos en los que buscaremos
    vector<int> vec(n); // Vector donde guardamos los datos en los que buscaremos
    for(int i=0; i<n; i++){
        cin >> vec[i]; // Leemos los 'n' datos
    }
    sort(vec.begin(), vec.end()); // Ordenamos los datos (solo funciona si los datos estan ordenados)

    int k; cin >> k; // Leemos el valor que queremos encontrar

    int p = ternarySearch(0, n-1, k, vec); // Llamamos a 'ternarySearch' con los valores (izq = 0, der = n-1, obj = k, vec = vec)
    if(p == -1) cout << k << " no se encuentra en el conjunto de datos" << endl; // Si 'p == -1', entonces no existe 'k' en el conjunto de datos
    else cout << "El valor " << k << " esta en la posicion " << p; // Imprimimos la posicion en la que se encuentra 'k'

    return 0;
}

/* Ejemplo:
    n = 20
    vec = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19]
    k = 5

    - 1er corte:
        - 'izq' = 0, 'der' = 19, 'mid1' = 6, 'mid2' = 13
        - Bloques: [ [0, 1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12, 13], [14, 15, 16, 17, 18, 19] ]
                    v                   v                         v                            v
                   izq                 mid1                      mid2                         der
        - Bloque a conservar: Bloque 1
        - Bloques a eliminar: Bloques 2 y 3
    - 2do corte:
        - 'izq' = 0, 'der' = 5, 'mid1' = 1, 'mid2' = 4
        - Bloques: [ [0, 1], [2, 3, 4], [5] ]
                    v    v          v      v
                   izq  mid1       mid2   der
        - Bloque a conservar: Bloque 3
        - Bloques a eliminar: Bloques 1 y 2
    - 3er corte:
        - 'izq' = 5, 'der' = 5, 'mid1' = 5, 'mid2' = 5
        - Bloques: [ [5] ]
                    v   v
                   izq der
        - Elemento encontrado!
        - Retorna '5'
*/