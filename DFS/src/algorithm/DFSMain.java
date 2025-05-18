package algorithm;

public class DFSMain{
    public static void main(String[] args) {
		Graph graph = new Graph(6);

        // Add edges
		graph.addEdge(0, 3);
		graph.addEdge(0, 2);
		graph.addEdge(0, 1);
		graph.addEdge(1, 4);
		graph.addEdge(2, 4);
		graph.addEdge(2, 3);


        // Perform DFS starting from node 0
        graph.dfs(0);
	}

}