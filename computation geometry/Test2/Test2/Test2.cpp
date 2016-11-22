#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main(){

    string str;
    while (getline(cin, str)){
        string res;
        for (int i = 0; i != str.size(); i++){
            if (str[i] >= 'A' && str[i] <= 'Z' || str[i] == ' ')
                res += str[i];
        }
        cout << res << endl;
    }

    return 0;
}