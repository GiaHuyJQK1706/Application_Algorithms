#include <bits/stdc++.h>
using namespace std;

bool checkPhone(string phone){
    if (phone.length() != 10)
        return false;

    for (int i = 0; i < phone.length(); i++)
        if (!(phone[i] >= '0' && phone[i] <= '9'))
            return false;

    return true;
};

int countTime(string ftime, string etime){
    int startTime = 3600 * ((ftime[0] - '0') * 10 + ftime[1] - '0') + 60 * ((ftime[3] - '0') * 10 + ftime[4] - '0') + ((ftime[6] - '0') * 10 + ftime[7] - '0');
    int endtTime = 3600 * ((etime[0] - '0') * 10 + etime[1] - '0') + 60 * ((etime[3] - '0') * 10 + etime[4] - '0') + ((etime[6] - '0') * 10 + etime[7] - '0');
    return endtTime - startTime;
};

map<string, int> numberCalls,timeCall;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type;
    int totalCalls = 0;
    int incorrectPhone = 0;
    do{
        cin >> type;
        if (type == "#"){
            continue;
        }
        ++totalCalls;
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        if (!checkPhone(fnum) || !checkPhone(tnum))
            ++incorrectPhone;
        numberCalls[fnum]++;
        timeCall[fnum] += countTime(ftime, etime);

    } while (type != "#");

    do{
        cin >> type;
        if (type == "#") continue;
        if (type == "?check_phone_number"){
            if (incorrectPhone == 0)
                cout << 1 << endl;
                else cout << 0 << endl;
        }else if(type == "?number_calls_from"){
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;
        }else if(type == "?number_total_calls")
            cout << totalCalls << endl;
         else if(type=="?count_time_calls_from"){
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
         }
    } while (type != "#");
    return 0;
}
