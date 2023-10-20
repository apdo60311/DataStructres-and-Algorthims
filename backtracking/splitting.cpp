#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void split(string str , string s = "" , int i = 0) {
    if(s.length() >= 2) {
        cout << s << endl;
        return;
    }
    for (int j = 0; j < str.length(); j++) {
        split(str.erase(str.begin()).base() , s + str[i] , i+1);
    }
    
}

int main(int argc, char const *argv[]) {
    split("050043");
    return 0;
}
