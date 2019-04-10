#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
using namespace std;
vector < pii > v;
bool cmp(pii a,pii b)
{
    return a.second*b.first > b.second*a.first;
}
int main()
{
    int N,W,weight,price,temp,ans = 0;
    cin >> N >> W;
    for(int i=0;i<N;i++)
    {
        cin >> weight >> price;
        v.push_back(pii(weight,price));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<N;i++)
    {
        temp = min(W,v[i].first);
        W -= temp;
        ans += temp*v[i].second;
    }
    cout << "Maximum Cost : " << ans << endl;
}
