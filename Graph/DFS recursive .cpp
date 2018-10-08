
#include<bits/stdc++.h>
using namespace std;
#define SIZE 1009
vector <int> adj[SIZE];
int Time;
int visit [SIZE];
int ft[SIZE];                       /*finishing time*/
int st[SIZE];                       /*Starting time*/

void DFS(int at)
{
    int i;
    if(visit[at]) return ;

    visit[at]=1;
    st[at]=++Time;

    for(i=0 ; i<adj[at].size(); i++)
    {
        DFS(adj[at][i]);
    }
    ft[at]=++Time;
}
int main()
{
    int node,edge,source,a,b,i;
    cin>>node>>edge;

    /*Create Graph*/
    while(edge--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    /*Call DFS*/
    cin>>source;
    DFS(source);
    /*Checking if graph is visited*/
    for(i=1; i<=node; i++)
    {
        cout<<i<<": is Visited if visit[i]= "<<visit[i]<<endl;
    }
    /*Checking starting and Ending time*/
    for(i=1; i<=node; i++)
    {
        cout<<"Node :"<<i<<" Starting time= "<<st[i]<<" Ending time: "<<ft[i]<<endl;
    }
    return 0;
}
