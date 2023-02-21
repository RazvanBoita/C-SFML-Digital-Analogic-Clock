
 char tempsec[15];
      char tempmin[15];
      char tempora[15];
      char sec[3]="";
      char min[3]="";
      char ora[3]="";
      sprintf(tempsec, "%d", timp_local->tm_sec);
      sprintf(tempmin, "%d", timp_local->tm_min);
      sprintf(tempora, "%d", timp_local->tm_hour);

      if(strlen(tempsec)==1){
      char aux=tempsec[0];
      tempsec[0]='0';
      tempsec[1]=aux;
      }
      sec[0]=tempsec[0];
      sec[1]=tempsec[1];

      if(strlen(tempmin)==1){
      char aux=tempmin[0];
      tempmin[0]='0';
      tempmin[1]=aux;
      }
      min[0]=tempmin[0];
      min[1]=tempmin[1];

      if(strlen(tempora)==1){
      char aux=tempora[0];
      tempora[0]='0';
      tempora[1]=aux;
      }
      ora[0]=tempora[0];
      ora[1]=tempora[1];

      sf::Text tsec;
      tsec.setFont(font);
      tsec.setCharacterSize(150);
      tsec.setColor(sf::Color::White);
      tsec.setPosition(1040,394);
      tsec.setString(sec);

      sf::Text tmin;
      tmin.setFont(font);
      tmin.setCharacterSize(150);
      tmin.setColor(sf::Color::White);
      tmin.setPosition(770,394);
      tmin.setString(min);

      sf::Text tora;
      tora.setFont(font);
      tora.setCharacterSize(150);
      tora.setColor(sf::Color::White);
      tora.setPosition(490,394);
      tora.setString(ora);

      window.draw(sprite); // background-ul
      window.draw(text);   // text-ul
      window.draw(tsec);
      window.draw(tmin);
      window.draw(tora);
      window.draw(pct1);
      window.draw(pct2);
      window.draw(pct3);
      window.draw(pct4);
      window.display();
      timp_local->tm_sec++;
      }