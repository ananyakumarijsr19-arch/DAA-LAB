#include<stdio.h>
#define MAX 10
#define INF 999

int n;
int cost[MAX][MAX];
int dp[1<<MAX][MAX];

int tsp(int mask,int pos)
{
    if(mask==(1<<n)-1)
        return cost[pos][0];

    if(dp[mask][pos]!=-1)
        return dp[mask][pos];

    int min=INF;

    for(int j=0;j<n;j++)
    {
        if((mask & (1<<j))==0)
        {
            int value = cost[pos][j] + tsp(mask | (1<<j), j);

            if(value < min)
                min = value;
        }
    }

    dp[mask][pos] = min;
    return min;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }

    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = tsp(1,0);

    printf("Minimum travelling cost = %d",ans);

    return 0;
}
