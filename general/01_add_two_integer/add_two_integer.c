#include <stdio.h>
#include <string.h>

#define MAX 10000

void reverse(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void add(char *a, char *b, char *result) {
    int carry = 0;
    int i;

    reverse(a);
    reverse(b);

    for (i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
        int sum = carry;
        if (a[i] != '\0') sum += a[i] - '0';
        if (b[i] != '\0') sum += b[i] - '0';
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    
    if (carry) result[i++] = carry + '0';
    
    result[i] = '\0';
    reverse(result);
}

int main() {
    char a[MAX], b[MAX], result[MAX];
    
    scanf("%s %s", a, b);
    add(a, b, result);
    printf("%s\n", result);

    return 0;
}
