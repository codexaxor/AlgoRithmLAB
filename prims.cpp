#include <list>
#include <set>
#include <map>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <limits>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <bitset>
#include <numeric>
#include <cassert>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;


#define inf 99999
typedef pair<int,int>PII;

int n, e, root=0;

vector<PII>V[1000];


struct Node{

    int u, cost;
    Node(){

    }

    Node(int _u, int _cost){
        u = _u;
        cost = _cost;
    }

};

bool operator<(Node A, Node B){

    return A.cost > B.cost;

}

priority_queue<Node>P;

int cost[100];
int taken[100];

int prims(){

    for (int i = 0; i < n; ++i) {
        cost[i] = inf;
        taken[i] = 0;
    }

    cost[root] = 0;
    P.push(Node(root,0));
    int mst = 0;

    while (!P.empty()){

        Node x = P.top();
        P.pop();

        if (taken[x.u])
            continue;

        taken[x.u] = 1;
        mst+=x.cost;

        for (PII v : V[x.u]) {
            if (taken[v.first])
                continue;

            if (v.second < cost[v.first]){

                P.push( Node(v.first,v.second) );
                cost[v.first] = v.second;
            }
        }


    }

    cout<<mst<<endl;

}

int main(){

    cin>>n>>e;

    for (int i = 0; i < e; ++i) {
        int u,v,w;
        cin>>u>>v>>w;
        V[u].push_back(make_pair(v,w));
        V[v].push_back(make_pair(u,w));
    }

    prims();

}