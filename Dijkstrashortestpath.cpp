#include<bits/stdc++.h>
using namespace std;
#define V 9
int mindist(int dist[] , bool sptset[])
{
    int min= INT_MAX, min_index ;
    for (int i = 0; i < V; i++)
    {
        if (sptset[i]==false && dist[i]< min )
        {
            min= dist[i];
             min_index= i ;
        }      
    }
    // cout<<"Min ";
    return min_index ;
}
void printsoln(int dist[])
{
    cout<<"Vertex /t Distance from source \n";
    for (int i = 0; i < V; i++)
    {
        cout<<i<<"\t\t"<<dist[i]<<"\n";
    }
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptset[V] ;
    for (int i = 0; i < V; i++)
    {
        dist[i]= INT_MAX;
        sptset[i]=false ;
    }
    dist[src]= 0 ;
    for (int i = 0; i < V-1; i++)
    {
        int u = mindist(dist,sptset) ;
        sptset[u]= true ;
        for ( int j = 0; j < V; j++)
        {
            if (!sptset[j] &&graph[u][j] && dist[u]!=INT_MAX && dist[u]+ graph[u][j] < dist[j] )
            {
                dist[j]= dist[u]+ graph[u][j] ;
            }           
        }
    }
    // cout<<"Djkstra comp ";
     printsoln(dist); 
}
int main()
{
     int graph[V][V]=  { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
        dijkstra(graph,0 );
}