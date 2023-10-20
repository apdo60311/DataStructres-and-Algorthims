#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> builedButtons() {
    vector<vector<char>> bottons(10);
    bottons[1] = {};
    bottons[2] = {'a','b' ,'c'};
    bottons[3] = {'d','e' ,'f'};
    bottons[4] = {'g','h' ,'i'};
    bottons[5] = {'j','k' ,'l'};
    bottons[6] = {'m','n' ,'o'};
    bottons[7] = {'p','q' ,'r' , 's'};
    bottons[8] = {'t','u' ,'v'};
    bottons[9] = {'w','x' ,'y' ,'z'};
    return bottons;
}

void solve(vector<vector<char>> bottons , string s , int s_index = 0, string a = "") {
    if (a.length() == s.length()) {
        cout << a << endl;
        return;
    }

    for (int i = 0; i < bottons[s[s_index] - '0'].size(); i++) {
        solve(bottons , s , s_index + 1 , a + bottons[s[s_index] - '0'][i]);
    }  
}

int main(int argc, char const *argv[]) {
    vector<vector<char>> vc = builedButtons();

    solve(vc, "23");

    return 0;
}
