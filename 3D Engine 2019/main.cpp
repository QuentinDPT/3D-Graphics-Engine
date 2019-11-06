#define SDL_MAIN_HANDLED

#include <iostream>

#include "Graphics.hpp"

using namespace std;

int main()
{
    cout << "Un Point    : " << Graphics::Point<int>(5,10) << '\n' ;
    cout << "Une Taille  : " << Graphics::Size<int>(5,10) << '\n' ;
    cout << "Une Couleur : " << Graphics::Color(255,255,75) << '\n' ;
    cout << "Une Couleur : " << Graphics::Color("#FFFFFA") << '\n' ;




    return 0;
}
