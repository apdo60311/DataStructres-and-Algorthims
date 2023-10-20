#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string str) {
    for (int i = 0 , j = str.length() - 1; i <= str.length() / 2 && j != i; i++ , j--) {
        if(str[i] != str[j]) return false; 
    }
    return true;
}

void palPartition(string str , string res = "" ,int i = 0) {
    if(i >= str.length()) {
        if(isPalindrome(res)) {
            cout << res << endl;
        }
        return;
    }
    palPartition(str, res , i+1);
    palPartition(str, res + str[i] , i+1);
}

int main(int argc, char const *argv[]) {
    palPartition("aab"); // {{a,a,b}, {aa,b}}
    return 0;
}
