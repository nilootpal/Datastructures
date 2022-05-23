#include <iostream>
#include <string>
using namespace std;

int BinarytoDecimal(int n){
    int ans = 0, temp = 1;
    while(n != 0){
        ans += temp*(n%10);
        temp *= 2;
        n /= 10;
    }
    return ans;
}

int OctaltoDecimal(int n){
    int ans = 0, temp = 1;
    while(n != 0){
        ans += temp*(n%10);
        temp *= 8;
        n /= 10;
    }
    return ans;
}

int HexadecimaltoDecimal( string n ){
    int ans = 0, temp = 1;
    int s = n.size();
    for( int i = s-1; i>=0; i-- ){
        if((n[i] >= '0') && (n[i] <= '9')){
            ans += (n[i]-'0')*temp;
        }
        else if((n[i] >= 'A') && (n[i] <= 'B')){
            ans += (n[i] - 'A' + 10) *temp;
        }
        temp*=16;
    }

    return ans;
}

int DecimaltoBinary(int n){
    int ans = 0, temp = 1;

    while(temp <= n){
        temp*=2;
    }
    temp/=2;

    while(temp > 0){
        int lastD = n/temp;
        n -= lastD*temp;
        temp/=2;
        ans = ans*10 + lastD;
    }

    return ans;
}

int DecimaltoOctal(int n){
    int ans = 0, temp = 1;

    while(temp <= n){
        temp*=8;
    }
    temp/=8;

    while(temp > 0){
        int lastD = n/temp;
        n -= lastD*temp;
        temp/=8;
        ans = ans*10 + lastD;
    }

    return ans;
}

string DecimaltoHexadecimal(int n){
    string ans = "";
    int temp = 1;
    while(temp <= n){
        temp*=16;
    }
    temp/=16;

    while(temp>0){
        int lastDig = n/temp;
        n -= lastDig*temp;
        temp/=16;

        if(lastDig <= 9){
            ans = ans + to_string(lastDig);
        }
        else{
            char c = 'A' + lastDig - 10;
            ans.push_back(c);
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    // string s;
    // cin>>s;

    cout<<DecimaltoHexadecimal(n)<<endl;
    return 0;
}