#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

// global variable
string studentNumber;

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
        string input = "";
        double converted_inputResult;
        char* end;
        cout << "Enter score: ";
        cin >> input;
        /*
        strtod 에서 성공적으로 변환을 하면 *end 에 널 값이 들어간다
        이때 널 값은 십진수로 보면 0 이랑 같다
        */
        converted_inputResult = strtod(input.c_str(), &end);
        if((*end!=0) && ((int)*end < 48 || (int)*end>57)){
            cout << "\a\033[1;31minvalid input\033[0m\n" << endl;
            i--;
            continue;
        }
        scores[i] = converted_inputResult;
    }
    double sum = totalSum(scores, count);   
    delete []scores;
    return sum * weight / maxScore;
}
string result(double score){
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
        return result;    
    }
    cout << "\n\033[1;32mResult: " << result << " [score: " << score << "]\033[0m\n\n"; // print green text

    return result;
}
void save_scoreResult(string fileName ,string header, string body){
    /*
    계산 되어진 결과를 사용자가 입력한 파일의 이름에다가 저장한다
    */   
    
    // 파일이 사전에 존재하면 내용을 추가하도록 함
    std::ofstream st(fileName, std::ios_base::app);
    // 파일에 내용 저장
    // header 저장
    st << header << endl;
    // body 저장
    st << body << endl;
    st << endl;
    // 저장 종료
    cout << "saved" << endl << endl;
}
void ask_toSave(string header, string body){
    string input;
    bool status = true;
    do{
        cout << "do you want to save the result? (y/n)" << endl;
        cin >> input;
        if(input.length() > 1 || (input[0] != 'y' && input[0] != 'n')){
            cout << "\a\n\033[1;31minvalid input\033[0m" << endl;
        } else{
            status = false;
        }
    }while(status);
    
    if(input[0] == 'y'){
        string fileName = studentNumber + "_score.txt";
        save_scoreResult(fileName, header, body);
    }
}
void calc_softwareArchitecture(){
    double saScores = 0;
    cout << "\nSoftware Architecture Score\n";
    saScores = scoreCalculator("\nenter assignment1 scores\n- quiz1\n- quiz2\n- quiz3\n- quiz4\n- quiz5\n- quiz6", 6, 20, 60);
    saScores += scoreCalculator("\nenter assignment2 scores\n- two elective topics quizzes", 2, 15, 20);
    saScores += scoreCalculator("\nenter assignment3 score\n- team project", 1, 45, 45);
    saScores += scoreCalculator("\nenter assignment 4 scores\n- peer review1\n- peer review2\n- peer review3\n- peer review4", 4, 20, 20);
    string score = result(saScores);
    string body = "result: " + score;
    ask_toSave("Subject: Software Architect", body);
}
void calc_mathematics(){
    double mathScores = 0;
    cout << "\nMathematics Score\n";
    mathScores = scoreCalculator("\nenter skill test scores\n- skill test1\n- skill test2\n- skill test3\n- skill test4\n- skill test5\n- skill test6\n- skill test7\n- skill test8\n- skill test9\n- skill test10", 10, 50, 50);
    mathScores += scoreCalculator("\nenter final exam score\n- final exam", 1, 50, 80);
    string score = result(mathScores);
    string body = "result: " + score;
    ask_toSave("Subject: Mathematics 1", body);
}
void calc_applicationDevelopmentWithDotNET(){
    double applicationScores = 0;
    cout << "\nApplication Development with .NET score\n";
    applicationScores = scoreCalculator("\nenter quizzes scores\n- quiz1\n- quiz2\n- quiz3\n- quiz4\n- quiz5", 5, 30, 30);
    applicationScores += scoreCalculator("\nenter assignment-1 score", 1, 35, 35);
    applicationScores += scoreCalculator("\nenter assignment-2 score", 1, 35, 35);
    string score = result(applicationScores);
    string body = "result: " + score;
    ask_toSave("Application Development with .NET", body);
}
void calc_fundamentalsOfInteractionDesign(){
    double interactionDesignScores = 0;
    cout << "\nFundamentals of Interaction Design score\n";
    interactionDesignScores = scoreCalculator("\nenter assessment 1 score\n- journal entry4", 1, 20, 20);
    interactionDesignScores += scoreCalculator("\nenter assessment 2 score\n- examination", 1, 35, 35);
    interactionDesignScores += scoreCalculator("\nenter assessment 3 score\n- persona\n- paper prototype\n- design in action video\n", 3, 45, 45);
    string score = result(interactionDesignScores);
    string body = "result: " + score;
    ask_toSave("Fundamentals of Interaction Design", body);
}
int main(){
    system("clear"); // clear the consoles
    cout << "Enter your student number please: ";
    cin >> studentNumber;
    system("clear");
    cout << "Student Number: " << studentNumber << endl << endl;
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
        else if(input == 5)
            break;
        else
            cout << "\a\n\033[1;31m[Warning] invalid input\033[0m\n\n"; // invalid input
        cout << menuText << "Enter 1 to 5 => ";
        cin >> input;
    } while(input != 5); 

    cout << "\nThe program is finished\n";
    return 0;
}