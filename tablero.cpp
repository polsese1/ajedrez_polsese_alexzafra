#include "tablero.h"
#include <iostream>

using namespace std;

// Esta funcion crea el tablero inicial de ajedrez y coloca las piezas en su posicion inicial
vector<vector<char>> inicializarTablero() {
    // ae crea una matriz de 8x8 llena con '*' para representar casillas vacias
    vector<vector<char>> tablero(8, vector<char>(8, '*'));

    // Se colocan las piezas negras en las dos primeras filas
    tablero[0] = { 't', 'h', 'b', 'k', 'q', 'b', 'h', 't' }; // Primera fila: torres, caballos, alfiles, rey y reina
    tablero[1] = { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' }; // Segunda fila: peones negros

    // Se colocan las piezas blancas en las dos ultimas filas (en mayusculas)
    tablero[6] = { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' }; // Septima fila: peones blancos
    tablero[7] = { 'T', 'H', 'B', 'Q', 'K', 'B', 'H', 'T' }; // Octava fila: piezas mayores blancas

    return tablero;
}

// esta funcion imprime el tablero
void mostrarTablero(vector<vector<char>>& tablero) {
    cout << "  1 2 3 4 5 6 7 8" << endl; // Numeros de columna

    for (int fila = 0; fila < 8; ++fila) {
        cout << 8 - fila << " "; // muestra el numero de fila
        for (int columna = 0; columna < 8; ++columna) {
            cout << tablero[fila][columna] << " "; 
        }
        cout << endl;
    }
}
