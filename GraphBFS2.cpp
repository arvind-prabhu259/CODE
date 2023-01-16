#include <bits/stdc++.h>
#include <time.h>
using namespace std;

vector<list<int>> adj;
vector<int> visited_nodes;//Stores visited nodes as 1,0

void BFS(int cnode){//start node node
    list<int> bfs_nodes;
    bfs_nodes.clear();
    visited_nodes[cnode] = 1;
    bfs_nodes.push_back(cnode);
    while(!bfs_nodes.empty()){
        cnode=bfs_nodes.front();
        cout << cnode+1 << " ";
        bfs_nodes.pop_front();
        for(auto adj_node: adj[cnode]){//iterating through nodes connected to cnode
            if((visited_nodes[adj_node]==0)){//&&(adj_node!=111)){
                bfs_nodes.push_back(adj_node);
                visited_nodes[adj_node]=1;
            }
        }
    }
}

int main(){
    int num_edges=0;
    visited_nodes.resize(30,0);
    srand(time(0));
    adj.resize(30);
    for(int i=0;i<5;i++){//Nodes 1-5 are separated from remaining 25 nodes
        for(int j=i+1;j<5;j++){//nodes cannot conect to themselves
            if(rand()%2 == 1){//randomly deciding if edge is there or not
                adj[j].push_back(i);
                adj[i].push_back(j);
                num_edges++;
            }
        } 
    }

    for(int i=5;i<30;i++){
        for(int j=i+1;j<30;j++){
            if(rand()%2 == 1){
                adj[j].push_back(i);
                adj[i].push_back(j);
                num_edges++;
            }
        }
    }

    cout << "Adjacency list:" << endl;
    list<int>::iterator it;
    for(int i=0;i<30;i++){//printing adjacency list
        it=adj[i].begin();
        cout << i+1 << ":\t";
        if(it==adj[i].end()){cout << "None";}
        while(it!=adj[i].end()){
            cout << (*it+1) << " ";
            ++it;
        }
        cout << endl;
    }
    
    // cout <<"\nAdjacency matrix: "<< endl;
    // for(int i=0;i<30;i++){
    //     it=adj[i].begin();
    //     for(int j=0;j<30;j++){
    //         if(j==*it){
    //             cout << "1 ";
    //             it++;
    //         }
    //         else{
    //             cout << "0 ";
    //         }
    //     }
    //     cout << endl;
    // }

    cout << endl;
    int count=0;//number of components
    for(int i=0;i<30;i++){//BFS of all nodes
        if(visited_nodes[i]==0){//calls BFS if nodes are disconnected
            visited_nodes[i]=1;
            cout << "\nStarting from node " << i+1 << ": ";
            BFS(i);
            count++;
        }
    }
    cout << "\nNumber of components of graph: " << count << endl;
    cout << "Number of edges: "<< num_edges << endl;



    //CODE STORAGE

    //Printing lists
    // for(int i=0;i<5;i++){
    //     it=adj[i].begin();
    //     cout << i+1 << ":\t";
    //     while(it!=adj[i].end()){
    //         cout << *it << " ";
    //         ++it;
    //     }
    //     cout << endl;
    // }
}