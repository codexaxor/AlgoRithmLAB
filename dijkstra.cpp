#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define INF 1000009
const int mx = 1e5+5;
vector<pii>G[mx];
int vis[mx],par[mx],dist[mx],N,E;

void dijkstra(int s)
{
    priority_queue< pii, vector<pii>, greater<pii> > q;
    memset(dist,INF,sizeof(dist));
    q.push(pii(0,s));
    dist[s] = 0;
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        vis[u] = 1;
        for(auto i : G[u])
        {
            int w = i.second , v = i.first;
            if(!vis[v] && dist[u]+w<dist[v])
            {
                dist[v] = dist[u]+w;
                q.push(pii(dist[v],v));
            }
        }
    }
}
int main()
{
    int u,v,w;
    cin >> N >> E;
    for(int i=0;i<E;i++)
    {
        cin >> u >> v >> w;
        G[u].push_back(pii(v,w));
        G[v].push_back(pii(u,w));
    }
    dijkstra(0);
    return 0;
}
