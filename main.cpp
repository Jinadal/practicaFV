#include <SFML/Graphics.hpp>
#include <iostream>
#include "Juego.h"

using namespace std;

int main() {

    Juego *p = new Juego();

    p->run();
    
    delete p;
    return 0;
}