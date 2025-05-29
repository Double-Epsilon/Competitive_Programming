#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* Strings:
        - Un string (o cadena) es un conjunto de caracteres (caracter es cualquier simbolo que acepta la computadora, como las letras y números)
        - Es utilizada para guardar principalmente frases y/o textos de varios caracteres de longitud
        
        Definicion : string -nombre-;
        - Donde:
            -nombre- : Nombre que le asignaremos al string
        
        - Los strings actuan igual que un arreglo, pues practicamente son lo mismo que un arreglo de caracteres (char array[n])
        - Así pues, es posible acceder a cada posición/símbolo del string mediante índices así como se haría con un arreglo

        Acceder a una posicion del string : -nombre-[-indice-]
        - Donde:
            -nombre- : Nombre del string
            -indice- : Posicion a la que queremos acceder

        - Los strings, al igual que los arreglos,  esta 0-indexados (es decir, su 1er elemento se encuentra en el indice 0)
        - Cada posicion del arreglo actua como una variable tipo caracter normal, es decir, podemos hacer lo que normalmente hariamos con una variable independiente

        Ejemplo de un string que almacena la frase "Hola Mundo":
            - String  : [Hola Mundo]
            - Valores : ['H', 'o', 'l', 'a', ' ', 'M', 'u', 'n', 'd', 'o']
            - Indices : [ 0 ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ]
        
        - Hay que recordar que para la computadora un caracter es representado con un número entre 0 y 255 (incluyendolos)
        - Este número es definido por el código ASCII -> (https://elcodigoascii.com.ar/)
    */

    string text; // Declaramos una variable de tipo string llamada 'text'
    cout << "Ingresa un secuencia de caracteres: ";
    cin >> text; // Leemos el valor de 'text' igual que hariamos con una variable comun

    cout << "El string ingresado es " << text << endl; // Imprimimos el valor de 'text' igual que hariamos con una variable comun

    cout << "-------------------------------------------------------" << endl;
    /* Funcion .size():
        Uso: -nombre-.size()
            - Donde:
                -nombre- : Nombre del string
        
        - Los strings tambien poseen la funcion ".size()" al igual que los arreglos
        - Funciona exactamente igual (regresa el tamaño del string, es decir, la cantidad de caracteres en el string)

        Ejemplo:
            - String s = "Hola Mundo"
            - cout << s.size(); (Esto imprime "10", pues 's' contiene 10 caracteres)
    */

    cout << "String letra por letra: " << endl;
    for(int i=0; i<text.size(); i++){ // Creamos un for que inicia en 0 (1er indice) y se ejecuta mientras 'i' sea menor a 'text.size()' (ultimo indice)
        cout << i << ": " << text[i] << endl; // Imprimimos 'i' (valor del indice actual) y 'text[i]' (la posicion 'i' del string)
    }

    cout << "---------------------------------------------------------------------" << endl;
    string text2 = "abcde"; // Declaramos un nuevo string y predefinimos su texto inicial
    //   indices = [01234];

    cout << "Posicion 2: " << text2[2] << endl; // Imprimimos el valor actual de 'text2[2]'
    text2[2] = 'w'; // Accedemos a la posicion 2 del string y cambiamos su valor por 'w'
    cout << "Nuevo valor posicion 2: " << text2[2] << endl; // Imprimimos el valor de 'text2[2]' (osea 'w')

    cout << "---------------------------------------------------------------------" << endl;
    string text3 = ""; // Declaramos un nuevo string inicialmente vacio
    char carac; // Declaramos una variable tipo char para almacenar los caracteres que nos van a ingresar
    do{ // Realizamos...
        cout << "Ingresa un caracter: ";
        cin >> carac; // Leemos el caracter que nos ingresen
        text3 += carac; // Agregamos el caracter ingresado a 'text3' (utilizando strings, '+=' sirve para agregar y no para sumar)
    }while(carac != 'a'); // Mientras 'carac' sea diferente de 'a'
    cout << "String construido: " << text3 << endl; // Imprimimos el string construido con los caracteres ingresados anteriormente

    cout << "--------------------------------------------------------------------" << endl;
    /* getline():
        - Aunque los strings pueden almacenar todo tipo de caracteres, la forma de ingresarlos no siempre es facil
        - La forma mas normal de leer un valor para un string es empleando "cin", pero este tiene una pequeña limitacion:
            - "cin" lee caracteres hasta encontrar un espacio, el cual ignora (no lo guarda) y deja de leer caracteres
            - Por ejemplo, si intentamos leer "Hola Mundo" con "cin", este solamente guardara "Hola", pues ignorara el espacio y todo lo que le sigue
        
        - En el caso de que se necesite leer tambien espacios, utilizamos la funcion "getline()"
        - "getline()" cumple la misma funcion que "cin", con la diferencia de que este lee toda la linea de texto (incluyendo espacios y lo que le siga)
        - "getline()" deja de leer caracteres cuando encuentra un salto de linea, el cual ignora (no lo guarda)

        Definicion : getline(cin, -nombre-)
            - Donde:
                -nombre : Nombre del string donde almacenaremos la linea de texto
        
        Ejemplo de la diferencia entre "cin" y "getline()":
            Frase : "Hola Mundo"
            String : s
            Con "cin" : cin >> s; (Guarda "Hola")
            Con "getline()" : getline(cin, s); (Guarda "Hola Mundo")
    */

    string text4; // Declaramos una variable tipo string 
    cout << "Ingresa un texto con espacios: ";
    cin >> text4; // Solo guardara los caracteres que esten ANTES del espacio
    cout << "Texto leido con 'cin': " << text4 << endl;
    getline(cin, text4); // Esto es solo para ignorar el resto de la linea que "cin" no pudo leer =P

    cout << "Ingresa otro texto con espacios: ";
    getline(cin, text4); // Guardara todos los caracteres de la linea
    cout << "Texto leido con 'getline()': " << text4 << endl;

    return 0;
}