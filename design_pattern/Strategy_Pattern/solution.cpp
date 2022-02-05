#include <iostream>

class IFlyBehavior
{
    public:
    virtual void fly() = 0;
};

class BaseFly: public IFlyBehavior
{
    public:
    void fly()
    {
        std::cout << "Duck:Fly\n";
    }
};

class CityFly: public IFlyBehavior
{
    public:
    void fly()
    {
        std::cout << "CityDuck: Fly\n";
    }
};

class NoFly: public IFlyBehavior
{
    public:
    void fly()
    {
        std::cout << "Duck: NoFly\n";
    }
};

class IDisplayBehavior
{
    public:
    virtual void display() = 0;
};

class BaseDisplay: public IDisplayBehavior
{
    public:
    void display()
    {
        std::cout << "Duck:Display\n";
    }
};

class WildDuckDisplay: public IDisplayBehavior
{
    public:
    void display()
    {
        std::cout << "Wild Duck: Display\n"; 
    }
};

class CityDuckDisplay: public IDisplayBehavior
{
    public:
    void display()
    {
        std::cout << "City Duck: Display\n"; 
    }
};

class ToyDuckDisplay: public IDisplayBehavior
{
    public:
    void display()
    {
        std::cout << "Toy Duck: Display\n"; 
    }
};

class IQuackBehavior
{
    public:
    virtual void quack() = 0;
};

class BaseQuack: public IQuackBehavior
{
    public:
    void quack()
    {
        std::cout << "Duck:Quack\n";
    }
};

class WildDuckQuack: public IQuackBehavior
{
    public:
    void quack()
    {
        std::cout << "Wild Duck: Quack\n"; 
    }
};

class CityDuckQuack: public IQuackBehavior
{
    public:
    void quack()
    {
        std::cout << "City Duck: Quack\n"; 
    }
};

class ToyDuckQuack: public IQuackBehavior
{
    public:
    void quack()
    {
        std::cout << "Toy Duck: Quack\n"; 
    }
};

// base class - version 0
// which contain 3
class Duck
{
    public:
        IFlyBehavior *pFly;
        IDisplayBehavior *pDisplay;
        IQuackBehavior *pQuack;
    
        virtual void get_display()
        {
            pDisplay->display();
        }
        virtual void get_quack()
        {
            pQuack->quack();
        }
        virtual void get_fly()
        {
            pFly->fly();
        }
};

// C=Duck 
class WildDuck: public Duck
{
    public:
        WildDuck(IFlyBehavior *fly, IDisplayBehavior *disp, IQuackBehavior *quack)
        {
            pFly = fly;
            pDisplay = disp;
            pQuack = quack;
        }

        // other wild duck specific methods if any
};

class CityDuck: public Duck
{
    public:
        CityDuck(IFlyBehavior *fly, IDisplayBehavior *disp, IQuackBehavior *quack)
        {
            pFly = fly;
            pDisplay = disp;
            pQuack = quack;
        }

        // other city duck specific methods if any
};

// ToyDuck cannot fly as normal duck. So we need specific no-fly behavior for the toy duck class
class ToyDuck: public Duck
{
    public:
        ToyDuck(IFlyBehavior *fly, IDisplayBehavior *disp, IQuackBehavior *quack)
        {
            pFly = fly;
            pDisplay = disp;
            pQuack = quack;
        }

        // other toy duck specific methods if any
};

int main()
{
    IFlyBehavior *baseFly = new BaseFly();
    IDisplayBehavior *baseDisplay = new BaseDisplay();
    IQuackBehavior *baseQuack = new BaseQuack();
    IDisplayBehavior *wildDisplay = new WildDuckDisplay();

    // creating wild duck
    WildDuck wildDuck(baseFly, wildDisplay, baseQuack);
    wildDuck.get_display();
    wildDuck.get_fly();
    wildDuck.get_quack();

    // creating CityDuck
    IDisplayBehavior *cityDisplay = new CityDuckDisplay();
    IQuackBehavior *cityQuack = new CityDuckQuack();
    CityDuck cityDuck(baseFly, cityDisplay, cityQuack);
    cityDuck.get_display();
    cityDuck.get_fly();
    cityDuck.get_quack();

    // creating ToyDuck
    IDisplayBehavior *toyDisplay = new ToyDuckDisplay();
    IQuackBehavior *toyQuack = new ToyDuckQuack();
    IFlyBehavior *toyFly = new NoFly();
    ToyDuck toyDuck(toyFly, toyDisplay, toyQuack);
    toyDuck.get_display();
    toyDuck.get_fly();
    toyDuck.get_quack();

    return 0;
}