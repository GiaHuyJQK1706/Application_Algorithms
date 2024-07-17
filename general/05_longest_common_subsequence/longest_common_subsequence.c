//C 
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int* X = (int*)malloc(n * sizeof(int));
    int* Y = (int*)malloc(m * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &Y[i]);
    }
    
    // Create two 1D DP arrays
    int* dpPrev = (int*)calloc(m + 1, sizeof(int));
    int* dpCurr = (int*)calloc(m + 1, sizeof(int));
    
    // Fill the DP table using only two rows
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dpCurr[j] = dpPrev[j - 1] + 1;
            } else {
                dpCurr[j] = max(dpPrev[j], dpCurr[j - 1]);
            }
        }
        // Swap dpPrev and dpCurr
        int* temp = dpPrev;
        dpPrev = dpCurr;
        dpCurr = temp;
    }
    
    // The length of the longest common subsequence
    int result = dpPrev[m];
    printf("%d\n", result);
    
    // Free allocated memory
    free(X);
    free(Y);
    free(dpPrev);
    free(dpCurr);
    
    return 0;
}
