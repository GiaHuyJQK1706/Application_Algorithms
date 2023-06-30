/*Gray code in C++*/
/*By Gia Huy Do*/
#include<bits/stdc++.h> 
using namespace std;
int cntGray = 0;
void TaoGray(int n){
    if (n<0) return;
    vector<string> arr;                 //Khai bao mang dong rong arr, voi arr la kieu xau
    arr.push_back("0");                 //them arr[0] = "0"
    arr.push_back("1");                 //them arr[1] = "1"
    int i, j;
    for (i=2; i < (1<<n); i=i<<1){
        for (j=i-1;j>=0;j--) arr.push_back(arr[j]);
        for (j=0;j<i;j++) arr[j] = "0" +arr[j];
        for (j=i;j<2*i;j++) arr[j] = "1" + arr[j];
    }
    for (i=0;i<arr.size(); i++) {
        cout << arr[i] << endl;
        cntGray++;

    }
}
int main(){
    int n;
    cout <<"Nhap so bit can in ra day GrayCode: ";
    cin >> n;
    cout << "__________________________________________________" << endl;
    TaoGray(n);
    cout << "__________________________________________________" << endl;
    cout <<"Co "<< cntGray <<" ma GrayCode co " << n << " bit" << endl;
    return 0;
}
