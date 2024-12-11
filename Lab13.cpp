#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(const string& name, double price) : name(name), price(price) {}

    string getName() {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    double getPrice() {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    virtual double getFinalPrice() = 0;
    virtual ~Product() {}
};

class Discountable {
public:
    virtual double applyDiscount(double price) = 0;
    virtual ~Discountable() {}
};

class Book : public Product, public Discountable {
public:
    Book(const string& name, double price) : Product(name, price) {}

    double applyDiscount(double price) override {
        return price * 0.9;
    }

    double getFinalPrice() override {
        return applyDiscount(price);
    }
};

class Pen : public Product, public Discountable {
public:
    Pen(const string& name, double price) : Product(name, price) {}

    double applyDiscount(double price) override {
        return price > 5 ? price - 5 : price;
    }

    double getFinalPrice() override {
        return applyDiscount(price);
    }
};

int main() {
    Book book1("Book 'Kolobok'", 152);
    Book book2("Book 'C++, become senior in 3 days of coding'", 148);
    Pen pen1("Pen blue", 52);
    Pen pen2("Pen black", 5.2);

    cout << "Product: " << book1.getName() << ", Base Price: " << book1.getPrice() << ", Final Price: " << book1.getFinalPrice() << endl;
    cout << "Product: " << book2.getName() << ", Base Price: " << book2.getPrice() << ", Final Price: " << book2.getFinalPrice() << endl;
    cout << "Product: " << pen1.getName() << ", Base Price: " << pen1.getPrice() << ", Final Price: " << pen1.getFinalPrice() << endl;
    cout << "Product: " << pen2.getName() << ", Base Price: " << pen2.getPrice() << ", Final Price: " << pen2.getFinalPrice() << endl;

}
