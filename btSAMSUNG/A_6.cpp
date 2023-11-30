#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


bool visited[100];
vector <int> adj[100];
vector <pair<int,int>> edges;
int n,m;


void dfs(int x)
{
    visited[x]= true;
    for (int it : adj[x])
    {
        if (!visited[it])
        {
            dfs(it);
        }
    }
}

int conectedComponents(int x)
{
    int ans = 0;
    for (int i = 1;i<=x;i++)
    {
        if(!visited[i])
        {
            ans++;
            dfs(i);
        }
    }
    return ans;
}

bool egdeConnect(int x)
{
    for(int i=0;i<m;i++)
    {
        if(i!=x)
        {
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
    }
    if(conectedComponents(n)>1)
    {
        return false;
    }
       return true;
}



int main()
{

    cin>> n >> m;
    for (int i=0;i<m;i++)
    {
        int x,y; cin>> x >> y;
        edges.push_back(make_pair(x,y));
    }
    bool check = true;
    for(int i=0;i<m;i++)
    {
        memset(visited,false,sizeof(visited));
        for(int j=0;j<100;j++)
        {
            adj[j].clear();
        }
        if(egdeConnect(i)==false){
            check = false;
            break;
        }
    }
    cout << check;
}
