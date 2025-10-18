 #include <iostream>
#include <string>
#include <sstream>
#include <thread>//manejar procesos 
#include <chrono>//definir tiempo
using namespace std;
//ctrl+k+f
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace ftxui;

string nave = 
string("      _      ")+ 
string("   _/   \_  ")+ 
string(" /  '---'  \ ")+ 
string("  '--___--'    ")+ 
string("     / \      ")+ 
string("    /   \     ")+ 
string("    /\O/\     ")+ 
string("    / | \     ")+ 
string("    // \\     ");
main()
{
    auto pantalla = screen::Create(
        Dimension::Full(0),
        Dimension::Fixed(10)
    );

    int x = 0;
    int y = 0;

    while(true)
   { 
    x++;

    stringstream ss(nave);
    string linea;
    int noLinea=0;
    while (getline(ss,nave))
        {
            int columna = 0;
      //obtener referencia del pixel y modificarlo
      for(auto &&letra :linea)
        {
        auto &pixel = pantalla.pixelAt(x + columna, y + noLinea);
        pixel.character = letra;
        columna++:
        }

        noLinea++;

       }
    }
//Imprimir la pantalla
    pantalla.print();
    pantalla.Clear();
    this_thread::sleep_for(chrono::seconds(1));
    cout<<pantalla.ResetPosition();
   }
   return 0;
}