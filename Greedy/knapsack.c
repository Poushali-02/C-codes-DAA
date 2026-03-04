// fractional knapsack
#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int weight;
    int value;
    float v_w_ratio;
} Item;

int comparator(const void *a, const void *b){
    float r1 = ((Item *) a) -> v_w_ratio;
    float r2 = ((Item *) b) -> v_w_ratio;
    
    return (r2 > r1) - (r2 < r1);
}

float knapsack(int capacity, Item items[], int n){
    qsort(items, n, sizeof(Item), comparator);

    int currWeight = 0;
    float finalVal = 0.0;

    for(int i=0; i<n; i++){
        // within capacity
        if(currWeight + items[i].weight <= capacity){
            currWeight += items[i].weight;
            finalVal += items[i].value;
        }
        else {
            float remain = (float) (capacity - currWeight);
            finalVal += items[i].v_w_ratio * remain;
            break;
        }
    }
    return finalVal;
}

int main(){
    int n, capacity;
    printf("Number of items: ");
    scanf("%d", &n);

    Item *items = (Item *) malloc(n * sizeof(Item));

    if (!items){
        printf("Memory allocation failed\n");
        return 0;
    }

    printf("Enter values and weights of items\n");
    for(int i=0; i<n; i++){
        printf("Item %d: Weight = ", i+1);
        scanf("%d", &items[i].weight);
        printf("Value = ", i+1);
        scanf("%d", &items[i].value);

        items[i].v_w_ratio = (float)items[i].value / items[i].weight;
    }
    
    printf("Enter capacity = ");
    scanf("%d", &capacity);

    float max = knapsack(capacity, items, n);
    printf("Maximum value in knapsack = %f", max);

    free(items);
    return 0;
}