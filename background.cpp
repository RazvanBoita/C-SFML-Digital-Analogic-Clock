#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>
#include "meniu.h"
#include <SFML/System/Sleep.hpp>
using namespace std;
char s[25];
char m[25];
char h[25];
bool alarma_a_sunat=false;
int main(){
   int ora_alarma,min_alarma;   
   cout<<"Introduceti, cu spatiu intre ele, ora si minutul la care vreti sa setati o alarma!"<<'\n';
   cout<<"Ora: ";
   cin>>ora_alarma;
   cout<<'\n';
   cout<<"Minutul: ";
   cin>>min_alarma;
   cout<<'\n';

   sf::Font font;
   font.loadFromFile("/home/user-razvan/ceasIP/fonts/DigitalNumbers-Regular.ttf");
   sf::CircleShape pct1(10);
   sf::CircleShape pct2(10);
   sf::CircleShape pct3(10);
   sf::CircleShape pct4(10);
   
   pct4.setFillColor(sf::Color::Red);
   pct1.setFillColor(sf::Color::Red);
   pct2.setFillColor(sf::Color::Red);
   pct3.setFillColor(sf::Color::Red);
   int x1=700;
   int x2=1010;
   int y1=430;
   int y2=550;
   pct1.setPosition(x1,y1);
   pct2.setPosition(x1,y2);
   pct3.setPosition(x2,y1);
   pct4.setPosition(x2,y2);

   sf::Text tsec;
   tsec.setFont(font);
   tsec.setCharacterSize(150);
   tsec.setColor(sf::Color::White);
   tsec.setPosition(1042,394);

   sf::Text tmin;
   tmin.setFont(font);
   tmin.setCharacterSize(150);
   tmin.setColor(sf::Color::White);
   tmin.setPosition(732,394);

   sf::Text tora;
   tora.setFont(font);
   tora.setCharacterSize(150);
   tora.setColor(sf::Color::White);
   tora.setPosition(420,394);

   // Setarea Backgroundului 

   sf::RenderWindow window(sf::VideoMode(1920,1080), "Ceas Digital",Style::Fullscreen);
   window.setFramerateLimit(60);
   srand(time(NULL));
   sf::Texture texture;
   if (!texture.loadFromFile("/home/user-razvan/ceasIP/background.jpg"))
    { 
      std::cout<<"FAIL"; 
      return false;
    }
   sf::Sprite sprite;
   sprite.setTexture(texture); 
   

   // Bucla in care se afiseaza, se controleaza imaginea  
   while(window.isOpen()){
     sf::Event event;
     while(window.pollEvent(event)){
       if(event.type==sf::Event::Closed)
          window.close();
       
       if(event.type==sf::Event::KeyPressed)
       {
           // Atunci cand se apasa Escape, iesim din program
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            std::cout<<"Ceasul a fost inchis!"<<std::endl;
            window.close();
           }
       }
     }
      window.clear(sf::Color(32,32,32));
      time_t timp_curent;
      timp_curent=time(NULL);
      tm* timp_local=localtime(&timp_curent);
      int sec=timp_local->tm_sec;
      int min=timp_local->tm_min;
      int ora=timp_local->tm_hour;
      if(min==min_alarma && ora==ora_alarma) 
      {
         alarma_a_sunat=true;
         window.close();
      }
      sprintf(s,"%d",sec);
      sprintf(m,"%d",min);
      sprintf(h,"%d",ora);
      if(strlen(s)==1){
         char aux=s[0];
         s[0]='0';
         s[1]=aux;
         s[2]=NULL;
      }
      if(strlen(m)==1){
         char aux=m[0];
         m[0]='0';
         m[1]=aux;
         m[2]=NULL;
      }
      if(strlen(h)==1){
         char aux=h[0];
         h[0]='0';
         h[1]=aux;
         h[2]=NULL;
      }
      tsec.setString(s);
      tmin.setString(m);
      tora.setString(h);
      window.draw(sprite); // background-ul
      window.draw(tsec);
      window.draw(tmin);
      window.draw(tora);
      window.draw(pct1);
      window.draw(pct2);
      window.draw(pct3);
      window.draw(pct4);
      window.display();
   }
   if(alarma_a_sunat){
   cout<<"Alarma dumneavoastra suna! Apasati combinatia de taste CTRL+C pentru a o opri! "<<endl;
   system("canberra-gtk-play -f mixkit-alarm-digital-clock-beep-989.wav  -V 10 -l 5");
   }
   else cout<<"Multumim pentru timpul acordat ceasului nostru!"<<endl;
   return 0;
   }   
