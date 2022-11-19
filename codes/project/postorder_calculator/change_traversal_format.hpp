#ifndef CHANGE_TRAVERSAL_FORMAT
#define CHANGE_TRAVERSAL_FORMAT
#include <iostream>
#include <stack>
using std::string;
using std::stack;

/*
중위 표기식을 후위 표기식으로 변환 알고리즘

1) 피연산자는 무조건 출력
2) 연산자인 경우
- stack의 top보다 우선순위가 크면 push
- stack의 top보다 우선순위가 작거나 같으면 pop 한후 2) 반복
3) '(' 는 push
4) ')' 이 나타나면 '(' 이 나올때까지 pop 후 출력
5) 피연산자가 더이상 없으면 stack에 있는 값들 출력 pop 반복
*/

/*
* / 은 우선순위를 가장 높게 준다 - 2
+ - 은 우선순위를 중간으로 준다 - 1
나머지 연산자, 즉 여기에서는 ( 인데 
이는 가장 낮은 우선순위인 0을 준다.
*/
int priority(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    return 0;
}
string change_traversal_to_postorder(string expression){
    stack<char> operators;
    string postorder_expression = "";
    char c;
    for(int i = 0; i < expression.length(); i++){
        // 문자열에서 한글자씩 가져오는 과정
        c = expression[i];
        if(c >= '0' && c <= '9'){
            postorder_expression += c;
            continue;
        }
        /*
        만약 stack에 아직 연산자가 하나도 없으면 push 해줘야 한다
        또한 만약 char의 값이 '(' 일때는 stack에 push 해야한다.
        */
        if(operators.empty() || c == '('){
            operators.push(c);
            continue;
        }
        // 연산자가 ')' 인 경우 '(' 이 나오기 전까지 출력 pop을 진행
        // 마지막으로 '('도 pop 해줘야 한다
        if(c == ')'){
            char oper = ' ';
            do{
                oper = operators.top();
                if(oper != '('){
                    postorder_expression += oper;
                    operators.pop();
                } 
                else if(oper == '('){
                    operators.pop();
                }
            }while(oper != '(');
            continue;
        }
        // 현재 연산자 우선순위 계산하기
        int current_operator_priority = priority(c);
        // stack 안에 들어있는 연산자 우선순위 계산하기
        int privous_operator_priority = priority(operators.top());
        // top 보다 우선순위가 큰 경우
        if(privous_operator_priority < current_operator_priority){
            operators.push(c);
            continue;
        }
        /*
        top 보다 우선순위 작거나 같으면 stack에서 pop
        한 후 2) 과정을 반복해줘야 한다.
        */
        while(privous_operator_priority >= current_operator_priority){
            postorder_expression += operators.top();
            operators.pop();
            privous_operator_priority = priority(operators.top());
            if(privous_operator_priority < current_operator_priority){
                operators.push(c);
            }
        }
        continue;


    }

    // stack 에 남아있는 연산자들을 출력해준다
    while(!operators.empty()){
        postorder_expression += operators.top();
        operators.pop();
    }
    return postorder_expression;
}
#endif // CHANGE_TRAVERSAL_FORMAT