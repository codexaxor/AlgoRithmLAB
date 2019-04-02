#include "/Users/mac/stdc++.h"
//#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI acos(-1.0)
//#define INF (1<<30)
using namespace std;
#define rd freopen("ip.txt","r",stdin)
#define wr freopen("op.txt", "w", stdout)
#define mem(array,int) memeset(array,int,sizeof(array))
#define lld long long int
#define nl cout<<endl;
#define MX 10005
#define MOD 1000000007


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

    rd;
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