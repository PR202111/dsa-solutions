#include <stdio.h>
#include <limits.h>

#define INF 99999999

int main() {
    int n;
    scanf("%d", &n);

    int mat[n][n];
    int next[n][n]; 


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == -1)
                mat[i][j] = INF;
            if (i == j)
                mat[i][j] = 0;

            
            if (mat[i][j] != INF && i != j)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][k] != INF && mat[k][j] != INF && 
                    mat[i][j] > mat[i][k] + mat[k][j]) {
                    
                    mat[i][j] = mat[i][k] + mat[k][j];
                    next[i][j] = next[i][k]; 
                }
            }
        }
    }

    // Print the final shortest distance matrix
    printf("\nShortest Distance Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] >= INF)
                printf("-1 ");
            else
                printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    
    int u, v;
    printf("\nEnter source and destination (u v): ");
    scanf("%d %d", &u, &v);

    if (next[u][v] == -1) {
        printf("No path exists between %d and %d\n", u, v);
        return 0;
    }

    printf("Shortest path from %d to %d: %d", u, v, u);
    while (u != v) {
        u = next[u][v];
        printf(" -> %d", u);
    }
    printf("\nTotal cost: %d\n", mat[u][v]);

    return 0;
}
