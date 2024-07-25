//C++ 
//CPP 
#include <bits/stdc++.h>
using namespace std;
int main(){
	queue<int> q;
	int rs[10000];
	int k = 0;
	while(1){
        string cmd;
        cin >> cmd;
        if (cmd == "PUSH"){
            int curr;
            cin >> curr;
            q.push(curr);
        } else if (cmd == "POP"){
            if (!q.empty()){
                int curr = q.front();
                rs[k] = curr;
                q.pop();
            }
            k++;
        } else if (cmd == "#"){
            break;
        }
	}
	for (int i=0;i<k;i++){
        if (rs[i] != 0){
            cout << rs[i] << endl;
        } else {
            cout << "NULL" << endl;
        }
	}
	return 0;
}
