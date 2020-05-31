#include<bits/stdc++.h>
using namespace std;

struct process{
    string pName;
    int pArrivalTime;
    int pBurstTime;
    //int pPriority;
    //int pTimeQuantam;
    int pTurnAroundTime=0;
    int pIndividualWaitingTime=0;
    //int pStart;
    int pEnd;
    int pNum;
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
    int n,i,j,r,time, totalWaitingTime=0;
    double averageWaitingTime;
    cout<<"Input total number of process : ";
    cin>>n;
    process a[n];

    int totalburst = 0;



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
    }

    sort(a,a+n,sortByArrivalTime);

    int result[totalburst];
    for(i=0;i<(totalburst+n+1);i++)
    {
        printf("-");
    }
    cout<<endl;
    printf("|");
    i=0;
    time = a[i].pArrivalTime;
    //i=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<a[i].pBurstTime;j++)

        {
            if(j == a[i].pBurstTime/2)
            {
                cout<<a[i].pName;
                time++;
            }
            else
            {
                printf(" ", r);
                time++;
            }
        }
        a[i].pEnd = time;
        printf("|");
    }
    cout<<endl;
    for(i=0;i<(totalburst+n+1);i++)
        {
            printf("-");
        }
        //-------------------------
cout<<endl;
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

//---------------------------------------------------------------
/**
    for(i=0;i<n;i++)
    {
        a[i].pIndividualWaitingTime=0;
        for(j=0;j<=i;j++)
        {
            a[i].pIndividualWaitingTime=a[i].pIndividualWaitingTime+a[j].pBurstTime;
        }
        a[i].pIndividualWaitingTime=a[i].pIndividualWaitingTime-a[i].pBurstTime- a[i].pArrivalTime;
        a[i].pTurnAroundTime = a[i].pIndividualWaitingTime+ a[i].pBurstTime;
        totalWaitingTime = totalWaitingTime + a[i].pIndividualWaitingTime;
//        cout<<"Process Name : "<<a[i].pName<<" Waiting time : "<<a[i].pIndividualWaitingTime<<" Turnaround Time :"<<a[i].pTurnAroundTime<<endl;

    }



    sort(a,a+n,sortByNum);

    for(i=0;i<n;i++)
    {

        cout<<"Process Name : "<<a[i].pName<<" Waiting time : "<<a[i].pIndividualWaitingTime<<" Turnaround Time :"<<a[i].pTurnAroundTime<<endl;

    }
    **/
    //---------------------------------------------
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


/**
    for(i=0;i<n;i++)
    {
        cout<<a[i].pName<<endl;
        cout<<a[i].pArrivalTime<<endl;
        cout<<a[i].pBurstTime<<endl;
        cout<<a[i].pPriority<<endl;
        cout<<a[i].pTimeQuantam<<endl;
    }
**/

    return 0;

}
