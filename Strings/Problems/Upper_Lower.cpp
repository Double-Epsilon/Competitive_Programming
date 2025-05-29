#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* El problema "Mayusculas a minusculas y viceversa" dice:
        - Se te dara una linea de caracteres que puede incluir letras, numeros y simbolos especiales
        - Deberas convertir las letras mayusculas a minusculas y viceversa
        - Todos los caracteres que NO sean letras deberan permanecer igual
        - Imprimiras la cadena convertida
    */

    cout << "Ingresa la cadena a convertir: ";
    string s; // Declaramos la variable 's', la cadena que vamos a convertir
    getline(cin, s); // Leemos el valor de 's' con "getline()" porque pueden haber espacios

    for(int i=0; i<s.size(); i++){ // Creamos un for que itere toda la cadena de principio a fin utilizando .size()
        if(s[i] >= 'a' && s[i] <= 'z'){ // Si el caracter actual 's[i]' esta en el rango de las minusculas...
            s[i] -= 32; // Le restamos 32 al caracter (todas las mayusculas estan 32 numeros atras de su version minuscula)
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){ // Si el caracter actual 's[i]' esta en el rango de las mayusculas...
            s[i] += 32; // Le sumamos 32 al caracter (todas las minusculas estan 32 numeros adelante de su version mayuscula)
        }
        // Si no entra en ninguno de los rangos, no hacemos nada, pues no es una letra
    }

    cout << "La frase convertida es: " << s;

    /* ¿Que hacemos?:
        - Declaramos una variable tipo string llamada 's'
        - Leemos el valor de 's' con "getline()", pues pueden haber espacios en nuestra cadena

        - Con ayuda de un bucle for, iteramos nuestra cadena completa iniciando en la 1ra posicion (indice 0) hasta la ultima (indice s.size()-1)
        - Revisamos el valor ASCII de cada caracter de la cadena:
            - Si el caracter entra en el rango de las minusculas, le restamos 32 para convertirla a mayuscula
            - Si el caracter entra en el rango de las mayusculas, le sumamos 32 para convertirla a minuscula
            - Si el caracter no entra en ningun rango, ignoramos el caracter y no realizamos ningun procedimiento
        
        Ejemplo para la cadena "HOLA mundo 123":
            - Al iterar el string, nos damos cuenta que las 1ras letras son mayusculas, por lo que les sumamos 32 a cada una para volverlas minusculas
            - Al seguir iterando, ignoramos el espacio al no ser una letra
            - Seguido del espacio encontramos 5 letras minusculas, a las que les restamos 32 para volverlas mayusculas
            - Finalmente ignoramos el 2do espacio y los numeros al no ser letras
            
            Resultado: "hola MUNDO 123"
    */

    return 0;
}