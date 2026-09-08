#include <iostream>
using namespace std;
#include <cctype>
class stack {
private:
    int top = -1;
    char* s;
    int size;

public:
    stack() {
        cout << "Enter size: ";
        cin >> size;

        s = new char[size];

        cout << "Made a stack of size " << size << endl;
    }
    stack(int len) {
        size=len;
        s = new char[len];
        cout << "Made a stack of size " << size << endl;
    }
    bool isFull() {
        if (top == size - 1) {
            return 1;
        }
        return 0;
    }
    bool isempty() {
        if (top == -1) {
            return 1;
        }
        return 0;
    }
    void disp() {
        if (isempty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        int temp = top;
        cout << "Stack elements: ";
        while (temp >= 0) {
            cout << s[temp] << " ";
            temp--;
        }
        cout << endl;
    }
    void push(char e) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push '" << e << "'" << endl;
            return;
        }

        top++;
        s[top] = e;
        cout << "Pushed '" << e << "' into stack." << endl;
    }
    char pop() {
        if (isempty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return '\0';
        }

        char temp = s[top];
        cout << "Removed '" << s[top] << "' from stack." << endl;
        top--;

        return temp;
    }
    ~stack() {
        delete[] s;
    }
    char peek(){
        return s[top];;
    }
   
};
int priority(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '+' || c == '-')
        return 1;

    return 0;
}
 void if_to_pf(){
        
        string infix;
        string postfix="";
        cout<<"write an infix expression";
        cin>>infix;
        stack s=stack(infix.length());
        for(char c : infix){
            //alphanum
            if(isalnum(c)){
                postfix+=c;
            }
            //opening brakcet
            else if(c=='('){
                s.push(c);
            }
            //closing bracket
            else if(c==')'){
                while(s.peek()!='('){
                    postfix+=s.pop();
                    
                }
                 s.pop();
            }
            //operator
            else{
                while(!s.isempty()&&s.peek()!='('&& priority(s.peek()) >= priority(c)){
                    postfix += s.peek();
                    s.pop();}
                    s.push(c);
            }
     
        }
               while(!s.isempty()){
    postfix += s.pop();
}
            
            for(char i: postfix ){
                cout<<i<<" ";
            }
    }
    
int main() {
    if_to_pf();

    return 0;
}

