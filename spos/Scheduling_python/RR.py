
# ----------------Round Robin---------------------
def find_waiting_time(n, bt, wt, quantum):
    rem_bt = [0] * n
    for i in range(n):
        rem_bt[i] = bt[i]
    t = 0
    while True:
        done = True
        for i in range(n):
            if rem_bt[i] > 0:
                done = False

                if rem_bt[i] > quantum:
                    t += quantum
                    rem_bt[i] -= quantum
                else:
                    t = t + rem_bt[i]
                    wt[i] = t - bt[i]
                    rem_bt[i] = 0
        if done:
            break
        
def find_turn_around_time(n, bt, wt, tat):
    for i in range(n):
        tat[i] = bt[i] + wt[i]
        
def find_avg_time(n, bt, quantum):
    wt = [0] * n
    tat = [0] * n
    find_waiting_time(n, bt, wt, quantum)
    find_turn_around_time(n, bt, wt, tat)
    print("Processes Burst Time   Waiting Time Turn-Around Time")
    total_wt = 0
    total_tat = 0
    for i in range(n):
        total_wt += wt[i]
        total_tat += tat[i]
        print(" ", i + 1, "\t\t", bt[i], "\t\t", wt[i], "\t\t", tat[i])
    print("\nAverage waiting time = %.5f" % (total_wt / n))
    print("Average turn around time = %.5f" % (total_tat / n))
    
n = 3
burst_time = [10, 5, 8]
quantum = 2
find_avg_time(n, burst_time, quantum)
