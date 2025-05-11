#include "movimiento.h"
#include "tablero.h"
#include <cstdlib>
#include "iostream"

using namespace std;

// devuelve true si el caracter es una letra mayuscula (A-Z)
bool esMayuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

// Devuelve true si el caracter es una letra minuscula (a-z)
bool esMinuscula(char c) {
    return c >= 'a' && c <= 'z';
}

// convierte un caracter a minuscula si es mayuscula
char aMinuscula(char c) {
    if (esMayuscula(c)) {
        return c + ('a' - 'A');
    }
    return c;
}

// Devuelve el valor absoluto de un numero (por ejemplo, -3 se convierte en 3)
int valorAbsoluto(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// verifica si un movimiento es valido para una pieza en particular
bool esMovimientoValido(char pieza, int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino, vector<vector<char>>& tablero) {
    int dx = filaDestino - filaOrigen;
    int dy = columnaDestino - columnaOrigen;
    pieza = aMinuscula(pieza); // Ignoramos el color para chequear tipo de pieza

    switch (pieza) {
    case 'p': // peon
        if (esMayuscula(tablero[filaOrigen][columnaOrigen])) { // Si es blanco
            // Movimiento simple hacia adelante
            if (dx == -1 && dy == 0 && tablero[filaDestino][columnaDestino] == '*') {
                return true;
            }
            // Primer movimiento doble desde la fila 6
            if (filaOrigen == 6 && dx == -2 && dy == 0 && tablero[filaDestino][columnaDestino] == '*') {
                return true;
            }
            // captura en diagonal
            if (dx == -1 && valorAbsoluto(dy) == 1 && esMinuscula(tablero[filaDestino][columnaDestino])) {
                return true;
            }
        }
        else { // Si es negro
            if (dx == 1 && dy == 0 && tablero[filaDestino][columnaDestino] == '*') {
                return true;
            }
            if (filaOrigen == 1 && dx == 2 && dy == 0 && tablero[filaDestino][columnaDestino] == '*') {
                return true;
            }
            if (dx == 1 && valorAbsoluto(dy) == 1 && esMayuscula(tablero[filaDestino][columnaDestino])) {
                return true;
            }
        }
        break;
    case 't': // torre: se mueve en linea recta
        if (dx == 0 || dy == 0) {
            return true;
        }
        break;
    case 'h': // Caballo: en L (2 y 1 en cualquier orden)
        if ((valorAbsoluto(dx) == 2 && valorAbsoluto(dy) == 1) || (valorAbsoluto(dx) == 1 && valorAbsoluto(dy) == 2)) {
            return true;
        }
        break;
    case 'b': // Alfil: se mueve en diagonal
        if (valorAbsoluto(dx) == valorAbsoluto(dy)) {
            return true;
        }
        break;
    case 'q': // Reina: combina alfil y torre
        if (valorAbsoluto(dx) == valorAbsoluto(dy) || dx == 0 || dy == 0) {
            return true;
        }
        break;
    case 'k': // Rey: se mueve una casilla en cualquier direccion
        if (valorAbsoluto(dx) <= 1 && valorAbsoluto(dy) <= 1) {
            return true;
        }
        break;
    }
    return false; // Si nada de lo anterior se cumple, el movimiento no es valido
}

// intenta mover una pieza del tablero y valida que todo sea legal
bool moverPieza(vector<vector<char>>& tablero, int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino, bool turnoBlanco) {
    char pieza = tablero[filaOrigen][columnaOrigen];

    // Si no hay nada en la casilla de origen
    if (pieza == '*') {
        cout << "No hay pieza en la posicion de origen" << endl;
        return false;
    }

    // verifica que el jugador este moviendo su color de piezas
    if (turnoBlanco && !esMayuscula(pieza)) {
        cout << "Es turno de las piezas blancas" << endl;
        return false;
    }

    if (!turnoBlanco && !esMinuscula(pieza)) {
        cout << "Es turno de las piezas negras" << endl;
        return false;
    }

    // Comprueba si el movimiento es legal segun la pieza
    if (!esMovimientoValido(pieza, filaOrigen, columnaOrigen, filaDestino, columnaDestino, tablero)) {
        cout << "Movimiento invalido segun las reglas" << endl;
        return false;
    }

    // No se puede capturar una pieza del mismo color
    if ((esMayuscula(pieza) && esMayuscula(tablero[filaDestino][columnaDestino])) ||
        (esMinuscula(pieza) && esMinuscula(tablero[filaDestino][columnaDestino]))) {
        cout << "No puedes comer tus propias piezas." << endl;
        return false;
    }

    // si se captura al rey enemigo, se termina el juego
    if (aMinuscula(tablero[filaDestino][columnaDestino]) == 'k') {
        if (turnoBlanco) {
            cout << "Jugador blanco ha ganado! El rey ha sido capturado" << endl;
        }
        else {
            cout << "Jugador negro ha ganado! El rey ha sido capturado" << endl;
        }
        exit(0); // Finaliza el programa
    }

    // Movimiento valido: actualiza el tablero
    tablero[filaDestino][columnaDestino] = tablero[filaOrigen][columnaOrigen];
    tablero[filaOrigen][columnaOrigen] = '*'; // Vacia la casilla de origen

    // Promocion de peones cuando llegan al final del tablero
    if ((turnoBlanco && filaDestino == 0 && tablero[filaDestino][columnaDestino] == 'P') ||
        (!turnoBlanco && filaDestino == 7 && tablero[filaDestino][columnaDestino] == 'p')) {
        if (turnoBlanco) {
            tablero[filaDestino][columnaDestino] = 'Q'; // Reina blanca
        }
        else {
            tablero[filaDestino][columnaDestino] = 'q'; // Reina negra
        }
        cout << "Peon promovido a reina" << endl;
    }

    return true; // movimiento completado con exito
}