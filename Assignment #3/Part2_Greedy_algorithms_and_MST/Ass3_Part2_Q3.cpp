//created by Aya Ehab Ramadan 20221209
// Date:12/30/2024

#include <bits/stdc++.h>
// to mske the code faster
#define AYA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5+5;
int n,m; // n is the number of nodes and m is the number of edges
vector<int>adj[N]; // adjacency list
bool vis[N]; // visited array
//Studying BFS
//Problem :
//There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1
//(inclusive). The edges in the graph are represented as a 2D integer array edges, where each
//edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex
//pair is connected by at most one edge, and no vertex has an edge to itself.
//You want to determine if there is a valid path that exists from vertex source to vertex
//destination.
//Given edges and the integers n, source, and destination, return true if there is a valid path
//from source to destination, or false otherwise.
//Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
//Output: true

//What is the bidirectional graph?
//A bidirectional graph is a graph in which the edges between the nodes are bidirectional, i.e.
//the edges are not directed. In a bidirectional graph, the edges are represented as a 2D integer
int BFS(int start, int end){
    queue<int>q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
      int node = q.front();
      q.pop();
      if (node==end){
        return true;
      }
      for(auto it:adj[node]){
        if (!vis[it]){
          vis[it]=1;
          q.push(it);
        }
      }
    }
    return false;
}
signed main(){
    AYA
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start,end;
    cin>>start>>end;
    if(BFS(start,end)) {
      cout << "true";
    }
    else {
      cout << "false";
    }
}
