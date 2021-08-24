#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
//算数表达式计算示意版，仅支持全部运算带括号，操作数为个位数
double evaluate(string s){
    if(s.size() <= 0){
        cout << "wrong input" << endl;
        return -1;
    }
    //操作数
    stack<double> nums;
    //运算符
    stack<char> ops;
    double v;
    for(char c : s){
        //若c为数字
        if(c <= 0x39 && c >= 0x30)
            nums.push(c - 0x30);    //将c的数值压进操作数栈
        //若c为运算符
        if('+' == c || '-' == c || '*' == c || '/' == c)
            ops.push(c);            //将c压入运算符栈
        //若c为右括号
        if(')' == c){
            //取出两个操作数和一个运算符，将其计算后压入操作数栈
            v = nums.top();
            nums.pop();
            switch (ops.top()){
                case '+':
                    v += nums.top();
                    break;
                case '-':
                    v = nums.top() - v;
                    break;
                case '*':
                    v *= nums.top();
                    break;
                case '/':
                    v = nums.top() / v;
                    break;
                default:
                    cout << "ops stack error" << endl;
                    break;
            }  
            ops.pop();
            nums.pop();
            nums.push(v);
        }
    }
    return v;
}

int main(){
    string s = "((1+(2*(3+4)/(1*2)))-((5-6)/(2-1)))";
    cout << evaluate(s) << endl;
}