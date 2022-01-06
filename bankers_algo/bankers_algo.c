#include<stdio.h>
#include<stdlib.h>
void main()
{
    int r=3, pno=5, need[100][100], finish[10];
    int alloc[5][3] = {{0, 1, 0},  // P0 // Allocation Matrix
                       {2, 0, 0},  // P1
                       {3, 0, 2},  // P2
                       {2, 1, 1},  // P3
                       {0, 0, 2}}; // P4

    int max[5][3] = {{7, 5, 3},  // P0 // MAX Matrix
                     {3, 2, 2},  // P1
                     {9, 0, 2},  // P2
                     {2, 2, 2},  // P3
                     {4, 3, 3}}; // P4

    int available[3] = {3, 3, 2};
    for (int i = 0; i < pno; ++i)
        for (int j = 0; j < r; ++j)
            {
                need[i][j] = max[i][j] - alloc[i][j];
            }
    printf("\n the allocation matrix is");
    for (int i = 0; i < pno; ++i)
    {
        printf("\n");
        for (int j = 0; j < r; ++j)
        {
            printf("%d", alloc[i][j]);
        }
    }
    printf("\n the max matrix is");
    for (int i = 0; i < pno; ++i)
    {
        printf("\n");
        for (int j = 0; j < r; ++j)
        {
            printf("%d", max[i][j]);
        }
    }
    printf("\n the need matrix is");
    for (int i = 0; i < pno; ++i)
    {
        printf("\n");
        for (int j = 0; j < r; ++j)
        {
            printf("%d", need[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < pno; i++)
    {
        finish[i] = 0;
    }
    int n = pno;
    int flag = 0;
    while(n)
    {
        for (int i = 0; i < pno;++i)
        {
            for (int j = 0; j < r;++j)
            {
                if((finish[i]==0)&&(need[i][j]<=available[j]))
                {
                    flag = 1;

                }
                else{
                    flag = 0;
                    break;
                }
            }
            if(flag==1)
            {
                printf("P%d", i);
                printf("\t");
                n--;
                finish[i] = 1;
                for (int k = 0; k < r;++k)
                {
                    available[k] += alloc[i][k];
                }
            }
        }
    }
}