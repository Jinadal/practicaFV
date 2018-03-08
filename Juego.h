#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "IA.h"
#include <SFML/System.hpp>



class Juego{
  
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
    Player* jugador1;
    IA* jugador2;
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