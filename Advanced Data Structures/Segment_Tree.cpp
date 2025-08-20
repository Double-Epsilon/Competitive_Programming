#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

/* Segment Tree:
    - Segment Tree (Arbol de Segmentos) es una estructura de datos que permite la consulta y actualizacion eficiente de intervalos/segmentos de un arreglo
    - Es particularmente util para problemas que involucran consultas de rango sobre un rango específico de elementos en un arreglo

    - El arbol se construye recursivamente dividiendo el arreglo en segmentos hasta que cada segmento representa un solo elemento
    - Cada segmento tiene guardados valores correspondientes a la respuesta para ese segmento, ademas de punteros a sus segmentos hijos (Si los tiene)
    - Esta estructura permite realizar operaciones de consulta y actualizacion rapidas con una complejidad de tiempo de O(log n)
    - Mientras que para un problema de querys, la complejidad total del programa seria de O(q log n)
*/

/* ¿Que haremos?:
    - La idea principal de la estructura es dividir el arreglo en subarreglos mas pequeños con el fin de mantener respuestas cortas para varios rangos
    - Al tener varios rangos pequeños ya calculados, se puede formar con ellos rangos mas grandes y emplear las respuestas para formar una respuesta mas grande

    CREACION DEL ARBOL {Complejidad: O(N)}
        - Iniciamos tomando el rango global del arreglo y lo dividimos en 2 partes iguales: 'izq' y 'der'
        - Por ejemplo, para 'a' = [1, 2, 3, 4, 5], su rango global seria [0, 4]
        - Sacamos la mitad del arreglo, que se calcula con 'm' = (l+r) / 2, donde 'l' y 'r' son los valores del rango
        - Para sacar el rango de 'izq', definimos que su rango es [l, m], donde 'l' es el limite izquierdo del rango y 'm' es la mitad del arreglo
        - Para sacar el rango de 'der', definimos que su rango es [m+1, r], donde 'm' es la mitad del arreglo y 'r' es el limite derecho del rango
        - Ahora, tenenos los rangos de 'izq' (para el ejemplo: 'izq' = [0, 2]) y 'der' (para el ejemplo: 'der' = [3, 4])

        - Repetimos este proceso para cada rango que obtengamos (es decir, aplicamos este proceso para 'izq' y 'der')
        - Dejamos de realizar el proceso cuando el rango consta solo de un elemento, pues este ya no se puede dividir mas (por ejemplo: [3, 3])
    
    CONSULTA {Complejidad: O(log N)}
        - Cuando se nos hace una consulta para un rango, hay 2 posibles situaciones:
            1. El rango corresponde a un segmento ya calculado, en este caso simplemente se regresa la respuesta precalculada
            2. El rango corresponde a la union de varios subsegmentos
        - Para un cuando se da un caso del tipo 2, necesitaremos recorrer los hijos 'izq y 'der' de cada segmento (empezando con el global)
        - Repetiremos recursivamente el proceso hasta que encontremos un segmento con un rango que cubra totalmente una parte o la totalidad del rango consultado
        - Al regresar de cada llamada, fusionaremos las respuestas recibidas de cada uno de sus hijos con el fin de formar una respuesta completa al rango consultado

        - EJEMPLO:
            - Para cada consulta, buscaremos el numero mas grande en el rango [l, r]
            - Para el arreglo 'a' = [5, 8, 2, 1, 7], su arbol de segmentos quedaria:
                                    [0, 4]
                               /            \
                          [0, 2]            [3, 4]
                          /    \            /    \
                     [0, 1]    [2, 2]  [3, 3]    [4, 4]
                     /    \
                [0, 0]    [1, 1]
            - Si hicieramos una consulta al rango [0, 2], simplemente regresariamos la respuesta almacenada en el rango correspondiente
            - En caso de que hicieramos una consulta al rango [0, 3], hariamos lo siguiente:
                - Iniciamos en el segmento raiz [0, 4]; como el rango posee un extremo fuera del rango consultado, dividimos nuestra busqueda a 'izq' y 'der':
                |   - Para 'izq' [0, 2], debido a que el segmento cubre una parte del rango consultado (no su totalidad), regresamos su respuesta almacenada (en este caso, '8')
                |   - Para 'der' [3, 4], el rango sigue teniendo un extremo fuera del rango consultado, por lo que volvemos a dividir nuestra busqueda a 'izq' y 'der':
                |   |   - Para 'izq' [3, 3], el segmento cubre una parte del rango consultado, por lo que regresamos su respuesta almacenada (en este caso, '1')
                |   |   - Para 'der' [4, 4], el rango no es parte del rango consultado ni total ni parcialmente, por lo que devolvemos un valor -infinito (pues es un rango que no nos sirve)
                - Ahora que hemos terminado nuestra busqueda, nos han regresado para 'izq' el valor '8' y  para 'der' el valor '1'
                - Solo queda verificar entre ellos cual es el resultado esperado (el mayor en este caso) y esa sera la respuesta
                - En este caso, el mayor entre '8' y '1' es '8', por lo que la respuesta para el rango [0, 3] es '8'
    
    ACTUALIZACION {Complejidad: O(log N)}
        - Para actualizar un valor, buscaremos el rango que cubre al elemento a actualizar, lo cambiaremos e iremos de regreso al segmento padre actualizando las respuesta precalculadas:
            - Tomemos como ejemplo el mismo caso anterior donde 'a' = [5, 8, 2, 1, 7] y su arbol de segmentos es:
                                    [0, 4]
                               /            \
                          [0, 2]            [3, 4]
                          /    \            /    \
                     [0, 1]    [2, 2]  [3, 3]    [4, 4]
                     /    \
                [0, 0]    [1, 1]
            - Si quisieramos hacer una actualizacion al elemento en el indice '1', hariamos lo siguiente:
                - Iniciamos en el segmento raiz [0, 4]; sacamos la mitad del rango 'm' y verificamos hacia que mitad se encuentra el elemento a buscar
                - Si el indice es menor o igual a 'm', entonces buscaremos en 'izq', de lo contrario, buscaremos en 'der'
                - En este caso, la mitad del rango 'm' = (l+r) / 2 es 'm' = '2' y ya que '1' <= '2', buscaremos en 'izq':
                |   - Estando en el segmento correspondiente a 'izq' [0, 2], repetimos el mismo proceso de encontrar la mitad y decidir hacia que lado irnos
                |   - En este caso, 'm' = '1' y como '1' <= '1', iremos hacia 'izq' de nuevo
                |   |   - Estando en 'izq' [0, 1], seguimos el mismo proceso anterior
                |   |   - En este caso, 'm' = '0' y como '1' > '0', esta vez iremos hacia 'der'
                |   |   |   - Una vez en 'der' [1, 1], nos damos cuenta de que este rango es de una sola posicion y corresponde al indice que buscamos
                |   |   |   - Entonces actualizamos las respuestas precalculadas para este segmento y regresamos la recursion con el fin de actualizar las demas respuestas
                |   |   - Regresamos a [0, 1] y actualizamos la respuesta precalculada comparando el mayor actual con el nuevo numero actualizado, luego regresamos la recursion
                |   - Regresamos a [0, 2] y actualizamos la respuesta precalculada comparando el mayor actual con el nuevo numero actualizado, luego regresamos la recursion
                - Regresamos a [0, 4] y actualizamos la respuesta precalculada comparando el mayor actual con el nuevo numero actualizado, luego regresamos la recursion
                - Como hemos llegado al segmento raiz, terminamos de actualizar los valores en el arbol de segmentos
*/

// Para este problema, buscaremos el valor maximo y minimo dentro de un rango [l, r]

const int INF = 1e9; // Definimos 'INF' con un numero inalcanzable para cualquier 'a[i]'; sera nuestro "infinito"

// Estructura correspondiente a cada segmento del arbol
struct Segment{
    int l, r; // 'l' = Inicio del rango, 'r' = Final del rango
    int mn, mx; // 'mn' = Valor minimo en este rango, 'mx' = Valor maximo en este rango
    Segment* izq; // 'izq' = Puntero hacia el segmento a la izquierda de este
    Segment* der; // 'der' = Puntero hacia el segmento a la derecha de este

    // Metodo constructor para 'Segment'
    Segment(int _l, int _r){ // '_l' = Inicio del rango, '_r' = Final del rango
        // Asignamos los valores dados a su respectiva variable
        l = _l;
        r = _r;
    }

    // Funcion 'pull': Actualiza la respuesta precalculada para este rango utilizando las respuestas precalculadas de sus hijos 'izq' y 'der'
    void pull(){
        mn = min(izq -> mn, der -> mn); // El valor minimo 'mn' obtendra el valor de la respuesta precalculada minima entre 'izq' y 'der'
        mx = max(izq -> mx, der -> mx); // El valor maximo 'mx' obtendra el valor de la respuesta precalculada maxima entre 'izq' y 'der'
    }

    // Funcion 'build': Construye el segmento actual y define los segmentos 'izq' y 'der'
    void build(const vector<int>& a){ // 'a' = Arreglo del que sacaremos los valores
        if(l == r){ // Si 'l' es igual a 'r', hemos llegado a un segmento con solo un elemento
            mn = mx = a[l]; // Tanto el valor minimo 'mn' como maximo 'mx' de este segmento seran el valor actual del arreglo en esa posicion 'a[l]'
            return; // Retornamos la recursion, pues no necesitamos definir un 'izq' y 'der' (no existen)
        }

        int m = (l+r) / 2; // Calculamos el valor de la mitad 'm'
        izq = new Segment(l, m); // Creamos un nuevo segmento que ira desde 'l' hasta 'm' y lo almacenamos en 'izq' 
        der = new Segment(m+1, r); // Creamos un nuevo segmento que ira desde 'm+1' hasta 'r' y lo almacenamos en 'der' 

        izq -> build(a); // Construimos el segmento 'izq' y todos sus hijos
        der -> build(a); // Construimos el segmento 'der' y todos sus hijos

        pull(); // Llamamos a la funcion 'pull()' para precalcular la respuesta de este rango
    }

    // Funcion 'update': Actualiza un valor especifico del arreglo
    void update(int idx, int v){ // 'idx' = Indice donde actualizaremos el valor, 'v' = Nuevo valor que obtendra el indice 'idx'
        if(l == r){ // Si 'l' es igual a 'r', hemos llegado a un segmento con solo un elemento
            mn = mx = v; // Tanto el valor minimo 'mn' como maximo 'mx' de este segmento seran el nuevo valor actualizado
            return; // Retornamos la recursion, pues ya hemos actualizado y ahora hay que actualizar las respuestas de los segmentos padres
        }

        int m = (l+r) / 2; // Calculamos el valor de la mitad 'm'
        if(idx <= m) izq -> update(idx, v); // Si el indice 'idx' es menor o igual a la mitad 'm', entonces buscaremos el indice en 'izq'
        else der -> update(idx, v); // En caso contrario, buscaremos el indice en 'der'

        pull(); // Una vez haya regresado la recursion a este segmento, llamamos a 'pull()' para que vuleva a precalcular la respuesta de este rango
    }

    // Funcion 'solve': Retorna un valor correspondiente a la respuesta para un rango [l, r]
    pair<int, int> solve(int _l, int _r){ // '_l' = Inicio del rango, '_r' = Final del rango
        if(r < _l || _r < l) return make_pair(INF, -INF); // Si 'r' es menor a '_l' o '_r es menor a 'l' (es decir, este segmento esta fuera del rango), retornamos 'INF' (este segmento no nos sirve)
        if(_l <= l && r <= _r) return make_pair(mn, mx); // Si '_l' es menor o igual a 'l' y 'r' es menor o igual a '_r' (es decir, este segmento esta completamente dentro del rango), retornamos 'mn' y 'mx' (nos sirve el segmento completo)
        
        pair<int, int> a = izq -> solve(_l, _r); // 'a' = La respuesta retornada por 'solve()' para el segmento 'izq' en el rango de busqueda
        pair<int, int> b = der -> solve(_l, _r); // 'b' = La respuesta retornada por 'solve()' para el segmento 'der' en el rango de busqueda
        return make_pair(min(a.first, b.first), max(a.second, b.second)); // Retornamos la respuesta precalculada minima 'mn' y maxima 'mx' de entre las respuestas precalculadas 'a' y 'b'
    }
};

// Funcion principal 'main()'
int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida

    int n; cin >> n; // 'n' = Tamaño del arreglo / Cantidad de elementos
    vector<int> a(n); // 'a' = Arreglo donde guardaremos los 'n' elementos
    for(int i=0; i<n; i++){ 
        cin >> a[i]; // Leemos los 'n' elementos y los almacenamos en 'a'
    }

    Segment root(0, n-1); // 'root' = Segmento principal que abarca el rango de '0' hasta 'n-1' (recordemos que los indices estan 0-indexados)
    root.build(a); // Construimos el segmento 'root' y debido a la recursion, tambien creamos todos los demas segmentos del arbol

    int q; cin >> q; // 'q' = Cantidad de querys a realizar
    while(q--){ // Mientras queden querys por realizar...
        int op; cin >> op; // 'op' = Tipo de query a realizar

        if(op == 1){ // Si 'op' es de tipo '1' (consulta)...
            int l, r; cin >> l >> r; // 'l' = Inicio del rango, 'r' = Final del rango
            pair<int, int> ans = root.solve(l, r); // 'ans' = Respuesta final para el rango [l, r]
            cout << ans.first << " " << ans.second << '\n'; // Imprimimos el valor de 'ans'
        }else if(op == 2){ // Si 'op' es de tipo '2' (actualizacion)...
            int idx, v; cin >> idx >> v; // 'idx' = Indice a actualizar, 'v' = Nuevo valor para el indice 'idx'
            root.update(idx, v); // Actualizamos el indice 'idx' con el nuevo valor 'v'
        }
    }
    
    return 0;
}
