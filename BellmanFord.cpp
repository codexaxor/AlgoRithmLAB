#include <bits/stdc++.h>
using namespace std;

#define MX 10005
#define INF 1000009

int N,E;

struct GRAPH{
    int u,v,w;
    GRAPH(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};


vector<GRAPH>G;
int dist[MX];

void BellmanFord(int s)
{
    memset(dist,INF,sizeof(dist));
    dist[s] = 0;

    for (int i=1; i<N; i++) {
        for (GRAPH g : G) {
            if (dist[g.v] > dist[g.u] + g.w) {
                dist[g.v] = dist[g.u] + g.w;
            }
        }
    }
}

int main(){

    int u,v,w;
    cin>>N>>E;
    for (int i=0; i<E; i++) {
        cin>>u>>v>>w;
        G.push_back(GRAPH(u,v,w));
    }
    BellmanFord(1);
    for (int i=1; i<=N; i++) {
        cout<<i<<" "<<dist[i]<<endl;
    }
    return 0;
}

/*
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
4 3 5
5 4 -3

 */