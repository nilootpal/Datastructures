#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
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

int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if((c == '/') || (c == '*')){
        return 2;
    }
    else if((c == '+') || c == '-'){
        return 1;
    }
    else{
        return -1; 
    }
}

string infixToPostfix( string s ){
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++){
        if(((s[i] >= 'a') && (s[i] <= 'z')) || (s[i] >= 'A') && (s[i] <= 'B')){
            res += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && (st.top() != '(')){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && (prec(s[i]) < prec(st.top()))){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    return res;  
}

string infixToPrefix( string s ){
    reverse(s.begin(), s.end());
    stack<char> st;
    string res = "";

    for (int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            res += ')';
        }
        else if(s[i] == ')'){
            res += '(';
        }
        else{
            res += s[i];
        }
    }    
    res = infixToPostfix(res);
    reverse(res.begin(), res.end());
    return res;
}

bool balanceBraces( string s ){
    stack<char> st;
    bool ans = true;

    for (int i = 0; i < s.length(); i++){
        if((s[i] == '{') || (s[i] == '[') || (s[i] == '(')){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.empty() && (st.top() == '(')){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == ']'){
            if(!st.empty() && (st.top() == '[')){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == '}'){
            if(!st.empty() && (st.top() == '{')){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }

    if(!st.empty()){
        return false;
    }

    return ans;
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

    // cout<<prefixEvaluation("-+7*45+20")<<endl;
    // cout<<postfixEvaluation("46+2/5*7+")<<endl;
    // cout<<infixToPrefix("(a-b/c)*(a/k-l)")<<endl;
    cout<<balanceBraces("{[()]")<<endl;
    
    return 0;
}

