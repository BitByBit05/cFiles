#include <stdio.h>
#include <math.h>

int main() {

    double x = 0.0, y = 0.0, z = 0.0;
    double xNew, yNew, zNew;
    const double TOLERANCE = 0.0001;
    int max_iter = 100;
    int iter = 0;

    printf("Starting Gauss-Jacobi Iteration...\n");

    do {
        double x_old = x;
        double y_old = y;
        double z_old = z;

        xNew = (10 - y_old - z_old) / 8.0;
        yNew = (12 - x_old - z_old) / 10.0;
        zNew = (10 - x_old - y_old) / 8.0;

        x = xNew;
        y = yNew;
        z = zNew;

        iter++;

        printf("Iteration %d: x = %.6f, y = %.6f, z = %.6f\n", iter, x, y, z);

    } while ((fabs(xNew - x) > TOLERANCE || fabs(yNew - y) > TOLERANCE || fabs(zNew - z) > TOLERANCE) && iter < max_iter);

    printf("\nSolution converged after %d iterations:\n", iter);
    printf("x = %.6f\n", x);
    printf("y = %.6f\n", y);
    printf("z = %.6f\n", z);

    return 0;
}
