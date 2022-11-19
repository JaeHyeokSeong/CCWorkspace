#ifndef CALCULATE_POSTORDER_EXPRESSION_HPP
#define CALCULATE_POSTORDER_EXPRESSION_HPP
/*
후위 표기식의 계산 알고리즘 (stack 사용)
1. 피연산자면 스택에 push.
2. 연산자면 스택에서 2개 pop해서 연산한 후 결과값을 push 한다.
*/
#include <iostream>
#include <stack>
using std::string;
using std::stack;
double calculate_postorder(string expression){
    stack<double> operands;
    char c;
    for(int i = 0; i < expression.length(); i++){
        c = expression[i];
        // 피연산자인 경우 (숫자)
        if(c >= '0' && c <= '9'){
            operands.push(c - '0');
            continue;
        }
        // 연산자 기호인 경우
        // stack에서 2개 pop한후 계산해서 다시 push한다
        // 주의할점 : (아래쪽 피연산자) 연산자 (위쪽 피연산자) 순으로 계산하기
        if(operands.size() < 2){
            throw "invalid expression";
        }
        double down_operand, up_operand, result;
        up_operand = operands.top();
        operands.pop();
        down_operand = operands.top();
        operands.pop();
        if(c == '+'){
            result = down_operand + up_operand;
        } else if(c == '-'){
            result = down_operand - up_operand;
        } else if(c == '*'){
            result = down_operand * up_operand;
        } else if(c == '/'){
            result = down_operand / up_operand;
        }
        operands.push(result);
    }
    return operands.top();
}
#endif // CALCULATE_POSTORDER_EXPRESSION_HPP