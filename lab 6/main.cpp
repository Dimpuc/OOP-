#include <iostream>
#include <string>

class Animal {
protected:
  std::string name;

public:
  Animal(const std::string& animalName) : name(animalName) {}
  virtual ~Animal() {}

  virtual void sound() const = 0;
  virtual void display() const = 0;
};

class Mammal : public Animal {
public:
  Mammal(const std::string& mammalName) : Animal(mammalName) {}

  void display() const override {
    std::cout << "Mammal: " << name << std::endl;
  }
};

class Hoofed : public Mammal {
public:
  Hoofed(const std::string& hoofedName) : Mammal(hoofedName) {}

  void sound() const override {
    std::cout << "Sound: Hoofed animal sound" << std::endl;
  }
};

class Bird : public Animal {
public:
  Bird(const std::string& birdName) : Animal(birdName) {}

  void display() const override {
    std::cout << "Bird: " << name << std::endl;
  }

  void sound() const override {
    std::cout << "Sound: Bird sound" << std::endl;
  }
};

int main() {
  Animal* animal1 = new Hoofed("Horse");
  Animal* animal2 = new Bird("Sparrow");

  animal1->display();
  animal1->sound();

  animal2->display();
  animal2->sound();

  delete animal1;
  delete animal2;

  return 0;
}