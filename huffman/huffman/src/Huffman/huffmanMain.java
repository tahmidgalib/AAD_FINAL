package Huffman;

import java.util.PriorityQueue;

public class huffmanMain {

    public static int printCode(huffmanNode root, String s, int total) {
        if (root.left == null && root.right == null && Character.isLetter(root.c)) {
            System.out.println(root.c + ":" + s);
            return total + s.length() * root.data;
        }
        
        int leftTotal = printCode(root.left, s + "0", 0);
        int rightTotal = printCode(root.right, s + "1", 0);
        return leftTotal + rightTotal + total;
    }
    
    public static void main(String[] args) {
        int n = 6;
        char[] charArray = {'a', 'b', 'c', 'd', 'e', 'f'};
        int[] charFreq = {5, 9, 13, 13, 16, 45};

        PriorityQueue<huffmanNode> q = new PriorityQueue<huffmanNode>(n, new mycomparator());

        for (int i = 0; i < n; i++) {
            huffmanNode hn = new huffmanNode(); 
            hn.c = charArray[i]; 
            hn.data = charFreq[i]; 
            hn.left = null; 
            hn.right = null; 
            q.add(hn); 
        }

        huffmanNode root = null; 

        while (q.size() > 1) {
            huffmanNode x = q.poll(); 
            huffmanNode y = q.poll(); 

            huffmanNode f = new huffmanNode(); 
            f.data = x.data + y.data; 
            f.c = '-'; 
            f.left = x; 
            f.right = y; 
            root = f; 
            q.add(f); 
        }

        // Get the final root node
        root = q.poll();
        
        System.out.println("Huffman Codes:");
        int totalBits = printCode(root, "", 0);
        
        int sum = 0;
        for (int freq : charFreq) {
            sum += freq;
        }
        
        System.out.println("Total Frequency = " + sum);
        System.out.println("ASCII needs: " + n * 8);
        System.out.println("HuffmanCode needs: " + totalBits);
    }
}