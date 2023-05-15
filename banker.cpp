#include <stdio.h>
void main()
{
    int n, m;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("Enter the number of resources : ");
    scanf("%d", &m);
    int alloc[100][100], max[100][100], avail[100];
    printf("Enter the details for processes\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nProcess P%d\nEnter allocated resources: ", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
        printf("Enter maximum requirements : ");
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }
    printf("\nEnter available resources : ");
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);
    int v[100], ans[100], ind = 0;
    for (int i = 0; i < n; i++)
        v[i] = 0;
    int need[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    v[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            flag = 0;
            printf("\nit will go in deadlock \n");
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nFollowing is SAFE Sequence \n");
        for (int i = 0; i < n; i++)
            printf(" P%d ->", ans[i]);
    }
}