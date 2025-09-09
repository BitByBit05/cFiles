#include <stdio.h>
#include <math.h>

// Function to print a matrix
void printMatrix(int n, float a[n][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%10.4f", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to perform Gaussian Elimination
void gaussianElimination(int n, float a[n][n + 1])
{
    printf("Starting Gaussian Elimination...\n\n");

    // Forward Elimination
    for (int i = 0; i < n - 1; i++)
    {
        // Find pivot row
        int pivot = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(a[j][i]) > fabs(a[pivot][i]))
            {
                pivot = j;
            }
        }

        // Swap rows if necessary
        if (pivot != i)
        {
            for (int k = i; k < n + 1; k++)
            {
                float temp = a[i][k];
                a[i][k] = a[pivot][k];
                a[pivot][k] = temp;
            }
        }

        // Check for zero pivot
        if (fabs(a[i][i]) < 1e-7)
        {
            printf("Error: Zero pivot encountered. System may be singular.\n");
            return;
        }

        // Elimination step
        for (int j = i + 1; j < n; j++)
        {
            float factor = a[j][i] / a[i][i];
            for (int k = i; k < n + 1; k++)
            {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    printf("Upper Triangular Matrix:\n");
    printMatrix(n, a);

    // Back Substitution
    float x[n];
    for (int i = 0; i < n; i++)
        x[i] = 0.0; // initialize

    for (int i = n - 1; i >= 0; i--)
    {
        float sum = 0.0;
        for (int j = i + 1; j < n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    float a[n][n + 1];

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nInitial Augmented Matrix:\n");
    printMatrix(n, a);

    gaussianElimination(n, a);

    return 0;
}
