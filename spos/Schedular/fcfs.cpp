#include<iostream>
#include<string.h>
using namespace std;

void FCFS(int n,int BT[],string p[])
{
    int Arrival_time=0,Finish_time[10],TA[10],WT[10];
    float cnt=0,count=0;
    for (int i = 0; i<n; i++)
    {
        if(i==0)
        {   Finish_time[i]=BT[i];
            TA[i]=Finish_time[i]-Arrival_time;
        }
        else
        {
            Finish_time[i]=BT[i]+Finish_time[i-1];
            TA[i]=Finish_time[i]-Arrival_time;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"  "<<p[i]<<"  ";
    }
    cout<<endl<<"0";
    for(int i=0;i<n;i++)
    {
        cout<<"    "<<TA[i];
    }
    cout<<endl;
    cout<<"TURN-AROUND TIME "<<endl;
    for (int i = 0; i<n; i++)
    {
        cout<<"Turn-around time of "<<p[i]<<"= "<<TA[i]<<" msec"<<endl;
    }
    for (int i = 0; i<n; i++)
    {
        cnt+=TA[i];
    }
    cnt=cnt/n;
    cout<<"Average Turn-around time of = "<<cnt<<" msec"<<endl;
    cout<<endl;
    for (int i = 0; i<n; i++)
    {
        WT[i]=TA[i]-BT[i];
        cout<<"Waiting time of "<<p[i]<<"= "<<WT[i]<<" msec"<<endl;
    }
    for (int i = 0; i<n; i++)
    {
        count+=WT[i];
    }
    count=count/n;
    cout<<"Average Waiting time of = "<<count<<" msec"<<endl;
}

int main()
{
    int n, BT[10];
    string p[10];
    cout<<"Enter the number of process: ";
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        cout<<"Enter the process name: ";
        cin>>p[i];
        cout<<"Enter the Burst time :";
        cin>>BT[i];
    }
    
    FCFS(n,BT,p);
    return 0;
}