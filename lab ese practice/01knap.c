#include <stdio.h>

void main()
{
    int n, bw;

    printf("\nEnter no of items, bag weight:");
    scanf("%d %d", &n, &bw);
    int p[n], w[n], X[n+1][bw+1];
    printf("\nEnter profit, weight:");
    for(int i = 0; i<n; i++)
    {
        scanf("%d %d", &p[i], &w[i]);
    }
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=bw; j++)
        {
            if(i == 0 || j == 0)
            {
                X[i][j] = 0;
            }
            else
            {
                if(((j-w[i-1]) >= 0)&&(X[i-1][(j-w[i-1])]+p[i-1])>X[i-1][j]){
                    X[i][j]= X[i-1][(j-w[i-1])]+p[i-1];
                }
                else
                {
                    X[i][j] = X[i-1][j];
                }
            }
        }
    }
    printf("\n - ");
    for(int i =0 ; i<= bw; i++){
        printf("\t %d ", i);
    }
    for (int i = 0; i <= n; i++)
    {
        printf("\n %d ", i);
        for(int j = 0; j<=bw; j++)
        {
            printf("\t %d ", X[i][j]);
        }
    }
    

}