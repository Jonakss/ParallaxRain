#include "Drop.hpp"
#include "consts.hpp"

Drop::Drop(sf::Color c, int v){
  this->vel = v;
  this->color = c;
  this->z = rand()%7+1;

  this->pos = sf::Vector2f(rand()%WIDTH, 0);
  this->size = sf::Vector2f(this->z, this->vel+5);

  this->d = sf::RectangleShape();
  this->d.setPosition(this->pos);
  this->d.setSize(this->size);
};

void Drop::draw(sf::RenderWindow& w){
  w.draw(d);
};

void Drop::update(){
  this->pos.y += this->z+5;

  if(this->pos.y > HEIGTH){
    this->pos = sf::Vector2f(rand()%WIDTH, 0);
    this->z = rand()%7+1;
  }

  this->size.x = this->z;
  this->color.a = Drop::map(1, 8, 80, 255, this->z);
  // this->size.x = rand()%5;

  this->d.setFillColor(color);
  this->d.setSize(this->size);
  this->d.setPosition(this->pos);
};

void Drop::setColor(sf::Color c){
  this->color = c;
};

int Drop::map(int a, int b, int c , int d, int x){
  return c+(x-a)*(d-c)/(b-a);
};
