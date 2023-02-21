
#include "meniu.h"
MainMenu::MainMenu(float width,float height){
    if(!font.loadFromFile("/home/user-razvan/ceasIP/fonts/DigitalNumbers-Regular.ttf"))
       cout<<"No font is here...";
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(400,200);
     
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Options");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(400,300);
    
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("Altceva");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(400,400);
    
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Exit");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(400,500);
    MainMenuSelected=-1;
}
MainMenu::~MainMenu(){

}
void MainMenu::draw(RenderWindow& window){
    for(int i=0;i<4;i++){
        window.draw(mainMenu[i]);
    }
}

void MainMenu::MoveUp(){
    if(MainMenuSelected-1>=0){
        mainMenu[MainMenuSelected].setColor(Color::White);
        MainMenuSelected--;
        if(MainMenuSelected==-1) MainMenuSelected=2;
    }
    mainMenu[MainMenuSelected].setFillColor(Color::Blue);
}

void MainMenu::MoveDown(){
    if(MainMenuSelected+1<=4){
        mainMenu[MainMenuSelected].setColor(Color::White);
        MainMenuSelected++;
        if(MainMenuSelected==4) MainMenuSelected=0;
    }
    mainMenu[MainMenuSelected].setFillColor(Color::Blue);
}
int main(){
    return 0;
}