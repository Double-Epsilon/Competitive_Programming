#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* Matrices:
        - Una matrix (matriz) es una estructura de datos que almacena varios valores de un tipo en un plano de 2 dimensiones (2D)
        - Es una forma facil y eficiente de guardar y utilizar muchos valores, especialmente cuando se necesita un sistema de coordenadas
        - Tambien se les conoce como arreglo de arreglos, pues una matriz trabaja practicamente igual que un arreglo, solo que en 2 dimensiones
        
        Definicion : -tipo- -nombre-[-filas-][-columnas-];
        - Donde:
            -tipo- : Tipo de variable de los valores a almacenar
            -nombre- : Nombre que le asignaremos a la matriz
            -filas- : Cantidad de filas que tendra nuestra matriz
            -columnas- : Cantidad de columnas que tendra nuestra matriz

        Acceder a una posicion de la matriz : -nombre-[-fila-][-columna-]
        - Donde:
            -nombre- : Nombre de la matriz
            -fila- : Indice de la fila a la que queremos acceder
            -columna- : Indice de la columna a la que queremos acceder

        - Para guardar/acceder valores en una matriz, utilizamos 'indices' al estilo de coordenadas
        - Una matriz esta 0-indexada (es decir, su 1er fila y columna tendran de indice 0)
        - Cada posicion de la matriz actua como una variable normal, es decir, podemos hacer lo que normalmente hariamos con una variable independiente
        - Toma en cuenta que si la matriz es de n filas y m columnas, su ultima fila sera n-1 y su ultima columna sera m-1
        - Intentar acceder a una posicion no existente podria regresar un valor fantasma (osea un valor random) o directamente marcar error y terminar la ejecucion

        Ejemplo de matriz con 5 filas y 5 columnas, junto a sus indices coorespondientes y la coordenada de cada posicion
                 0      1      2      3      4
            0 [{0,0}, {0,1}, {0,2}, {0,3}, {0,4}]
            1 [{1,0}, {1,1}, {1,2}, {1,3}, {1,4}]
            2 [{2,0}, {2,1}, {2,2}, {2,3}, {2,4}]
            3 [{3,0}, {3,1}, {3,2}, {3,3}, {3,4}]
            4 [{4,0}, {4,1}, {4,2}, {4,3}, {4,4}]

        - Si te das cuenta, para acceder a una posicion 1ro colocamos el indice de la fila y luego el de la columna
        - Las posiciones actuan igual que un sistema de coordenadas
        - Como regla general, se suele asignar el iterador 'i' a la fila y el iterador 'j' a la columna
    */

    int matrix[3][3]; // Declaramos un matriz de tamaño 3

    for(int i=0; i<3; i++){ // Creamos un for que inicia en 0 (1ra fila) y se ejecuta mientras 'i' sea menor a 3 (porque la ultima fila es n-1, osea 2)
        for(int j=0; j<3; j++){ // Creamos un for que inicia en 0 (1ra columna) y se ejecuta mientras 'j' sea menor a 3 (porque la ultima columna es m-1, osea 2)
            cout << "Ingresa el valor de la posicion [" << i << "," << j << "] de la matriz: ";
            cin >> matrix[i][j]; // Leemos el valor para la posicion '[i,j]' de la matriz
        }
    }

    cout << "Valores de la matriz: " << endl;
    for(int i=0; i<3; i++){ // Creamos un for que inicia en 0 (1ra fila) y se ejecuta mientras 'i' sea menor a 3 (porque la ultima fila es n-1, osea 2)
        for(int j=0; j<3; j++){ // Creamos un for que inicia en 0 (1ra columna) y se ejecuta mientras 'j' sea menor a 3 (porque la ultima columna es m-1, osea 2)
            cout << matrix[i][j] << " "; // Imprimimos la posicion '[i,j]' de la matriz
        }
        cout << endl; // Imprimimos un salto de linea porque acabamos la fila 'i' 
    }

    cout << "Posicion [2,2]: " << matrix[2][2] << endl; // Imprimimos el valor actual de 'matrix[2][2]'
    matrix[2][2] = 4; // Accedemos a la posicion [2,2] de la matriz y cambiamos su valor por 4
    cout << "Nuevo valor posicion [2,2]: " << matrix[2][2] << endl; // Imprimimos el nuevo valor de 'matrix[2][2]' (osea 4)

    int matrix2[3][3] = {{1,2,3},
                         {4,5,6},
                         {7,8,9}}; // Declaramos una nueva matriz de tamaño 3*3 y predefinimos los valores de cada posicion

    cout << "Matriz 2 en reversa: " << endl; // Imprimiremos 'matrix2' pero del ultimo al 1er elemento
    for(int i=2; i>=0; i--){ // Creamos un for que inicia en 2 (ultima fila) y se ejecuta hasta 0 (1er columna)
        for(int j=2; j>=0; j--){ // Creamos un for que inicia en 2 (ultima columna) y se ejecuta hasta 0 (1er columna)
            cout << matrix2[i][j] << " "; // Imprimimos la posicion '[i,j]' de la matriz
        }
        cout << endl; // Imprimimos un salto de linea porque acabamos la fila 'i' 
    }

    return 0;
}