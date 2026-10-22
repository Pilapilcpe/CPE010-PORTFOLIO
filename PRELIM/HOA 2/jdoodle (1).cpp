#include <iostream>
#include <string>

class fruit {
private:
    std::string name;
    double price;
    int qty;

public:
    fruit(std::string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        qty = q;
    }

    ~fruit() {}

    fruit(const fruit& f) {
        name = f.name;
        price = f.price;
        qty = f.qty;
    }

    fruit& operator=(const fruit& f) {
        if (this != &f) {
            name = f.name;
            price = f.price;
            qty = f.qty;
        }
        return *this;
    }

    double calculatesum() {
        return price * qty;
    }

    void display() {
        std::cout << "Fruit: " << name
                  << " Price: PHP " << price
                  << " Quantity: " << qty
                  << " Total: PHP " << calculatesum()
                  << std::endl;
    }
};

class veg {
private:
    std::string name;
    double price;
    int qty;

public:
    veg(std::string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        qty = q;
    }

    ~veg() {}

    veg(const veg& v) {
        name = v.name;
        price = v.price;
        qty = v.qty;
    }

    veg& operator=(const veg& v) {
        if (this != &v) {
            name = v.name;
            price = v.price;
            qty = v.qty;
        }
        return *this;
    }

    double calculatesum() {
        return price * qty;
    }

    void display() {
        std::cout << "Vegetable: " << name
                  << " Price: PHP " << price
                  << " Quantity: " << qty
                  << " Total: PHP " << calculatesum()
                  << std::endl;
    }
};

int main() {

    fruit* app = new fruit("Apple", 10, 7);
    fruit* ban = new fruit("Banana", 10, 8);

    veg* bro = new veg("Broccoli", 60, 12);
    veg* let = new veg("Lettuce", 50, 10);

    fruit* fruits[] = {app, ban};
    veg* vegs[] = {bro, let};

    for (int i = 0; i < 2; i++) {
        fruits[i]->display();
    }

    for (int i = 0; i < 2; i++) {
        vegs[i]->display();
    }

    delete app;
    delete ban;
    delete bro;
    delete let;

    return 0;
}