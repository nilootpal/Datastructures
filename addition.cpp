#include <iostream>
using namespace std;

int binaryAddition(int a, int b){
    int ans = 0, prevCarry = 0;
    while(a && b){
        if((a%10 == 0) && (b%10 == 0)){
            ans = ans*10 + prevCarry;
            prevCarry = 0;
        }
        else if(((a%10 == 0) && (b%10 == 1)) || ((a%10 == 1) && (b%10 == 0))){
            ans = ans*10 + (prevCarry ? 0 : 1);
        }
        else{
            ans = ans*10 + prevCarry;
            prevCarry = 1;
        }
        a/=10;
        b/=10;
    }

    while(a){
        if(a%10 == 1){
            ans = ans*10 + (prevCarry ? 0 : 1);
        }
        else{
            ans = ans*10 + prevCarry;
            prevCarry = 0;
        }
        a/=10;
    }
    while(b){
        if(b%10 == 1){
            ans = ans*10 + (prevCarry ? 0 : 1);
        }
        else{
            ans = ans*10 + prevCarry;
            prevCarry = 0;
        }
        b/=10;
    }

    return ans;
}

int main(){
    int n = 1;

    int sample = 5 + (n ? 1: 5);
    cout<<sample;
    return 0;
}