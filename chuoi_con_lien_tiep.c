#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 750

int main()
{
	char a[MAX];
	int n, k, m, l, c=0;

	printf("Chuoi nay co bao nhieu phan tu?: ");
	scanf("%d", &n);
	printf("Nhap chuoi: ");
	scanf("%s", a);

	printf("\n___________________________________________________________________________________________________________\n");
	printf("Cac chuoi lien tiep tu 1 den %d phan tu la:\n\n", n);

	for(k=1;k<=n;k++){				//So ky tu moi chuoi con
		for(m=0;m<=n-k;m++){			//Vi tri dau tien cua ky tu do
			for(l=m;l<m+k;l++){	//in tung ky tu mot
				printf("%c",a[l]);
			}
			c++;
			printf("\n");
		}
	}
	printf("So chuoi con trong chuoi input la: %d", c);
	return 0;
}
