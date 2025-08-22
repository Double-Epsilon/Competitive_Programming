#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

/* Lazy Segment Tree:
    - Lazy Segment Tree (Arbol de Segmentos Perezoso) es una variante de Segment Tree especializada en actualizaciones de rangos
    - Es particularmente util para problemas que involucran actualizaciones sobre un rango específico de elementos en un arreglo

    - En un Segment Tree, la complejidad de una actualizacion es de O(log n) para un solo elemento
    - Para actualizar un rango de valores [l, r], se deberian realizar r-l+1 actualizaciones, lo que daria una complejidad de O((r-l+1) log n) por actualizacion de rango
    - En el peor caso, tocaria actualizar un rango [0, n-1], lo que seria una complejidad de O(n log n); una complejidad demasiado grande si se llegara a repetir varias veces
    - En este tipo de casos, es mejor utilizar un Lazy Segment Tree, pues su complejidad en una actualizacion de rangos es de O(log n); la misma que para una actualizacion individual

    - El arbol se construye de igual forma que un Segment Tree normal, (dividir el arreglo en segmentos hasta que cada segmento represente un solo elemento)
    - La diferencia radica en la forma en que se manejan las actualizaciones, pues aplicaremos una propagacion perezosa para manejarlas (Lazy Propagation)
    - Asi podemos realizar operaciones de consulta y actualizacion de rangos rapidas con una complejidad de tiempo de O(log n)
    - Y para un problema de querys, la complejidad total del programa seria de O(q log n)
*/

/* ¿Que haremos?:
    - En general, aplicaremos la misma logica que un Segment Tree comun, solamente cambiando la forma de actualizar valores
    - En un Segment Tree comun, la actualizacion se basa en llegar al segmento individual, actualizarlo, y posteriormente regresar recursivamente a sus padres para actualizar sus respuestas
    - En el caso de un Lazy Segment Tree, utilizaremos una propagacion perezosa para evitar buscar el segmento individual y asi ahorrar la recursion que esto conlleva
    - Es decir, cuando queramos actualizar un rango, simplemente buscaremos a los segmentos que conforman el rango completo y los actualizaremos solo a ellos
    - Sus segmentos hijos permaneceran sin actualizarse (modo 'lazy') y solo cambiaran cuando realmente sea necesario (esto es propagacion perezosa)

    - EJEMPLO:
        - Tomemos como ejemplo un arreglo 'a' de tamaño 'n' = 5, donde su arbol de segmentos se veria asi:
                               [0, 4]
                           /            \
                      [0, 2]            [3, 4]
                      /    \            /    \
                 [0, 1]    [2, 2]  [3, 3]    [4, 4]
                 /    \
            [0, 0]    [1, 1]
        - Si quisieramos hacer una actualizacion al rango [0, 3], hariamos lo siguiente:
        |   - Iniciamos en el segmento raiz [0, 4]; debido a que este segmento contiene elementos fuera del rango de actualizacion, dividiremos nuestra busqueda a 'izq' y 'der':
        |   |   - Para 'izq' [0, 2], este segmento contiene solamente elementos dentro del rango deseado, por lo que actualizaremos su respuesta y marcaremos a sus hijos [0, 1] y [2, 2] como 'lazy'
        |   |   - Para 'der' [3, 4], este segmento todavia contiene elementos fuera del rango deseado, por lo que volveremos a dividir nuestra busqueda en 'izq' y 'der':
        |   |   |   - Para 'izq' [3, 3], este segmento contiene un unico elemento que forma parte del rango deseado, por lo que actualizaremos su valor sin mas (no tiene hijos para posponer)
        |   |   |   - Para 'der' [4, 4], este segmento contiene un unico elemento que no forma parte del rango deseado, por lo que simplemente lo omitimos por completo
        |   |   |   - Una vez terminamos de actualizar, aprovechamos que regresamos al segmento [3, 4] y lo actualizamos tambien
        |   |   - Una vez terminamos de actualizar, aprovechamos que regresamos al segmento [0, 4] y lo actualizamos tambien
        |   - Acabada nuestra actualizacion, los segmentos modificados serian:
        |                                     [0, 4] Act.
        |                             /                      \
        |                        [0, 2] Act.                 [3, 4] Act.
        |                      /        \                  /        \
        |                 [0, 1] Lazy   [2, 2] Lazy   [3, 3] Act.   [4, 4] Sin camb.
        |            /             \
        |       [0, 0] Sin camb.   [1, 1] Sin camb.
        |       - Donde "Act." significa "Actualizado", "Lazy" significa "Modo Lazy" y "Sin camb." significa "Sin cambios"
        - Ahora, si quisieramos hacer una consulta al rango [0, 1], hariamos:
            - Iniciamos nuestro proceso comun de busqueda donde recorremos el arbol hasta llegar a los segmentos que conforman el rango de consulta
            - ...
            - Una vez llegamos al segmento [0, 1], deberiamos simplemente devolver la respuesta para contestar a la consulta, pues este rango conforma en su totalidad el rango deseado
            - Sin embargo, si hicieramos eso estariamos enviando una respuesta incorrecta debido a que la respuesta almacenada en este segmento no ha sido actualizada aun (se encuentra en modo 'lazy')
            - Antes de regresar la respuesta, debemos actualizar su valor con el valor correspondiente
            - Una vez actualizamos su respuesta, este segmento ya no se encuentra en modo 'lazy', pero sus hijos deben pasar a 'lazy' debido a que no han sido modificados aun
            - Acabado este proceso, podemos regresar la respuesta y deberia ser correcta
            - El arbol de segmentos al final quedaria:
                                            [0, 4] Act.
                                   /                      \
                              [0, 2] Act.                 [3, 4] Act.
                            /        \                  /        \
                       [0, 1] Act.   [2, 2] Lazy   [3, 3] Act.   [4, 4] Sin camb.
                     /        \
                [0, 0] Lazy   [1, 1] Lazy
    
*/

// Para este problema, buscaremos la suma dentro de un rango [l, r]
// Ademas, las consultas de tipo actualizacion aplicaran a un rango completo

// Estructura correspondiente a cada segmento del arbol
struct Segment{
    int l, r; // 'l' = Inicio del rango, 'r' = Final del rango
    int sum; // 'sum' = Valor de la suma de este rango
    Segment* izq; // 'izq' = Puntero hacia el segmento a la izquierda de este
    Segment* der; // 'der' = Puntero hacia el segmento a la derecha de este
    int lazy = 0; // 'lazy' = Cuando 'lazy' == '0', el segmento actual esta en modo 'lazy'
    // Cuando 'lazy' != '0', indica el cambio que se debe realizar a este segmento al momento de actualizarlo

    // Metodo constructor para 'Segment'
    Segment(int _l, int _r){ // '_l' = Inicio del rango, '_r' = Final del rango
        // Asignamos los valores dados a su respectiva variable
        l = _l;
        r = _r;
    }

    // Funcion 'pull': Actualiza la respuesta precalculada para este rango utilizando las respuestas precalculadas de sus hijos 'izq' y 'der'
    void pull(){
        sum = izq -> sum + der -> sum; // La suma 'sum' obtendra el valor de la suma de las respuesta precalculada de 'izq' y 'der'
    }

    // Funcion 'build': Construye el segmento actual y define los segmentos 'izq' y 'der'
    void build(const vector<int>& a){ // 'a' = Arreglo del que sacaremos los valores
        if(l == r){ // Si 'l' es igual a 'r', hemos llegado a un segmento con solo un elemento
            sum = a[l]; // El valor 'sum' de este segmento sera el valor actual del arreglo en esa posicion 'a[l]'
            return; // Retornamos la recursion, pues no necesitamos definir un 'izq' y 'der' (no existen)
        }

        int m = (l+r) / 2; // Calculamos el valor de la mitad 'm'
        izq = new Segment(l, m); // Creamos un nuevo segmento que ira desde 'l' hasta 'm' y lo almacenamos en 'izq' 
        der = new Segment(m+1, r); // Creamos un nuevo segmento que ira desde 'm+1' hasta 'r' y lo almacenamos en 'der' 

        izq -> build(a); // Construimos el segmento 'izq' y todos sus hijos
        der -> build(a); // Construimos el segmento 'der' y todos sus hijos

        pull(); // Llamamos a la funcion 'pull()' para precalcular la respuesta de este rango
    }

    // Funcion 'push': Actualiza el estado de un segmento cuando este se encuentra en modo 'lazy', ademas de establecer a sus hijos en modo 'lazy'
    void push(){
        if(lazy != 0){ // Solamente realizaremos esta actualizacion cuando el segmento actual se encuentre en modo 'lazy'
            int rango = r - l + 1; // 'rango' = Tamaño del rango correspondiente a este segmento
            sum = rango * lazy; // El nuevo valor de la suma 'sum' sera el tamaño del rango 'rango' por el valor almacenado en 'lazy'
            // Esto es ya que cuando actualizamos todos los valores de un rango a un mismo numero, la suma del rango es multiplicar ese numero por el tamaño del rango

            if(izq != NULL){ // Si 'izq' NO es 'NULL' (es decir, este segmento tiene hijos)
                izq -> lazy = lazy; // Definimos su segmento 'izq' como 'lazy'
                der -> lazy = lazy; // Definimos su segmento 'der' como 'lazy'
            }

            lazy = 0; // Este segmento ya NO esta en modo 'lazy'
        }
    }

    // Funcion 'updateRange': Actualiza un rango especifico del arreglo
    void updateRange(int _l, int _r, int val){ // '_l' = Inicio del rango, '_r' = Final del rango, 'val' = Nuevo valor que obtendran los elementos en el rango [_l, _r]
        push(); // Antes de actualizar, debemos asegurarnos de que este segmento no tiene actualizaciones pendientes

        if(r < _l || _r < l) return; // Si 'r' es menor a '_l' o '_r' es menor a 'l' (es decir, este segmento esta fuera del rango), retornamos (este segmento no nos sirve)

        if(_l <= l && r <= _r){ // Si '_l' es menor o igual a 'l' y 'r' es menor o igual a '_r' (es decir, este segmento esta completamente dentro del rango)...
            lazy = val; // Definimos este segmento como 'lazy' con el valor de 'val', pues lo vamos a actualizar con este valor (es esencial actualizarlo)
            push(); // Actualizamos el segmento actual y definimos a sus hijos como 'lazy'
            return; // Retornamos, pues no es necesario actualizar a sus hijos (estan en modo 'lazy')
        }

        // En caso de que solo necesitemos una parte del rango, dividiremos nuestra busqueda a 'izq' y 'der'
        izq -> updateRange(_l, _r, val); // Mandamos a actualizar la parte del rango que se encuentre en 'izq'
        der -> updateRange(_l, _r, val); // Mandamos a actualizar la parte del rango que se encuentre en 'der'

        sum = izq -> sum + der -> sum; // Actualizamos el valor de la suma 'sum' con las respuestas ya actualizadas de 'izq' y 'der'
    }

    // Funcion 'solve': Retorna un valor correspondiente a la respuesta para un rango [l, r]
    int solve(int _l, int _r){ // '_l' = Inicio del rango, '_r' = Final del rango
        if(r < _l || _r < l) return 0; // Si 'r' es menor a '_l' o '_r' es menor a 'l' (es decir, este segmento esta fuera del rango), retornamos 'INF' (este segmento no nos sirve)
        
        if(lazy != 0) push(); // Para evitar enviar una respuesta incorrecta, debemos asegurarnos de que este segmento no tiene actualizaciones pendientes
        if(_l <= l && r <= _r) return sum; // Si '_l' es menor o igual a 'l' y 'r' es menor o igual a '_r' (es decir, este segmento esta completamente dentro del rango), retornamos 'sum' (nos sirve el segmento completo)
        
        // En caso de que solo necesitemos una parte del rango, dividiremos nuestra busqueda a 'izq' y 'der'
        int a = izq -> solve(_l, _r); // 'a' = La respuesta retornada por 'solve()' para el segmento 'izq' en el rango de busqueda
        int b = der -> solve(_l, _r); // 'b' = La respuesta retornada por 'solve()' para el segmento 'der' en el rango de busqueda
        return a + b; // Retornamos la suma de las respuestas precalculada 'sum' de 'a' y 'b'
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
            cout << root.solve(l, r) << '\n'; // Imprimimos la respuesta final para el rango [l, r]
        }else if(op == 2){ // Si 'op' es de tipo '2' (actualizacion en rango)...
            int l, r, v; cin >> l >> r >> v; // 'l' = Inicio del rango, 'r' = Final del rango, 'v' = Nuevo valor que obtendran los elementos en el rango [l, r]
            root.updateRange(l, r, v); // Actualizamos todos los elementos en el rango [l, r] con el nuevo valor 'v'
        }
    }
    
    return 0;
}
