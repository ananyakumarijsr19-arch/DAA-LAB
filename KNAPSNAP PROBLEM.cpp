#include <stdio.h>

void swap(float *a, float *b)
{
    float t;
    t = *a;
    *a = *b;
    *b = t;
}

float knapsack(float w[], float p[], float r[], int n, float cap)
{
    int i;
    float profit = 0;

    for (i = 0; i < n; i++)
    {
        if (w[i] <= cap)
        {
            cap = cap - w[i];
            profit = profit + p[i];
        }
        else
        {
            profit = profit + r[i] * cap;
            break;
        }
    }
    return profit;
}

int main()
{
    int n, i, j;
    float w[100], p[100], r[100], cap;
    float w1[100], p1[100], r1[100];
    float profit1, profit2, profit3, maxProfit;

    printf("Enter number of items:");
    scanf("%d", &n);

    printf("Enter capacity M:");
    scanf("%f", &cap);

    printf("Enter weight and profit:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &w[i], &p[i]);
        r[i] = p[i] / w[i];
    }

    for (i = 0; i < n; i++)
    {
        w1[i] = w[i];
        p1[i] = p[i];
        r1[i] = r[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (r1[j] < r1[j + 1])
            {
                swap(&p1[j], &p1[j + 1]);
                swap(&w1[j], &w1[j + 1]);
                swap(&r1[j], &r1[j + 1]);
            }
        }
    }

    profit1 = knapsack(w1, p1, r1, n, cap);

    for (i = 0; i < n; i++)
    {
        w1[i] = w[i];
        p1[i] = p[i];
        r1[i] = r[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (w1[j] > w1[j + 1])
            {
                swap(&p1[j], &p1[j + 1]);
                swap(&w1[j], &w1[j + 1]);
                swap(&r1[j], &r1[j + 1]);
            }
        }
    }

    profit2 = knapsack(w1, p1, r1, n, cap);

    for (i = 0; i < n; i++)
    {
        w1[i] = w[i];
        p1[i] = p[i];
        r1[i] = r[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (r1[j] < r1[j + 1])
            {
                swap(&p1[j], &p1[j + 1]);
                swap(&w1[j], &w1[j + 1]);
                swap(&r1[j], &r1[j + 1]);
            }
        }
    }

    profit3 = knapsack(w1, p1, r1, n, cap);

    maxProfit = profit1;
    int bestCase = 1;

    if (profit2 > maxProfit)
    {
        maxProfit = profit2;
        bestCase = 2;
    }
    if (profit3 > maxProfit)
    {
        maxProfit = profit3;
        bestCase = 3;
    }

    printf("\nCase 1 (Max Profit) Profit = %.2f", profit1);
    printf("\nCase 2 (Min Weight) Profit = %.2f", profit2);
    printf("\nCase 3 (Max Profit/Weight) Profit = %.2f", profit3);
    printf("\nMaximum Profit = %.2f (Case %d)", maxProfit, bestCase);

    return 0;
}

