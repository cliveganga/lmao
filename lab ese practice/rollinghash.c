#include <stdio.h>
#include <string.h>
#include <math.h>


void main()
{
    char pattern[100], text[100];

    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern to be searched: ");
    scanf("%s", pattern);

    int n = strlen(pattern);
    int b = strlen(text);
    int n2 = n-1;
    int hash = 0;
    for(int i = 0; i<n; i++){
        hash += pattern[i]*pow(26,n2);
        n2--;
    }
    
    for(int i = 0, j = n-1; j < b; j++, i++ ){
        n2=n-1;
            int jash = 0;    
            for(int q = i; q<=j; q++)
            {
                jash += text[q]*pow(26,n2);
                n2--;
            } 
        if(jash == hash)
        {
            printf("\nMatching string: ");
            for(int q = i; q<=j; q++)
            {
                printf("%c",text[q]);
            } 
        }
    }

}