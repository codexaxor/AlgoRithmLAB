#include<bits/sdc++.h>
using namespace std;

sruct activity
        {
                int start,end,index;

        } greedy[100];

bool operator<(activity A,activity B)
{
return (A.end < B.end);
}

int main()
{
    int n,i,j;
    cin>>n;

    for(int i = 1; i<=n; i++)
    {
        int s,e;
        cin>>s>>e;
        greedy[i].start = s;
        greedy[i].end = e;
        greedy[i].index = i;
    }
    sort(greedy,greedy+n);
    i=1;
    cout<<greedy[i].index<<" ";

    for(j = 2; j<=n; j++)
    {
        if(greedy[j].start>=greedy[i].end)
        {
            cout<<greedy[j].index<<" ";
            i=j;
        }
    }
}
