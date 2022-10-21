#include <iostream>
using namespace std;

void checkAge(){
    int age = 0;
    cout << "나이를 입력해 주세요: ";
    cin >> age;
    if(age >= 19){
        cout << "당신은 영화를 볼 수 있습니다!\n";
    } else {
        cout << "당신은 영화를 볼 수 없습니다!\n";
    }
}
void checkScore(){
    double score = 0.0;
    cout << "당신의 점수를 입력하고 Enter를 누르세요\n";
    cin >> score;
    if(score >= 50){
        cout << "PASS";
    } else{
        cout << "FAIL";
    }
    cout << '\n';
}
void checkMark(){
    double score = 0.0;
    cout << "당신의 점수를 입력하고 Enter를 누르세요: ";
    cin >> score;
    if(score >= 85){
        cout << "HD";
    } else if(score >= 75){
        cout << 'D';
    } else if(score >= 60){
        cout << 'C';
    } else if(score >= 50){
        cout << 'P';
    } else {
        cout << 'F';
    }
    cout << '\n';
}
void checkCapital(){
    char c;
    cout << "키보드로 키 하나를 입력하세요: ";
    cin >> c;
    if(c >= 'a' && c <= 'z'){
        cout << "lower case";
    } else if(c >= 'A' && c <= 'Z') {
        cout << "upper case";
    } else {
        cout << "not a alphabet";
    }
    cout << '\n';
}
void merge(int left, int right, int numbers[], int temp_numbers[]){
    int mid = (left+right)/2;
    int i = left, j =  mid + 1;
    int k = left;
    while(i <= mid && j <= right){
        if(numbers[i] > numbers[j]){
            temp_numbers[k++] = numbers[j++];
        } else {
            temp_numbers[k++] = numbers[i++];
        }
    }
    if(j>right){
        while(k<=right){
            temp_numbers[k++] = numbers[i++];
        }
    }
    if(i>mid){
        while(k<=right){
            temp_numbers[k++] = numbers[j++];
        }
    }

    for(int i = left; i <= right; i++) {
        numbers[i] = temp_numbers[i];
    }
}
void divide(int left, int right, int numbers[], int temp_numbers[]){
    int mid = (left+right)/2;
    if(left < right){
        divide(left, mid, numbers, temp_numbers);
        divide(mid+1, right, numbers, temp_numbers);
        merge(left, right, numbers, temp_numbers);
    }
}
void findMaxMin(int size){
    int numbers[size];
    int temp_numbers[size];
    for(int i = 0; i < size; i++) {
        cout << "Enter a number and press Enter: ";
        cin >> numbers[i];
    }
    divide(0, size-1, numbers, temp_numbers);
    cout << "Max: " << numbers[size-1] << '\n';
    cout << "Min: " << numbers[0] << '\n';
}
int main(){
    // checkAge();
    // checkScore();
    // checkMark();
    // checkCapital();
    findMaxMin(3);

    return 0;
}