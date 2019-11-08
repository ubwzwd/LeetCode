#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    if(s.size() <= 2){
        cout << s << endl;
        return 0;
    }
    int left = 0;
    int i = 0;
    int flag = 0;
    string temp;
    while(i < s.size()){
        if(s[i] == '['){
            left ++;
        }
        else if(s[i] != ']'){
            if(flag == 0 && s[i] != ','){
                temp.push_back('[');
                flag = 1;
            }
            temp.push_back(s[i]);
        }
        else{
            left --;
            if(temp.empty())
                cout << '[' <<']';
            else
                cout << temp << ']';
            temp.clear();
            flag = 0;
        }
        i++;
    }
    return 0;
}