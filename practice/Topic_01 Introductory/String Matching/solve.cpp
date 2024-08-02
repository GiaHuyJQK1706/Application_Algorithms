//C++, solved by Gia-Huy Do
#include <iostream>
#include <string>
using namespace std;
int main() {
    string p;
    cin.ignore();
    getline(cin, p);

    string text;
    cin.ignore(); 
    getline(cin, text);

    size_t occurrences = 0;
    size_t pos = text.find(p);
    while (pos != string::npos) {
        occurrences++;
        pos = text.find(p, pos + 1);
    }

    cout << occurrences << endl;
    return 0;
}
