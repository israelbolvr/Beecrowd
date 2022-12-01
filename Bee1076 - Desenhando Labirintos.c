#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<set<int>>&adj, int s, int d);
void DFS(vector<set<int>>&adj, int V, int s);
void createGraph(vector<set<int>> adj, int tam);
 
int main() { 
    vector<set<int>> adj;
    int tam;
    cin >> tam;
    createGraph(adj, tam);
    return 0;
}

void addEdge(vector<set<int>>&adj, int s, int d) {
 adj[s].insert(d);
 adj[d].insert(s);
}
 
void DFS(vector<set<int>>&adj, int V, int s){
    vector<bool> visited(V, false);
    stack<int> stk;
    int cont = 0;
    stk.push(s);
    visited[s] = true;
    while(!stk.empty()){
        s = stk.top();
        visited[s] = true;
        stk.pop();
        for(auto i: adj[s]){
            if(!visited[i]){
                cont+=2;
                stk.push(i);
            }
        }
    }
    cout << cont << endl;
}

void createGraph(vector<set<int>> adj, int tam){
    for(int m = 0; m<tam; m++){
        vector<set<int>> adj;
        int s = 0;
        int V, E;
        int a, b;
        cin >> s;
        cin >> V >> E;
        adj.resize(V);
        for(int i = 0; i<E; i++){
            cin >> a >> b;
            addEdge(adj, a, b);
        }
        DFS(adj, V, s);
    }
}