#include <stdio.h>
#include <math.h>
void details()
{
    printf("Name: Shivansh Gaur\nSection: D(G2)\nRno: 63\n\nSimpson's 3/8 Method\n\n");
}
double f(double x)
{
    return 1 / (1 + (x * x));
}
void simpson3by8_rule(double a, double b, int n)
{
    double h = (b - a) / n;
    double integral = 0, x, sum = 0.0, y;

    printf("\nStep\txi\tyi\n");
    for (int i = 0; i <= n; i++)
    {
        x = a + i * h;
        y = f(x);
        printf("x%d\t%.2lf\t%.2lf\n", i, x, y);
        if (i == 0 || i == n)
        {
            integral += y;
        }
        else if (i % 3 == 0)
        {
            integral += 2 * y;
        }
        else
        {
            integral += 3 * y;
        }
    }

    integral = (3 * h / 8) * integral;
    integral * 3;
    printf("\nThe approximate area under the curve is : %.4lf\n", integral);
}

int main()
{
    details();
    double a, b;
    int n;

    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);
    simpson3by8_rule(a, b, n);
}
