#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <SFML/System.hpp>


class Juego{
private:
    const int W=600,D=480;
    
private:
    sf::RenderWindow ventana;
    sf::Event miEvento;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock1;
    bool inGame{true};
    bool virgen{true};
    Player* jugador;
    void inicializar();
    void eventos();
    void update();
    void render();
    void cleared();
public:
    Juego();
    void run();
    
    
};