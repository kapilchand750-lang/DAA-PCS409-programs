// Week7 Ques(1) : Implement Dijkstra O((V+E)logV)

#include<bits/stdc++.h>
using namespace std;

void dijkstra(int src, vector<vector<pair<int,int>>>& adj,
              vector<int>& parent, vector<long long>& dist){

    priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        auto it = pq.top(); pq.pop();

        long long d = it.first;
        int node = it.second;

        if(d > dist[node]) continue;

        for(auto ngh : adj[node]){
            int next = ngh.second;
            int wt = ngh.first;

            if(d + wt < dist[next]){
                dist[next] = d + wt;
                parent[next] = node;
                pq.push({dist[next], next});
            }
        }
    }
}

void printPath(int node, vector<int>& parent){
    if(parent[node] == -1){
        cout << node;
        return;
    }
    printPath(parent[node], parent);
    cout << " -> " << node;
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // undirected
    }

    int akshayHouse;
    cin >> akshayHouse;  // destination

    vector<long long> dist(V, LLONG_MAX);
    vector<int> parent(V, -1);

    // Run Dijkstra from Akshay's house
    dijkstra(akshayHouse, adj, parent, dist);

    // Print result for each friend
    for(int i = 0; i < V; i++){
        if(i == akshayHouse) continue;

        cout << "\nFriend at node " << i << ":\n";

        if(dist[i] == LLONG_MAX){
            cout << "No path exists\n";
            continue;
        }

        cout << "Shortest Distance: " << dist[i] << endl;
        cout << "Path: ";
        printPath(i, parent);
        cout << endl;
    }
}