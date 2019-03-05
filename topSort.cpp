#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int node,edge;
vector<int>v[1000];
int color[1000];
stack<int>s;


void DFS(int n){

    color[n]=1;
    int x;

    for (int i = 0; i < v[n].size(); ++i) {
        x = v[n][i];

        if(color[x] == 0)
            DFS(x);
    }

    color[n] = 2;
    s.push(n);


}

void CheckNode(){

    for (int i = 1; i <= node; ++i) {
        if (color[i] == 0)
            DFS(i);
    }

}


int main() {


    freopen("input.txt","r",stdin);

    cin>>node>>edge;

    for (int i = 0; i < edge; ++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }

    CheckNode();

    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    //  cout<<endl;

    return 0;
}