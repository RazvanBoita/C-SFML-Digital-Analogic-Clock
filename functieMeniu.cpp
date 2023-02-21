
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstring>
#include </home/user-razvan/ceasIP/about.cpp>
using namespace std;
using namespace sf;
void meniu_principal(){
    RenderWindow meniu(VideoMode(1920,1080),"Meniu Principal",Style::Default);
    Sprite sprite;
    Font font;
    Font fontcifre;
    Texture texture;
    texture.loadFromFile("/home/user-razvan/ceasIP/stawt.jpg");
    font.loadFromFile("/home/user-razvan/ceasIP/AntipastoPro_trial.ttf");
    //fontcifre.loadFromFile("/home/user-razvan/ceasIP/fonts/DigitalNumbers-Regular.ttf");
    sprite.setTexture(texture);

    Text about;
    about.setCharacterSize(30);
    about.setColor(Color::White);
    about.setFont(font);
    about.setString("4. Despre proiect");
    about.setPosition(100,950);

    Text eliza;
    eliza.setCharacterSize(25);
    eliza.setColor(Color::White);
    eliza.setFont(font);
    eliza.setString("Eliza Ladaru");
    eliza.setPosition(1300,908);

    Text razvan;
    razvan.setCharacterSize(25);
    razvan.setColor(Color::White);
    razvan.setFont(font);
    razvan.setString("Razvan Boita");
    razvan.setPosition(1590,929);

    Text titlu;
    titlu.setCharacterSize(85);
    titlu.setColor(Color::White);
    titlu.setFont(font);
    titlu.setString("Bine ati venit!");
    titlu.setPosition(meniu.getSize().x/2-300,10);

    Text opt1;
    opt1.setCharacterSize(30);
    opt1.setFont(font);
    opt1.setColor(Color::White);
    opt1.setString("1. Incercati ceasul digital");
    opt1.setPosition(100,170);

    Text opt2;
    opt2.setCharacterSize(30);
    opt2.setFont(font);
    opt2.setColor(Color::White);
    opt2.setString("2. Incercati ceasul analogic");
    opt2.setPosition(100,270);

    Text opt3;
    opt3.setCharacterSize(30);
    opt3.setFont(font);
    opt3.setColor(Color::White);
    opt3.setString("3. Setati o alarma");
    opt3.setPosition(100,370);
    meniu.setFramerateLimit(60);

    Text opt4;
    opt4.setCharacterSize(30);
    opt4.setFont(font);
    opt4.setColor(Color::White);
    opt4.setString("4.Incercati temporizatorul");
    opt4.setPosition(100,470);

    Text opt5;
    opt5.setCharacterSize(30);
    opt5.setFont(font);
    opt5.setColor(Color::White);
    opt5.setString("5.Cand se schimba ora?");
    opt5.setPosition(100,570);

    Text opt6;
    opt6.setCharacterSize(30);
    opt6.setFont(font);
    opt6.setColor(Color::White);
    opt6.setString("6. Vedeti calendarul");
    opt6.setPosition(100,670);

    while(meniu.isOpen()){
        Event event;
        while(meniu.pollEvent(event)){
            if(event.type==Event::Closed){
                meniu.close();
            }
            if(event.type==Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                   meniu.close();
                if(Keyboard::isKeyPressed(Keyboard::Tab))
                    schimbaOra();
            }
        }
        if(Mouse::getPosition().x>=100&&Mouse::getPosition().x<=370&&Mouse::getPosition().y<=470 &&Mouse::getPosition().y>=450)
            {opt3.setColor(Color::Red);
             if(event.type==Event::MouseButtonPressed){
                ceasAlarma();
                // se apasa pe alarma
             }
            }
        else opt3.setColor(Color::White);

       if(Mouse::getPosition().x>=100&&Mouse::getPosition().x<=450&&Mouse::getPosition().y<=370&&Mouse::getPosition().y>=350)
           {opt2.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed) ceasAnalogic();
            // se apasa pe ceas analogic
           }
        else opt2.setColor(Color::White);

        if(Mouse::getPosition().x>=100&&Mouse::getPosition().x<=430&&Mouse::getPosition().y<=270&&Mouse::getPosition().y>=250){
            opt1.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed) ceasDigital();
            // se apasa pe ceas digital
        }
        else opt1.setColor(Color::White);

        if(Mouse::getPosition().x>=100&&Mouse::getPosition().x<=430&&Mouse::getPosition().y>=550&&Mouse::getPosition().y<=570){
            opt4.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed) temporizator();
            //se apasa pe temporizator
        }
        else opt4.setColor(Color::White);

        if(Mouse::getPosition().x>=100&&Mouse::getPosition().x<=410&&Mouse::getPosition().y>=650&&Mouse::getPosition().y<=670){
            opt5.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed) schimbaOra();
        }
        else opt5.setColor(Color::White);

        if(Mouse::getPosition().x>=100&&Mouse::getPosition().x<=390&&Mouse::getPosition().y>=750&&Mouse::getPosition().y<=770){
            opt6.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed) calendar();;;
        }
        else opt6.setColor(Color::White);

        if(Mouse::getPosition().x>=100&&Mouse::getPosition().x<=340&&Mouse::getPosition().y>=1030&&Mouse::getPosition().y<=1050){
            about.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed) sectiuneDespre();
            // se apasa pe despre
        }
        else about.setColor(Color::White);

        meniu.draw(sprite);
        meniu.draw(titlu);
        meniu.draw(opt1);
        meniu.draw(opt2);
        meniu.draw(opt3);
        meniu.draw(opt4);
        meniu.draw(opt5);
        meniu.draw(opt6);
        meniu.draw(eliza);
        meniu.draw(razvan);
        meniu.draw(about);
        meniu.display();
    }
}