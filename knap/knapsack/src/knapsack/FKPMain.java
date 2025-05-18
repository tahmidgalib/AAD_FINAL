package knapsack;

import java.util.*;


public class FKPMain {

    public static void main(String[] args) {
        ArrayList<itemvalue> itemvalues=new ArrayList<itemvalue>();
        itemvalue itemvalue1=new itemvalue();
        itemvalue1.setObject(2);
        itemvalue1.setProfit(5);
        itemvalue1.setWeight(1);

        itemvalue itemvalue2=new itemvalue();
        itemvalue2.setObject(1);
        itemvalue2.setProfit(12);
        itemvalue2.setWeight(3);

        itemvalue itemvalue3=new itemvalue();
        itemvalue3.setObject(3);
        itemvalue3.setProfit(16);
        itemvalue3.setWeight(4);

        itemvalue itemvalue4=new itemvalue();
        itemvalue4.setObject(4);
        itemvalue4.setProfit(7);
        itemvalue4.setWeight(2);

        itemvalue itemvalue5=new itemvalue();
        itemvalue5.setObject(6);
        itemvalue5.setProfit(11);
        itemvalue5.setWeight(4);

        itemvalue itemvalue6=new itemvalue();
        itemvalue6.setObject(7);
        itemvalue6.setProfit(6);
        itemvalue6.setWeight(3);

        itemvalue itemvalue7=new itemvalue();
        itemvalue7.setObject(5);
        itemvalue7.setProfit(9);
        itemvalue7.setWeight(9);

        itemvalues.add(itemvalue1);
        itemvalues.add(itemvalue2);
        itemvalues.add(itemvalue3);
        itemvalues.add(itemvalue4);
        itemvalues.add(itemvalue5);
        itemvalues.add(itemvalue6);
        itemvalues.add(itemvalue7);

        Collections.sort(itemvalues,new FKPcomparator());

        double totalvalue=0;
        int capacity=15;

        for(itemvalue i: itemvalues)
        {
            int value1=i.getWeight();
            int value2=i.getProfit();

            if(capacity>=value1)
            {
                capacity=capacity-value1;
                totalvalue+=value2;
            }

            else
            {
                // totalvalue += i.value1* ((double) capacity / i.getWeight());
                // break;
                // double frac = ((double)capacity/(double)value1);
				// totalvalue += (frac * value2);
				// capacity -= (value1*frac);
				// break;
                totalvalue += ((double) capacity / value1) * value2;
                break;

            }
        }

      System.out.println("MaxProfit="+totalvalue);

    

    }

    
    
}