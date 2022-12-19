// Program 3 - auto
#include <iostream>
#include <vector>

class Product{
    private:
        int product_id;
        const char* product_name;
    public:
        Product(const int product_id, const char* product_name){
            this->product_id = product_id;
            this->product_name = product_name;
        }
        int get_product_id() const{
            return product_id;
        }
        const char* get_product_name() const{
            return product_name;
        }
};
int main(){
    std::vector<Product> products;
    products.push_back(Product(1, "phone"));
    products.push_back(Product(2, "laptop"));
    // for(int i = 0; i < products.size(); i++){
    //     std::cout << "id: " << products[i].get_product_id() 
    //     << ", name: " << products[i].get_product_name() << '\n';
    // }
    // for(std::vector<Product>::iterator it = products.begin(); it != products.end(); it++){
    //     std::cout << it->get_product_id() << ", " << it->get_product_name() << '\n';
    // }
    // for(auto it = products.begin(); it != products.end(); it++){
    //     std::cout << it->get_product_id() << ' ' << it->get_product_name() << '\n';
    // }
    for(std::vector<Product>::iterator it = products.begin(); it != products.end(); it++){
        std::cout << it->get_product_id() << (*it).get_product_name() << '\n';
    }
    return 0;
}