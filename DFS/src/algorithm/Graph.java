package algorithm;

import java.util.LinkedList;

public class Graph {
    private int vertices;
    private LinkedList<Integer>[] adjList;

    // Constructor
    public Graph(int v) {
        this.vertices = v;
        adjList = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adjList[i] = new LinkedList<>();
        }
    }

    // Add an edge (undirected by default)
    public void addEdge(int u, int v) {
        adjList[u].add(v);
        //adjList[v].add(u);
    }

    // Public method to start DFS
    public void dfs(int start) {
        boolean[] visited = new boolean[vertices];
        System.out.print("DFS traversal starting from node " + start + ": ");
        dfsUtil(start, visited);
        System.out.println();
    }

    // Recursive utility for DFS
    private void dfsUtil(int current, boolean[] visited) {
        visited[current] = true;
        System.out.print(current + " ");

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }
    
}
