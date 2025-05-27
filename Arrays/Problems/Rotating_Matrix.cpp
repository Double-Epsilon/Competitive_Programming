#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* El problema "Matriz giratoria" dice:
        - Se te daran 2 numeros n y m, la cantidad de filas y columnas de una matriz, respectivamente
        - Se te daran n*m numeros, los numeros de la matriz
        - Imprimiras la matriz 4 veces: girada 0°, 90°, 180° y 270°
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

    cout << "Girada 0°" << endl;
    for(int i=0; i<n; i++){ // Creamos un for para iterar las 'n' filas de la matriz
        for(int j=0; j<m; j++){ // Creamos otro for para iterar las 'm' columnas de la matriz
            cout << matrix[i][j] << " "; // Imprimimos el valor de la posicion '[i,j]'
        }
        cout << endl;
    }

    cout << "Girada 90°" << endl;
    for(int j=0; j<m; j++){ // Creamos un for para iterar las 'm' columnas de la matriz
        for(int i=n-1; i>=0; i--){ // Creamos otro for para iterar las 'n' filas de la matriz
            cout << matrix[i][j] << " "; // Imprimimos el valor de la posicion '[i,j]'
        }
        cout << endl;
    }

    cout << "Girada 180°" << endl;
    for(int i=n-1; i>=0; i--){ // Creamos un for para iterar las 'n' filas de la matriz
        for(int j=m-1; j>=0; j--){ // Creamos otro for para iterar las 'm' columnas de la matriz
            cout << matrix[i][j] << " "; // Imprimimos el valor de la posicion '[i,j]'
        }
        cout << endl;
    }

    cout << "Girada 270°" << endl;
    for(int j=m-1; j>=0; j--){ // Creamos un for para iterar las 'm' columnas de la matriz
        for(int i=0; i<n; i++){ // Creamos otro for para iterar las 'n' filas de la matriz
            cout << matrix[i][j] << " "; // Imprimimos el valor de la posicion '[i,j]'
        }
        cout << endl;
    }

    /* ¿Que hacemos?:
        - Primero, leemos el valor de 'n', el numero de filas que nos van a ingresar
        - Luego, leemos el valor de 'm', el numero de columnas que nos van a ingresar
        - Definimos una matriz de 'n*m' posiciones para guardar los 'n*m' numeros
        - Leemos cada numero y lo guardamos en su respectiva posicion de la matriz

        - Para 0°: 
            - Creamos 2 bucles for, el 1ro itera por cada fila y el 2do por cada columna
            - Recorremos nuestra matriz de arriba hacia abajo, de izquierda a derecha
            - Imprimimos el valor de cada posicion hasta terminar

        - Para 90°: 
            - Creamos 2 bucles for, el 1ro itera por cada columna y el 2do por cada fila
            - Recorremos nuestra matriz de izquierda a derecha, de abajo hacia arriba
            - Imprimimos el valor de cada posicion hasta terminar
        
        - Para 180°: 
            - Creamos 2 bucles for, el 1ro itera por cada fila y el 2do por cada columna
            - Recorremos nuestra matriz de abajo hacia arriba, de derecha a izquierda
            - Imprimimos el valor de cada posicion hasta terminar

        - Para 270°: 
            - Creamos 2 bucles for, el 1ro itera por cada columna y el 2do por cada fila
            - Recorremos nuestra matriz de derecha a izquierda, de arriba hacia abajo
            - Imprimimos el valor de cada posicion hasta terminar

        Ejemplo:
            o = Esquina superior izquierda
            
            - Para 0°, vamos de arriba -> abajo, izquierda -> derecha
            o --->
            | [1, 2, 3]
            v [4, 5, 6]
              [7, 8, 9]

            - Para 90°, vamos izquierda -> derecha, abajo -> arriba
              [1, 2, 3]    [7, 4, 1]
            ^ [4, 5, 6]  = [8, 5, 2]
            | [7, 8, 9]    [9, 6, 3]
            o --->

            - Para 180°, vamos abajo -> arriba, derecha -> izquierda
            [1, 2, 3]      [9, 8, 7]
            [4, 5, 6] ^  = [6, 5, 4]
            [7, 8, 9] |    [3, 2, 1]
                 <--- o
            
            - Para 270°, vamos derecha -> izquierda, arriba -> abajo
                 <--- o
            [1, 2, 3] |    [3, 6, 9]
            [4, 5, 6] v  = [2, 5, 8]
            [7, 8, 9]      [1, 4, 7]
    */

    return 0;
}