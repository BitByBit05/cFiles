#include <stdio.h>
#include <math.h>

// Helper function to print a matrix
void printMatrix(int n, float a[n][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%.4f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to perform Gauss-Jordan Elimination
void gaussJordan(int n, float a[n][n + 1])
{
    printf("Starting Gauss-Jordan Elimination...\n\n");

    // Forward Elimination: This part creates the upper triangular form
    for (int i = 0; i < n; i++)
    {
        // Find the pivot row with the largest absolute value
        int pivot_row = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(a[j][i]) > fabs(a[pivot_row][i]))
            {
                pivot_row = j;
            }
        }

        // Swap the current row with the pivot row if necessary
        if (pivot_row != i)
        {
            for (int k = i; k < n + 1; k++)
            {
                float temp = a[i][k];
                a[i][k] = a[pivot_row][k];
                a[pivot_row][k] = temp;
            }
        }

        // Normalize the pivot row to make the pivot element 1
        float pivot_val = a[i][i];
        for (int k = i; k < n + 1; k++)
        {
            a[i][k] /= pivot_val;
        }

        // Eliminate elements below the pivot
        for (int j = i + 1; j < n; j++)
        {
            float factor = a[j][i];
            for (int k = i; k < n + 1; k++)
            {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    // Backward Elimination: This part makes the matrix a diagonal matrix
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            float factor = a[j][i];
            for (int k = i; k < n + 1; k++)
            {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    printf("Final Reduced Row Echelon Form:\n");
    printMatrix(n, a);

    // Print the solution directly from the final column
    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.4f\n", i + 1, a[i][n]);
    }
}

int main()
{
    // This example solves the system:
    // x1 + 2x2 - x3 = 3
    // 2x1 - x2 + 3x3 = -4
    // x1 - 3x2 + 2x3 = -1
    // The augmented matrix is:
    // [ 1  2 -1 |  3 ]
    // [ 2 -1  3 | -4 ]
    // [ 1 -3  2 | -1 ]

    int n = 3; // Number of equations
    float a[3][4] = {
        {1, 2, -1, 3},
        {2, -1, 3, -4},
        {1, -3, 2, -1}};

    printf("Initial Augmented Matrix:\n");
    printMatrix(n, a);

    gaussJordan(n, a);

    return 0;
}
