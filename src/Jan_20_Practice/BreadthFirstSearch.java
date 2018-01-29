package Jan_20_Practice;

import java.util.ArrayList;
import java.util.Scanner;

public class BreadthFirstSearch {

    static int[] bfs(int n, int m, int[][] edges, int s) {
        // n = # of nodes
        // m = # of edges
        // s = starting node;


        int[] output = new int[n-1];

        Node[] graph = new Node[n];

        //building the nodes in the graph
        for (int i = 0; i < n; i++) {
            graph[i] = new Node(i+1, n);
        }

        //building the edges in the graph
        for (int i = 0; i < m; i++) {
            graph[edges[i][0]-1].createLink(graph[edges[i][1]-1]);
        }

        Node first = graph[s-1];

        search(first, output);

        for (int i = 0; i < output.length; i++) {
            if (output[i] == 0) {
                output[i] = -1;
            }
        }

        return output;
    }

    static void search(Node node, int[] output){
        for (int i = 0; i < node.connections.size(); i++) {

            Node connectedNode = node.connections.get(i); //The node that is connected by an edge

            if (!connectedNode.visited[connectedNode.visitCounter]) {
                output[connectedNode.id - 1] += 6;
                connectedNode.visited();
                search(connectedNode, output);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int a0 = 0; a0 < q; a0++) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] edges = new int[m][2];
            for (int edges_i = 0; edges_i < m; edges_i++) {
                for (int edges_j = 0; edges_j < 2; edges_j++) {
                    edges[edges_i][edges_j] = in.nextInt();
                }
            }
            int s = in.nextInt();
            int[] result = bfs(n, m, edges, s);
            for (int i = 0; i < result.length; i++) {
                System.out.print(result[i] + (i != result.length - 1 ? " " : ""));
            }
            System.out.println("");


        }
        in.close();
    }

    static class Node {
        ArrayList<Node> connections = new ArrayList<>();
        boolean[] visited;
        int id;
        int visitCounter = 0;
        Node(int id, int totalNodes) {
            this.id = id;
            visited = new boolean[totalNodes];
        }

        void visited(){
            visited[visitCounter] = true;
            visitCounter++;
        }


        void createLink(Node newLink) {
            this.connections.add(newLink);
            newLink.connections.add(this);
        }
    }
}