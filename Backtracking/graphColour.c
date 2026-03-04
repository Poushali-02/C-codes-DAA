#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX]; // the graph 
int colours[MAX]; // available colours
int n; // number of vertices
int m; // number of colours available

bool isSafe(int vertex, int colour){ // check if it is safe to put colour on vertex 
    for(int i=0; i<n; i++){
        if(graph[vertex][i] && colours[i] == colour){
            return false;
        }
    }
    return true;
}

bool graphColour(int vertex){
    if(vertex == n){
        return true;
    }

    for(int colour=1; colour<=m; colour++){
        if(isSafe(vertex, colour)){
            colours[vertex] = colour;

            if(graphColour(vertex + 1)){
                return true;
            }

            colours[vertex] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        colours[i] = 0;

    if (graphColour(0)) {
        printf("Solution exists:\n");
        for (int i = 0; i < n; i++)
            printf("Vertex %d -> Color %d\n", i, colours[i]);
    } else {
        printf("No solution exists with %d colors\n", m);
    }

    return 0;
}