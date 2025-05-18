package algorithms;

public class BFSMain {
    public static void main(String[] args) {
		Graph graph = new Graph(6);

        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 5);

        // Perform BFS starting from node 1
    graph.bfs(0);
	}
}
