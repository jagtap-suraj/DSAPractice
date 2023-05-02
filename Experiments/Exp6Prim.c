// AOA Experiment No. 06

#include <stdio.h>
#include <conio.h>

int visited[10] = {0};
int cost[10][10];

int main()
{
    int ne = 1, a, b, u, v, n, i, j, min, mincost = 0;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;

    printf("\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        b = v = j;
                        min = cost[i][j];
                        a = u = i;
                    }
                }
            }
        }

        if (visited[u] != 0 || visited[v] != 0)
        {
            printf("\nEdge %d: (%d %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d", mincost);
    getch();
    return 0;
}
