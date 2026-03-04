#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct job
{
    char id[5]; 
    int deadline;
    int profit;
} Job;

int comparator(const void *a, const void *b){
    return ((Job *) b) -> profit - ((Job *)a) -> profit;
}

void jobSequence(Job jobs[], int n){
    qsort(jobs, n, sizeof(Job), comparator);

    int max_deadline = 0;

    for(int i=0; i<n; i++){
        if(jobs[i].deadline > max_deadline) max_deadline = jobs[i].deadline;
    }

    char (*result)[5] = malloc(max_deadline * sizeof(char[5]));  // Array of char[5]

    bool *slot = malloc(max_deadline * sizeof(bool));

    if (!result || !slot) {
        printf("Memory allocation failed\n");
        return;
    }
    for (int i = 0; i < max_deadline; i++) {
        slot[i] = false;
        result[i][0] = '\0';
    }

    int totalProfit = 0;

    for(int i=0; i<n; i++){
        for(int j=jobs[i].deadline - 1; j>=0; j--){
            if(!slot[j]){
                strcpy(result[j], jobs[i].id);
                slot[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled Jobs: ");
    for(int k=0; k<max_deadline; k++)
        if(slot[k]) printf("%s ", result[k]);
    printf("\nMax Profit: %d\n", totalProfit);

    free(result);
    free(slot);
}

int main(void) {
    Job jobs[] = {{"j1", 2, 60}, {"j2", 1, 100}, {"j3", 3, 20}, {"j4", 2, 40}, {"j5", 1, 20}};
    jobSequence(jobs, 5);
    return 0;
}