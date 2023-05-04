#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

// function to print the optimal parenthesization of a matrix chain
void print_optimal_parens(int s[MAX_SIZE][MAX_SIZE], int i, int j, char name) {
    if (i == j) {
        printf("%c", name++);
    } else {
        printf("(");
        print_optimal_parens(s, i, s[i][j], name);
        print_optimal_parens(s, s[i][j]+1, j, name+s[i][j]-i+1);
        printf(")");
    }
}

// function to compute the minimum cost of matrix multiplication using dynamic programming
int matrix_chain_order(int p[], int n, char name) {
    int m[MAX_SIZE][MAX_SIZE], s[MAX_SIZE][MAX_SIZE];

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\n");

     printf("\n");
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(j<i)
            {
                printf("--\t");
            }
            else
            {
                printf("%lld\t", m[i][j]);
            }
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    print_optimal_parens(s, 1, n, name);
    printf("\n");

    return m[1][n];
}

int main() {
    int num_matrices;
    printf("\n");
    printf("Enter the number of matrices: ");
    scanf("%d", &num_matrices);
    int matrix_sizes[MAX_SIZE];
    printf("Enter the dimensions of matrix :");
    // loop through each matrix and get its dimensions
    for (int i = 0; i < num_matrices+1; i++) {
        scanf("%d", &matrix_sizes[i]);
    }

    

    // compute the minimum cost and optimal parenthesization using dynamic programming
    printf("Minimum cost of matrix multiplication: %d\n", matrix_chain_order(matrix_sizes, num_matrices, 'A'));

    return 0;
}