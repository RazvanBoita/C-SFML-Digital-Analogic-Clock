
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#include <cstring>
using namespace sf;
using namespace std;
char s[4],m[4],h[4];
int main(){
    RenderWindow window(VideoMode(1920,1080),"Cronometru", Style::Default);
    Sprite sprite;
    Texture texture;
    texture.loadFromFile("/home/user-razvan/ceasIP/planeta2.jpg");
    sprite.setTexture(texture);
    Font font;
    font.loadFromFile("/home/user-razvan/ceasIP/Lato-BoldItalic.ttf");
    Text ora,min,sec;
    CircleShape redCircles[4];
    for(int i=0;i<4;i++){
        redCircles[i].setFillColor(Color::Red);
        redCircles[i].setRadius(8);
        if(i<2)
            redCircles[i].setPosition(870,485+i*50);
        else redCircles[i].setPosition(1055,485+(i%2)*50);
    }
    ora.setFont(font);
    min.setFont(font);
    sec.setFont(font);
    ora.setColor(Color::White);
    min.setColor(Color::White);
    sec.setColor(Color::White);
    ora.setCharacterSize(100);
    min.setCharacterSize(100);
    sec.setCharacterSize(100);
    ora.setString("00");
    sec.setString("00");
    min.setString("00");
    ora.setPosition(730,450);
    min.setPosition(910,450);
    sec.setPosition(1090,450);

    CircleShape buton(50);
    buton.setFillColor(Color::Green);
    buton.setPosition(1080,630);
    buton.setOutlineColor(Color::White);
    buton.setOutlineThickness(3.0f);

    CircleShape reset(50);
    reset.setFillColor(Color(105,105,105));
    reset.setPosition(750,630);
    reset.setOutlineColor(Color::White);
    reset.setOutlineThickness(3.0f);

    Text treset,tstart;
    treset.setFont(font); treset.setString("Reset"); treset.setColor(Color::White); treset.setCharacterSize(35);
    tstart.setFont(font); tstart.setString("Start"); tstart.setCharacterSize(35); tstart.setColor(Color::White);
    tstart.setPosition(1095,655); treset.setPosition(760,655);

    int contor=0;
    bool am_inceput=false;
    bool doar_o_data=false;
    int ora_cur,min_cur,sec_cur,now_ora,now_min,now_sec,sec_init,sec_final,de_afisat,ora_fin=0,min_fin=0,sec_fin=0;
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed) window.close();
            if(event.type==Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                    window.close();
            }
            if(Mouse::getPosition().x>=1080&&Mouse::getPosition().x<=1180&&Mouse::getPosition().y>=700&&Mouse::getPosition().y<=800){
                if(event.type==Event::MouseButtonPressed) contor++;
            }
        }
        if(contor%2==0){
            buton.setFillColor(Color::Green);
            tstart.setString("Start");
            am_inceput=false;
        }
        else{
            buton.setFillColor(Color::Red);
            tstart.setString("Stop");
            am_inceput=true;
            doar_o_data=false;
        }
        if(am_inceput){
            //incepe magia
            time_t timp_curent;
            timp_curent=time(NULL);
            tm* timp_local=localtime(&timp_curent);
            if(doar_o_data==false){
                ora_cur=timp_local->tm_hour;
                min_cur=timp_local->tm_min;
                sec_cur=timp_local->tm_sec;
                doar_o_data=true;
            }
            sec_init=ora_cur*3600+min_cur*60+sec_cur*60;
            now_ora=timp_local->tm_hour;
            now_min=timp_local->tm_min;
            now_sec=timp_local->tm_sec;
            sec_final=now_ora*3600+now_min*60+now_sec;
            de_afisat=sec_final-sec_init;
            ora_fin=de_afisat/3600;
            min_fin=(de_afisat%3600)/60;
            sec_fin=(de_afisat%3600)%60;
        }
        sprintf(s,"%d",sec_fin);
        sprintf(m,"%d",min_fin);
        sprintf(h,"%d",ora_fin);
        ora.setString(h);
        min.setString(m);
        ora.setString(h);
        window.draw(sprite);
        window.draw(ora);
        window.draw(sec);
        window.draw(min);
        for(int i=0;i<4;i++) window.draw(redCircles[i]);
        window.draw(buton); window.draw(tstart);
        window.draw(reset); window.draw(treset);
        window.display();
    }
    return 0;
}
