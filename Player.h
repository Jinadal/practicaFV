#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    int Movimiento();
    void update();
    void render();
    void setDireccion(int dir);
    sf::RectangleShape getShape(){
        return *shape;
    }
private:
    sf::RectangleShape *shape;
    int direccion=4;
    int x=400,y=300;
};

#endif

