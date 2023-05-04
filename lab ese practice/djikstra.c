#include <stdio.h>
#define INFINITY 999999

void kondakadj(int n, int G[n][n], int start){
    int cost[n][n], distance[n], path[n], visited[n], nextnode;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(G[i][j] == 0)
            {
                cost[i][j] =  INFINITY;
            }
            else
            {
                cost[i][j] =  G[i][j];
            }
        }
    }
    for(int i = 0; i<n; i++)
    {
        distance[i] = cost[start][i];
        path[i] = start;
        visited[i] = 0;
    }
    printf("\ncost i n %d\n",cost[1][3]);
    distance[start] = 0;
    visited[start] = 0;

    for(int count = 0; count< n-1; count++ )
    {
        int minDist = INFINITY;
        for(int i = 0; i<n; i++)
        {
            if(visited[i] == 0 && distance[i]< minDist)
            {
                nextnode = i;
                minDist = distance[i];
            }
        }
            visited[nextnode] = 1;
        for(int i = 0; i<n; i++)
        {
            if(!visited[i] && distance[nextnode]+cost[nextnode][i] < distance[i])
            {
                distance[i] = distance[nextnode]+cost[nextnode][i];
                path[i] = nextnode;
            }
        }
    }
    //printing
    printf("\nVertex \t Dist \t path ");
    for(int i = 0; i<n; i++){
        printf("\n%d\t%d\t%d", i, distance[i], i);
        int j = i;
        do{
            j = path[j];
            printf("<-%d", j);
        }while ( j != start);
        
    }
            
}


 void main()
 {
    int n ;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter matrix:\n");
    int G[n][n];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%d", &G[i][j]);
    printf("\nEnter Starting node:");
    int start;
    scanf("%d", &start);
    kondakadj(n, G, start);
 }