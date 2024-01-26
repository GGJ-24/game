#include <SFML/Graphics.hpp>
#include "MainMenu.h"

using namespace sf;

int main(){
  
  RenderWindow Menu(VideoMode(960,720),"Main Menu",Style::Default);
  MainMenu mainMenu(Menu.getSize().x,Menu.getSize().y);

  while (Menu.isOpen())
  {
    Event event;
    while (Menu.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        Menu.close();
      }

      if (event.type == Event::KeyReleased)
      {
        if (event.key.code == Keyboard::Up)
        {
          mainMenu.MoveUp();
          break;
        }
        if (event.key.code == Keyboard::Down)
        {
          mainMenu.MoveDown();
          break;
        }
        
        if (event.key.code == Keyboard::Return) 
        {
          RenderWindow Play(VideoMode(960,720),"PUNCHER");

          int x = mainMenu.MainMenuPressed();

          if(x==0){
            while (Play.isOpen())
            {
              Event event2;

              while (Play.pollEvent(event2))
              {
                if (event2.type == Event::Closed)
                {
                  Play.close();
                }
                if (event2.type == Event::KeyPressed)
                {
                  if (event2.key.code == Keyboard::Escape)
                  {
                    Play.close();
                  }
                  
                }              
              }

              Play.clear();
              Play.display();
            }
          }

          if (x==1)
          {
            Menu.close();
          }
          break;
        } 
      }
    }
    Menu.clear();
    mainMenu.draw(Menu);
    Menu.display();
    
  }
  
}