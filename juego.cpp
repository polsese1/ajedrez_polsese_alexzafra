#include "juego.h"
#include <iostream>

using namespace std;

// la funcion pide al jugador las coordenadas de origen y destino para mover una pieza
void pedirMovimiento(int& filaOrigen, int& columnaOrigen, int& filaDestino, int& columnaDestino) {
    string origen;
    string destino;

    // Pide al usuario que escriba la posicion de la pieza que quiere mover
    cout << "Ingrese la posicion de origen (ej: 2A):";
    cin >> origen;

    // ahora la posicion a la que quiere moverla
    cout << "Ingrese la posicion de destino (ej: 3A):";
    cin >> destino;

    // Se convierte la letra en numero de columna
    columnaOrigen = origen[1] - 'A';

    // Se transforma el numero ingresado
    filaOrigen = 8 - (origen[0] - '0');

    // ae hace lo mismo para la posicion de destino
    columnaDestino = destino[1] - 'A';
    filaDestino = 8 - (destino[0] - '0');
}
