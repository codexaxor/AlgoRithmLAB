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
int p[MX];


void BellmanFord(int s)
{
    memset(dist,INF,sizeof(dist));
    dist[s] = 0;
    p[s] = -1;

    for (int i=1; i<N; i++) {
        for (int i=0; i<G.size(); i++) {
            GRAPH g = G[i];
            if (dist[g.v] > dist[g.u] + g.w) {
                dist[g.v] = dist[g.u] + g.w;
                p[g.v] = g.u;
            }
        }
    }
}

void PrintPath(int s, int e){
    vector<int>path;
    int k = e;

    while (k != -1) {
        path.push_back(k);
        k = p[k];
    }
    reverse(path.begin(),path.end());
    for (int i=0; i<path.size(); i++) {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

bool NS(int s){
    BellmanFord(s);

    for (int i=0; i<G.size(); i++) {
        GRAPH g = G[i];

        if ( g.w + dist[g.u] < dist[g.v] ) {
            return true;
        }
    }
    return false;
}

int main(){

    int u,v,w;
    cin>>N>>E;
    for (int i=0; i<E; i++) {
        cin>>u>>v>>w;
        G.push_back(GRAPH(u,v,w));
    }
    if (NS(1)) {
        cout<<"NEGATIVE CYCLE FOUND"<<endl;
    } else {
        PrintPath(1,N);
    }

    return 0;
}


/*

 5 6
 1 2 2
 2 5 5
 2 3 4
 1 4 1
 4 3 3
 3 5 1

 4 5
 1 2 -2
 3 1 -5
 2 3 -3
 3 4 -2
 1 4 6

 3 3
 1 2 -1
 1 3 2
 2 3 -1


 */
