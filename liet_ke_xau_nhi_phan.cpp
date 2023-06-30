#include <bits/stdc++.h>
using namespace std;
#define N 101
int b[N], n, cnt = 0;
void print(){
	for (int i=1;i<=n;i++){
		cout << b[i];
	}
	cout << endl;
}
void solve(){
	for (int i=1;i<=n;i++) b[i]=0;
	while (1){
		print();
		cnt++;
		int i=n;
		while (i>=1 && b[i]==1)
		i=i-1;
		if(i==0){
			break;
		}
		b[i]=1;
		for (int j=i+1;j<=n;j++) b[j]=0;
	}
}
int main(){
	cout << "Cho biet do dai xau nhi phan: ";
	cin >> n;
	solve();
	cout << "Co " << cnt << " xau nhi phan tat ca";
	return 0;
}
