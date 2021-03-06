#include "/Users/mac/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define inf 1000009
const int mx = 1e5+5;
int dist[mx], N, E;
vector<pii>G[mx];
int mst=0;

void prim(int s){

    priority_queue<pii,vector<pii>, greater<pii> > q;
    memset(dist,inf,sizeof(dist));
    q.push(pii(0,s));
    dist[s] = 0;

    while(!q.empty()){

        int u = q.top().second;
        q.pop();
        mst+=dist[u];
        for (int i = 0; i < G[u].size(); ++i)
        {
            if ( dist[u] < dist[G[u][i].first])
            {
                dist[G[u][i].first] = dist[u];
                q.push(pii(dist[G[u][i].first],G[u][i].first));
            }
        }

    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt","r",stdin);
    int u,v,w;
    cin>>N>>E;
    for (int i = 0; i < E; ++i)
    {
        cin>>u>>v>>w;
        G[u].push_back(pii(v,w));
        G[u].push_back(pii(u,w));
    }
    prim(0);
    cout<<mst<<endl;
    return 0;
}
