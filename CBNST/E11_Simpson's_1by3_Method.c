#include <stdio.h>
#include <math.h>
void details()
{
    printf("Name: Shivansh Gaur\nSection: D(G2)\nRno: 63\n\nSimpson's 1/3 Method\n\n");
}
double f(double x)
{
    return 1 / (1 + (x * x));
}
double simpson1_rule(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.0, x;
    printf("\nStep\txi\tyi\n");
    for (int i = 0; i <= n; i++)
    {
        x = a + i * h;
        double y = f(x);
        printf("x%d\t%.2lf\t%.2lf\n", i, x, y);

        if (i == 0 || i == n)
        {
            sum += y;
        }
        else if (i % 2 == 0)
        {
            sum += 2 * y;
        }
        else
        {
            sum += 4 * y;
        }
    }
    return sum * (h / 3);
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
    double integral=simpson1_rule(a, b, n);
    printf("\nThe approximate area under the curve is : %.4lf\n", integral);

}
