#include <iostream>

// base class - version 0
// which contain 3
class Duck
{
    public:
        virtual void display()
        {
            std::cout << "Duck:display\n";
        }
        virtual void quack()
        {
            std::cout << "Duck:quack\n";
        }
        virtual void fly()
        {
            std::cout << "Duck:fly\n";
        }
};

// C=Duck 

class WildDuck: public Duck
{
    public:
        void display()
        {
            std::cout << "WildDuck:display\n";
        }
};

class CityDuck: public Duck
{
    public:
        void display()
        {
            std::cout << "CityDuck:display\n";
        }
        void quack()
        {
            std::cout << "CityDuck:quack\n";
        }
};

// ToyDuck cannot fly as normal duck. So we need specific no-fly behavior for the toy duck class
class ToyDuck: public Duck
{
    public:
        void display()
        {
            std::cout << "ToyDuck:display\n";
        }
        void quack()
        {
            std::cout << "ToyDuck:quack\n";
        }
        void fly()
        {
            std::cout << "ToyDuck:can not fly\n";
        }
};

// class MixDuck uses the display behavior of the WildDuck and quack behavior of the CityDuck
// So in this case we need to reimplement the code which is already implemented in the other deried classes and cannot reuse the same code
class MixDuck: public Duck
{
    public:
        void display()
        {
            std::cout << "WildDuck:display\n";
        }
        void quack()
        {
            std::cout << "CityDuck:quack\n";
        }
};

// class MountainDuck has again mix-match behavior with various other Duck classes and we need to reimplement the same behavior again
class MountainDuck: public Duck
{
    public:
        void display()
        {
            std::cout << "MixDuck:display\n";
        }
        void quack()
        {
            std::cout << "ToyDuck:quack\n";
        }
};

int main()
{
    WildDuck wd;
    wd.display();
    wd.quack();
    return 0;
}