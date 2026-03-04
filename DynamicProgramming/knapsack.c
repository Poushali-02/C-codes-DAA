// binary knapsack

#include <stdio.h>
#include <stdlib.h>

int maximum (int a, int b){
    return a > b ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int n){
    int i, w;
    int **dp = (int **)malloc((n+1) * sizeof(int *)); // dp table
    for(i = 0; i <= n; i++)
        dp[i] = (int *)malloc((capacity+1) * sizeof(int));
    
    for(int i=0; i<=n; i++){
        for (int w = 0; w <= capacity; w++){
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weights[i-1] <= w){
                dp[i][w] = maximum(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]); // max of previous value, and new value added
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int result = dp[n][capacity];
    
    for(i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);

    return result;
}

int main(){
    int n, capacity;
    printf("No of items : ");
    scanf("%d", &n);
    
    int *values = malloc(n * sizeof(int));
    int *weights = malloc(n * sizeof(int));

    printf("Enter details\n");
    printf("Enter values \n");
    for(int i=0; i<n; i++){
        scanf("%d", &values[i]);
    }

    printf("Enter weights \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }
    
    printf("Enter capacity = ");
    scanf("%d", &capacity);

    printf("Maximum value = %d", knapsack(capacity, weights, values, n));
    return 0;
}