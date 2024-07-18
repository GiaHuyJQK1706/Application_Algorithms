//C++ 
#include <stdio.h>
#include <string.h>
char s[1000001];
int main() {
    scanf("%s", s);                         //Nhap xau s chi toan dau ngoac
    int i, tron=0, vuong=0, nhon=0;         //Mac dinh gia tri
    for (i=0; i<strlen(s); i++){            //Xet tung ky tu ngoac trong xau ky tu s
        if (s[i]=='(') tron++;
        else if (s[i]==')') tron--;
        else if (s[i]=='[') vuong++;
        else if (s[i]==']') vuong--;
        else if (s[i]=='{') nhon++;
        else if (s[i]=='}') nhon--;
        if (tron<0 || vuong<0 || nhon<0) {printf("0"); return 0;}
    }
    if (tron==0 && vuong==0 && nhon==0) printf("1");         //Khong co chenh lech
    else printf("0");
    return 0;
}
