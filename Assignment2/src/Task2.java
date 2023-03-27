import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.*;
public class Task2 {
    public static void main(String[] args) {

        List<Process> tasks = new ArrayList<Process>();
        Random rn = new Random();
        tasks.add(new Process("T1", rn.nextInt(10), 25));
        tasks.add(new Process("T2", rn.nextInt(10), 10));
        tasks.add(new Process("T3", rn.nextInt(10), 20));
        tasks.add(new Process("T4", rn.nextInt(10), 35));
        tasks.add(new Process("T5", rn.nextInt(10), 10));

        FCFS(tasks);
        System.out.println("FIRST COME FIRST SERVE SCHEDULING ");
        System.out.println();

        for (Process task : tasks) {
            System.out.println("Task " + task.name + ": ");
            System.out.println("Priority: " + task.priority);
            System.out.println("Burst time: " + task.bursttime);
            System.out.println("Waiting time: " + task.waitingtime);
            System.out.println("Turnaround time: " + task.turnaroundtime);
            System.out.println();
        }

        List<Process> tasks1 = new ArrayList<Process>();

        tasks1.add(new Process("T1", rn.nextInt(10), 25));
        tasks1.add(new Process("T2", rn.nextInt(10), 10));
        tasks1.add(new Process("T3", rn.nextInt(10), 20));
        tasks1.add(new Process("T4", rn.nextInt(10), 35));
        tasks1.add(new Process("T5", rn.nextInt(10), 10));

        SJFPreemptive(tasks1);
        System.out.println("SJF PREEMPTIVE ScHEDULING ");
        System.out.println();

        for (Process task : tasks1) {
            System.out.println("Task " + task.name + ": ");
            System.out.println("Priority: " + task.priority);
            System.out.println("Waiting time: " + task.waitingtime);
            System.out.println("Turnaround time: " + task.turnaroundtime);
            System.out.println();
        }
        List<Process> tasks2 = new ArrayList<Process>();

        tasks2.add(new Process("T1", rn.nextInt(10), 25));
        tasks2.add(new Process("T2", rn.nextInt(10), 10));
        tasks2.add(new Process("T3", rn.nextInt(10), 20));
        tasks2.add(new Process("T4", rn.nextInt(10), 35));
        tasks2.add(new Process("T5", rn.nextInt(10), 10));

        System.out.println("Priority Scheduling ");
        System.out.println();
        priorityscheduling(tasks2);
//        for (Process task : tasks2) {
//            System.out.println("Task " + task.name + ": ");
//            System.out.println("Burst Time "+ task.bursttime);
//            System.out.println("Priority: " + task.priority);
//            System.out.println("Waiting time: " + task.waitingtime);
//            System.out.println("Turnaround time: " + task.turnaroundtime);
//            System.out.println();
//        }

    }

    public static void FCFS(List<Process> tasks) {


        tasks.sort(new Comparator<Process>() {
            @Override
            public int compare(Process o1, Process o2) {
                return Integer.compare(o1.starttime, o2.starttime);
            }
        });
        int cur_time = 0;
        for (Process task : tasks) {
            if (cur_time < task.starttime) {
                cur_time = task.starttime;
            }
            task.waitingtime = cur_time - task.starttime;
            task.turnaroundtime = task.waitingtime + task.bursttime;
            cur_time = cur_time + task.bursttime;
        }
    }

    public static void SJFPreemptive(List<Process> tasks) {
        int currentTime = 0;
        int remainingTasks = tasks.size();
        int i =0;

        while (remainingTasks > 0) {
            Process nextTask = null;
            int sh_B_time = Integer.MAX_VALUE;

            for (Process task : tasks) {
                if (!task.executed && task.starttime <= currentTime && task.bursttime < sh_B_time) {
                    nextTask = task;
                    sh_B_time = task.bursttime;

                }
            }
            if (nextTask != null) {
                nextTask.waitingtime = nextTask.starttime;
                nextTask.starttime = currentTime;
                nextTask.bursttime = nextTask.bursttime - 1;
                i++;

                if (nextTask.bursttime == 0) {
                    nextTask.executed = true;
                    nextTask.turnaroundtime = currentTime +1;
                    nextTask.waitingtime = currentTime+1-i;
                    remainingTasks--;
                    i=0;
                }

            }
            currentTime++;


        }
    }
    public static void priorityscheduling(List <Process> tasks) {
        List<Process> sortedProcess = new ArrayList<>(tasks);
        Queue<Process> readyqueue = new LinkedList<>();

        sortedProcess.sort((p1, p2) -> p2.priority - p1.priority);
        int currentTime = 0;
        int quantum = 10;
        int i =0;
        int j=0;
        while(i<sortedProcess.size()){
            j=i+1;
            while(j<sortedProcess.size()){
                if(sortedProcess.get(i).priority==sortedProcess.get(j).priority){
                    readyqueue.add(sortedProcess.get(i));
                    readyqueue.add(sortedProcess.get(j));
                }
                j++;
            }
            j=0;
            i++;
        }
        for(Process task : sortedProcess){
            System.out.println("Priority : "+task.priority);
        }
        System.out.println("Size");
        System.out.println(readyqueue.size());
        System.out.println(readyqueue.peek().priority);
        



    }

}
