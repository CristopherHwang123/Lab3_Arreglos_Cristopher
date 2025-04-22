#include <iostream>
using namespace std;

const int TAM = 15;

// Funcion para ingresar datos
void ingresarNumeros(int arreglo[]) {
    cout << "Ingrese " << TAM << " numeros enteros:" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}

// Funcion para calcular el promedio
double calcularPromedio(int arreglo[]) {
    int suma = 0;
    for (int i = 0; i < TAM; i++) {
        suma += arreglo[i];
    }
    return static_cast<double>(suma) / TAM;
}

// Funcion para filtrar los valores mayores al promedio
int filtrarMayoresAlPromedio(int origen[], int destino[], double promedio) {
    int contador = 0;
    for (int i = 0; i < TAM; i++) {
        if (origen[i] > promedio) {
            destino[contador] = origen[i];
            contador++;
        }
    }
    return contador;
}

// Funcion para imprimir un arreglo
void imprimirArreglo(int arreglo[], int tam, const string& nombre) {
    cout << nombre << ": ";
    for (int i = 0; i < tam; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Funcion para ordenar un arreglo de mayor a menor (burbuja)
void ordenarDescendente(int arreglo[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (arreglo[j] < arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numeros[TAM];
    int mayores[TAM];  // Puede tener hasta TAM elementos como maximo

    ingresarNumeros(numeros);

    double promedio = calcularPromedio(numeros);
    cout << "Promedio: " << promedio << endl;

    int cantidadMayores = filtrarMayoresAlPromedio(numeros, mayores, promedio);

    cout << endl;
    imprimirArreglo(numeros, TAM, "Arreglo original");
    imprimirArreglo(mayores, cantidadMayores, "Mayores al promedio");

    // Extra: ordenar y mostrar el arreglo filtrado
    ordenarDescendente(mayores, cantidadMayores);
    imprimirArreglo(mayores, cantidadMayores, "Mayores al promedio ordenados");

    return 0;
}
