#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,p,pageUnit,ph,i,j,logicalAdress,logicalMemoryPage,pageTableIndex,pageOffset,physicalMemoryPage,physicalMemoryAddress,out ;
    printf("Logical memory size :");
    scanf("%d", &l);
    printf("Physical memory size :");
    scanf("%d", &ph);
    printf("Page unit size :");
    scanf("%d", &pageUnit);

    p=l/pageUnit;
    if(l%pageUnit!=0)
    {
        p++;
    }

/**
    p=ph/pageUnit;
    if(ph%pageUnit!=0)
    {
        p++;
    }
    **/
    int logicalMemory[l];
    int pageTable[p];
    int physicalMemory[ph];
/**
    for(i=0;i<p;i++)
    {
        printf("Page Table index %d : ", i);
        scanf("%d", &pageTable[i]);
    }
    **/

    //-----------------------------
    int pt = ph/pageUnit;
    int temp;
    for(i=0;i<p;i++)
    {
        pageTable[i]=l+1;
    }
    for(i=0;i<pt;i++)
    {
        printf("Page number ");
        scanf("%d", &temp);
        printf("  Frame Number ");
        scanf("%d", &pageTable[temp]);
        if(pageTable[temp]>=pt)
        {
            printf("Invalid Input\n");
        }
    }
    //----------------------------
    printf("Enter logical address = ");
    scanf("%d", &logicalAdress);

    logicalMemoryPage = l/pageUnit;

    pageTableIndex = logicalAdress/ pageUnit;
    pageOffset = logicalAdress%pageUnit;

    physicalMemoryPage = pageTable[pageTableIndex];

    physicalMemoryAddress = physicalMemoryPage*pageUnit+pageOffset;

    if(physicalMemoryAddress>ph)
        printf("Not Found");
    else
        printf("\nPhysical Memory Address : %d\n",physicalMemoryAddress);

    //-----------------------------------------------
    printf("\n\nLogical Memory\n------------------------------------------\n");

    for(i=0;i<l;i++)
    {
        if(i+pageUnit-1<=999)
        {
            if(i+pageUnit-1>l)
            {
                out = l;
            }
            else
            {
                out = i+pageUnit-1;
            }

            printf("|\t%d-%d\t\t|  Page %d\t|\n", i,out, i/pageUnit);
        }

        else
        {
            if(i+pageUnit-1>l)
            {
                out = l;
            }
            else
            {
                out = i+pageUnit-1;
            }
            printf("|\t%d-%d\t|  Page %d\t|\n", i,out, i/pageUnit);
        }
        i=i+pageUnit-1;

        printf("------------------------------------------\n");
    }

    printf("\n\nPage Table\n-------------------------------------------\n");


    for(i=0;i<p;i++)
    {
        printf("|\t%d\t|\t%d\t\t|\n", i, pageTable[i]);
        printf("------------------------------------------\n");
    }

    printf("\n\nPhysical\n------------------------------------------\n");

    for(i=0;i<ph;i++)
    {
        if(i+pageUnit<=999)
        {
            if(i+pageUnit-1>ph)
            {
                out = ph;
            }
            else
            {
                out = i+pageUnit-1;
            }

            printf("|\t%d-%d\t\t|  Frame %d\t|\n", i,out, i/pageUnit);
        }

        else
        {
            if(i+pageUnit-1>ph)
            {
                out = ph;
            }
            else
            {
                out = i+pageUnit-1;
            }
            printf("|\t%d-%d\t|  Frame %d\t|\n", i,out, i/pageUnit);
        }
        i=i+pageUnit-1;

        printf("------------------------------------------\n");
    }
    return 0;
}
