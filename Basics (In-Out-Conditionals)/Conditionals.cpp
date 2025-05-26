#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida

    /* Operadores lógicos:
        == : Igual que (10 == 10)
        != : Diferente que (10 != 5)
        < : Menor que (5 < 10)
        > : Mayor que (10 > 5)
        <= : Menor o igual que (10 <= 10)
        >= : Mayor o igual que (5 >= 5)
        && : Y (10 > 5 && 2 < 8)
        || : O (10 < 12 || 8 < 7)
    */

    int a = 10, b = 5; // Declaramos 2 variables con valor (10 y 5)

    /* Sentencia if
        if(-condicion-){ // Si se cumple esta condicion...
            -accion- // Se realiza esta accion
        }else{ // Si no se cumple la condicion...
            -accion- // Se realiza esta otra accion
        }
    */

    if(a == b){ // Si se cumple la condicion (Si a es igual a b)
        cout << a << " y " << b << " son iguales" << endl;
    }else{ // Si no se cumple la condicion
        cout << a << " y " << b << " son diferentes" << endl;
    }

    if(a > b){ // Si a es mayor que b
        cout << a << " es mayor que " << b << endl;
    }else if(a < b){ // Si a es menor que b
        cout << a << " es menor que " << b << endl;
    }else{ // Si no cumple ninguna de las condiciones
        cout << a << " y " << b << " son iguales" << endl;
    }

    if(a == 10 && b == 5){ // Si se cumplen ambas condiciones
        cout << "Se cumplen ambas condiciones" << endl;
    }

    if(a == 10 || b == 5){ // Si solo se cumple una condicion
        cout << "Al menos UNA condicion se cumple" << endl;
    }

    /* Sentencia switch
        switch(-variable-){ // Para esta variable...
            case -valor-: // Si la variable tiene este valor...
                -accion- // Se realiza esta accion
            break; // Termina la condicion
            case -valor-: // Si la variable tiene este otro valor...
                -accion- // Se realiza esta accion
            break; // Termina la condicion
            default: // Si la variable no tiene ningun valor anterior...
                -accion- // Se realiza esta accion
            break; // Termina la condicion
        }
    */

    switch(a){ // Tomamos la variable 'a'
        case 1: // Si a vale 1...
            cout << "a equivale a 1";
        break; // Fin del caso a==1

        case 2: // Si a vale 2...
            cout << "a equivale a 2";
        break; // Fin del caso a==2

        case 3: // Si a vale 3...
            cout << "a equivale a 3";
        break; // Fin del caso a==3

        default: // Si no se cumple ninguna condicion...
            cout << "a NO es 1,2 o 3";
        break; // Fin del caso default
    }


    return 0;
}