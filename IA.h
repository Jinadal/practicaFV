#ifndef IA_H
#define IA_H
#include <SFML/Graphics.hpp>
class IA {
public:
    IA();
    IA(const IA& orig);
    virtual ~IA();
    int Movimiento();
    void update();
    void render();
    void setDireccion(int dir);
    sf::RectangleShape getShape(){
        return *shape;
    }
private:
    sf::RectangleShape *shape;
    int direccion=2;
    int x=600,y=350;
};

#endif