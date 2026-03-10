#include <stdio.h>
#define INF 9999
#define MAX 10

int main()
{
    int n;
    int cost[MAX][MAX];
    int dist[MAX];
    int path[MAX];
    int i, j;

    printf("Enter no of vertices : ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    printf("Enter 9999 if no edge\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    dist[n-1] = 0;

    for(i = n-2; i >= 0; i--)
    {
        dist[i] = INF;

        for(j = 0; j < n; j++)
        {
            if(cost[i][j] != INF)
            {
                if(cost[i][j] + dist[j] < dist[i])
                {
                    dist[i] = cost[i][j] + dist[j];
                    path[i] = j;
                }
            }
        }
    }

    printf("Min Cost from source to destination: %d\n", dist[0]);

    printf("Shortest Path : 0");

    int k = 0;

    while(k != n-1)
    {
        printf(" -> %d", path[k]);
        k = path[k];
    }

    return 0;
}
