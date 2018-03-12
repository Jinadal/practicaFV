#include "Juego.h"
#define kUpdateTimePS 1000/15

Juego::Juego(): ventana{sf::VideoMode{W,D}, "Tron FV"}{
    
                                                          }

void Juego::inicializar()
{
    ventana.setFramerateLimit(60);
    jugador=new Player();
    if (!texture.loadFromFile("background.jpg",sf::IntRect(0,0,480,480)))
    {
    }
    sprite.setTexture(texture);
}

void Juego::eventos(){
    while(ventana.pollEvent(miEvento)){
        if(miEvento.type==sf::Event::Closed)
            inGame=false;
        if(miEvento.key.code==sf::Keyboard::W && jugador->Movimiento()!=3){
            jugador->setDireccion(1);
        }
        if(miEvento.key.code==sf::Keyboard::A && jugador->Movimiento()!=4){
            jugador->setDireccion(2);
        }
        if(miEvento.key.code==sf::Keyboard::S && jugador->Movimiento()!=1){
            jugador->setDireccion(3);
        }
        if(miEvento.key.code==sf::Keyboard::D && jugador->Movimiento()!=2){
            jugador->setDireccion(4);
        }  
    }
}
void Juego::render(){
    if(virgen){
    ventana.clear(sf::Color::Black);
    ventana.draw(sprite);    
    virgen=false;
    }
    jugador->render();
    ventana.draw(jugador->getShape());
    ventana.display();
}
void Juego::cleared(){
    ventana.close();
}
void Juego::update(){
    jugador->update();
}
void Juego::colisiones(){
    int xnext=jugador->getShape().getPosition().x,ynext=jugador->getShape().getPosition().y;
    if(jugador->Movimiento()==1){
        ynext=ynext-7;
    }
    if(jugador->Movimiento()==2){
        xnext=xnext-7;
    }
    if(jugador->Movimiento()==3){
        ynext=ynext+7;
    }
    if(jugador->Movimiento()==4){
        xnext=xnext+7;
    }
    Image=ventana.capture();
    if(Image.getPixel(xnext,ynext)==sf::Color::Blue){
        inGame=false;
    }
}
void Juego::run(){
    inicializar();
    sf::Time timeStartUpdate=clock1.getElapsedTime();
    while(inGame){
        eventos();
        if(clock1.getElapsedTime().asMilliseconds()- timeStartUpdate.asMilliseconds()>kUpdateTimePS)
        {
            colisiones();
            update();
            timeStartUpdate=clock1.getElapsedTime();
        }
        render();
    }
    cleared();
}