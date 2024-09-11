#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "colors.h"
#include "Prototype.h"
#include "DQueue.h"

int main(int argc, char const *argv[])
{
    int Usuario_Input = 0;
    int score = 0;
    int opcion = 0;
    int GeneratedColor = Random();

    // Obtener el manejador de la consola
    HWND consoleWindow = GetConsoleWindow();

    // Ocultar la consola para evitar el parpadeo mientras aplicamos los cambios
    ShowWindow(consoleWindow, SW_HIDE);

    // Obtener el estilo de la ventana de la consola
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

    // Eliminar los estilos que permiten redimensionar y maximizar
    style &= ~(WS_SIZEBOX | WS_MAXIMIZEBOX);

    // Agregar el estilo que elimina los bordes y la barra de título
    style &= ~(WS_CAPTION | WS_THICKFRAME);

    // Establecer los nuevos estilos
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    // Aplicar los cambios de estilo
    SetWindowPos(consoleWindow, NULL, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

    // Obtener la resolución de la pantalla primaria
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Ajustar el tamaño de la consola para que ocupe toda la pantalla
    MoveWindow(consoleWindow, 0, 0, screenWidth, screenHeight, TRUE);

    // Mostrar la consola con los nuevos ajustes
    ShowWindow(consoleWindow, SW_SHOW);

    DQueue Simon_a;
    createDQ(&Simon_a);

    Logo();

    for (int i = 0; i <= 100; ++i)
    {
        BarraDeCarga(i);
        int n = RandomSleep();
        Sleep(n);
    }

    Logo();

    TextoProgresivo("\t\t\t\t\t\t\t\t\t\t\t PRESIONA ENTER PARA CONTINUAR...");
    fflush(stdin);
    _getch();

    Sleep(400);

    system("cls");

    do
    {
        opcion = Menu(opcion, GeneratedColor, Simon_a, Usuario_Input, score);
    } while (opcion != 6);

    return 0;
}