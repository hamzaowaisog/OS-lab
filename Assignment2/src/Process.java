public class Process {
    String name;
    int priority;
    int bursttime;
    int waitingtime;
    int turnaroundtime;
    int starttime;
    int remainingtime;
    boolean executed;

    public Process(String name, int priority, int bursttime) {
        this.name = name;
        this.priority = priority;
        this.bursttime = bursttime;
        this.remainingtime = bursttime;
        this.waitingtime = 0;
        this.turnaroundtime = 0;
        this.starttime = 0;
        this.executed = false;
    }
}
