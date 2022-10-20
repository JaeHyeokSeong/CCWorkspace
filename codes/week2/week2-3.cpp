#include <iostream>
using namespace std;

/*
한개발 57.5
엄청군 125.6
갈비양 35.7

엄청군 125.6
한개발 57.5
갈비양 35.7
*/

struct Person{
    string name;
    double weight;
};

void printPersons(Person persons[], int length){
    for(int i = 0; i < length; i++) {
        cout << persons[i].name << " " << persons[i].weight << "\n"; 
    }
}
void swap(Person* p1, Person* p2){
    Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main(){
    // [1] Input
    const int SIZE = 3;
    Person persons[SIZE] = {{"한개발", 57.5}, {"엄청군", 125.6}, {"갈비양", 35.7}};

    // [2] Process
    for(int i = 0; i < SIZE-1; i++){
        for(int j = i+1; j < SIZE; j++){
            if(persons[i].weight > persons[j].weight){
                swap(&persons[i], &persons[j]);
            }
        }
    }

    // [3] Ouput
    printPersons(persons, SIZE);
    return 0;
}