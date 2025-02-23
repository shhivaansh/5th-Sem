#include<stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], pt[n], index[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and priority: ");
        scanf("%d %d", &bt[i], &pt[i]);
        index[i] = i + 1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pt[j] < pt[j + 1]) {
                int temp;

                temp = pt[j];
                pt[j] = pt[j + 1];
                pt[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }

    int t = 0;
    for (int i = 0; i < n; i++) {
        printf("Process %d executed from %d to %d\n", index[i], t, t + bt[i]);
        t += bt[i];
    }

    int wt = 0, tat = 0, totwt = 0;
    printf("\nProcess\tBT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", index[i], bt[i], wt);
        totwt += wt;
        wt += bt[i];
        tat += wt;
    }

    printf("Average waiting time: %.2f\n", (float)totwt / n);
    printf("Average turn around time: %.2f\n", (float)tat / n);

    return 0;
}
