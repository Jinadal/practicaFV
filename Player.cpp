#include "Player.h"
#include <iostream>
Player::Player() {
    shape=new sf::RectangleShape(sf::Vector2f(10, 10));
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}
int Player::Movimiento(){
    return direccion;
}
void Player::render(){
    shape->setFillColor(sf::Color::Cyan);
    shape->setPosition(x,y);
}
void Player::update(){
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
void Player::setDireccion(int dir){
    direccion=dir;
}


