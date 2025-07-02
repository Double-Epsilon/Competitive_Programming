#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

/* Knapsack Algorithm:
    - Se te dan 'n' articulos donde cada articulo tiene asociado un peso y un valor
    - Tambien se te da una mochila con capacidad 'w', es decir, la mochila puede contener como maximo 'w' peso en ella
    - La tarea es colocar los articulos en la mochila de tal manera que la suma de los valores asociados sea la maxima posible
    - Podemos poner o no un articulo dentro de la mochila (no es posible poner solamente una parte del articulo)

    Ejemplos:
        - Entrada:  w = 4, n = 3, peso[n] = [4, 5, 1], valor[n] = [1, 2, 3]
        - ​Salida: 3
        - Explicacion: Hay dos articulos que tienen un peso menor o igual a 4:
            - Si seleccionamos el articulo con peso 4, la ganancia obtenida es de 1
            - Si seleccionamos el articulo con peso 1, la ganancia obtenida es de 3
            - No podemos poner juntos los articulos con peso 4 y 1, ya que la capacidad de la mochila es 4 y excederia su capacidad
            - Por lo tanto, la ganancia maxima posible es 3 (con el articulo de peso 1 dentro de la mochila)
        
        - Entrada: w = 4, n = 5, peso[n] = [1, 2, 3, 2, 2], valor[n] = [8, 4, 0, 5, 3]
        - Salida: 13
        - Explicacion: La ganancia maxima posible es de 13 (con los articulos de valor 8 y 5 (pesos 1 y 2) dentro de la mochila)
*/

/* ¿Que haremos?:
    - La idea es probar todas las combinaciones de articulos validas (es decir, que no excedan el peso de la mochila)
    - Para ello, partiremos en cada articulo y mediante un arbol recursivo calcularemos las posibles soluciones al problema
    - Es decir, para cada articulo calcularemos 2 posibilidades diferentes: tomar el articulo o no tomarlo
    - Por ejemplo, para un conjunto de articulos [A: [1, 1], B: [2, 7], C: [3, 11]] y una mochila de capacidad 5, su arbol recursivo seria:
                         []
    A:           /                 \
              []                   [A]
    B:     /      \           /          \
          []      [B]       [A]        [A,B]
    C:   /  \    /   \     /   \      /     \
        [] [C] [B] [B,C] [A] [A,C] [A,B] [A,B,C]
    V:  0 |11 | 7 | 18  | 1 | 12  |  8  |  19
    W:  0 | 3 | 2 |  5  | 1 |  4  |  3  |   6
        - Donde:
            - Tomar el camino de la izquierda significa NO tomar el articulo actual
            - Tomar el camino de la derecha significa SI tomar el articulo actual
            - 'V' = Ganancia final de la mochila
            - 'W' = Peso final de la mochila
    - Aunque la solucion [A, B, C] tiene la mayor ganancia total (19), esta excede el peso maximo de la mochila ('w' = 5) ('w' < 6)
    - Por lo tanto, la solucion seria 18, con los articulos [B, C] como respuesta y peso total de 5 ('w' >= 5)
*/

const int N = 2005; // Cantidad maxima de articulos
const int INF = 1e9; // Numero infinito (para nuestros estandares)

int w; // Capacidad de la mochila
int n; // Cantidad de articulos
int p[N]; // Peso de cada articulo
int v[N]; // Valor de cada articulo
int mem[N][N]; // Memoria (guardar los resultados ya calculados de las recursiones)
bool vis[N][N]; // Visitados (su arbol recursivo ya fue calculado o no)

// Funcion recursiva "Knapsack" (Algoritmo de la Mochila)
int knapsack(int pos, int peso){ // 'pos' = posicion actual en el arreglo, 'peso' = peso acumulado hasta el momento
    if(peso > w) return -INF; // Si 'peso' es mayor a 'w', retorna -INF (caso no valido, excedio el peso limite de la mochila)
    if(pos == n) return 0; // Si 'pos' es igual a 'n', retorna 0 (ya no quedan items disponibles)
    
    if(vis[pos][peso]) return mem[pos][peso]; // Si ya lo visitamos, retorna su respuesta almacenada en la memoria
    
    int tomar = knapsack(pos+1, peso+p[pos]) + v[pos]; // 'tomar' = Arbol recursivo donde SI tomamos el articulo
    int no_tomar = knapsack(pos+1, peso); // 'no_tomar' = Arbol recursivo donde NO tomamos el articulo
    
    mem[pos][peso] = max(tomar, no_tomar); // Guardamos en memoria el mayor resultado entre tomar y no tomar el articulo
    vis[pos][peso] = true; // Marcamos como visitado
    
    return mem[pos][peso]; // Retornamos la respuesta almacenada en la memoria (mejor respuesta para este arbol recursivo)
}

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    cin >> w >> n; // Leemos el valor de 'w' (capacidad de la mochila) y de 'n' (cantidad de articulos)
    
    for(int i=0; i<n; i++){
        cin >> p[i] >> v[i]; // Leemos los 'n' valores de cada articulo ('p[i]' = peso, 'v[i]' = valor)
    }
    
    cout << knapsack(0, 0); // Imprimimos el resultado final de 'knapsack' iniciando en la posicion 0 y con peso inicial 0

    return 0;
}

/* Ejemplo:
    w = 4
    n = 3
    p[n] = [1, 2, 3]
    v[n] = [4, 5, 8]
            A, B, C

    - Mochila actual: []
    - Peso actual: 0
    - Ganancia actual: 0
    - Siguiente articulo: A = {1, 4}
        - NO TOMAR:
        |    - Mochila actual: []
        |    - Peso actual: 0
        |    - Ganancia actual: 0
        |    - Siguiente articulo: B = {2, 5}
        |        - NO TOMAR:
        |        |    - Mochila actual: []
        |        |    - Peso actual: 0
        |        |    - Ganancia actual: 0
        |        |    - Siguiente articulo: C = {3, 8}
        |        |        - NO TOMAR:
        |        |        |    - Mochila final: []
        |        |        |    - Peso final: 0
        |        |        |    - Ganancia final: 0
        |        |        ------------------------------------------
        |        |        - SI TOMAR:
        |        |        |    - Mochila final: [C]
        |        |        |    - Peso final: 3
        |        |        |    - Ganancia final: 8
        |        |        ------------------------------------------
        |        ---------------------------------------------------
        |        - SI TOMAR:
        |        |    - Mochila actual: [B]
        |        |    - Peso actual: 2
        |        |    - Ganancia actual: 5
        |        |    - Siguiente articulo: C = {3, 8}
        |        |        - NO TOMAR:
        |        |        |    - Mochila final: [B]
        |        |        |    - Peso final: 2
        |        |        |    - Ganancia final: 5
        |        |        ------------------------------------------
        |        |        - SI TOMAR:
        |        |        |    - Mochila final: [B, C]
        |        |        |    - Peso final: 5
        |        |        |    - Ganancia final: 13
        |        |        ------------------------------------------
        |        ---------------------------------------------------
        ------------------------------------------------------------
        - SI TOMAR:
        |    - Mochila actual: [A]
        |    - Peso actual: 1
        |    - Ganancia actual: 4
        |    - Siguiente articulo: B = {2, 5}
        |        - NO TOMAR:
        |        |    - Mochila actual: [A]
        |        |    - Peso actual: 1
        |        |    - Ganancia actual: 4
        |        |    - Siguiente articulo: C = {3, 8}
        |        |        - NO TOMAR:
        |        |        |    - Mochila final: [A]
        |        |        |    - Peso final: 1
        |        |        |    - Ganancia final: 4
        |        |        ------------------------------------------
        |        |        - SI TOMAR:
        |        |        |    - Mochila final: [A, C]
        |        |        |    - Peso final: 4
        |        |        |    - Ganancia final: 12
        |        |        ------------------------------------------
        |        ---------------------------------------------------
        |        - SI TOMAR:
        |        |    - Mochila actual: [A, B]
        |        |    - Peso actual: 3
        |        |    - Ganancia actual: 9
        |        |    - Siguiente articulo: C = {3, 8}
        |        |        - NO TOMAR:
        |        |        |    - Mochila final: [A, B]
        |        |        |    - Peso final: 3
        |        |        |    - Ganancia final: 9
        |        |        ------------------------------------------
        |        |        - SI TOMAR:
        |        |        |    - Mochila final: [A, B, C]
        |        |        |    - Peso final: 6
        |        |        |    - Ganancia final: 17
        |        |        ------------------------------------------
        |        ---------------------------------------------------
        ------------------------------------------------------------
    
    - Mochilas finales:
                    W   V
        - []        0   0
        - [C]       3   8
        - [B]       2   5
        - [B, C]    5   13 <- 2da mayor ganancia, pero sobrepasa peso maximo
        - [A]       1   4
        - [A, C]    4   12 <- 3ra mayor ganancia, no sobrepasa peso maximo
        - [A, B]    3   9
        - [A, B, C] 6   17 <- Mayor ganancia, pero sobrepasa peso maximo
    - Mayor subsecuencia: [A, C] (ans = 12)
*/