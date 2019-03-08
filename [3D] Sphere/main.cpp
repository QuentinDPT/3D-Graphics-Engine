#include <iostream>
#include <fstream>
#include <windows.h>

#include "Game.hpp"
#include "Graphics3D.hpp"

using namespace std;

int main()
{
    system("title [DEBUG] MyWorld 1.0.0") ;
    creation_fenetre("MyWorld 1.0.0",winLength,winWidth) ;

    mainGame() ;

    return 0;
}
