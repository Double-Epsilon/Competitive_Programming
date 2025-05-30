#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* El problema "Suma de valores ASCII" dice:
        - Se te dara una linea de caracteres que puede incluir letras, numeros, espacios y simbolos especiales
        - Por cada caracter, deberas imprimir su valor ASCII y el tipo de caracter que es (minuscula, mayuscula, numero o especial)
        - Deberas sumar los valores ASCII de todos los caracteres dentro de la cadena
        - Al final, imprimiras la suma de todos los caracteres
    */

    cout << "Ingresa la cadena: ";
    string s; // Declaramos la variable 's', la cadena que vamos a sumar
    getline(cin, s); // Leemos el valor de 's' con "getline()" porque pueden haber espacios

    int suma = 0; // Declaramos un variable tipo entero 'suma' para ir almacenando la suma del valor ASCII de cada caracter
    for(int i=0; i<s.size(); i++){ // Creamos un for que itere toda la cadena de principio a fin utilizando .size()
        if(s[i] >= 'a' && s[i] <= 'z'){ // Si el caracter esta en el rango de las minusculas...
            cout << s[i] << " es minuscula"; // Imprimimos que el caracter actual es una minuscula
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){ // Si el caracter esta en el rango de las mayusculas...
            cout << s[i] << " es mayuscula"; // Imprimimos que el caracter actual es una mayuscula
        }
        else if(s[i] >= '0' && s[i] <= '9'){ // Si el caracter esta en el rango de los numeros...
            cout << s[i] << " es numero"; // Imprimimos que el caracter actual es un numero
        }
        else{ // Si el caracter no entra en ningun rango...
            cout << s[i] << " es simbolo especial"; // Imprimimos que el caracter actual es un simbolo especial
        }
        cout << " - Valor ASCII = " << int(s[i]) << endl; // Al final imprimimos el valor ASCII del caracter

        suma += s[i]; // Sumamos a 'suma' el valor del caracter actual
    }

    cout << "La suma de todos los valores ASCII es: " << suma;

    /* ¿Que hacemos?:
        - Declaramos una variable tipo string llamada 's'
        - Leemos el valor de 's' con "getline()", pues pueden haber espacios en nuestra cadena

        - Con ayuda de un bucle for, iteramos nuestra cadena completa iniciando en la 1ra posicion (indice 0) hasta la ultima (indice s.size()-1)
        - Revisamos el valor ASCII de cada caracter de la cadena:
            - Si el caracter entra en el rango de las minusculas, imprimimos que es una minuscula
            - Si el caracter entra en el rango de las mayusculas, imprimimos que es una mayuscula
            - Si el caracter entra en el rango de los numeros, imprimimos que es un numero
            - Si el caracter no entra en ningun rango, imprimimos que es un simbolo especial
        
        Ejemplo para la cadena "HOLA mundo 123 :)":
            - H es mayuscula - Valor ASCII = 72
            - O es mayuscula - Valor ASCII = 79
            - L es mayuscula - Valor ASCII = 76
            - A es mayuscula - Valor ASCII = 65
            -   es simbolo espacial - Valor ASCII = 32
            - m es minuscula - Valor ASCII = 109
            - u es minuscula - Valor ASCII = 117
            - n es minuscula - Valor ASCII = 110
            - d es minuscula - Valor ASCII = 100
            - o es minuscula - Valor ASCII = 111
            -   es simbolo espacial - Valor ASCII = 32
            - 1 es numero - Valor ASCII = 49
            - 2 es numero - Valor ASCII = 50
            - 3 es numero - Valor ASCII = 51
            -   es simbolo espacial - Valor ASCII = 32
            - : es simbolo espacial - Valor ASCII = 58
            - ) es simbolo espacial - Valor ASCII = 41
            - La suma de todos los valores ASCII es: 1184
    */

    return 0;
}