#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
#include <Corral.hpp>
#include <thread>
#include <chrono>
using namespace ftxui;

int main()
{
    // Crear la ventana
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24)
    );

    // Agregar código de los elementos de la granja
    const std::vector<std::u32string> granja1 = {
        U"  _______ ",
        U" /  ___  \\",
        U"|  |   |  |",
        U"|  |   |  |",
        U"|__|___|__|"
    };

    const std::vector<std::u32string> pistola = {
        U"     +--^----------,--------,-----,--------^-",
        U"     | |||||||||   `--------'     |          O",
        U"     `+---------------------------^----------|",
        U"       `\\_,---------,---------,--------------'",
        U"         / XXXXXX /'|       /'",
        U"        / XXXXXX /  `\\    /'",
        U"       / XXXXXX /`-------'",
        U"      / XXXXXX /",
        U"     / XXXXXX /",
        U"    (________(",
        U"     `------' ",
    };


    const std::vector<std::u32string> bala = {
        U" :>> ̗̀",
    };

    GestorDibujos gestor;
    gestor.Agregar(Dibujo(8, 10, pistola, ftxui::Color::GrayLight));  // pistola gris
    gestor.Agregar(Dibujo(10, 11, bala, ftxui::Color::White));   // bala blanca (bajada 5 renglones)

    // Índice y parámetros de la bala (ajusta start_x y speed)
    size_t idx_bala = gestor.dibujos.size() - 1; // índice de la última bala añadida
    const int bala_start_x = 10;
    const int screen_width = 80;
    const int bala_speed = 1; // columnas por frame

    // Crear corral más grande y vacas separadas dentro
     Corral corral(50, 15, 30, 18, ftxui::Color::White);


    // Limpia pantalla del terminal y oculta cursor (una vez al inicio)
    std::cout << "\x1b[2J";     // Clear screen
    std::cout << "\x1b[?25l";   // Hide cursor
    std::cout << std::flush;

    int frames = 120;
    for (int frame = 0; frame < frames; ++frame)
    {
        // Limpia la pantalla interna de ftxui
        screen.Clear();

        // Mover la bala hacia la derecha si existe
        if (idx_bala < gestor.dibujos.size()) {
            int x = bala_start_x + frame * bala_speed;
            // si sale de la pantalla, reinicia para que vuelva a salir por la pistola
            if (x >= screen_width) x = bala_start_x + ((x - bala_start_x) % (screen_width - bala_start_x));
            gestor.dibujos[idx_bala].x = x;
        }

   
        gestor.DibujarTodos(screen);
        std::cout << "\x1b[H" << screen.ToString() << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Restaurar cursor visible antes de salir
    std::cout << "\x1b[?25h" << std::flush;

    return 0;
    //./bin/animacion
    //g++ -std=c++20 -I./include -o bin/animacion src/animacion.cpp \
  -L./lib -lftxui-component -lftxui-dom -lftxui-screen -pthread
}