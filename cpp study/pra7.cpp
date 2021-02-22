////////////////////////////////////////////////////////////////
// Name:  김하연
// Student ID  :   20191580
// Program ID :   HW2 Infix - to - Postfix conversion & Evaluation
// Description:   infix 형으로 받은 식을 postfix형으로 변형하여 계산한다.
// Algorithm :  
//      1) infix형의 식이 담긴 데이터 파일을 읽어온다.
//      2) 숫자가 나오면 화면에 표시해준다.
//      3) '('를 만나면 ST에 push
//      4) ')'를 만나면 '('를 만날때까지 arr[]에 저장하며 pop 한뒤 arr 출력
//      5) 다른 연산자를 만나면  ST top element 와 priority 비교하여 top element가 작으면 push
//      6) 그렇지 않으면 pop 하고 출력
//      7) arr에 저장된 값을 읽으며 계산하여 RST에 저장
//      8) RST 출력
// Variables:   
//      isp - priority of top element
//      icp - 읽어온 값의 priority
//      arr - 후위표기 저장 배열
//      void postfix(char buffer[]) : infix 형의 식을 postfix 형으로 변경
//      int eval(char arr[]) : 변경한 식을 계산
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>


using namespace std;

typedef enum {lparen, rparen, times, divide, Plus, Minus, operand}precedence;
int isp[] = {0,3,2,2,1,1,0}; //top element의 priority
int icp[] = {4,3,2,2,1,1,0}; // 읽어 온 값의 priority
const int stackSize = 100;
char arr[100]={0}; // 후위표기 저장 배열
void postfix(char buffer[]);
int eval(char arr[]);
ifstream infile("hw2.txt"); //파일 읽어오기

class STACK{ //STACK class 생성
    private:
        int stack[stackSize];
        int top;
    public:
        STACK(){ //초기화
        top = -1;
        }

        int isEmpty(){ // 비어있을 때
            if(top == -1)
                return true;
            else return false;
        }

        void push(int val){ // push
            ++top;
            stack[top]=val;
        }

        int pop(){ // pop
            return(stack[top--]);
        }

        int getTop(){ // top element 반환
            return stack[top];
        }

        void displayStack(){ // stack 출력
            int sp;
            if (isEmpty()) cout << "Stack is empty!" << endl;
            else {
                sp = top;
                while (sp != -1) {
                    cout << stack[sp]; --sp;
                }
            }
        }
};
STACK ST; // 연산자 저장하는 stack
STACK RST; // 결과값을 계신하기 위한 식을 저장하는 stack
precedence getToken(char s){ // 연산자 -> token
    switch(s){
        case '(': 
            return lparen;
        case ')': 
            return rparen;
        case '*': 
            return times;
        case '/': 
            return divide;
        case '+': 
            return Plus;
        case '-': 
            return Minus;
        default:
            return operand;
	}
    
}
char getVal(precedence T){ //token -> 연산자
    switch (T) {
	case lparen: 
        return '(';
	case rparen: 
        return ')';
	case times: 
        return '*';
	case divide: 
        return '/';
    case Plus: 
        return '+';
	case Minus: 
        return '-';
    default:
        return '\0';
	}

}
precedence op;

int main(){
    
    char buffer[100];

    while(infile.getline(buffer,100)){
        
        cout << "1) Enter data (infix form) : " << buffer<<endl;
        cout << "2) Conversion (postfix form) : ";
        postfix(buffer);
        cout <<endl<< "3) Result : " ;
        eval(arr);
        cout <<endl;

    }
    return 0;

}
////////////////////////////////////////////////////////////////
// Description:   infix 형으로 받은 식을 postfix형으로 변형
// Algorithm :  
//      1) 숫자가 나오면 출력
//      2) '('를 만나면 ST에 push
//      3) ')'를 만나면 '('를 만날때까지 arr에 저장하며 pop 한뒤 arr 출력
//      4) 다른 연산자를 만나면  ST top element 와 priority 비교하여 top element가 작으면 push
//      5) 그렇지 않으면 pop 하고 출력
//      6) ST에 있는 값 출력
// Variables:   
//      arr[] - 후위표기 저장배열
//      buffer - 파일에서 읽어온 값
//      temp - arr 인덱스 값
/////////////////////////////////////////////////////////////////


void postfix(char buffer[]){
    int temp =0;
    
    for(int i = 0; i< strlen(buffer); i++){
        if(buffer[i]>='0' && buffer[i]<='9'){
            arr[temp++]=buffer[i];
            cout << buffer[i];
        }
        else if (buffer[i]=='('){
            ST.push(lparen);
        }
        else if (buffer[i]==')'){
            while((op=(precedence)ST.pop())!=lparen){
                arr[temp++]=getVal(op);
                cout << getVal(op);

            }
        }
        else {
            while(!ST.isEmpty()&&(icp[getToken(buffer[i])]<=isp[ST.getTop()])){
                
                op=(precedence)ST.pop();
                arr[temp++]=getVal(op);
                cout << getVal(op);
                
            }
            ST.push(getToken(buffer[i]));
        }
    }
    while(!ST.isEmpty()){
            op=(precedence)ST.pop();
            cout << getVal(op);
            arr[temp++]=getVal(op);
    }
}
////////////////////////////////////////////////////////////////
// Description:  postfix 식을 계산한다.
// Algorithm :  
//      1) for문에서 arr를 읽고 숫자가 있으면 RST에 push
//      2) 그렇지 않으면 op1 과 op2에  RST pop한 값 저장 후
//      3) 연산자 별로 op1,op2를 이용하여 게산
//      4) 계산 결과 RST에 push
//      5) for문이 끝나면 RST 출력
// Variables:   
//      op2 - RST top에 있는 숫자 pop
//      op1 - op2 저장 후 RST pop (infix 식에서 앞에 숫자)
/////////////////////////////////////////////////////////////////

int eval(char arr[]){
    
    int op1, op2;
    int top = -1;
    for(int i=0; i<strlen(arr);i++){
        if(arr[i]>='0' && arr[i]<='9'){
            RST.push(arr[i]-48);
        }
        else{
            op2 = RST.pop();
            op1 = RST.pop();
            switch (arr[i]) {
			
			case '*':
				RST.push(op1 * op2);
				break;
			case '/':
				RST.push(op1 / op2);
				break;
			case '+':
				RST.push(op1 + op2);
				break;
			case '-':
				RST.push(op1 - op2);
				break;
            }
        }
    }
    cout<< RST.pop();
    return 0;
    
}