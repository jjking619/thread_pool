#include <stdio.h>
#include <limits.h>
#define m 3
#define n 4

int main()
{
    int a[m][n] = {{1, 9, -8, 7}, {11, -12, 3, 1}, {10, 6, 4, 5} /* , {1, 0, 3, 8} */};
    int b[m + 2][n + 2];
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (i == 0 || i == m + 1 || j == 0 || j == n + 1)
            {
                b[i][j] = INT_MIN;
            }
            b[i + 1][j + 1] = a[i][j];
        }
    }
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            printf("%-15d", b[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {                   //   左                       右                     上                      下
            if (b[i][j] > b[i][j - 1] && b[i][j] > b[i][j + 1] && b[i][j] > b[i - 1][j] && b[i][j] > b[i + 1][j])
            {
                printf("%-4d", b[i][j]);
            }
        }
    }
    return 0;
}