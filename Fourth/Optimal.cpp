#include<bits/stdc++.h>
using namespace std;

struct frameSingle
{
    char frameValue;
    int frameNP;
};

int main()
{
    int i,j, numPage,numFrame, pagefault=0, hasIt,pff=0, change,k, found;

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
                hasIt=1;

                for(k=i+1;k<numPage;k++)
                {
                    found = 0;
                    if(page[k]==frame[j].frameValue)
                    {
                        frame[j].frameNP=k;
                        found = 1;
                        break;

                    }

                }
                if(found != 1)
                {
                    frame[j].frameNP = numPage+100;
                }
            }
        }

        if(hasIt !=1)
        {
            if(i<numFrame)
            {
                frame[i].frameValue=page[i];
                found = 0;
                for(k=i+1;k<numPage;k++)
                {
                    if(page[k]==frame[i].frameValue)
                    {
                        frame[i].frameNP=k;
                        found = 1;
                        break;
                    }
                }
                if(found!=1)
                {
                    frame[j].frameNP = numPage+100;
                }
                pagefault++;
                pff=1;
            }

            else
            {
                change = 0;
                for(j=1;j<numFrame;j++)
                {
                    if(frame[change].frameNP<frame[j].frameNP)
                    {
                        change = j;
                    }
                }
                frame[change].frameValue = page[i];
                found = 0;
                for(k=i+1;k<numPage;k++)
                {
                    if(page[k]==frame[change].frameValue)
                    {
                        frame[change].frameNP=k;
                        found = 1;
                        break;
                        //printf("Exp k = %d change = %d frame[change] = %d\n", k, change, frame[change]);
                    }
                }
                if(found !=1)
                {
                    frame[change].frameNP = numPage+100;
                }
                pagefault++;
                pff = 1;
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

    printf("Page Fault : %d\n" , pagefault);


    endprog:
    return 0;
}
