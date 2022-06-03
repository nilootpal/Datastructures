#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

void reverseSentence(string s){
    stack<string> st;

    for (int i = 0; i < s.length(); i++){
        string word = "";
        while((s[i] != ' ') && (i<s.length())){
            word+=s[i];
            ++i;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
    
}

void insertAtBottom(stack<int> &st, int elem){
    if(st.empty()){
        st.push(elem);
        return;
    }

    int topelem = st.top();
    st.pop();
    insertAtBottom(st, elem);
    st.push(topelem);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int elem = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, elem);
}

int prefixEvaluation(string s){
    stack<int> st;

    for (int i = s.length()-1; i >= 0; i--){
        if((s[i] >= '0') && (s[i] <= '9')){
            st.push(s[i]-'0');
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch(s[i]){
                case '+': st.push(op1+op2); break;
                case '-': st.push(op1-op2); break;
                case '/': st.push(op1/op2); break;
                case '*': st.push(op1*op2); break;
                case '^': st.push(pow(op1, op2)); break;
            }
        }
    }

    return st.top();
}

int postfixEvaluation(string s){
    stack<int> st;

    for (int i = 0; i < s.length(); i++){
        if((s[i] >= '0') && (s[i] <= '9')){
            st.push(s[i]-'0');
        }
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch(s[i]){
                case '+': st.push(op1+op2); break;
                case '-': st.push(op1-op2); break;
                case '/': st.push(op1/op2); break;
                case '*': st.push(op1*op2); break;
                case '^': st.push(pow(op1, op2)); break;
            }
        }
    }

    return st.top();
}

string inToPost(string s){
    
}

int main(){
    // string s = "Hey, How are you doing?";
    // reverseSentence(s);

    // stack<int> st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);
    // st.push(6);

    // reverseStack(st);
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;

    cout<<prefixEvaluation("-+7*45+20")<<endl;
    cout<<postfixEvaluation("46+2/5*7+")<<endl;
    
    return 0;
}

