#include<bits/stdc++.h>
using namespace std;
#define mx 10005
int dp[mx][mx];
string s1,s2,ans;

int LCS(int x, int y)
{
    int l1=0,l2=0;
    if (s1[x]=='\0' || s2[y]=='\0')
    {
        return 0;
    }
    else if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    if (s1[x] == s2[y])
    {
        l1 = 1+LCS(x+1,y+1);
    }
    else
    {
        l1 = LCS(x+1,y);
        l2 = LCS(x,y+1);
    }
    return dp[x][y] = max(l1,l2);
}

void LCS_Find(int x, int y)
{
    if (s1[x]=='\0' || s2[y]=='\0')
    {
        cout<<ans<<endl;
        return ;
    }
    if (s1[x]==s2[y])
    {
        ans+=s1[x];
        LCS_Find(x+1,y+1);
    }
    else
    {
        if (dp[x+1][y] > dp[x][y+1])
        {
            LCS_Find(x+1,y);
        }
        else
            LCS_Find(x,y+1);
    }
}

int main(int argc, char const *argv[])
{
    memset(dp,-1,sizeof(dp));
    cin>>s1>>s2;
    cout<<LCS(0,0)<<endl;
    LCS_Find(0,0);
    return 0;
}