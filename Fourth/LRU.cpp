#include<bits/stdc++.h>
using namespace std;

struct frameSingle
{
    int frameValue;
    int frameLP;
};

int main()
{
    int i,j, numPage,numFrame, pagefault=0, hasIt,pff=0, change;

    printf("Enter Number of Pages : ");
    scanf("%d", &numPage);

    int page[numPage];
    //string pageinput;

    //cin>>pageinput;

    for(i=0;i<numPage;i++)
    {
        scanf("%d", &page[i]);
    }
/**
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
    **/

    printf("Enter Number of Frames : ");

    scanf("%d", &numFrame);

    frameSingle frame[numFrame];

    for(i=0;i<numFrame;i++)
    {
        frame[i].frameValue=9999;
    }

    for(i=0;i<numPage;i++)
    {
        hasIt = 0;
        for(j=0;j<numFrame;j++)
        {
            if(frame[j].frameValue==page[i])
            {
                frame[j].frameLP = i;
                hasIt=1;
            }
        }

        if(hasIt!=1)
        {
            if(i<numFrame)
            {
                frame[i].frameValue=page[i];
                frame[i].frameLP = i;
                pagefault++;
                pff=1;
            }

            else
            {
                change = 0;
                for(j=1;j<numFrame;j++)
                {
                    if(frame[change].frameLP>frame[j].frameLP)
                    {
                        change = j;
                    }
                }
                frame[change].frameValue = page[i];
                frame[change].frameLP = i;
                pagefault++;
                pff = 1;
            }

        }

        printf("%d    ", page[i]);
        if(pff==1)
        {
            printf("|");
            for(j=0;j<numFrame;j++)
            {
                if(frame[j].frameValue==9999)
                {
                    printf("     |");
                }
                else
                {
                    printf("  %d  |", frame[j].frameValue);
                }
            }
            pff=0;
            hasIt=0;
        }
        printf("\n");


    }

     printf("Page Fault : %d", pagefault);

    endprog:
    return 0;
}
