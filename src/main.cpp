#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800,600}), "HyperManifold");
    //window.setVerticalSyncEnabled(true);  //maybe don't use this with setFramerateLimit()
    window.setFramerateLimit(60); //internally uses sf::sleep...might need to change later

    //Player entity; might need to make separate class
    sf::RectangleShape player({40.f,60.f});

    //Ground entity 
    sf::Vector2f posY(0.f,450.f);
    sf::RectangleShape ground({960.f,40.f});
    ground.setPosition(posY);

    while(window.isOpen())
    {
        //pollEvent()is method using FIFO event queue so always call it in A LOOP
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);



        //typically, call it after all OpenGL rendering is done
        window.display(); //this is double-buffering; buffer copies and draws it to window
    }//end of "window open" while loop

    std::cout<<"Thank you for playing my game!";
}



