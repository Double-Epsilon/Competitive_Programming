#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* Caracter (char):
        - Un caracter es cualquier simbolo que la computadora puede interpretar (pueden ser por ejemplo numeros y letras)
        - Para la computadora, cada caracter es representado con un número entre 0 y 255 (incluyendolos)
        - El codigo que se emplea para determinar que numero corresponde a que caracter es el codigo ASCII

        - El codigo ASCII transforma caracteres a numeros que la computadora puede interpretar facilmente
        - Existen muchos caracteres diferentes, pero los mas importantes son:
            - Tipo              : Abarca     : Codigo ASCII
            --------------------------------------------------
            - Letras minusculas : 'a' -> 'z' : 97 -> 122
            - Letras mayusculas : 'A' -> 'Z' : 65 -> 90
            - Numeros           : '0' -> '9' : 48 -> 57
            - Espacio           : ' '        : 32
        
        - Ejemplo:
            char carac = 'a';
            - Mientras que para nosotros 'carac' es solamente 'a', para la computadora 'carac' es realmente '97'
    */

    char carac; // Declaramos una variable de tipo caracter llamada 'carac'
    cout << "Ingresa un caracter: ";
    cin >> carac; // Leemos el valor de 'carac'

    cout << "El caracter ingresado es " << carac << endl; // Imprimimos el valor de 'carac' en su forma de caracter
    cout << "El caracter ingresado en ASCII es " << int(carac) << endl; // Imprimimos el valor de 'carac' en su forma de numero (forma ASCII)

    // Vamos a descifrar el tipo de caracter de 'carac' utilizando condiciones numericas
    if(carac >= 97 && carac <= 122){ // Si 'carac' es mayor o igual a '97' ('a') Y es menor o igual a '122' ('z')...
        cout << carac << " es una letra minuscula" << endl; // 'carac' es una letra minuscula, pues esta dentro del rango ASCII de las minusculas (97 -> 122)
    }
    else if(carac >= 65 && carac <= 90){ // Si 'carac' es mayor o igual a '65' ('A') Y es menor o igual a '90' ('Z')...
        cout << carac << " es una letra mayuscula" << endl; // 'carac' es una letra mayuscula, pues esta dentro del rango ASCII de las mayusculas (65 -> 90)
    }
    else if(carac >= 48 && carac <= 57){ // Si 'carac' es mayor o igual a '48' ('0') Y es menor o igual a '57' ('9')...
        cout << carac << " es un numero" << endl; // 'carac' es un numero, pues esta dentro del rango ASCII de los numeros (48 -> 57)
    }
    else{ // Si 'carac' no cumple ninguna de las condiciones anteriores...
        cout << carac << " no es ni letra ni numero" << endl; // 'carac' no es ni una letra ni un numero (tal vez sea un simbolo especial)
    }

    cout << "-------------------------------------------------------------" << endl;
    /* Operaciones con caracteres:
        - Los caracteres son convertidos mediante el codigo ASCII a un numero entero 
        - Esta conversion numerica nos permite realizar cierto tipo de operaciones con los caracteres que naturalmente no son posibles
        - Las principales que podemos realizar son operaciones matematicas (+ y -)

        Ejemplo:
            - Si el valor ASCII de la letra 'e' es el 101...
                - Podriamos sumarle +1 y obtendriamos la letra 'f' (ASCII = 102)
                - Podriamos restarle -32 y obtendriamos la letra 'E' (ASCII = 69)
        
        - Estas operaciones sirven especialmente para convertir caracteres a otros caracteres en especifico
    */

    char letra; // Declaramos una variable tipo char llamada 'letra'
    cout << "Ingresa una letra: ";
    cin >> letra; // Leemos el valor de 'letra'

    // Esta vez, en vez de comparar con numeros vamos a comparar con la letra directamente, pues para la computadora equivalen a un numero
    if(letra >= 'a' && letra <= 'z'){ // Si 'letra' es minuscula...
        cout << letra << " es minuscula (ASCII = " << int(letra) << ")" << endl; // Imprimimos que 'letra' es minuscula
        cout << "Su version mayuscula es " << char(letra - 32) << " (ASCII = " << letra - 32 << ")" << endl; // Imprimimos el valor de 'letra - 32' (su version mayuscula)
    }
    else if(letra >= 'A' && letra <= 'Z'){ // Si 'letra' es mayuscula...
        cout << letra << " es mayuscula (ASCII = " << int(letra) << ")" << endl; // Imprimimos que 'letra' es mayuscula
        cout << "Su version minuscula es " << char(letra + 32) << " (ASCII = " << letra + 32 << ")" << endl; // Imprimimos el valor de 'letra + 32' (su version minuscula)
    }
    else{
        cout << letra << " no es una letra" << endl; // En caso de que no sea minuscula ni mayuscula, no es una letra
    }

    return 0;
}