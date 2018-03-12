#include <iostream>
#include <stdlib.h>  
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
void IA::control(int dir, bool der,bool izq){
    int dir2=0;
    srand(time(NULL));
    int v1=rand() % 21;
    if(v1==0){          //ELEGIMOS UNA NUEVA DIRECCION ALEATORIA//
        dir2=dir;
    }
    if(v1>0 && v1<=10){
        dir2=dir+1;
    }
    else if(v1>10 && v1<=20){
        dir2=dir-1;
    }
     if(dir2==0){
         dir2=4;
     }
     if(dir2==5){
         dir2=1;
     }
        if(dir==1 && dir2==2 && izq==true){     //SI GIRAMOS A UN LADO OCUPADO, VAMOS AL OPUESTO//
            dir2=4;
        }
        if(dir==2 && dir2==3 && izq==true){
            dir2=1;
        }
        if(dir==3 && dir2==4 && izq==true){
            dir2=2;
        }
        if(dir==4 && dir2==1 && izq==true){
            dir2=3;
        }
        if(dir==1 && dir2==4 && der==true){
            dir2=2;
        }
        if(dir==2 && dir2==1 && der==true){
            dir2=3;
        }
        if(dir==3 && dir2==2 && der==true){
            dir2=4;
        }
        if(dir==4 && dir2==3 && der==true){
            dir2=1;
        }
    
    if(dir==1 && dir2==3){                  //SI QUIERE IR POR DONDE HA VENIDO, RELLAMAMOS AL METODO//
        control(dir,der,izq);
    }
    if(dir==2 && dir2==4){
        control(dir,der,izq);
    }
    if(dir==3 && dir2==1){
        control(dir,der,izq);
    }
    if(dir==4 && dir2==2){
        control(dir,der,izq);
        
    }
    setDireccion(dir2);
}
void IA::setDireccion(int dir){
    direccion=dir;
}



