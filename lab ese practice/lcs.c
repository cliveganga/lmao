#include <stdio.h>
#include<string.h>
int str_length(char str[]) {
    int count; 
    for (count = 0; str[count] != '\0'; ++count);
    return count; 
}
int max(int a, int b)
{
    if(a>b)
        return a;
    else 
        return b;
}

void main(){
    char s1[100];
    char s2[100]; 
    printf("Enter First String:");
    scanf("%s", s1);
    printf("\nEnter Second String:");
    scanf("%s", s2);
    int a = str_length(s1);
    int b = str_length(s2);
    int mat[a+1][b+1];
    for(int i=0; i<=a; i++){
       for(int j=0; j<=b; j++){
        if(i == 0 || j == 0)
        {
            mat[i][j] = 0;
        }
        else
        {
           if(s1[i-1] == s2[j-1])
               mat[i][j] = 1 + mat[i-1][j-1];
           else
               mat[i][j] = max(
                   mat[i-1][j],
                   mat[i][j-1]
               ); 
        }
           
       }
   }
   int lcsSize =  mat[a][b];
   int scounter = lcsSize-1;
   char lcs[lcsSize+1];
   lcs[lcsSize] = '\0';
   int ac = a;
   int bc = b;
   
   
    while (ac>0 || bc>0)
    {
        int current  = mat[ac][bc];
        if(mat[ac][bc-1] == current)
        {
            bc--;
        }
        else if (mat[ac-1][bc] == current)
        {
            ac--;
        }
        else
        {
            lcs[scounter--] = s1[ac-1];
            ac--;
            bc--;
        }
        
    }
    

    printf("\n -  - ");
    for(int i = 0; i <b; i++ )
    {
       printf(" %c ", s2[i]);
    }
    for(int i = 0; i <= a; i++ )
    {
        if(i == 0)
        {
            printf("\n - ");

        }
        else
        {
            printf("\n %c ", s1[i-1]);
        }
        for (int j = 0; j <= b; j++)
        {
            printf(" %d ", mat[i][j]);
        }
        
    }
    printf("\nLCS :%s", lcs);
}