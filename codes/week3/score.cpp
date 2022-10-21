#include <iostream>
#include "score.h"

double addAll(double scores[], int length){
    double sum = 0;
    for(int i = 0; i < length; i++) {
        sum += scores[i];
    }
    return sum;
}