#pragma once

#include <vector>

using namespace std;

bool esMayuscula(char c);
bool esMinuscula(char c);
char aMinuscula(char c);
int valorAbsoluto(int x);
bool esMovimientoValido(char pieza, int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino, vector<vector<char>>& tablero);
bool moverPieza(vector<vector<char>>& tablero, int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino, bool turnoBlanco);
