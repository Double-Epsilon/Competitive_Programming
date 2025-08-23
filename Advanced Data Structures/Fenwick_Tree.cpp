#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

/* Fenwick Tree (Binary Indexed Tree / BIT):
    - El Fenwick Tree (o Binary Indexed Tree / BIT) es una estructura de datos tipo arbol
    - Es muy util para trabajar con sumas en rangos y actualizaciones en tiempo logaritmico

    - Imagina que tienes un arreglo A de n elementos y quieres responder muchas veces preguntas del tipo:
        - Suma de rango: calcular A[l] + A[l+1] + ... + A[r]
        - Actualizar: cambiar el valor de una posicion A[i]
    - Si lo hacemos de forma bruta o lineal:
        - La suma de rango tarda O(n)
        - La actualizacion tarda O(1)
    - Pero si usamos Fenwick Tree:
        - La suma de rango tarda O(log n)
        - La actualizacion tarda O(log n)

    - El Fenwick Tree guarda las sumas parciales en un arreglo auxiliar BIT[]
    - Cada posicion BIT[i] almacena la suma de un segmento de A
    - La clave es como decidimos que segmento guarda cada BIT[i]
    - Ese segmento se determina por el ultimo bit encendido (Last Significant Bit / LSB) de i en binario
    - En otras palabras, LSB es el '1' mas a la derecha del numero i en binario

    - Ejemplo:
        - Recordemos que cada posicion equivale a (..., 16, 8, 4, 2, 1)
        - 6 = (110), entonces LSB(6) = 2 (porque el ultimo bit encendido es el bit equivalente a "2")
        - 12 = (1100), entonces LSB(12) = 4 (el ultimo bit encendido es el equivalente a "4")

    - En un Fenwick Tree de tamaño n:
        - BIT[i] guarda la suma de los ultimos LSB(i) elementos de A hasta la posicion i
        - Ejemplo:
            - Si A = [a1, a2, a3, a4, a5, a6, a7, a8]
                - BIT[1] guarda a1 (porque LSB(1) = 1, suma 1 elemento)
                - BIT[2] guarda a1 + a2 (porque LSB(2) = 2, suma los primeros 2 elementos desde i=2)
                - BIT[3] guarda a3 (porque LSB(3) = 1, suma el primer elemento desde i=3)
                - BIT[4] guarda a1 + a2 + a3 + a4 (porque LSB(4) = 4, suma los primeros 4 elementos desde i=4)
                - BIT[5] guarda a5 (porque LSB(5) = 1)
                - BIT[6] guarda a5 + a6 (porque LSB(6) = 2)
                - BIT[7] guarda a7 (porque LSB(7) = 1)
                - BIT[8] guarda a1 + ... + a8 (porque LSB(8) = 8)
*/

/* Que haremos?:
    - Ya que definimos como se guarda cada suma en un Fenwick Tree, ahora veamos como se realiza cada operacion:

    SUMA DE PREFIJO {Complejidad: O(log n)}
        - Queremos conseguir la suma de "A[1] + ... + A[i]"
        - El truco es ir saltando de bloque en bloque hacia atras usando 'LSB(i)'
        - En cada salto, sumamos a una variable el valor del bloque actual
        - Una vez llegamos o sobrepasamos al bloque en la posicion '0', hemos terminado de recorrer los bloques necesarios
        - Para ese punto, ya tenemos la suma correspondiente al bloque 'i'

        - EJEMPLO:
            - Para i=13 (recordemos que LSB equivale al bit encendido de menor valor [mas a la derecha]):
                - Por ahora, i = 13; Agregamos el valor de BIT[13]
                - 13 = (1101); entonces LSB(13) = 1, asi que i -= 1 = 12; Agregamos el valor de BIT[12]
                - 12 = (1100); entonces LSB(12) = 4, asi que i -= 4 = 8; Agregamos el valor de BIT[8]
                - 8 = (1000); entonces LSB(8) = 8, asi que i -= 8 = 0. Debido a que hemos llegado al bloque 0, aqui terminamos de agregar valores

            - Cada sub-bloque es mas pequeño y todos estan contenidos en el bloque 13
        - Podemos decir que la suma de todos los sub-bloques contenidos en el bloque 'i' equivale a la suma de prefijos de 'i'
    
    ACTUALIZACION {Complejidad: O(log n)}
        - Queremos hacer "A[i] += x"
        - Entonces debemos actualizar todos los 'BIT[j]' que incluyen a 'A[i]'
        - Para ello, saltaremos de bloque en bloque hacia adelante utilizando 'LSB(i)'
        - En cada salto, modificamos el valor de 'BIT[i]' sumandole el valor de 'x'
        - Una vez sobrepasamos el tamaño del arbol 'n', dejamos de avanzar
        - Para este punto, ya hemos terminado de actualizar todos los bloques que contienen dentro de si a 'BIT[i]'

        - EJEMPLO:
            - Para i=1 y n=8 (recordemos que LSB equivale al bit encendido de menor valor [mas a la derecha]):
                - Por ahora, i = 1; Actualizamos BIT[1]
                - 1 = (0001); entonces LSB(1) = 1, asi que i += 1 = 2; Actualizamos BIT[2]
                - 2 = (0010); entonces LSB(2) = 2, asi que i += 2 = 4; Actualizamos BIT[4]
                - 4 = (0100); entonces LSB(4) = 4, asi que i += 4 = 8; Actualizamos BIT[8]
                - 8 = (1000); entonces LSB(8) = 8, asi que i += 8 = 16. Debido a que 16 > 'n', aqui terminamos de actualizar

            - Cada bloque que actualizamos es mas grande y todos contienen dentro de si al bloque 1
        - AL final, cada que modificamos un valor en un bloque 'i', todos los bloques que lo contienen tambien cambiaran
    
    SUMA DE RANGO {Complejidad: O(2 log n)}
        - Queremos conseguir la suma de "A[l] + A[l+1] + ... + A[r]"
        - Cuando queremos conocer la suma de un rango especifico, basta con conocer la suma de prefijos de 'l-1' y 'r'
        - Una vez conocemos ambos valores, la suma del rango se define como:
            - sum(l, r) = sum(r) - sum(l-1)
        - Esto se debe a que la suma del bloque 'r' contiene la suma de prefijos hasta 'r'
        - Mientras que la suma del bloque 'l-1' contiene la suma de prefijos hasta 'l-1'
        - Entonces, si a la suma de 'r' le restamos todos los valores ANTES de 'l', nos quedan solamente los valores de 'l' a 'r' 
*/

/* Para este problema, se nos dara un arreglo 'a' de 'n' posiciones
    Adicionalmente, nos daran 'q' consultas que pueden ser:
        1. Regresa la suma de los elementos en el rango [l, r]
        2. Suma un valor 'x' a una posicion 'i'
        3. Cambia una posicion 'i' por un valor 'x'
    (Todo en este problema se encuentra 1-indexado, tanto las entradas como los indices del Fenwick Tree)
*/

// Estructura que almacena el arbol de Fenwick
struct Fenwick{
    int n; // 'n' = Tamaño del arbol (cantidad de nodos)
    vector<int> BIT; // 'BIT' = Respuesta de la suma precalculada para el bloque 'i' 
    
    // Metodo constructor para 'Fenwick'
    Fenwick(int n) : n(n), BIT(n+1, 0) {} // Establecemos 'BIT' con tamaño de 'n+1' para tener todo 1-indexado
    
    // Funcion 'add': Suma un valor 'x' a un elemento 'i'
    void add(int i, int x){ // 'i' = Posicion del elemento a incrementar, 'x' = Valor que le vamos a sumar al elemento 'i'
        while(i <= n){ // Mientras 'i' sea menor o igual a 'n' (mientras no hayamos salido del arbol)...
            BIT[i] += x; // Sumamos a este bloque el valor de 'x' (este bloque incluye al elemento 'i')
            i += i & -i; // Avanzamos 'LSB(i)' posiciones (i += LSB(i))

            /* Ejemplo:
            - Para i=5 y n=8 (recordemos que LSB equivale al bit encendido de menor valor [mas a la derecha]):
                - Por ahora, i = 5; Actualizamos BIT[5]
                - 5 = (0101); entonces LSB(5) = 1, asi que i += 1 = 6; Actualizamos BIT[6]
                - 6 = (0110); entonces LSB(6) = 2, asi que i += 2 = 8; Actualizamos BIT[8]
                - 8 = (1000); entonces LSB(8) = 8, asi que i += 8 = 16. Debido a que 16 > 'n', aqui terminamos de actualizar

            - Cada bloque que actualizamos es mas grande y todos contienen a la posicion 5
            */
        }
    }
    
    // Funcion 'set': Define el valor de la posicion 'i' con el nuevo valor 'v'
    void set(int i, int v){ // 'i' = Posicion del elemento a modificar, 'v' = Nuevo valor que le vamos a asignar al elemento 'i'
        int actual = rangeSum(i, i); // 'actual' = Suma del rango 'i' a 'i' (es decir, el valor del elemento individual)
        int delta = v - actual; // 'delta' = La resta del nuevo valor menos el elemento individual en la posicion 'i'
        add(i, delta); // Sumamos el valor 'delta' a la posicion 'i'

        /* Ejemplo:
        - Digamos que modificamos el valor de la posicion i=5, que tiene actualmente el valor de 10, por el nuevo valor 15:
            - 'actual' seria igual a la suma del rango [5, 5] (osea unicamente 10)
            - 'delta' seria igual a la resta de 'v' y 'actual' (en este caso, 15 - 10 = 5)
            - Finalmente, sumamos a la posicion 5 el valor de 'delta' (practicamente, le estamos sumando 5 a 10 y esto da 15)
        */
    }

    // Funcion 'sum': Establece la suma de todos los sub-bloques del bloque 'i'
    int sum(int i){ // 'i' = Posicion del bloque a precalcular su suma
        int res = 0; // 'res' = Respuesta del bloque 'i'
        while(i > 0){ // Mientras 'i' sea mayor a 0 (es decir, mientras hayan sub-bloques que faltan por agregar a la suma)
            res += BIT[i]; // Sumamos a 'res' el valor del bloque en 'i'
            i -= i & -i; // Retrocedemos 'LSB(i)' posiciones (i -= LSB(i))

            /* Ejemplo:
            - Para i=7 y n=8 (recordemos que LSB equivale al bit encendido de menor valor [mas a la derecha]):
                - Por ahora, i = 7; Agregamos el valor de BIT[7]
                - 7 = (0111); entonces LSB(7) = 1, asi que i -= 1 = 6; Agregamos el valor de BIT[6]
                - 6 = (0110); entonces LSB(6) = 2, asi que i -= 2 = 4; Agregamos el valor de BIT[4]
                - 4 = (0100); entonces LSB(4) = 4, asi que i -= 4 = 0. Debido a que 0 <= 0, aqui terminamos de agregar valores

            - Cada sub-bloque es mas pequeño y todos estan contenidos en el bloque 7
            */
        }
        return res; // Una vez terminamos, regresamos el valor de 'res'
    }

    // Funcion 'rangeSum': Regresa la suma del rango [l, r]
    int rangeSum(int l, int r){ // 'l' = Inicio del rango, 'r' = Final del rango
        // La forma mas facil de conocer la suma de un rango es simplemente restarle a la suma del bloque 'r' la suma del bloque 'l-1'
        return sum(r) - sum(l-1); // Retornamos el resultado de esa operacion
    }
};

// Funcion principal 'main()'
int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida

    int n; cin >> n; // 'n' = Tamaño del arreglo / Cantidad de elementos
    
    vector<int> a(n+1); // 'a' = Arreglo donde guardaremos los 'n' elementos (1-indexados)
    for(int i=1; i<=n; i++){
        cin >> a[i]; // Leemos los 'n' elementos y los almacenamos en 'a'
    }
    
    Fenwick ft(n); // 'ft' = Estructura correspondiente al arbol de Fenwick (con tamaño de 'n' nodos)
    
    for(int i=1; i<=n; i++){
        ft.add(i, a[i]); // Añadimos los 'n' nodos al arbol, cada uno con indice 'i' y valor 'a[i]'
    }
    
    int q; cin >> q; // 'q' = Cantidad de querys a realizar
    while(q--){ // Mientras queden querys por realizar...
        int op; cin >> op; // 'op' = Tipo de query a realizar

        if(op == 1){ // Si 'op' es de tipo '1' (consulta)...
            int l, r; cin >> l >> r; // 'l' = Inicio del rango, 'r' = Final del rango
            cout << ft.rangeSum(l, r) << '\n'; // Imprimimos la respuesta final para el rango [l, r]
        }
        else if(op == 2){ // Si 'op' es de tipo '2' (adicion)...
            int idx, sum; cin >> idx >> sum; // 'idx' = Posicion del elemento a incrementar, 'sum' = Valor que vamos a sumar
            ft.add(idx, sum); // Sumamos el valor 'sum' a la posicion 'idx' y actualizamos los bloques que lo contienen
        }
        else if(op == 3){ // Si 'op' es de tipo '3' (actualizacion)...
            int idx, val; cin >> idx >> val; // 'idx' = Posicion del elemento a modificar, 'val' = Nuevo valor que obtendra el elemento 'idx'
            ft.set(idx, val); // Modificamos la posicion 'idx' con el nuevo valor 'val' utilizando la tecnica con 'delta'
        }
    }

    return 0;
}
