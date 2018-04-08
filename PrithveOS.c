#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    printf("Enter number of Process\n");
    scanf("%d",&n);
    int BT[n],Pr[n],Ps[n];
    int RT[n],CT[n];
    int WT[n],ESWT[n];
    int TRT[n];
    int AvgWT=0,AvgTRT=0;
    int i,j;
    printf("All Process are Arriving at time \"0\"\n");
    for(i=0;i<n;i++)
    {
        printf("Enter Brust Time of Process P%d\n",i+1);
        scanf("%d",&BT[i]);
        RT[i] = BT[i];
        Ps[i] = i+1;
    }
    int temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(BT[i]>BT[j])
            {
                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                temp = RT[i];
                RT[i] = RT[j];
                RT[j] = temp;

                temp = Ps[i];
                Ps[i] = Ps[j];
                Ps[j] = temp;
            }
        }
    }
    int m;
    for(i=0,m=n;i<n;i++,m--)
    {
        Pr[i] = m;
    }
    for(i=0;i<n;i++)
    {
        CT[i] = 0;
        for(j=0;j<=i;j++)
        {
            CT[i] = CT[i] + BT[j];
        }
        ESWT[i] = CT[i] - BT[i];
    }
    for(i=1;i<n;i++)
    {
        Pr[i] = 1 + (ESWT[i]/BT[i]);
    }
    Pr[0] == n;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(Pr[i]<Pr[j])
            {
                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                temp = RT[i];
                RT[i] = RT[j];
                RT[j] = temp;

                temp = Ps[i];
                Ps[i] = Ps[j];
                Ps[j] = temp;

                temp = Pr[i];
                Pr[i] = Pr[j];
                Pr[j] = temp;
            }
            else if(Pr[i] == Pr[j] && BT[i]>BT[j])
            {
                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                temp = RT[i];
                RT[i] = RT[j];
                RT[j] = temp;

                temp = Ps[i];
                Ps[i] = Ps[j];
                Ps[j] = temp;

                temp = Pr[i];
                Pr[i] = Pr[j];
                Pr[j] = temp;
            }
        }
    }
    printf("-------------------Process Execution:------------------\n");
    int time=0;
    for(i=0;i<n;i++)
    {
        WT[i] = 0;
        TRT[i] = 0;
        printf("P%d with Priority %d and it time of Execution is : %d - %d\n",Ps[i],Pr[i],time,time+BT[i]);
        time = time + BT[i];
        TRT[i] = time;
        WT[i] = TRT[i] - BT[i];
    }
    printf("\n");
    printf("Processes  Waiting Time of Processes:      ||      Turn Around Time of Processes: \n");
    int a;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==(Ps[j]-1))
            {
                a=i;
                i=j;
                break;
            }
        }
        printf("P%d : \t\t%d\t\t\t\t\t %d\n",Ps[i],WT[i],TRT[i]);
        AvgWT = AvgWT + WT[i];
        AvgTRT = AvgTRT + TRT[i];
        i=a;
    }
    printf("Average Waiting Time : %d\n",AvgWT/n);
    printf("Average Trun Around Time : %d\n",AvgTRT/n);
}
