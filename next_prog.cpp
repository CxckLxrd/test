#include <iostream>

struct Base {
    int x;
    Base() {
        std::cout << "Base()\n";
    }
    virtual void v_met() {
        std::cout << "Base call virtual\n";
    }
};

struct Derived : Base {
    int y;
    Derived() {
        std::cout << "Derived()\n";
    }
    void v_met () override {
        std::cout << "Derived call virtual\n";
    }
};

struct Subderived : Derived {
    int z;
    Subderived() {
        std::cout << "Subderived()\n";
    }

    void v_met () override {
        std::cout << "Subderived call virtual";
    }
};

void fun(Base &b) {
    std::cout << "hello from fun\n";
}

int main()
{
    Base b;
    Subderived s;
    Derived d;
    // fun(d);
    (dynamic_cast<Base &> (d)).v_met();
    // (dynamic_cast<Derived &> (s)).v_met();
}