#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    int a, b; // Declaramos 2 variables (a, b)
    cin >> a >> b; // Leemos el valor de a y b

    cout << a << " " << b << endl; // Imprimimos el valor de a y b
    cout << b << " " << a << endl; // Imprimimos el valor de a y b (al reves)
    cout << a+b << endl; // Imprimimos la suma de las 2 variables
    cout << a-b << endl; // Imprimimos la resta de las 2 variables
    cout << a*b << endl; // Imprimimos la multiplicacion de las 2 variables
    cout << a/b << endl; // Imprimimos la division de las 2 variables
    cout << a%b << endl; // Imprimimos el modulo de las 2 variables (Modulo = El residuo de la division a/b)

    return 0;
}