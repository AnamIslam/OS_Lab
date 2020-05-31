#include<bits/stdc++.h>
using namespace std;

struct process{
    string pName;
    int pArrivalTime;
    int pBurstTime;
    int pPriority;
    //int pTimeQuantam;
    int pTurnAroundTime=0;
    int pIndividualWaitingTime=0;
    int pBurstTemp;
    int pEnd;
    int pNum;
    //int pUsed = 0;
};

bool sortByArrivalTime(process time1, process time2)
{
    return (time1.pArrivalTime<time2.pArrivalTime);
}

bool sortByNum(process num1, process num2)
{
    return (num1.pNum<num2.pNum);
}

int main()
{
    int n,i,j,k,tq, totalburst=0, line =1, totalWaitingTime=0,time,endTime;
    double averageWaitingTime;
    cout<<"Input total number of process : ";
    cin>>n;
    process a[n];
    cout<<"Input time quantum : ";
    cin>>tq;
     for(i=0;i<n;i++)
    {
        cout<<"Enter process name :";
        cin>>a[i].pName;
        cout<<"Enter arrival time :";
        cin>>a[i].pArrivalTime;
        cout<<"Enter burst time :";
        cin>>a[i].pBurstTime;
        //cin>>a[i].pPriority;
        //cin>>a[i].pTimeQuantam;
        totalburst = totalburst+a[i].pBurstTime;
        a[i].pNum = i;
        a[i].pBurstTemp=a[i].pBurstTime;
        line=line+a[i].pBurstTime+(a[i].pBurstTime+2)/3;

        if(i==0)
        {
            time = a[i].pArrivalTime;
        }
        else
        {
            if(time>a[i].pArrivalTime)
            {
                time = a[i].pArrivalTime;
            }
        }
    }

    sort(a,a+n,sortByArrivalTime);

    int m[line];

    for(i=0;i<line;i++)
    {
        m[i]=0;
    }

    //cout<<"m[0] : "<<m[0]<<endl;



    for(i=0;i<line;i++)
    {
        printf("--");
    }
    cout<<endl;
    //time=0;
    i=0;
    endTime = time+totalburst;
    printf("||");
    m[time]=1;
    while(time!=endTime)
    {

        if(a[i].pBurstTemp >= tq && a[i].pArrivalTime<=time)  //j = time
        {
            for(k=0;k<tq;k++)
            {
                printf("%d ", a[i].pNum+1);
                a[i].pBurstTemp--;
                time++;
                if(k==tq-1)
                {
                    printf("||");
                    m[time]=1;
                }
                if(a[i].pBurstTemp == 0)
                {
                    a[i].pEnd=time;
                }
            }
        }
        else
        {
            for(k=0;k<a[i].pBurstTemp;k++)
            {
                printf("%d ", a[i].pNum+1);
                //a[i].pBurstTemp--;
                time++;
                if(k==a[i].pBurstTemp-1)
                {
                    a[i].pBurstTemp=0;
                    a[i].pEnd = time;
                    m[time]=1;
                    printf("||");
                }
            }
        }
        i++;
        i=i%n;
    }
    cout<<endl;
    for(i=0;i<line;i++)
    {
        printf("--");
    }
    cout<<endl;
    int flag = 0;
    for(j=0;j<line;j++)
    {
        if(m[j]==1)
        {
            if(flag!=0)
            {
                cout<<" ";
            }
            cout<<j<<"  ";
            flag = 1;
        }
        else
        {
            if(flag!=0)
            {
                cout<<"  ";
            }

        }
    }
    cout<<endl;

    sort(a,a+n,sortByNum);

    for(i=0;i<n;i++)
    {
        //cout<< "Process end "<< a[i].pEnd<<endl;
        a[i].pTurnAroundTime= a[i].pEnd-a[i].pArrivalTime;
        a[i].pIndividualWaitingTime =  a[i].pTurnAroundTime - a[i].pBurstTime;
        totalWaitingTime = totalWaitingTime + a[i].pIndividualWaitingTime;
        cout<<"Process Name "<< a[i].pName << " Turnaround Time : "<<a[i].pTurnAroundTime<<" Individual Waiting Time "<< a[i].pIndividualWaitingTime<<endl;
    }

    cout<<"Total Waiting Time : "<< totalWaitingTime<< endl;
    averageWaitingTime = (double)totalWaitingTime/n;
    cout<<"Average Waiting Time : "<< averageWaitingTime<< endl;
    return 0;
}
