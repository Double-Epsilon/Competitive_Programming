#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

/* Edit Distance:
    - Se te dan dos cadenas s1 y s2, y las operaciones que se pueden realizar en s1
    - La tarea consiste en determinar el numero mínimo de ediciones (operaciones) necesarias para convertir s1 en s2
    - Las operaciones son:
        - Insertar : Inserta cualquier caracter antes o despues de cualquier indice de s1
        - Eliminar: Eliminar un caracter de s1
        - Reemplazar: Reemplaza un caracter en cualquier indice de s1 con algun otro caracter.
    
    Ejemplos:
        - Entrada: s1 = "hola", s2 = "hiola" 
        - Salida: 1 
        - Explicación: Podemos convertir s1 en s2 insertando una 'i' entre la 'h' y 'o' de s1

        - Entrada: s1 = "gfg", s2 = "gfg" 
        - Salida: 0 
        - Explicación: Ambas cadenas son iguales

        - Entrada: s1 = "abcd", s2 = "bcfe" 
        - Salida: 3 
        - Explicación: Podemos convertir s1 en s2 eliminando 'a', reemplazando 'd' con 'f' e insertando 'e' al final.
*/

/* ¿Que haremos?:
    - La idea es procesar todos los caracteres uno por uno, comenzando desde el lado izquierdo o derecho de ambas cadenas.  
    - Procesemos desde el extremo izquierdo de las cadenas:
        - Hay 2 posibilidades para cada par de caracteres que recorremos: coinciden o no
            - Si los caracteres de ambas cadenas coinciden:
                - Los omitimos (no hacemos operacion)
                - En ambas cadenas nos pasamos al siguiente caracter
            
            - Si los caracteres no coinciden:
                - Realizamos las 3 operaciones (insertar, reemplazar y eliminar):
                    - Insertar : Avanzamos al siguiente caracter de la cadena s2
                    - Eliminar : Avanzamos al siguiente caracter de la cadena s1
                    - Reemplazar : Avanzamos al siguiente caracter de ambas cadenas
                - Calculamos recursivamente para cada operacion el resultado para la parte restante de la cadena
                - Al finalizar estas operaciones, seleccionamos la respuesta mínima y le sumamos 1 (una operacion realizada)
    
    - Cuando hayamos llegado al final de alguna de las 2 cadenas, realizamos:
        - Si llegamos al final de s1, retornamos la cantidad de caracteres restantes de s2 (Insertamos a s1)
        - Si llegamos al final de s2, retornamos la cantidad de caracteres restantes de s1 (Eliminamos de s1)
*/

const int N = 2005; // Variable constante equivalente al largo maximo de las cadenas
string s1, s2; // Variables tipo string equivalentes a 's1' y 's2' (las cadenas que debemos igualar) 
int mem[N][N]; // Matriz para guardar memoria de situaciones pasadas (evitar recursiones ya calculadas)

// editDistance: Funcion que calcula la minima cantidad de operaciones para que 's1' y 's2' sean iguales
int editDistance(int i, int j){ // i = Posicion actual de 's1', j = Posicion actual de 's2'
    if(i == s1.size()) return s2.size() - j; // Si llegamos al final de 's1', retornamos los caracteres restantes de 's2' (Insertar)
    if(j == s2.size()) return s1.size() - i; // Si llegamos al final de 's2', retornamos los caracteres restantes de 's1' (Eliminar)
    if(mem[i][j] != -1) return mem[i][j]; // Si ya calculamos esta situacion, retornamos el calculo
    
    // Si son caracteres iguales, los omitimos, pasamos a los siguientes y no hacemos operacion
    if(s1[i] == s2[j]) return editDistance(i+1, j+1);
    
    // Retornamos la situacion que ocupe menos operaciones en realizarse
    return mem[i][j] = min({editDistance(i+1, j) + 1, // Eliminar (Avanzamos uno en 's1')
                            editDistance(i, j+1) + 1, // Insertar (Avanzamos uno en 's2')
                            editDistance(i+1, j+1) + 1}); // Reemplazar (Avanzamos uno en ambas cadenas)
}

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida

    memset(mem, -1, sizeof mem); // Asignamos "-1" a todas las posiciones de 'mem' (no han sido visitadas)
    
    cin >> s1 >> s2; // Leemos el valor de 's1' y 's2' 
    
    cout << editDistance(0, 0); // Imprimimos la cantidad minima de operaciones necesarias para convertir 's1' en 's2'
    
    return 0;
}

/* Ejemplo:
    s1 = FOOD
    s2 = MONEY

    Paso #1 (Operaciones = 0):
         i
        [F, O, O, D]
        [M, O, N, E, Y]
         j
        (Reemplazamos 'F' por 'M'; +1 Operacion)
    
    Paso #2 (Operaciones = 1):
            i
        [M, O, O, D]
        [M, O, N, E, Y]
            j
        (No hacemos nada, caracteres iguales; +0 Operaciones)
    
    Paso #3 (Operaciones = 1; Caracteres iguales):
               i
        [M, O, O, D]
        [M, O, N, E, Y]
               j
        (Reemplazamos 'O' por 'N'; +1 Operacion)
    
    Paso #4 (Operaciones = 2):
                  i
        [M, O, N, D]
        [M, O, N, E, Y]
                  j
        (Reemplazamos 'D' por 'E'; +1 Operacion)
    
    Paso #5 (Operaciones = 3):
                     i
        [M, O, N, E]
        [M, O, N, E, Y]
                     j
        (Llegamos al final de 's1', insertamos a 's1' los caracteres sobrantes en 's2' (Uno: 'Y'); +1 Operacion)
    
    Paso #6 (Operaciones = 4):
                     i
        [M, O, N, E, Y]
        [M, O, N, E, Y]
                     j
        (Terminamos el proceso con 4 operaciones como minimo)
*/