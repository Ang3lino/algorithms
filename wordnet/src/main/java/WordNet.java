// package src.main.java;

import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;


public class WordNet {
    private Digraph digraph;
    private Bag<String> intToString;    

    // constructor takes the name of the two input files
    public WordNet(String synsets, String hypernyms) {
        In in = new In(synsets);
        int vertexCount = 0;
        while (in.hasNextLine()) {
            StdOut.println(in.readLine());
        }
    }

    public static void main(String[] args) {
        String synsets = "synsets.txt", hypernyms = "hypernyms.txt";
        WordNet wnet = new WordNet(synsets, hypernyms);
    }
}
