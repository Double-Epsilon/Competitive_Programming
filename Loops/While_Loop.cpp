#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* Bucle While
        while(-condicion-){ // Mientras se cumpla la condicion...
            -accion- // Se realiza esta accion
        }

        // El bucle while no siempre se ejecuta, solo lo hace si se cumple la condicion
    */

    int a=1; // Declaramos una variable 'a' con valor inicial 1
    cout << "Numeros de 1 a 10" << endl;
    while(a < 11){ // Mientras que 'a' sea menor a 11 (cuando 'a' sea igual a 11, dejara de ejecutar)
        cout << a << " "; // Imprimimos 'a', seguido de un espacio
        a++; // Aumentamos 'a' en 1
    }
    cout << endl;

    int b, i = 2; // Declaramos 2 variables 'b', 'i' = 2
    cout << "Ingresa un valor para 'b': ";
    cin >> b; // Leemos un valor para b
    cout << "Numeros PARES de 2 a " << b << endl;
    while(i <= b){ // Mientras que 'i' sea menor o igual a 'b' (cuando 'i' sea mayor a 'b', dejara de ejecutar)
        cout << i << " "; // Imprimimos 'a', seguido de un espacio
        i+=2; // Aumentamos 'a' en 2
    }
    cout << endl;

    /* Bucle Do_While
        do{ // Hacer...
            -accion- // Se realiza esta accion
        }while(-condicion-){ // Mientras se cumpla la condicion

        // El bucle do_while ejecuta el ciclo AL MENOS 1 VEZ
    */

    int c; // Declaramos una variable 'c'
    cout << "Hasta que sea PAR" << endl;
    do{ // Hacer...
        cout << "Ingresa un valor para 'c': ";
        cin >> c; // Leemos una valor para c
    }while(c % 2 == 1); // Volvemos a ejecutar si c % 2 == 1 (osea, mientras 'c' sea impar)
    cout << c << " es par, termina el bucle";

    return 0;
}