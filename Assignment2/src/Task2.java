import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.*;
public class Task2 {
    public static void main(String[] args) {

        List<Process> tasks = new ArrayList<Process>();
        Random rn = new Random();
        tasks.add(new Process("T1",rn.nextInt(10),25));
        tasks.add(new Process("T2",rn.nextInt(10),10));
        tasks.add(new Process("T3",rn.nextInt(10),20));
        tasks.add(new Process("T4",rn.nextInt(10),35));
        tasks.add(new Process("T5",rn.nextInt(10),10));

        FCFS(tasks);
        System.out.println("FIRST COME FIRST SERVE SCHEDULING ");
        System.out.println();

        for(Process task : tasks){
            System.out.println("Task " + task.name + ": ");
            System.out.println("Priority: " + task.priority);
            System.out.println("Burst time: " + task.bursttime);
            System.out.println("Waiting time: " + task.waitingtime);
            System.out.println("Turnaround time: " + task.turnaroundtime);
            System.out.println();
        }


    }
    public static void FCFS(List<Process> tasks){


        tasks.sort(new Comparator<Process>() {
            @Override
            public int compare(Process o1, Process o2) {
                return Integer.compare(o1.starttime, o2.starttime);
            }
        });
        int cur_time = 0;
        for (Process task : tasks){
            if(cur_time < task.starttime){
                cur_time = task.starttime;
            }
            task.waitingtime = cur_time- task.starttime;
            task.turnaroundtime = task.waitingtime+task.bursttime;
            cur_time = cur_time+ task.bursttime;
        }
    }
    public static void SJFPreemptive (List <Process> tasks){
        int currentTime = 0;
        int remainingTasks = tasks.size();

        while (remainingTasks >0){
            Process nextTask = null;
            int sh_B_time = Integer.MAX_VALUE;
            
        }


    }
}
