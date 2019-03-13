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


vector<int>G[1000];
vector<int>RG[1000];

int color[1000];

queue<int>q;

stack<int>s;

int cm;

int node,edge;



void DFS1(int n){


    color[n] = 1;

    for (int i=0; i<G[n].size(); i++) {
        int x = G[n][i];

        if (color[x] == 0) {
            DFS1(x);
        }
    }

    s.push(n);


}

void DFS2(int n){


    color[n] = 1;

    for (int i=0; i<RG[n].size(); i++) {
        int x = RG[n][i];

        if (color[x] == 0) {
            cout<<x<<" ";
            DFS2(x);
        }
    }

}


void SCC(){

    while (!s.empty()) {
        int x = s.top();
        s.pop();
        if (color[x]==0) {
            cm++;
            cout<<x<<" ";
            DFS2(x);
            cout<<endl;
        }
    }
}


int main(){

   // rd;

    cin>>node>>edge;
    for (int i =0; i<edge; i++) {
        int u, v;
        cin>>u>>v;

        G[u].push_back(v);
        RG[v].push_back(u);

    }
    for (int i=1; i<=node; i++) {
        if (color[i]==0) {
            DFS1(i);
        }

    }

    memset(color,0,sizeof(color));

    SCC();

    cout<<cm<<endl;


    return 0;
}
