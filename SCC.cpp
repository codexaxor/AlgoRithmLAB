#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int node,edge;

vector<int>v[1000];
vector<int>Rv[1000];
int color[1000];
int visited[1000];
vector<int>::iterator it;
stack<int>s;
int mark=0;


void DFS(int n){

    color[n]=1;
    int x;

    for (int i = 0; i < v[n].size(); ++i) {
        x = v[n][i];
        if(color[x] == 0)
        {
            DFS(x);
        }
    }
    color[n] = 2;
    s.push(n);

}

void DFS2(int n){

    visited[n]=1;
    int x;

    for (int i = 0; i < Rv[n].size(); ++i) {
        x = Rv[n][i];
        if(visited[x] == 0)
            DFS2(x);
    }
    visited[n]=2;

}


int main() {


    freopen("input.txt","r",stdin);

    cin>>node>>edge;

    for (int i = 1; i <= edge; ++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        Rv[y].push_back(x);
    }

    for (int j = 1; j <= node; ++j) {
        if (color[j] == 0)
            DFS(j);
    }


    while (!s.empty()){

        int x = s.top();
        s.pop();

        if (visited[x] == 0)
        {
            DFS2(x);
        }
    }
    cout<<mark<<endl;


    return 0;
}