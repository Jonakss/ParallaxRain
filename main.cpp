#include <SFML/Window.hpp>
#include "Drop.hpp"
#include <SFML/Graphics.hpp>
#include "consts.hpp"
#include <unistd.h>

using drop_ptr = std::unique_ptr<Drop>;


int main(int argc, char *argv[]){
    const int dc = 250;
    std::array<std::unique_ptr<Drop>, dc> rain;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "Parallax Rain");
    for (int i = 0; i < dc; i++) {
      rain[i] = drop_ptr(new Drop(sf::Color::White, 10));
    }

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        for (int i = 0; i < dc; i++) {
          rain[i]->update();
          rain[i]->draw(window);
        }
        // Update the window
        window.display();

        usleep(10000);
    }
    return 0;
}
