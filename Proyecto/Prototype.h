#ifndef LEADERBOARD
#define LEADERBOARD
#include "DQueue.h"

// Estructura para almacenar los récords
struct Record
{
    char name[50];
    int score;
    char date[100];
};

struct Login
{
    char Usuario[50];
    char Contra[50];
};

void ObtenerFecha(char *Fecha);
void TextoProgresivo(char Texto[]);
int CompareRecords(const void *a, const void *b);
int Random();
int RandomSleep();
void BarraDeCarga(int Porcentaje);
void Logo();
void Color(int ColorGenerado);
int SimonDice(int Input, DQueue Simon, int ColorGenerado, NodeDQ *aux);
void Instrucciones();
int Menu(int Opcion, int ColorGenerado, DQueue Simon, int Input, int Score);
void Registro(char *Usuar, char *Contras);
int Inicio(char *Usuar, char *Contras);
void MostrarRecords();
void GuardarRecord(int Score, char *Usuar);
void Circulo(int ColorGenerado);

#include "Functions.c"
#endif