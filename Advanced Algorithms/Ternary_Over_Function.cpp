#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::
#define ll long long // Definir 'll' para 'long long'

/* Mejor valor de una funcion (Ternary Over a Function):
    - En este caso abarcaremos otro uso que se le puede dar a una busqueda ternaria
    - Utilizaremos la busqueda ternaria para encontrar el mejor resultado conforme a una funcion
    - Esta funcion se puede evaluar con esta busqueda porque es del tipo no lineal
    - Trabajaremos con un problema en especifico con el fin de explicar mejor la situacion
*/

/* Problema:
    - Bob decidio abrir una panaderia. El dia de la inauguracion, horneo 'n' panes que puede vender
    - El precio habitual de un pan es 'a' monedas, pero para atraer clientes, Bob organizo la siguiente promocion:
        - Bob elige un numero entero 'k' (0 ≤ k ≤ min(n, b))
        - Bob vende los primeros 'k' panes a un precio modificado
        - En este caso, el precio del 'i-esimo' (1 ≤ i ≤ k) pan vendido es de "(b − i + 1)" monedas
        - Los restantes 'n − k' panes se venden en 'a' monedas cada uno
        - Toma en cuenta que 'k' puede ser igual a 0, en cuyo caso Bob vendera todos los panes a 'a' monedas cada uno
    - Ayuda a Bob a determinar la ganancia maxima que puede obtener al vender todos los 'n' panes
    
    - Entrada:
        - La primera linea contiene un unico entero 't' (1 ≤ t ≤ 10^4) — el numero de casos de prueba
        - Le seguiran 't' lineas, cada una representando un caso de prueba diferente
        - La unica linea de cada caso de prueba contiene tres numeros enteros 'n', 'a' y 'b' (1 ≤ n, a, b ≤ 10^9), donde:
            - 'n' es la cantidad de panes
            - 'a' es el precio habitual de un pan
            - 'b' es el precio del primer pan que se vendera con la promocion
    - Salida:
        - Para cada caso de prueba, imprime un unico numero entero: la ganancia maxima que Bob puede obtener
*/

/* ¿Que haremos?:
    - Tenemos que encontrar la ganancia maxima que Bob puede obtener aplicando la oferta a los primeros 'k' panes
    - El precio de un pan en oferta se define con la formula (b - i + 1), donde 'b' es el precio de oferta inicial e 'i' el numero de pan
    - El resto de los panes se venderan al precio habitual
    - La ganancia total de colocar la oferta a los primeros 'k' panes se define como:
        s = (a * (n-k)) + (b * k - gauss(k) + k)
        - Donde:
            - 's' = Ganancia total de vender los 1ros 'k' panes con la oferta
            - 'a' = Precio habitual de un pan
            - 'n' = Cantidad total de panes
            - 'k' = Cantidad de panes que se venderan en oferta
            - 'gauss(x)' = Funcion que calcula la suma de Gauss de un numero 'x'
    - Al emplear la formula con cualquier valor de 'k' posible, podemos saber cual es la ganancia de cada sitaucion posible
    - Simplemente queda encontrar cual es la MAXIMA GANANCIA POSIBLE

    - Debido a que la formula de las ganancias se grafica como una funcion no lineal, no podemos emplear una busqueda binaria
    - En su lugar podemos utilizar una busqueda ternaria utilizando los resultados de cada funcion como elemento comparativo
    - Para hacerlo, emplearemos los mismo principios de una busqueda ternaria, pero con algunas modificaciones:
        1. Inicializacion:
            - Se establecen dos punteros ('izq' y 'der'), que apuntan inicialmente al 1er y ultimo elemento del espacio de busqueda
        2. Dividir el espacio de busqueda lo mas posible:
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
            - Los datos ahora estan divididos en ['izq' -> 'mid1'], ['mid1' -> 'mid2'] y ['mid2' -> 'der']
        3. Comparacion:
            - Si el valor de la funcion en 'izq' es mayor o igual al de la funcion en 'der', actualizamos el puntero derecho a 'mid2'
            - Si el valor de la funcion en 'der' es mayor al de la funcion en 'izq', actualizamos el puntero izquierdo a 'mid1'
            
            - Repetiremos los pasos 2. y 3. una gran cantidad de veces con el fin de quedarnos con un espacio de busqueda pequeño
        4. Evaluacion y finalizacion:
            - Una vez tenemos nuestro espacio de busqueda de tamaño reducido, procedemos a verificar manualmente que resultado es mejor
            - Iteramos cada posible valor restante en el intervalo [izq -> der]
            - Guardamos en una variable 'best' el mejor resultado de los valores restantes
            - Al final imprimimos 'best', que termina siendo el mejor resultado de evaluar la funcion
*/

// Nota: En este codigo todos los numeros se utilizaran con tipo de dato 'long long' debido a los limites del problema

ll n, a, b; // 'n' = numero de panes, 'a' = precio general, 'b' = precio de promocion
// Estas variables dependen del problema actual, podrian cambiar acorde al problema

// 'gauss': Funcion para calcular la suma de Gauss (es exclusiva para este problema, no es siempre necesaria)
ll gauss(ll x){ // 'x' = Ultimo numero hasta el que se sumara
    return x * (x + 1LL) / 2LL; // Retornar la suma de Gauss
}

// 'func': Funcion sobre la que se buscara el mejor resultado (funcion no lineal que define la forma del grafico)
ll func(ll k){ // 'k' = Posicion actual a revisar
    // Esta funcion varia segun la formula que se quiere analizar, por lo que se tendra que cambiar acorde al problema
    // Para este problema, la formula se divide en 2: los panes SIN promocion y los panes CON promocion
    ll s = a * (n - k); // Para todos los panes SIN promocion, la formula es simplemente "a * (n-k)"
    s += b * k - gauss(k) + k; // Para todos los panes CON promocion, la formula es "b * k - gauss(k) + k"
    
    return s; // Retorna la suma de los panes SIN y CON promocion
}

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    int t; cin >> t; // Leer numero de casos de prueba
    while(t--){ // Mientras falten casos de prueba...
        cin >> n >> a >> b; // Leemos los valores de 'n', 'a' y 'b'
        
        ll izq = 0;  // 'izq' = Punto mas a la izquierda
        ll der = n; // 'der' = Punto mas a la derecha

        // Recortaremos 123 veces el intervalo de valores ['izq' -> 'der'] para conseguir un intervalo mas pequeño
        for(int i=0; i<123; i++){ // 123 es un numero arbitrario que la mayoria de veces basta para sacar el rango (en caso que no funcione, utiliza 234 y asi sucesivamente)
            ll mid1 = izq + (der - izq) / 3; // Calculamos la posicion del puntero medio 1 ('mid1')
            ll mid2 = der - (der - izq) / 3; // Calculamos la posicion del puntero medio 2 ('mid2')
            
            if(func(izq) >= func(der)){ // Si el mejor resultado esta a la izquierda...
                der = mid2; // Recorro mi punto derecho al 2do corte
            }else{ // Si no...
                izq = mid1; // Recorro mi punto izquierdo al 1er corte
            }
        }

        /*
        - Al final nos quedara un rango de valores acortado ['izq' -> 'der'] donde se encuentra el mejor resultado
        - Al ser pocos los valores restantes, podemos verificar el resultado de cada uno por individual
        - Finalmente encontraremos el mejor resultado de la funcion =)
        */
        
        ll best = 0LL; // 'best' = Mejor resultado
        while(izq <= der){ // Mientras existan valores en el rango ['izq' -> 'der']...
            best = max(best, func(izq)); // Sacamos el mejor resultado hasta el momento
            izq++; // Avanzamos una posicion
        }
        
        cout << best << '\n'; // Imprimimos el mejor resultado obtenido
    }
    
    return 0;
}