package knapsack;

import java.util.*;

public class FKPcomparator implements Comparator<itemvalue> {

    @Override
    public int compare(itemvalue a, itemvalue b) {
        double r1=(double) a.getProfit()/a.getWeight();
        double r2=(double) b.getProfit()/b.getWeight();
        return Double.compare(r2,r1);
       
    }

    
    
}
