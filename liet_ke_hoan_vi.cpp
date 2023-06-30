#include <bits/stdc++.h>
using namespace std;
#define N 60
int a[N];
int n, cnt;
void print(){
	for (int i=1;i<=n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void swap(int i , int j){
	int tmp =a[i];
	a[i] = a[j];
	a[j]= tmp;
}
void solve(){
	for (int i=1;i<=n;i++)
		a[i] = i;
	while (1){
		print();
		cnt++;
		int j=n;
		while (j>=1 && a[j] > a[j+1]) j=j-1;
		if (j==0) break;
		int k=j+1;
		while (k<= n && a[k]>a[j]) k=k+1;
		k=k-1;
		swap(j,k);
		for(int i=j+1;i<=(n+j+1)/2;i++) swap(i, n+j+1-i);
	}
}
int main(){
	cout <<"Cho biet so phan tu tu 1 den n: ";
	cin >> n ;
	solve();
	cout << "Co " << cnt << " hoan vi";
	return 0;
}
