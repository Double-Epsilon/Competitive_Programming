#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida

    /* El problema "Formula general de ecuaciones de 2do grado" dice:
        - Se te daran 3 numeros a, b y c, los coeficientes de una ecuacion cuadratica del tipo "ax^2 + bx + c"
        - El programa deberá utilizar la fórmula general de ecuaciones de 2do grado para obtener los valores de x1 y x2

        - Dependiendo los resultados, imprimirás lo siguiente:
            - Si los valores de x1 y x2 son diferentes, imprimirás:
                -El mensaje "Hay 2 soluciones"
                - El valor de x1 (Cuando la fórmula emplea "+")
                - El valor de x2 (Cuando la fórmula emplea "-")
            - Si los valores de x1 y x2 son iguales, imprimirás:
                - El mensaje "Hay 1 solucion"
                - El valor de x1
            - Si no existe valor para x, imprimirás:
                - El mensaje "No hay soluciones"
    */

    int a, b, c; // Declaramos los valores de 'a', 'b' y 'c': Los coeficientes de la ecuacion cuadrática
    cin >> a >> b >> c; // Leemos los valores de 'a', 'b' y 'c'
    
    // ------------------------------------------------------------------------------------------------
    // Resolveremos la función por partes, iniciando por la parte dentro de la raíz cuadrada
    int potencia = pow(b, 2); // Declaramos una variable 'potencia' que guardará b^2
    potencia += (-4 * a * c); // Sumamos a 'potencia' la ecuación "-4 * a * b" (La segunda parte dentro de la raíz)
    if(potencia < 0){ // Si nuestro resultado dentro de la raíz es menor a 0 (valor negativo)
        cout << "No hay soluciones"; // Imprimimos "No hay soluciones", pues no existe raíz de números negativos
        return 0; // Terminamos el problema, pues no vale la pena realizar la función ya que no existe raíz
    }

    float res = sqrt(potencia); // Declaramos una variable 'res' que guardará el resultado de la raíz
    
    float x1 = (-b + res) / (2*a); // Declaramos la variable 'x1' que guardará el valor de la función cuando empleamos '+'
    float x2 = (-b - res) / (2*a); // Declaramos la variable 'x2' que guardará el valor de la función cuando empleamos '-'
    
    if(x1 == x2){ // Si x1 y x2 son iguales...
        cout << "Hay 1 solucion" << endl << fixed << setprecision(2) << x1; // Imprimimos que existe solo una solución y el valor de x1 (redondeado a 2 decimales)
    }else{ // Si no se cumple la condicion (x1 y x2 son diferentes)...
        cout << "Hay 2 soluciones" << endl << fixed << setprecision(2) << x1 << endl << x2; // Imprimimos que existen 2 soluciones y los valores de x1 y x2 respectivamente (redondeados a 2 decimales)
    }

    /* ¿Que hacemos?
        - Nos piden utilizar la fórmula general de ecuaciones de 2do grado para obtener los valores de x1 y x2
        - Inicialmente, leemos los valores de 'a', 'b' y 'c', que son los coeficientes de la ecuación cuadrática

        - Dividimos nuestra fórmula en 2 partes:
            - Primero resolvemos la parte interna de la raíz cuadrada "√((b^2) + (4*a*c))"
            - Luego resolvemos el resto de la fórmula utilizando '+' y '-' "(-b ± √) / (2*a)"
        
        - Cuando el resultado de la parte interna de la raíz es un número negativo, no existen soluciones para 'x', pues no existen raíces de números negativos
        - En caso de que tengamos un número negativo, imprimimos la frase correspondiente y terminamos el programa, pues realizar el resto de la fórmula daría error
        
        - Si el resultado de la parte interna de la raíz es un número positivo, continuamos el proceso
        - Sacamos los valores de x1 ('+') y x2 ('-') con la respectiva fórmula

        - Una vez obtenidos los valores, revisamos si son iguales o no:
            - Si son iguales, imprimimos la frase correspondiente y solamente el resultado de x1
            - Si son diferentes, imprimimos la frase correspondiente e imprimimos los valores de x1 y x2
        - Cuando imprimimos el valor de algun 'x', colocamos "fixed << setprecision(2)", esto para redondear la respuesta a 2 decimales
    */

    return 0;
}