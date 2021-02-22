#include <iostream>
#include <cstring>
#define MAX_SIZE 999

using namespace std;

bool check(char* exp);
bool match(char a,char b);

class Stack {
public:
   char *stack;
   int top;
   int size;

   Stack(int value);
   int IsFull();
   int IsEmpty();
   void push(char str);
   char pop();
};

Stack::Stack(int value) {
   top = -1;
   size = value;
   stack = new char[size];
}

int Stack::IsFull() {
   if (top == size - 1) {
      return 1;
   }
   else {
      return 0;
   }
}

int Stack::IsEmpty() {
   if (top == -1) {
      return 1;
   }
   else {
      return 0;
   }
}

void Stack::push(char str) {
   if (IsFull())
      return;
   else
      stack[++top] = str;
}

char Stack::pop() {
   if (IsEmpty())
      return -1;
   else
      return stack[top--];
}

bool check(char* exp) {
    Stack stack(MAX_SIZE);
    for(int i = 0; i < strlen(exp); i++){
        if (exp[i]=='(' || exp[i] == '{' || exp[i] == '['){
            stack.push(exp[i]);
        }
        if (exp[i]==')' || exp[i] == '}' || exp[i] == ']'){
            if(stack.IsEmpty()){
                return false;
            }
            else{
                char temp = stack.pop();
                if (!match(temp, exp[i])){
                    return false;
                }
            }
        }
    }

    if(stack.IsEmpty()){
        return true;
    }
    else{
        return false;
    }
}

bool match(char a, char b) {
    switch(a)
    {
    case '(':
        if (b == ')') return true;
        else return false;
        break;
    case '{':
        if (b == '}') return true;
        else return false;
        break;
    case '[':
        if(b == ']') return true;
        else return false;
        break;
    }
    
    return -1;
}

int main() {
   int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases+1; i++){
        char buffer[101];
        cin.getline(buffer, 101);
        bool validity = check(buffer);
        if(i>0){
        if(validity){
           cout << 1 << endl;
       }

       else{
           cout << 0 << endl;
       }
        }

    }
    return -1;
}