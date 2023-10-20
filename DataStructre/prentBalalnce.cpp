#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPair(char left, char right) {
    if(left == '(' && right == ')') {return true;}
    else if(left == '[' && right == ']') {return true;}
    else if(left == '{' && right == '}') {return true;}
    else if(left == '<' && right == '>') {return true;}
    else {return false;}
}

bool Pbalance(string str) {
    stack<char> prent;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] == '[' || str[i] == '{' || str[i] == '(' || str[i] == '<') {
            prent.push(str[i]);
        }
        else if (str[i] == ']' || str[i] == '}' || str[i] == ')' || str[i] == '>') {
            if(prent.empty()) {
                return false;
            }
            else if(isPair(prent.top(),str[i])) {
                prent.pop();
            }
        }
    }
    return prent.empty()?true:false;
}


int main(int argc, char const *argv[]) {
    cout << Pbalance("(<(({(hello)}))>)") << endl;
    return 0;
}
