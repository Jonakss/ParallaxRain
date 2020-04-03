#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


class Drop{
  public:
    Drop(sf::Color c, int v);
    void draw(sf::RenderWindow& w);
    void update();
    void setColor(sf::Color c);
  private:
    sf::Vector2f pos, size;
    int vel, z;
    sf::Color color;
    sf::RectangleShape d;
    int map(int a, int b, int c, int d, int x);
};
