package knapsack;

public class itemvalue {
    private int weight;
    private int profit;
    private int object;
    public double value2;
    public double value1;
    public int getWeight() {
        return weight;
    }
    @Override
    public String toString() {
        return "itemvalue [weight=" + weight + ", profit=" + profit + ", object=" + object + ", value2=" + value2
                + ", value1=" + value1 + "]";
    }
    public void setWeight(int weight) {
        this.weight = weight;
    }
    
    public int getProfit() {
        return profit;
    }
    public void setProfit(int profit) {
        this.profit = profit;
    }
    public int getObject() {
        return object;
    }
    public void setObject(int object) {
        this.object = object;
    }
}
    