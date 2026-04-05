// Week 8 (Ques 3) : Implementation of Prim's to find Max MST O((V+E)logV)

#include<bits/stdc++.h>
using namespace std;

int maxPrims(vector<vector<pair<int,int>>>& adj, int V, int src){
    
    priority_queue<pair<int,int>> pq; // MAX HEAP
    
    vector<int> key(V, INT_MIN);   // max edge weight
    vector<int> parent(V, -1);     // MST structure
    vector<bool> visited(V, false);
    
    key[src] = 0;
    pq.push({0, src});
    
    int totalCost = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int node = it.second;
        int weight = it.first;
        
        if(visited[node]) continue;
        
        visited[node] = true;
        totalCost += weight;
        
        for(auto &ngh : adj[node]){
            int adjNode = ngh.second;
            int adjWeight = ngh.first;
            
            if(!visited[adjNode] && adjWeight > key[adjNode]){
                key[adjNode] = adjWeight;
                parent[adjNode] = node;
                pq.push({key[adjNode], adjNode});
            }
        }
    }
    
    // 🔹 Print MST edges
    cout << "\nEdges in MAX MST:\n";
    for(int i = 0; i < V; i++){
        if(parent[i] != -1){
            cout << parent[i] << " - " << i 
                 << " (weight = " << key[i] << ")\n";
        }
    }
    
    // 🔹 Parent Array
    cout << "\nParent Array:\n";
    for(int i = 0; i < V; i++){
        cout << "Node " << i << " -> Parent: " << parent[i] << "\n";
    }
    
    // 🔹 Key Array
    cout << "\nKey Array:\n";
    for(int i = 0; i < V; i++){
        cout << "Node " << i << " -> Key: " << key[i] << "\n";
    }
    
    return totalCost;
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int cost = maxPrims(adj, V, 0);
    
    cout << "\nTotal Maximum Cost (MST): " << cost << endl;
}