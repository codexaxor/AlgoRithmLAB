#include <bits/stdc++.h>
using namespace std;

const int mx = 100 , inf = 999999;
int N,E;
int G[mx][mx];
void FloydWarshall()
{
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if(G[i][j] > G[i][k]+G[k][j] )
                    G[i][j] = G[i][k]+G[k][j];

}
void PRINT()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (G[i][j] == inf)
                printf("%5s", "INF");
            else
                printf ("%5d", G[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int u,v,w;
    cin >> N >> E;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            G[i][j] = inf;

    for(int i=1; i<=N; i++)
        G[i][i] = 0;

    for(int i=0; i<E; i++)
    {
        cin >> u >> v >> w;
        G[u][v] = w;
    }
    FloydWarshall();
    PRINT();
}


/* 4 4
 * 1 4 10
 * 1 2 5
 * 2 3 3
 * 3 4 1
 *
 * */