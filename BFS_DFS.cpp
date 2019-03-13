#include "/Users/mac/stdc++.h"
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


vector<int>G[1000];

int color[1000];

queue<int>q;


int node,edge;

void BFS(int n){

    color[n] = 1;
    q.push(n);

    while (!q.empty()) {
        int u = q.front();

        cout<<u<<" ";

        q.pop();

        for (int i=0; i<G[u].size(); i++) {
            int x = G[u][i];

            if (color[x]==0) {
                q.push(x);
                color[x]=1;
            }
        }
    }



}



void DFS(int n){


    color[n] = 1;

    for (int i=0; i<G[n].size(); i++) {
        int x = G[n][i];

        if (color[x] == 0) {
            DFS(x);
        }
    }
    // color[n] = 2;
    cout<<n<<" ";

}






int main(){

    rd;

    cin>>node>>edge;
    for (int i =0; i<edge; i++) {
        int u, v;
        cin>>u>>v;

        G[u].push_back(v);
        G[v].push_back(u);

    }

    cout<<"BFS : ";
    BFS(1);
    cout<<endl;
    memset(color,0,sizeof(color));
    cout<<"DFS : ";
    DFS(1);

    return 0;
}
