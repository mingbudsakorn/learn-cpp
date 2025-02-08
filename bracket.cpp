#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string input;
    stack<char> stack;
    cin >> input;
    bool isBalanced = true;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(' || input[i] == '{' || input[i] == '(')
        {
            stack.push(input[i]); 
        }
        else{
            if(stack.empty()){
                isBalanced = false;
                break;
            }
            if(stack.top() == '(') {
                if(input[i] != ')'){
                    isBalanced = false;
                    break;
                }
            }
            if(stack.top() == '{') {
                if(input[i] != '}'){
                    isBalanced = false;
                    break;
                }
            }
            if(stack.top() == '[') {
                if(input[i] != ']'){
                    isBalanced = false;
                    break;
                }
            }
            stack.pop();
        }

    }
    if (!stack.empty()){
        isBalanced=false;
    }
    if(isBalanced){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
}