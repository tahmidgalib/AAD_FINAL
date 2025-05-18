package activity;

import java.util.*;

public class TestComparator implements Comparator<activity_selection_problem> {

    @Override
    public int compare(activity_selection_problem o1, activity_selection_problem o2) {
        return o1.getFinish() - o2.getFinish();

    
    }
}
