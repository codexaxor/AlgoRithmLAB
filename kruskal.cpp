kruskal

#include "/Users/mac/stdc++.h"
//#include "/bits/stdc++.h"
#define fst ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI acos(-1.0)
#define INF (1<<30)
using namespace std;
#define rd freopen("ip.txt","r",stdin)
#define wr freopen("op.txt", "w", stdout)
#define mem(array,int) memeset(array,int,sizeof(array))
#define lld long long int
#define nl cout<<endl;
#define MX 100005
#define MOD 1000000007




int node,edge;

int parent[1000];

struct GRAPH{
    int u,v,w;
};

bool operator < ( GRAPH a, GRAPH b)
{
    return a.w < b.w;
}

vector<GRAPH>G;
vector<GRAPH>::iterator it;


int FindParent(int r){

    if (parent[r] == r) {
        return r;
    }
    else
        return FindParent(parent[r]);

}
int cost=0;

void mst(){

    sort(G.begin(),G.end());

    for (int i=1; i<=node; i++) {
        parent[i] = i;

    }

    for ( it = G.begin() ; it != G.end(); it++) {
        int u = FindParent((*it).u);
        int v = FindParent((*it).v);
        if (u!=v) {
            cost+=(*it).w;
        }
    }


}

int main(){

   // rd;

    cin>>node>>eg;

    for (int i =0; i<eg; i++) {
        edge e;
        cin>>e.u>>e.v>>e.w;
        G.push_back(e);

    }
    mst();

    cout<<cost<<endl;

    return 0;
}
