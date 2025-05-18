package activity;

public class activity_selection_problem{
    private String activity;
    private int start;
    private int finish;
    public void setActivity(String activity) {
        this.activity = activity;
    }
    public void setStart(int start) {
        this.start = start;
    }
    public String getActivity() {
        return activity;
    }
    public int getStart() {
        return start;
    }
    public int getFinish() {
        return finish;
    }
    public void setFinish(int finish) {
        this.finish = finish;
    }
    @Override
    public String toString() {
        return "activity_selection_problem [activity=" + activity + ", start=" + start + ", finish=" + finish + "]";
    }

      
}