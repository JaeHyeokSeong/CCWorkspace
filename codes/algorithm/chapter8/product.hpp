#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <iostream>
using std::string;

class Product{
    private:
        string name;
        double price;
    public:
        Product(const string name, const double price){
            this->name = name;
            this->price = price;
        }
        string getName() const{
            return name;
        }
        double getPrice() const{
            return price;
        }
        void setPrice(const double price){
            this->price = price;
        }
        void setName(const char* name){
            this->name = name;
        }
        bool operator <(const Product& product) const{
            return this->price < product.getPrice();
        }
};
#endif // PRODUCT_HPP