
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <string>

#include "bat.h"
#include "ball.h"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    int window_width = 1200;
    int window_height = 800;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Mrinank's Pong");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "PressStart2P.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text title("PONG!", font, 50);
    title.setFillColor(sf::Color::White);
    title.setPosition((window_width - title.getLocalBounds().width)/2, 50);
    
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "boomaga.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();
    
    int player1_score = 0;
    int player2_score = 0;
    
    sf::Text p1_score("0", font, 100);
    p1_score.setFillColor(sf::Color::White);
    p1_score.setPosition((0.5 * window_width - p1_score.getLocalBounds().width)/2, (window_height - p1_score.getLocalBounds().height)/2);
    
    sf::Text p2_score("0", font, 100);
    p2_score.setFillColor(sf::Color::White);
    p2_score.setPosition((1.5 * window_width - p2_score.getLocalBounds().width)/2, (window_height - p1_score.getLocalBounds().height)/2);
    
    title.setPosition((window_width - title.getLocalBounds().width)/2, 50);
    
    Bat player1_bat (20, window_height/2, window_height);
    Bat player2_bat (window_width-30, window_height/2, window_height);
    
    // create a ball
    Ball ball(window_width / 2, window_height/2);
    
    sf::Text info("The First to 6 Wins! Player 1: Up/Down. Player 2: W/S Keys.", font, 20);
    info.setFillColor(sf::Color::White);
    info.setPosition((window_width - info.getLocalBounds().width)/2, window_height-30);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            player1_bat.mvUp();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            player1_bat.mvDown();
        }
        
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            player2_bat.mvUp();
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            player2_bat.mvDown();
        }
        
        
        if (ball.getPosition().top > window_height or ball.getPosition().top < 0)
        {
            ball.reboundTopOrBottom();
        }
        
        if (ball.getPosition().intersects(player1_bat.getPosition()) or ball.getPosition().intersects(player2_bat.getPosition()))
        {
            // Hit detected so reverse the ball and score a point
            ball.reboundBat();
        }
         
        if (ball.getPosition().left < 0)
        {
            ball.center();
            player2_score++;
            if (player2_score > 5){
                player1_score = 0;
                player2_score = 0;
            }
            p1_score.setString(std::to_string(player1_score));
            p2_score.setString(std::to_string(player2_score));
        }
        else if(ball.getPosition().left+ball.getSize() > window_width){
            ball.center();
            player1_score++;
            if (player1_score > 5){
                player1_score = 0;
                player2_score = 0;
            }
            p1_score.setString(std::to_string(player1_score));
            p2_score.setString(std::to_string(player2_score));
        }
        
        ball.update();
        player1_bat.update();
        player2_bat.update();
        
        // Clear screen
        window.clear();

        window.draw(player1_bat.getShape());
        window.draw(player2_bat.getShape());
        window.draw(ball.getShape());
        // Draw the string
        window.draw(title);
        window.draw(p1_score);
        window.draw(p2_score);
        window.draw(info);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
