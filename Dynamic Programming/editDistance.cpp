#include <iostream>

using namespace std;

int minDistance(string word1, string word2) {
    int cache[word1.length() + 1][word2.length() + 1];
    for(int j =0; j < word2.length()+1;j++) {
        cache[word1.length()][j] = word2.length() - j;
    }
    for(int i =0; i < word1.length()+1;i++) {
        cache[i][word2.length()] = word1.length() - i;
    }
    for(int i = word1.length() - 1; i >=0;i--) {
        for(int j = word2.length() - 1; j >=0;j--) {
            if(word1[i] == word2[j]) {
                cache[i][j] = cache[i + 1][j + 1];
            }
            else {
                cache[i][j] = 1 + min(cache[i +1][j], min(cache[i][j + 1],cache[i + 1][j + 1]));
            }
        }    
    }
    return cache[0][0];
}


int main(int argc, char const *argv[]) {
   
    string str1 = "";
    string str2 = "";

    cin >> str1 >> str2;
    cout << minDistance(str1,str2) << endl;
    
    return 0;
}
