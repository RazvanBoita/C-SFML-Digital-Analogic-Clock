
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
void calendar(){

    RenderWindow window(VideoMode(1920,1080),"Calendar 2023",Style::Fullscreen);
    Font font;
    font.loadFromFile("/home/user-razvan/ceasIP/Lato-BoldItalic.ttf");
    Sprite sprite;
    Texture texture[12];
    texture[0].loadFromFile("/home/user-razvan/ceasIP/poze/ianuarie.jpg");
    texture[1].loadFromFile("/home/user-razvan/ceasIP/poze/februarie.jpg");
    texture[2].loadFromFile("/home/user-razvan/ceasIP/poze/martie.jpg");
    texture[3].loadFromFile("/home/user-razvan/ceasIP/poze/aprilie.jpg");
    texture[4].loadFromFile("/home/user-razvan/ceasIP/poze/mai.jpg");
    texture[5].loadFromFile("/home/user-razvan/ceasIP/poze/iunie.jpg");
    texture[6].loadFromFile("/home/user-razvan/ceasIP/poze/iulie.jpg");
    texture[7].loadFromFile("/home/user-razvan/ceasIP/poze/august.jpg");
    texture[8].loadFromFile("/home/user-razvan/ceasIP/poze/septembrie.jpg");
    texture[9].loadFromFile("/home/user-razvan/ceasIP/poze/octombrie.jpg");
    texture[10].loadFromFile("/home/user-razvan/ceasIP/poze/noiembrie.jpg");
    texture[11].loadFromFile("/home/user-razvan/ceasIP/poze/decembrie.jpg");
    sprite.setTexture(texture[0]);

    Text sageata_stanga,sageata_dreapta;
    sageata_dreapta.setString(">"); sageata_dreapta.setFont(font); sageata_dreapta.setCharacterSize(120);
    sageata_dreapta.setColor(Color::Blue); sageata_dreapta.setOutlineThickness(5.0f); sageata_dreapta.setPosition(1800,520);
    sageata_stanga.setString("<"); sageata_stanga.setFont(font); sageata_stanga.setCharacterSize(120);
    sageata_stanga.setColor(Color::Blue); sageata_stanga.setOutlineThickness(5.0f); sageata_stanga.setPosition(70,520);

    CircleShape exit(30);
    exit.setFillColor(Color::Red);
    exit.setPosition(1810,25);
    Text corner;
    corner.setFont(font); corner.setCharacterSize(40); corner.setString("X"); corner.setColor(Color::White); corner.setOutlineThickness(5.0f);
    corner.setPosition(1827,30);
    int contor=0;
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed) window.close();
            if(event.type==Event::KeyPressed)
                if(Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

            if(Mouse::getPosition().x>=1810&&Mouse::getPosition().x<=1870&&Mouse::getPosition().y>=10&&Mouse::getPosition().y<=80){
                exit.setFillColor(Color::White);
                corner.setColor(Color::Red);
                if(event.type==Event::MouseButtonPressed) window.close();
            }
            else{
                exit.setFillColor(Color::Red);
                corner.setColor(Color::White);
            }

            if(Mouse::getPosition().x>=1810&&Mouse::getPosition().x<=1865&&Mouse::getPosition().y>=565&&Mouse::getPosition().y<=625){
                sageata_dreapta.setColor(Color::White);
                if(event.type==Event::MouseButtonPressed){
                    if(contor<11) contor++;
                    else contor=0;
                }
            }
            else sageata_dreapta.setColor(Color::Blue);

            if(Mouse::getPosition().x>=80&&Mouse::getPosition().x<=135&&Mouse::getPosition().y>=565&&Mouse::getPosition().y<=625){
                sageata_stanga.setColor(Color::White);
                if(event.type==Event::MouseButtonPressed){
                    if(contor>0) contor--;
                    else contor=11;
                }
            }
            else sageata_stanga.setColor(Color::Blue);

            if(event.type==Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Left)){
                    if(contor>0) contor--;
                    else contor=11;
                }
                if(Keyboard::isKeyPressed(Keyboard::Right)){
                    if(contor<11) contor++;
                    else contor=0;
                }
            }
        }
        sprite.setTexture(texture[contor]);
        window.draw(sprite);
        window.draw(sageata_stanga);
        window.draw(sageata_dreapta);
        window.draw(exit);
        window.draw(corner);
        window.display();
    }
}