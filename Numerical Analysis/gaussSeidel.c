#include <stdio.h>
#include <math.h>

int main() {
    double x = 0.0, y = 0.0, z = 0.0;

    double x_prev, y_prev, z_prev;

    const double TOLERANCE = 0.0001;
    int max_iter = 100;
    int iter = 0;

    printf("Starting Gauss-Seidel Iteration...\n");

    do {
        x_prev = x;
        y_prev = y;
        z_prev = z;

        x = (10.0 - y - z) / 8.0;
        y = (12.0 - x - z) / 10.0;
        z = (10.0 - x - y) / 8.0;

        iter++;

        printf("Iteration %d: x = %.6f, y = %.6f, z = %.6f\n", iter, x, y, z);

    } while ((fabs(x - x_prev) > TOLERANCE || fabs(y - y_prev) > TOLERANCE || fabs(z - z_prev) > TOLERANCE) && iter < max_iter);

    printf("\nSolution converged after %d iterations:\n", iter);
    printf("x = %.6f\n", x);
    printf("y = %.6f\n", y);
    printf("z = %.6f\n", z);

    return 0;
}
