package activity;

import java.util.ArrayList;
import java.util.Collections;


public class ASPMain{
    public static void main(String[] args) throws Exception {
         ArrayList<activity_selection_problem> list= new ArrayList<>();
   
       activity_selection_problem activity1=new activity_selection_problem();
       activity1.setActivity("A1");
       activity1.setStart(0);
       activity1.setFinish(6);

       activity_selection_problem activity2=new activity_selection_problem();
       activity2.setActivity("A2");
       activity2.setStart(3);
       activity2.setFinish(4);

       activity_selection_problem activity3=new activity_selection_problem();
       activity3.setActivity("A3");
       activity3.setStart(1);
       activity3.setFinish(2);

       activity_selection_problem activity4=new activity_selection_problem();
       activity4.setActivity("A4");
       activity4.setStart(5);
       activity4.setFinish(9);

       activity_selection_problem activity5=new activity_selection_problem();
       activity5.setActivity("A5");
       activity5.setStart(5);
       activity5.setFinish(7);

       activity_selection_problem activity6=new activity_selection_problem();
       activity6.setActivity("A6");
       activity6.setStart(8);
       activity6.setFinish(9);


       list.add(activity1);
       list.add(activity2);
       list.add(activity3);
       list.add(activity4);
       list.add(activity5);
       list.add(activity6);

       Collections.sort(list, new TestComparator());

       for(activity_selection_problem problem: list)
         System.out.println(problem.getActivity());

        //  System.out.println("Selected Activities:");
        //  int lastFinishTime = 0;
 
        //  for (activity_selection_problem activity : list) {
        //      if (activity.getStart() >= lastFinishTime) {
        //          System.out.println(activity.getActivity() );
        //          lastFinishTime = activity.getFinish();
        //      }
        //  }
        
       selectActivities(list);
     
    }



public static void selectActivities(ArrayList<activity_selection_problem> list) {
  System.out.println("\nSelected Activities:");
  int lastFinishTime = 0;

  for (activity_selection_problem activity : list) {
      if (activity.getStart() >= lastFinishTime) {
          System.out.println(activity.getActivity() );
          lastFinishTime = activity.getFinish();
      }
  }
}
}