#include "Juego.h"
#define kUpdateTimePS 1000/15

Juego::Juego(): ventana{sf::VideoMode{700,700}, "Tron FV"}{
    
                                                          }

void Juego::inicializar()
{
    ventana.setFramerateLimit(60);
    jugador1=new Player();
    jugador2=new IA();
    if (!texture.loadFromFile("background2.jpg",sf::IntRect(0,0,700,700)))
    {
    }
    sprite.setTexture(texture);
}

void Juego::eventos(){
    while(ventana.pollEvent(miEvento)){
        if(miEvento.type==sf::Event::Closed)
            inGame=false;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && jugador1->Movimiento()!=3){
            jugador1->setDireccion(1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && jugador1->Movimiento()!=4){
            jugador1->setDireccion(2);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && jugador1->Movimiento()!=1){
            jugador1->setDireccion(3);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && jugador1->Movimiento()!=2){
            jugador1->setDireccion(4);
        } 
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && jugador2->Movimiento()!=3){
            jugador2->setDireccion(1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && jugador2->Movimiento()!=4){
            jugador2->setDireccion(2);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && jugador2->Movimiento()!=1){
            jugador2->setDireccion(3);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && jugador2->Movimiento()!=2){
            jugador2->setDireccion(4);
        }  
    }
}
void Juego::render(){
    if(virgen){
    ventana.clear(sf::Color::Black);
    ventana.draw(sprite);    
    virgen=false;
    }
    jugador1->render();
    jugador2->render();
    ventana.draw(jugador1->getShape());
    ventana.draw(jugador2->getShape());
    ventana.display();
}
void Juego::cleared(){
    ventana.close();
}
void Juego::update(){
    jugador1->update();
    jugador2->update();
}
void Juego::colisiones(){
    int xnext=jugador1->getShape().getPosition().x,ynext=jugador1->getShape().getPosition().y;
    int xnext2=jugador2->getShape().getPosition().x,ynext2=jugador2->getShape().getPosition().y;
    if(jugador1->Movimiento()==1){
        ynext=ynext-10;
    }
    if(jugador1->Movimiento()==2){
        xnext=xnext-10;
    }
    if(jugador1->Movimiento()==3){
        ynext=ynext+10;
    }
    if(jugador1->Movimiento()==4){
        xnext=xnext+10;
    }
    if(jugador2->Movimiento()==1){
        ynext2=ynext2-10;
    }
    if(jugador2->Movimiento()==2){
        xnext2=xnext2-10;
    }
    if(jugador2->Movimiento()==3){
        ynext2=ynext2+10;
    }
    if(jugador2->Movimiento()==4){
        xnext2=xnext2+10;
    }
    Image=ventana.capture();
    if(Image.getPixel(xnext,ynext)==sf::Color::Cyan || Image.getPixel(xnext,ynext)==sf::Color::Yellow || Image.getPixel(xnext2,ynext2)==sf::Color::Yellow || Image.getPixel(xnext2,ynext2)==sf::Color::Cyan ||xnext<0 || xnext2<0 || xnext>=700 || xnext2>=700 || ynext<0 || ynext2<0 || ynext>=700 || ynext2>=700){
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