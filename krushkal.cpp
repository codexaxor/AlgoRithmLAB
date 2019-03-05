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

int parent[1000];
int RankParent[1000];
int totalCost;

struct EDGE{
    int u,v,w;
};

vector<EDGE>E;

bool operator<(EDGE A, EDGE B){
    return A.w < B.w;
}

void MakeSet(int Node){
    for (int i = 0; i < Node; ++i) {
        parent[i] = i;
        RankParent[i] = 0;
    }
}

int FindParent(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = FindParent(parent[x]);
}

void Union(int u, int v){
    int x = FindParent(u);
    int y = FindParent(v);

    if(x==y)
        return;
    if(RankParent[x]>RankParent[y])
        parent[y] = x;
    else if(RankParent[y]>RankParent[x])
        parent[x] = y;
    else{
        parent[y] = x;
        RankParent[x]++;
    }
}

void KrushKal(int Node){
    MakeSet(Node);
    sort(E.begin(),E.end());
    int limit = (int)E.size();
    int MST=0;
    for (int i = 0; i < limit; ++i) {
        if(FindParent(E[i].u) != FindParent(E[i].v)){
            Union(parent[E[i].u],parent[E[i].v]);
            MST+=E[i].w;
        }
    }
    cout<<totalCost-MST<<endl;
}

int main(){

    freopen("input.txt","r",stdin);
    int node,edge;
    cin>>node>>edge;
    for (int i = 0; i < edge; ++i) {
        EDGE e;
        cin>>e.u>>e.v>>e.w;
        E.push_back(e);
        totalCost+=e.w;
    }
    KrushKal(node);
    return 0;
}

