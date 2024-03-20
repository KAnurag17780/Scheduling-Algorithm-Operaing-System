// code  for fcfs but only works for sorted arrivl time!!!!
#include <stdio.h>
typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void findcompletiontime(Process p[],int n)
{
    p[0].completion_time = p[0].burst_time;
    for(int i =1 ;i<n;i++)
    {
        p[i].completion_time = p[i-1].completion_time + p[i].burst_time;

    }
   
}

 void findturnaroundtime(Process p[],int n)
    {       
            for(int i =0 ; i<n;i++)
            p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
    }

void findwaitingtime(Process p[],int n)
{
    p[0].waiting_time = 0;
    for (int i = 1; i < n; i++)
    {
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time; 
    }
    
}

void findFCFS(Process p[], int n)
{
    findcompletiontime(p,n);
    findturnaroundtime(p,n);
    findwaitingtime(p,n); 



    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].process_id, p[i].arrival_time,
               p[i].burst_time, p[i].completion_time, p[i].turnaround_time,
               p[i].waiting_time);
    }
}




void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortFCFS(Process p[], int n) {
    // Sorting the processes based on arrival time using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}







int main()
{
    int n;
    printf("Enter the number of processes \n");
    scanf("%d",&n);

    Process p[n];

     for (int i = 0; i < n; i++) {
        p[i].process_id = i + 1;
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
    }

    // Sort the processes based on arrival time
    sortFCFS(p, n);

    

   
    findFCFS(p,n);

}
