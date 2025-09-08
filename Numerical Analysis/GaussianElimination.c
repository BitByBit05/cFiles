#include <stdio.h>
#include <math.h>

void gaussianElimination(int n, float matrix[n][n + 1])
{
    for (int i = 0; i < n - 1; i++) {
        int x = i;
        while (x < n-1) {
            if(matrix[x][i] < matrix[x+1][i]) {
                //swap
            }
            x++
        }
        for (int j = i + 1; j < n; j++) {
            if (matrix[j][i] == 0) {
                continue;
            } 
            else {
                float factor = matrix[j][i] / matrix[i][i] ;
                for(int k = i; k < n+1; k++){
                    matrix[j][k] = matrix[j][k] - (factor * matrix[i][k]);
                }
            }
        }
    }
}

int main() {
    float array[2][3] = {
        {2, 1, 5},
        {1, -3, -5}
    };

}