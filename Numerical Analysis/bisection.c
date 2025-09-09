#include <stdio.h>
#include <math.h>

// This function defines the equation we want to find the root of
// f(x) = x^2 - 4
double f(double x)
{
    return x * x - 4;
}

// This function performs the Bisection Method
void bisection(double a, double b)
{
    // Check initial condition: make sure the root is bracketed
    double fa = f(a);
    double fb = f(b);

    if (fa * fb >= 0)
    {
        printf("Error: Initial guesses do not bracket the root.\n");
        return;
    }

    double c;
    const double TOLERANCE = 0.0001;
    int max_iter = 100;
    int iter = 0;

    printf("Starting Bisection Method...\n");

    // The main loop that performs the bisection
    while (fabs(b - a) > TOLERANCE && iter < max_iter)
    {
        c = (a + b) / 2.0; // Calculate the midpoint
        double fc = f(c);

        printf("Iteration %d: a = %.6f, b = %.6f, c = %.6f, f(c) = %.6f\n", iter + 1, a, b, c, fc);

        // If the midpoint is the root, we're done
        if (fc == 0.0)
        {
            break;
        }

        // Check the signs to narrow the interval
        if (fa * fc < 0)
        {
            b = c;
        }
        else
        {
            a = c;
            fa = fc;
        }
        iter++;
    }

    printf("\nRoot found at %.6f\n", c);
}

int main()
{
    // We are solving f(x) = x^2 - 4
    // The roots are at x = +/- 2.
    // Let's find the positive root by bracketing it with initial guesses.
    double guess1 = 1.0;
    double guess2 = 4.0;

    // Call the bisection function
    bisection(guess1, guess2);

    return 0;
}
