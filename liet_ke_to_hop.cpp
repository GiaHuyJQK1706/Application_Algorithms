#include<stdio.h>
#include<math.h>
#define MAX 450
int n, k;
int a[MAX];
int cnt;
int v;
void printSolution(){
	cnt += 1;
	for (int i=1;i<=k;i++) printf("%d ", a[i]);
	printf("\n");
}
int check(int v, int i){
	return 1;
}
void BackTracking(int i){
	int v;
	for (v = a[i-1]+1;v<= n-k+i;v++){
		if (check(v,i)){
		a[i] = v;
		if (i==k) printSolution();
		else BackTracking(i+1);
		}
	}
}
int main(){
	printf("Tap hop tu 1 den n, hay nhap n: "); scanf("%d", &n);
	printf("To hop chap k, hay nhap k: "); scanf("%d", &k);
	a[0] = 0; cnt = 0;
	BackTracking(1);
	printf("So to hop chap %d cua %d phan tu la: %d",k, n, cnt);
	return 0;
}
