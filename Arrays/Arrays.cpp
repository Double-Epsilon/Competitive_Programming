#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* Arrays:
        - Un array (arreglo) es una estructura de datos que almacena varios valores de un tipo
        - Es una forma mas facil y eficiente de guardar y utilizar muchos valores, pues ahorra declarar cientos de variables individuales
        
        Definicion : -tipo- -nombre-[-tamaño-];
        - Donde:
            -tipo- : Tipo de variable de los valores a almacenar
            -nombre- : Nombre que le asignaremos al arreglo
            -tamaño- : Cantidad de valores que almacenaremos dentro del arreglo

        Acceder a una posicion del arreglo : -nombre-[-indice-]
        - Donde:
            -nombre- : Nombre del arreglo
            -indice- : Posicion a la que queremos acceder

        - Para guardar/acceder valores en un arreglo, utilizamos 'indices'
        - Un arreglo esta 0-indexado (es decir, su 1er elemento se encuentra en el indice 0)
        - Cada posicion del arreglo actua como una variable normal, es decir, podemos hacer lo que normalmente hariamos con una variable independiente
        - Toma en cuenta que si el arreglo es de n posiciones, su ultimo indice sera n-1 (porque el 1ro es 0)
        - Intentar acceder a una posicion no existente podria regresar un valor fantasma (osea un valor random) o directamente marcar error y terminar la ejecucion

        Ejemplo de arreglo tamaño 5, donde ya asignamos valores a cada indice:
            - Valor  :  [5, 8, 1, 2, 4]
            - Indice :  [0, 1, 2, 3, 4]
    */

    int array[5]; // Declaramos un arreglo de tamaño 5

    for(int i=0; i<5; i++){ // Creamos un for que inicia en 0 (1er indice) y se ejecuta mientras 'i' sea menor a 5 (porque el ultimo indice es n-1, osea 4)
        cout << "Ingresa el valor de la posicion " << i << " del arreglo: ";
        cin >> array[i]; // Leemos el valor para la posicion 'i' del arreglo
    }

    cout << "Valores del arreglo: " << endl;
    for(int i=0; i<5; i++){ // Creamos un for que inicia en 0 (1er indice) y se ejecuta mientras 'i' sea menor a 5 (porque el ultimo indice es n-1, osea 4)
        cout << i << ": " << array[i] << endl; // Imprimimos 'i' (valor del indice actual) y 'array[i]' (la posicion 'i' del arreglo)
    }

    cout << "Posicion 2: " << array[2] << endl; // Imprimimos el valor actual de 'array[2]'
    array[2] = 4; // Accedemos a la posicion 2 del arreglo y cambiamos su valor por 4
    cout << "Nuevo valor posicion 2: " << array[2] << endl; // Imprimimos el valor de 'array[2]' (osea 4)

    int array2[10] = {1,2,3,4,5,6,7,8,9,10}; // Declaramos un nuevo arreglo de tamaño 10 y predefinimos los valores de cada posicion
    //     indices = [0,1,2,3,4,5,6,7,8,9 ];

    cout << "Arreglo 2 en reversa: "; // Imprimiremos el arreglo 2 pero del ultimo al 1er elemento
    for(int i=9; i>=0; i--){ // Creamos un for que inicia en 9 (ultimo indice) y se ejecuta hasta 0 (1er indice)
        cout << array2[i] << " "; // Imprimimos 'i' (valor del indice actual) y 'array[i]' (la posicion 'i' del arreglo)
    }

    int suma = 0; // Declaramos una variable 'suma' para calcular la suma de todos los elementos del arreglo 2
    for(int i=0; i<10; i++){ // Creamos un for que inicia en 0 (1er indice) y se ejecuta mientras 'i' sea menor a 10 (porque el ultimo indice es n-1, osea 9)
        suma += array2[i]; // Aumentamos a 'suma' el valor de la posicion 'i' del arreglo
    }
    cout << endl << "Suma de todos los elementos del arreglo 2: " << suma; // Imprimimos el valor de 'suma'

    return 0;
}