//CPP 
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    set<string> db;
    vector<int> rs;

    while(1){
        string db_element;
        cin >> db_element;
        if (db_element == "*"){
            break;
        } else {
            db.insert(db_element);
        }
    }

    while(1){
        string cmd;
        cin >> cmd;
        if (cmd == "***"){
            break;
        } else if(cmd == "insert"){
            string ins_element;
            cin >> ins_element;
            if (db.find(ins_element) != db.end()){
                rs.push_back(0);
            } else {
                db.insert(ins_element);
                rs.push_back(1);
            }
        } else if(cmd == "find"){
            string k;
            cin >> k;
            if (db.find(k) != db.end()){
                rs.push_back(1);
            } else {
                rs.push_back(0);
            }
        }
    }

    for (int i:rs){
        cout << i << endl;
    }

    return 0;
}
