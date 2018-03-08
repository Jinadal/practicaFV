#include <iostream>
#include "IA.h"

IA::IA() {
    shape=new sf::RectangleShape(sf::Vector2f(10, 10));
}

IA::IA(const IA& orig) {
}

IA::~IA() {
}
int IA::Movimiento(){
    return direccion;
}
void IA::render(){
    shape->setFillColor(sf::Color::Yellow);
    shape->setPosition(x,y);
}
void IA::update(){
    switch(direccion){
            case 1:
                y=y-10;
                break;
            case 2:
                x=x-10;
                break;
            case 3:
                y=y+10;
                break;
            case 4:
                x=x+10;
                break;
            default:
                break;
    }
}
void IA::setDireccion(int dir){
    direccion=dir;
}



