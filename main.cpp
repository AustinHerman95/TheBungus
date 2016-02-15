/* The Game
 * A simple prototype for a game I hope to finish
 * Author: Austin Herman
 * Started: 12/15/15
 * Last Update: 12/25/15
 * Progress: Building
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "level1.h"
#include "saveload.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(768, 768), "The Game");

	sf::IntRect menu1(0,0,768,768);
	sf::IntRect menu2(768,0,768,768);
	sf::IntRect menu3(1536,0,768,768);

	sf::IntRect selectArray[] = {menu1, menu2, menu3};

	sf::Texture sTexture;
	sf::Sprite sSprite;
	sTexture.loadFromFile("png/menu/splashscreen768x768.png");
	sSprite.setTexture(sTexture);
	sSprite.setTextureRect(menu1);

	int choice = 0;

	while(window.isOpen())
	{
		sf::Event sEvent;
		while (window.pollEvent(sEvent))
        {
			if(sEvent.type == sf::Event::Closed)
				window.close();

			if(sEvent.type == sf::Event::KeyPressed)
			{
				if(sEvent.key.code == sf::Keyboard::W)
				{
					choice--;

					if(choice < 0)
						choice = 2;
				}
				if(sEvent.key.code == sf::Keyboard::S)
				{
					choice++;
					
					if(choice > 2)
						choice = 0;
				}
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			break;

		sSprite.setTextureRect(selectArray[choice]);

		window.clear();
		window.draw(sSprite);
		window.display();
	}
	
	switch(choice)
	{
	case 0: 
		{
			level1* level = new level1();
			level->level1Display(window, SaveLoad::load(false));
			delete level;
			break;
		}
	case 1:
		{
			level1* level = new level1();
			level->level1Display(window, SaveLoad::load(true));
			delete level;	
			break;
		}
	case 2:{window.close();}
	}

	//level1* level = new level1();

	//level->level1Display(window);
	//delete level;

    return 0;
}
