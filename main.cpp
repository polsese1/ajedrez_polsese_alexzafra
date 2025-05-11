#include "tablero.h"
#include "movimiento.h"
#include "juego.h"
#include "iostream"

using namespace std;

int main() {
    // Se crea el tablero e inicia con las piezas
    vector<vector<char>> tablero = inicializarTablero();
    bool turnoBlanco = true; // true si es el turno de las blancas, false para las negras

    while (true) {
        // muestra el tablero
        mostrarTablero(tablero);

        // Muestra un mensaje del turno
        if (turnoBlanco) {
            cout << "Turno de las blancas (mayusculas)" << endl;
        }
        else {
            cout << "Turno de las negras" << endl;
        }

        // variables posiciones de origen y destino del movimiento
        int filaOrigen, columnaOrigen, filaDestino, columnaDestino;

        // Se pide al jugador que introduzca el movimiento
        pedirMovimiento(filaOrigen, columnaOrigen, filaDestino, columnaDestino);

        // Se comprueba que las coordenadas esten dentro de los limites del tablero
        if (filaOrigen < 0 || filaOrigen >= 8 || columnaOrigen < 0 || columnaOrigen >= 8 ||
            filaDestino < 0 || filaDestino >= 8 || columnaDestino < 0 || columnaDestino >= 8) {
            cout << "Posicion fuera del tablero" << endl;
            continue; // Se vuelve a pedir un movimiento
        }

        // si el movimiento es valido, se cambia el turno
        if (moverPieza(tablero, filaOrigen, columnaOrigen, filaDestino, columnaDestino, turnoBlanco)) {
            turnoBlanco = !turnoBlanco; // Se alterna el turno
        }
    }

    return 0;
}
