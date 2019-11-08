/*
找到N以内所有的质数

[2, sqrt(n)]
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n = 100;
    if(n == 1) {
        cout << 1 << endl;
    }
    else if (n == 2){
        cout << 1 << endl << 2 << endl;
    }
    else{
        cout << 1 << endl << 2 << endl;
        int flag = 0;
        for(int i = 3; i <= n; i++){
            for(int j = 2; j < sqrt(float(i)); j++){
                if(i % j != 0)
                    flag = 1;
                    break;
            }
            if(flag == 0) cout << i << endl;
            flag = 0;
        }
    }
    return 0;
}