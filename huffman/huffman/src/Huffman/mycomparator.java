package Huffman;

import java.util.Comparator;

public class mycomparator implements Comparator<huffmanNode>{

    @Override
    public int compare(huffmanNode x, huffmanNode y) {
       
        return x.data-y.data;
    }
    
}