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
    sf::Image Image;
    bool inGame{true};
    bool virgen{true};
    bool colisionado{false};
    Player* jugador;
    void inicializar();
    void eventos();
    void update();
    void render();
    void cleared();
    void colisiones();
public:
    Juego();
    void run();
    
    
};