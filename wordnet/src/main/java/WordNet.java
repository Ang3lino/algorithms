// package src.main.java;

import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.ResizingArrayBag;
import edu.princeton.cs.algs4.StdOut;

import javax.swing.plaf.basic.BasicBorders.SplitPaneBorder;

import edu.princeton.cs.algs4.Bag;

public class WordNet {
    private Digraph digraph;
    private String[] intToString;

    private int buildIntToString(String synsets) {
        In in = new In(synsets); // reader
        Queue<String> lines = new Queue<>();
        while (in.hasNextLine()) {
            lines.enqueue(in.readLine());
        }
        int vertexCount = lines.size();
        intToString = new String[vertexCount];
        for (int i = 0; !lines.isEmpty(); ++i) {
            intToString[i] = lines.dequeue();
        }
        return vertexCount;
    }

    private void buildDigraph(String hypernyms, int V) {
        digraph = new Digraph(V);
        for (In in = new In(hypernyms); in.hasNextLine(); ) {
            String[] splitted = in.readLine().split(",");
            Integer[] vertices = new Integer[splitted.length];
            for (int i = 0; i < vertices.length; ++i) 
                vertices[i] = Integer.parseInt(splitted[i]);
            for (int i = 1; i < vertices.length; ++i) 
                digraph.addEdge(vertices[0], vertices[i]);
        }
    }

    // constructor takes the name of the two input files
    public WordNet(String synsets, String hypernyms) {
        int verticesCount = buildIntToString(synsets);
        StdOut.println("Mapper int -> str done");
        buildDigraph(hypernyms, verticesCount);
        StdOut.println("Graph built");
    }

    // returns all WordNet nouns
    public Iterable<String> nouns() {
        Bag<String> nouns = new Bag<>();
        for (int i = 0; i < intToString.length; ++i) {
            for (String noun: intToString[i].split(" "))
                nouns.add(noun);
        }
        return nouns;
    }

    public static void main(String[] args) {
        String synsets = "synsets.txt", hypernyms = "hypernyms.txt";
        WordNet wnet = new WordNet(synsets, hypernyms);
    }
}
