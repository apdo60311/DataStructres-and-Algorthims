#include <iostream>
#include <map>
#include <vector>
using namespace std;


char repeatedCharacter(string s) {
    map <char , int> m;
    vector <pair<char,int>> v;
    for(int i = 0;i < s.length();i++) {
        m[s[i]]++;
    }
    for(int i = 0;i < s.length();i++) {
        if(m[s[i]] == 2){
            pair<char,int> pair_temp;
            pair_temp.first = s[i];
            pair_temp.second = i;
            v.push_back(pair_temp);
        }
    }
    cout << "._____." << endl;
    for(int i = 0;i < v.size();i++) {
        cout << "|" << v[i].first << " : " << v[i].second << "|"<< endl;
    }
    return ' ';
}

int main() {

    repeatedCharacter("abccbaacz");
    return 0;
}