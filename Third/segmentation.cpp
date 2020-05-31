#include<bits/stdc++.h>
using namespace std;

struct segment
{
    int sNum;
    int sBase;
    int sLimit;
};

bool sortByBase(segment s1, segment s2)
{
    return (s1.sBase<s2.sBase);
}


int main()
{
    int numSegment, sizeSegment, physicalMemorySize, logicalSegNum, logicalOffset,physicalBase,physicalAddress, totalSegmentSize=0;
    int i,j;
    printf("Enter Number Of Segments : ");
    scanf("%d", &numSegment);

    int segmentSize[numSegment];

    for(i=0;i<numSegment;i++)
    {
        printf("Enter Segment Size Of Segment %d : ", i);
        scanf("%d", &segmentSize[i]);
        totalSegmentSize = totalSegmentSize+segmentSize[i];
    }

    printf("Enter Physical Memory Size : ");
    scanf("%d", &physicalMemorySize);
    if(totalSegmentSize > physicalMemorySize)
    {
        printf("Invalid Input\n");
        goto endProg;
    }

    //int physicalMemoryData[physicalMemorySize];
    segment segTable[numSegment];

    for(int i=0;i<numSegment;i++)
    {
        printf("Enter base of segment %d : ", i);
        scanf("%d", &segTable[i].sBase);
        //printf("Enter limit of segment %d : ", i);
        //scanf("%d", &segTable[i].sLimit);
        segTable[i].sLimit = segmentSize[i];
        segTable[i].sNum = i;
        if(segTable[i].sBase+segTable[i].sLimit>physicalMemorySize)
        {
            printf("Invalid Input\n");
            goto endProg;
        }
    }

    scanf("%d %d",&logicalSegNum, &logicalOffset);

    if(logicalOffset>segTable[logicalSegNum].sLimit)
    {
        printf("Invalid Input\n");
        goto endProg;
    }

    physicalBase = segTable[logicalSegNum].sBase;
    physicalAddress = physicalBase+logicalOffset;

    printf("%d\n", physicalAddress);

    //--------------------------------------------

    printf("\n\nLogical Address\n");
    printf("---------------------------\n");
    for(i=0;i<numSegment;i++)
    {
        printf("| Segment %d\t|  %d\t|\n", i, segTable[i].sLimit);
        printf("---------------------------\n");
    }
    //-----------------------------------------------
    printf("\n\nSegment Table\n");
    printf("---------------------------------\n");
    for(i=0;i<numSegment;i++)
    {
        printf("| Segment %d\t|  %d\t|  %d\t|\n", i, segTable[i].sBase, segTable[i].sLimit);
        printf("---------------------------------\n");
    }
    //printf("------------------------------------------------------\n");

    //-----------------------------------------------
    printf("\n\nPhysical Memory\n");
    sort(segTable, segTable+numSegment,sortByBase);
    printf("---------------------------------\n");
    j=0;
    for(i=0;i<physicalMemorySize;i++)
    {
        if(segTable[j].sBase != i)
        {
            if(segTable[j].sBase-1<1000)
            {
                printf("| %d-%d\t\t|  No Segment\t|\n", i, segTable[j].sBase-1);
                printf("---------------------------------\n");
            }
            else
            {
                printf("| %d-%d\t|  No Segment\t|\n", i-1, segTable[j].sBase-1);
                printf("---------------------------------\n");
            }
        }
        //------------------
        if(segTable[j].sBase<10)
        {
            printf("| %d-%d\t\t|  Segment %d\t|\n", segTable[j].sBase, segTable[j].sBase+segTable[j].sLimit-1, segTable[j].sNum);
        }
        else
        {
            printf("| %d-%d\t|  Segment %d\t|\n", segTable[j].sBase, segTable[j].sBase+segTable[j].sLimit-1, segTable[j].sNum);
        }
        i= segTable[j].sBase+segTable[j].sLimit;
        //printf("%d\n",i);
        j++;
        printf("---------------------------------\n");
        if(j==numSegment)
        {
            if(i==physicalMemorySize)
            {
                break;
            }
            else
            {
                printf("| %d-%d\t|  No Segment\t|\n", i+1, physicalMemorySize-1);
                printf("---------------------------------\n");
                break;
            }
        }
        //
        //printf("| Segment %d\t|  %d\t|  %d\t|\n", i, segTable[i].sBase, segTable[i].sLimit);
        //printf("-----------------------------------------\n");
    }

    endProg:
    return 0;
}
