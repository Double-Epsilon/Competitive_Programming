#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* El problema "Sumar filas y columnas" dice:
        - Se te daran 2 numeros n y m, la cantidad de filas y columnas de una matriz, respectivamente
        - Se te daran n*m numeros, los numeros de la matriz
        - Imprimiras la suma de todos los numeros de cada fila, asi como la suma de todos los numeros de cada columna
    */

    cout << "Ingresa el valor de n: ";
    int n; cin >> n; // Declaramos y leemos la variable 'n', el numero de filas de la matriz

    cout << "Ingresa el valor de m: ";
    int m; cin >> m; // Declaramos y leemos la variable 'm', el numero de columnas de la matriz

    int matrix[n][m]; // Declaramos una matriz de n*m posiciones
    for(int i=0; i<n; i++){ // Creamos un for para leer las 'n' filas de la matriz
        for(int j=0; j<m; j++){ // Creamos otro for para leer las 'm' columnas de la matriz
            cout << "Posicion [" << i << "," << j << "]: ";
            cin >> matrix[i][j]; // Leemos el valor de la posicion '[i,j]'
        }
    }

    cout << "Filas" << endl;
    for(int i=0; i<n; i++){ // Creamos un for para iterar las 'n' filas de la matriz
        int suma = 0; // Por cada columna, declaramos una variable 'suma' para guardar la suma de todos los numeros de la fila
        for(int j=0; j<m; j++){ // Creamos otro for para iterar las 'm' columnas de la matriz
            suma += matrix[i][j]; // Sumamos el valor de la posicion '[i,j]'
        }
        cout << "Fila " << i+1 << ": " << suma << endl; // Cuando terminamos de sumar, imprimimos la suma y pasamos a la siguiente fila
    }

    cout << "Columnas" << endl;
    for(int j=0; j<m; j++){ // Creamos un for para iterar las 'm' columnas de la matriz
        int suma = 0; // Por cada columna, declaramos una variable 'suma' para guardar la suma de todos los numeros de la columna
        for(int i=0; i<n; i++){ // Creamos otro for para iterar las 'n' filas de la matriz
            suma += matrix[i][j]; // Sumamos el valor de la posicion '[i,j]'
        }
        cout << "Columna " << j+1 << ": " << suma << endl; // Cuando terminamos de sumar, imprimimos la suma y pasamos a la siguiente columna
    }

    /* ¿Que hacemos?:
        - Primero, leemos el valor de 'n', el numero de filas que nos van a ingresar
        - Luego, leemos el valor de 'm', el numero de columnas que nos van a ingresar
        - Definimos una matriz de 'n*m' posiciones para guardar los 'n*m' numeros
        - Leemos cada numero y lo guardamos en su respectiva posicion de la matriz

        - Para las filas: 
            - Creamos 2 bucles for, el 1ro itera por cada fila y el 2do por cada columna
            - Así podemos sumar los elementos de cada fila, pues el 2do bucle ira recorriendo los elementos de la fila 'i' uno por uno
            - Cada vez que hayamos terminado de recorrer la fila, imprimimos la suma correspondiente y pasamos a la siguiente

        - Para las columnas:
            - Creamos 2 bucles for, el 1ro itera por cada columna y el 2do por cada fila
            - Así podemos sumar los elementos de cada columna, pues el 2do bucle ira recorriendo los elementos de la columna 'j' uno por uno
            - Cada vez que hayamos terminado de recorrer la columna, imprimimos la suma correspondiente y pasamos a la siguiente

        Ejemplo:
               0  1  2
            0 [1, 2, 3] = 6
            1 [4, 5, 6] = 15
            2 [7, 8, 9] = 24
               =  =  =
               12 15 18
        
        - En el 1er bucle doble, recorremos la matriz de arriba hacia abajo, de izquierda a derecha
        - Cada vez que llegamos al final, imprimimos la suma de toda la fila y pasamos a la de abajo
        - Repetimos hasta que se acaben las filas
        - En el 2do bucle doble, recorremos la matriz de izquierda a derecha, de arriba hacia abajo
        - Cada vez que llegamos al final, imprimimos la suma de toda la columna y pasamos a la de la derecha
        - Repetimos hasta que se acaben las columnas
    */

    return 0;
}