#include <iostream>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::string;

double totalSum(double* scores, int length){
    double total = 0;
    for(int i = 0; i < length; i++) {
        total += scores[i];  
    }
    return total;
}
double scoreCalculator(const char* txt, int count, int weight, double maxScore){
    double* scores = new double[count];
    cout << txt << '\n';
    for(int i = 0; i < count; i++){
        cout << "Enter score: ";
        cin >> scores[i];        
    }
    double sum = totalSum(scores, count);   
    delete []scores;
    return sum * weight / maxScore;
}
void result(double score){
    string result;
    if(score >= 85)
        result = "HD";
    else if(score >= 75)
        result = "D";
    else if(score >= 65)
        result = "C";
    else if(score >= 50)
        result = "P";
    else    
        result = "Fail";
    if(result == "Fail"){
        cout << "\n\033[1;31mResult: " << result << " [score: " << score << "]\033[0m\n\n"; // print red text
        return;    
    }
    cout << "\n\033[1;32mResult: " << result << " [score: " << score << "]\033[0m\n\n"; // print green text
}
void calc_softwareArchitecture(){
    double saScores = 0;
    cout << "\nSoftware Architecture Score\n";
    saScores = scoreCalculator("\nenter assignment1 scores", 6, 20, 60);
    saScores += scoreCalculator("\nenter assignment2 scores", 2, 15, 20);
    saScores += scoreCalculator("\nenter assignment3 score", 1, 45, 45);
    saScores += scoreCalculator("\nenter assignment 4 scores", 4, 20, 20);
    result(saScores);
}
void calc_mathematics(){
    double mathScores = 0;
    cout << "\nMathematics Score\n";
    mathScores = scoreCalculator("\nenter skill test scores", 10, 50, 50);
    mathScores += scoreCalculator("\nenter final exam score", 1, 50, 80);
    result(mathScores);
}
void calc_applicationDevelopmentWithDotNET(){
    double applicationScores = 0;
    cout << "\nApplication Development with .NET score\n";
    applicationScores = scoreCalculator("\nenter quizzes scores", 5, 30, 30);
    applicationScores += scoreCalculator("\nenter assignment-1 score", 1, 35, 35);
    applicationScores += scoreCalculator("\nenter assignment-2 score", 1, 35, 35);
    result(applicationScores);
}
void calc_fundamentalsOfInteractionDesign(){
    double interactionDesignScores = 0;
    cout << "\nFundamentals of Interaction Design score\n";
    interactionDesignScores = scoreCalculator("\nenter assessment 1 score", 1, 20, 20);
    interactionDesignScores += scoreCalculator("\nenter assessment 2 score", 1, 35, 35);
    interactionDesignScores += scoreCalculator("\nenter assessment 3 score\n- persona\n- paper prototype\n- design in action video\n", 3, 45, 45);
    result(interactionDesignScores);
}
int main(){
    system("clear"); // clear the consoles
    int input = 0;
    const char* menuText = "1 (Software Architecture)\n2 (Mathematics)\n3 (Application development with .NET)\n4 (Fundamentals of Interaction Design)\n5 (Exit)\n";
    cout << menuText << "Enter 1 to 5 => ";
    cin >> input;
    do{
        if(input == 1)
            calc_softwareArchitecture();
        else if(input == 2)
            calc_mathematics();
        else if(input == 3)
            calc_applicationDevelopmentWithDotNET();
        else if(input == 4)
            calc_fundamentalsOfInteractionDesign();
        else
            cout << "\a\n\033[1;31m[Warning] invalid input\033[0m\n\n"; // invalid input
        cout << menuText << "Enter 1 to 5 => ";
        cin >> input;
    } while(input != 5); 

    cout << "\nThe program is finished\n";
    return 0;
}