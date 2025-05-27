#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* Vectores:
        - Un vector es una estructura de datos que almacena varios valores de un tipo
        - Los vectores cumplen practicamente la misma funcion que un arreglo, solo con un algunas diferencias:
            - Los vectores pueden ser declarados sin un tamaño inicial (es decir, son dinamicos)
            - Los vectores poseen varias funciones que sirven para realizar acciones especificas
            - Los vectores pueden iniciar todos sus elementos con un valor especifico
        
        Definicion : vector<-tipo-> -nombre-(-tamaño-, -valor inicial-);
        - Donde:
            -tipo- : Tipo de variable de los valores a almacenar
            -nombre- : Nombre que le asignaremos al vector
            -tamaño- : Cantidad de valores que almacenaremos dentro del vector (opcional)
            -valor inicial- : Valor inicial de todos los elementos del vector (opcional, solo se puede si se ingreso un tamaño)

        Acceder a una posicion del vector: -nombre-[-indice-]
        - Donde:
            -nombre- : Nombre del vector
            -indice- : Posicion a la que queremos acceder

        - Para acceder a una posicion se utiliza la misma sintaxis que con un arreglo
        - Los vectores tambien estan 0-indexados (su 1er indice es 0 y el ultimo es n-1)

        Ejemplo de vector tamaño 5, donde ya asignamos valores a cada indice:
            - Valor  :  [5, 8, 1, 2, 4]
            - Indice :  [0, 1, 2, 3, 4]
    */

    vector<int> vec(5); // Declaramos un vector de tamaño 5

    for(int i=0; i<5; i++){ // Creamos un for que inicia en 0 (1er indice) y se ejecuta mientras 'i' sea menor a 5 (porque el ultimo indice es n-1, osea 4)
        cout << "Ingresa el valor de la posicion " << i << " del vector: ";
        cin >> vec[i]; // Leemos el valor para la posicion 'i' del vector
    }

    cout << "Valores del vector: " << endl;
    for(int i=0; i<5; i++){ // Creamos un for que inicia en 0 (1er indice) y se ejecuta mientras 'i' sea menor a 5 (porque el ultimo indice es n-1, osea 4)
        cout << i << ": " << vec[i] << endl; // Imprimimos 'i' (valor del indice actual) y 'vec[i]' (la posicion 'i' del vector)
    }


    vector<int> vec2(4, 0); // Declaramos un nuevo vector de tamaño 4 y decimos que las 1ras 4 posiciones creadas iniciaran con valor 0

    cout << "Vector 2: " << endl; // Imprimiremos el vector 2, donde declaramos que todas sus posiciones inicialmente seran 0
    for(int i=0; i<4; i++){ // Creamos un for que inicia en 0 (1er indice) y se ejecuta mientras 'i' sea menor a 4 (porque el ultimo indice es n-1, osea 3)
        cout << i << ": " << vec2[i] << endl; // Imprimimos 'i' (valor del indice actual) y 'vec[i]' (la posicion 'i' del vector)
    }

    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Funciones especiales de los vectores" << endl;
    /* Funciones especiales de los vectores (solo las basicas, realmente hay mas):
        .push_back() : Agrega un nuevo elemento al vector
        .pop_back() : Elimina el ultimo elemento del vector
        .size() : Regresa el tamaño actual del vector
        .front() : Regresa el 1er elemento del vector
        .back() : Regresa el ultimo elemento del vector
        .empty() : Regresa 'true' si el vector esta vacio (es decir, tiene 0 posiciones)
        .clear() : Vacia el vector

        Nota: Antes de cada funcion, se coloca el nombre del vector
    */

    vector<int> vec3 = {1,2,3,4,5}; // Declaramos un vector con valores ya definidos

    cout << "Vector actual (de tamano " << vec3.size() << "): "; // .size() regresa el tamaño actual del vector (en este caso es 5)
    for(int i=0; i<vec3.size(); i++){ // Gracias al .size(), aseguramos que iteramos todo el vector sin acceder a una posicion inexistente
        cout << vec3[i] << " "; // Imprimimos los valores predefinidos del vector
    }
    cout << endl;

    cout << "Ultima posicion: " << vec3[4] << endl;
    // cout << vec3[5]; Esto no seria posible, ya que no existe la posicion 5 del vector (la ultima es 4)
    vec3.push_back(6); // Agregamos el valor '6' al final del vector con .push_back()
    cout << "Ultima posicion agregada: " << vec3[5] << endl; // Debido al .push_back() ahora si es posible, pues agregamos la posicion 5 del vector y le asignamos valor de '6'
    vec3.pop_back(); // Eliminamos el ultimo valor del vector (es decir, la posicion 5 en este caso)
    // cout << vec3[5]; Esto otra vez ya no seria posible, pues eliminamos la ultima posicion con el .pop_back()

    cout << "Primer posicion: " << vec3.front() << endl; // Con .front() imprimimos el valor de la 1ra posicion del vector (en este caso es 1)
    cout << "Ultima posicion: " << vec3.back() << endl; // Con .back() imprimimos el valor de la ultima posicion del vector (en este caso es 5)

    if(vec3.empty() == true){ // .empty() regresa 'true' si el vector esta vacio (no tiene posiciones)
        cout << "Nuestro vector esta vacio =(" << endl;
    }else{ // Si .empty() regresa 'false', el vector tiene al menos una posicion
        cout << "Nuestro vector tiene elementos =)" << endl;
    }

    vec3.clear(); // .clear() vacia todo el vector (elimina todas las posiciones existentes)
    if(vec3.empty() == true){ // Ahora que vaciamos el vector, .empty() deberia regresar 'true'
        cout << "Nuestro vector esta vacio =(" << endl;
    }else{
        cout << "Esto no deberia verse nunca ._." << endl;
    }

    // Toma en cuenta que con un vector vacio, ninguna posicion existe, lo que significa que incluso vec[0] no funciona

    return 0;
}