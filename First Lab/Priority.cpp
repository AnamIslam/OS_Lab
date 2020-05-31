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
    int pStart;
    int pEnd;
    int pNum;
    int pUsed = 0;
};
bool sortByPriority(process time1, process time2)
{
    return (time1.pPriority<time2.pPriority);
}

bool sortByNum(process num1, process num2)
{
    return (num1.pNum<num2.pNum);
}

bool sortByEnd(process num1, process num2)
{
    return (num1.pEnd<num2.pEnd);
}

int main()
{
    int n,i,j,k,r,time,totalburst=0,totalWaitingTime=0;
    double averageWaitingTime;
    cout<<"Input total number of process : ";
    cin>>n;
    process a[n];

   for(i=0;i<n;i++)
    {
        cout<<"Enter process name :";
        cin>>a[i].pName;
        cout<<"Enter arrival time :";
        cin>>a[i].pArrivalTime;
        cout<<"Enter burst time :";
        cin>>a[i].pBurstTime;
        cout<<"Enter priority :";
        cin>>a[i].pPriority;
        //cin>>a[i].pTimeQuantam;
        totalburst = totalburst+a[i].pBurstTime;
        a[i].pNum = i;

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

    sort(a,a+n,sortByPriority);

     for(i=0;i<(totalburst+n+1);i++)
    {
        printf("-");
    }

    cout<<endl;
    //time = 0;
    printf("|");
    for(k=0;k<n;k++)
    {
        for(i=0;i<=n;i++)
        {
            if(a[i].pArrivalTime<=time)
            {
                if(a[i].pUsed == 0)
                {
                    a[i].pUsed = 1;
                    for(j=0;j<a[i].pBurstTime;j++)
                    {
                        //cout<<a[i].pNum;
                        if(j == a[i].pBurstTime/2)
                        {
                            cout<<a[i].pName;
                        }
                        else
                        {
                            cout<<" ";
                        }

                        time++;
                    }
                    if(j==a[i].pBurstTime)
                    {
                        a[i].pEnd = time;
                        break;
                    }
                }
            }
        }
        printf("|");
    }
    cout<<endl;
    for(i=0;i<(totalburst+n+1);i++)
    {
        printf("-");
    }
    cout<<endl;
    //----------------------------------------
    //cout<<endl;
    sort(a,a+n,sortByEnd);
    i=0;
    time++;
    cout<<a[i].pArrivalTime;
    for(i=0;i<n;i++)
    {

        for(j=0;j<a[i].pBurstTime;j++)
        {
            cout<<" ";
        }
        cout<<a[i].pEnd;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    //--------------------------------------------

    sort(a,a+n,sortByNum);

    for(i=0;i<n;i++)
    {
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
