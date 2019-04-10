#include<bits/stdc++.h>
using namespace std;
#define mx 10005
int dp[mx][mx], w[mx], p[mx], capacity,n;

int KNAPSACK(int x, int y)
{

    int p1(0),p2(0);

    if (x == n)
    {
        return 0;
    }
    if (dp[x][y] != -1)
        return dp[x][y];

    if (y + w[x] <= capacity)
        p1 = p[x]+KNAPSACK(x+1,y+w[x]);
    else
        p2 = KNAPSACK(x+1,y);

    return dp[x][y] = max(p1,p2);
}

int main(int argc, char const *argv[])
{

    memset(dp,-1,sizeof(dp));
    cin>>n>>capacity;
    for (int i = 0; i < n; ++i)
    {
        cin>>w[i]>>p[i];
    }
    cout<<KNAPSACK(0,0)<<endl;
    return 0;
}