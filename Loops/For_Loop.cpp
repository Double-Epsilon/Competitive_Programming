#include <bits/stdc++.h> // Libreria <bits/stdc++.h>
using namespace std; // Evitar colocar std::

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion de entrada/salida
    
    /* Bucle For
        for(-iterador-; -condicion-; -cambio-){
            -accion- // Accion a realizar
        }
        
        -iterador- : Variable que servira como guia para el bucle
        -condicion- : Condicion que debe cumplirse para que el bucle continue (Si no se cumple, termina el bucle)
        -cambio- : Cambio que realizamos por cada iteracion del bucle (generalmente al iterador)
    */

    cout << "Numeros del 1 al 10" << endl;
    for(int i=1; i<11; i++){
        cout << i << endl; // Imprime todos los valores de i mientras que i < 11 (1 -> 10)
    }
    /* Para el for anterior:
        int i=0 : Declaramos una variable de tipo entero 'i' que inicia con un valor 1
        i<11 : Decimos que el bucle se ejecute siempre que 'i' sea menor a 11 (Cuando i sea igual a 11, dejara de ejecutar)
        i++ : Decimos que por cada iteracion, 'i' aumente en 1 (i++ es lo mismo que i+=1)
        cout << i << endl; : Por cada iteracion, imprimimos el valor de 'i' seguido de un salto de linea
    */

    cout << "Numeros del 10 al 1" << endl;
    for(int i=10; i>0; i--){
        cout << i << endl; // Imprime todos los valores de i mientras que i > 0 (10 -> 1)
    }
    /* Para el for anterior:
        int i=10 : Declaramos una variable de tipo entero 'i' que inicia con un valor 10
        i>0 : Decimos que el bucle se ejecute siempre que 'i' sea mayor a 0 (Cuando i sea igual a 0, dejara de ejecutar)
        i-- : Decimos que por cada iteracion, 'i' disminuye en 1 (i-- es lo mismo que i-=1)
        cout << i << endl; : Por cada iteracion, imprimimos el valor de 'i' seguido de un salto de linea
    */

    cout << "Numeros PARES entre 1 y 10" << endl;
    for(int i=1; i<=10; i++){
        if(i%2 == 0){ // Si i % 2 == 0 (es decir: si 'i' es divisible entre 2 [numero par])
            cout << i << endl; // Imprime todos los valores pares de i
        }
    }
    /* Para el for anterior:
        int i=1 : Declaramos una variable de tipo entero 'i' que inicia con un valor 1
        i<=10 : Decimos que el bucle se ejecute siempre que 'i' sea menor o igual a 10 (Cuando i sea mayor a 10, dejara de ejecutar)
        i++ : Decimos que por cada iteracion, 'i' aumente en 1
        if(i%2 == 0) : Comprobamos si 'i' es un numero divisible entre 2 (osea, un numero par)
        cout << i << endl; : Por cada iteracion donde se cumpla la condicion, imprimimos el valor de 'i' seguido de un salto de linea
    */

    cout << "Numeros IMPARES entre 1 y 10" << endl;
    for(int i=1; i<=10; i++){
        if(i%2 == 1){ // Si i % 2 == 1 (es decir: si 'i' NO es divisible entre 2 [numero impar])
            cout << i << endl; // Imprime todos los valores impares de i
        }
    }
    /* Para el for anterior:
        int i=1 : Declaramos una variable de tipo entero 'i' que inicia con un valor 1
        i<=10 : Decimos que el bucle se ejecute siempre que 'i' sea menor o igual a 10 (Cuando i sea mayor a 10, dejara de ejecutar)
        i++ : Decimos que por cada iteracion, 'i' aumente en 1
        if(i%2 == 1) : Comprobamos si 'i' NO es un numero divisible entre 2 (osea, un numero impar)
        cout << i << endl; : Por cada iteracion donde se cumpla la condicion, imprimimos el valor de 'i' seguido de un salto de linea
    */

    cout << "Multiplos de 3 hasta el 30" << endl;
    for(int i=3; i<=30; i+=3){
        cout << i << endl; // Imprimimos todos los valores de i mientras i <= 30
    }
    /* Para el for anterior:
        int i=3 : Declaramos una variable de tipo entero 'i' que inicia con un valor 3
        i<=30 : Decimos que el bucle se ejecute siempre que 'i' sea menor o igual a 30 (Cuando i sea mayor a 30, dejara de ejecutar)
        i+=3 : Decimos que por cada iteracion, 'i' aumentara en 3
        cout << i << endl; : Por cada iteracion, imprimimos el valor de 'i' seguido de un salto de linea
    */

    return 0;
}