#include <iostream>
using namespace std;
bool check(int m){

    int temp = m;
    int n = 0;

    while(temp){
        n = n * 10 + temp % 10;
        temp = temp / 10;
    }


    return (m == n);


}


bool optimal_check(int x){

    if(x < 0 || (x % 10 == 0 && x != 0)){
        return false;
    }

    int temp = 0;
    while(x > temp){
        temp = temp * 10 + x % 10;
        x = x / 10;
    }

    cout << "x is: " << x << " temp is: " << temp <<"\n";
    return x == temp || x == temp / 10;


}

int main(){

    int n = 12321;

    if(optimal_check(n)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}