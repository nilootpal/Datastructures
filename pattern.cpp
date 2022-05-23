#include <iostream>
using namespace std;

int main(){
    //zig-zag pattern
    for( int i = 1; i <= 3; ++i ){
        for( int j = 1; j <= 9; ++j ){
            if( ((i + j)%4 == 0) || (i == 2) && ((j%4) == 0) ){
                cout<<" * ";
            }
            else{
                cout<<"   ";
            }

        }
        cout<<endl;
    }

    //palindromic pattern
    // for(int i = 1; i <= 5; ++i){
    //     for(int j = 1; j <= 5-i; ++j){
    //         cout<<"   ";
    //     }
    //     int k = i;
    //     for(int j = 1; j <= i; ++j){
    //         cout<<k--<<"  ";
    //     }
    //     k = 2;
    //     for(int j = 1; j < i; ++j){
    //         cout<<k++<<"  ";
    //     }
    //     cout<<endl;
    // }

    //number pattern
    // for(int i = 1; i <= 5; ++i){
    //     for(int j = 1; j <= 5-i; ++j){
    //         cout<<"  ";
    //     }
    //     for(int j = 1; j <= i; ++j){
    //         cout<<"  "<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    //rhombus pattern
    // for(int i = 1; i <= 5; ++i){
    //     for(int j = 1; j <= 5-i; ++j){
    //         cout<<" ";
    //     }
    //     for(int j = 1; j <= 5; ++j){
    //         cout<<" * ";
    //     }
    //     cout<<endl;
    // }

    //01 pattern
    // for(int i = 1; i <= 5; ++i){
    //     for(int j = 1; j <= i; ++j){
    //         if((i+j)%2){
    //             cout<<" 0 ";
    //         }
    //         else{
    //             cout<<" 1 ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // floyd triangle
    // int count = 1;

    // for(int i = 1; i <= 5; ++i){
    //     for ( int j = 5-i; j < 5; j++ ){
    //         cout<<"   "<<count++<<"     ";
    //     }
    //     cout<<endl;
    // }

    //half pyramid after 180deg rotation
    // for( int i = 0; i < 5; ++i ){
    //     for( int j = 0; j < 5; ++j ){
    //         if(j < 5-i){
    //             cout<<"   ";
    //         }
    //         else{
    //             cout<<" * ";
    //         }
    //     }
    //     // for( int j = 0; j < 5-i; ++j ){
    //     //     cout<<"   ";
    //     // }
    //     // for( int j = 0; j <= i; ++j ){
    //     //     cout<<" * ";
    //     // }
    //     cout<<endl;
    // }



//hollow rectangle
    // for( int i = 0; i < 5; ++i ){
    //     for( int j = 0; j < 4; ++j ){
    //         if( i == 0 || i == 4 ){
    //             cout<<" * ";
    //         }
    //         else if( j == 0 || j == 3 ){
    //             cout<<" * ";
    //         }
    //         else{
    //             cout<<"   ";
    //         }
    //     }
    //     cout<<endl;
    // }

    return 0;
}