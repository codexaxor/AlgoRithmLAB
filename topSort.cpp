#include "/Users/mac/stdc++.h"
//#include "/bits/stdc++.h"
#define fst ios_base::sync_with_stdio(0); ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI acos(-1.0)
#define INF (1<<30)
using namespace std;
#define rd freopen("input.txt","r",stdin)
#define wr freopen("output.txt", "w", stdout)
#define mem(array,int) memeset(array,int,sizeof(array))
#define lld long long int
#define nl cout<<endl;
#define MX 100005
#define MOD 1000000007


vector<int>G[1000];

int color[1000];

queue<int>q;

stack<int>s;

int node,edge;



void DFS(int n){


    color[n] = 1;

    for (int i=0; i<G[n].size(); i++) {
        int x = G[n][i];

        if (color[x] == 0) {
            DFS(x);
        }
    }

    s.push(n);

}



void TopSort(){

    for (int i=0; i<node; i++) {
        if (color[i] == 0) {
            DFS(i);
        }
    }
    while (!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }

}


int main(){

  //  rd;

    cin>>node>>edge;
    for (int i =0; i<edge; i++) {
        int u, v;
        cin>>u>>v;

        G[u].push_back(v);

    }
    TopSort();


    return 0;
}
