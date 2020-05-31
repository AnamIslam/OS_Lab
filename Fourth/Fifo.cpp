#include<bits/stdc++.h>
using namespace std;

struct frameSingle
{
    char frameValue;
    int frameNum;
};

int main()
{
    int i,j, numPage,numFrame, pagefault=0, hasIt,pff=0;

    printf("Enter Number of Pages : ");
    scanf("%d", &numPage);

    char page[numPage];
    string pageinput;

    cin>>pageinput;

    if(pageinput.length()>numPage)
    {
        goto endprog;
    }

    else
    {
        for(i=0;i<numPage;i++)
        {
            page[i]=pageinput[i];
        }
    }

    printf("Enter Number of Frames : ");

    scanf("%d", &numFrame);

    frameSingle frame[numFrame];

    for(i=0;i<numFrame;i++)
    {
        frame[i].frameValue=' ';
    }


    for(i=0;i<numPage;i++)
    {
        hasIt = 0;

        for(j=0;j<numFrame;j++)
        {
            if(frame[j].frameValue==page[i])
            {
                hasIt = 1;
            }
        }
        if(hasIt!=1)
        {

            if(i<numFrame)
            {
                frame[i].frameValue=page[i];
                pagefault++;
                pff=1;
                /**
                printf("%d Frame : ", i);
                for(j=0;j<numFrame;j++)
                {
                    printf("%c-", frame[j].frameValue);
                }
                printf("\n");
                **/

            }

            else
            {
                frame[pagefault%numFrame].frameValue=page[i];
                pagefault++;
                pff=1;
                /**
                printf("%d Frame : ", i);
                for(j=0;j<numFrame;j++)
                {
                    printf("%c-", frame[j]);
                }

                printf("\n");
                **/

            }
        }

        printf("%c    ", page[i]);
        if(pff==1)
        {
            printf("|");
            for(j=0;j<numFrame;j++)
            {
                printf("  %c  |", frame[j].frameValue);
            }
            pff=0;
            hasIt=0;
        }
        printf("\n");


    }

    printf("Page Fault : %d", pagefault);
    endprog :
    return 0;
}
