#ifndef ANIMAL_HPP
#define ANIMAL_HPP
class Animal{
    private:
        const char* name;
        int age;
    public:
        Animal(const char* name, int age){
            this->name = name;
            this->age = age;
        }
        const char* get_name() const{
            return name;
        }
        int get_age() const{
            return age;
        }
};
#endif // ANIMAL_HPP