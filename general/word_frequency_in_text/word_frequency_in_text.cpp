//CPP 
#include<bits/stdc++.h>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, int> wordCount;
    string line;
    int countEmptyLine = 0;
    while(getline(cin, line)){
        if (line.empty()){
            countEmptyLine++;
            if (countEmptyLine > 0){
                break;
            }
        } else {
            countEmptyLine = 0;
            istringstream luong(line);  // Chuyen sang luong
            string word;
            while (luong >> word){
                if (word.back() == '.' || word.back() == ','){
                    word = word.substr(0,word.size()-1);
                }
                wordCount[word]++;
            }
        }
    }
    for (const auto&pair : wordCount){
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}
