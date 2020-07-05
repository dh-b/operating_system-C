#include<stdio.h>
#define N 5
void compute(int i,int j,int p[],int avail[],int need[3][j],int alloc[3][j])
{
    int x,y,z,count=0,status=0;
    int flag=1;
    while(count<i)
    {
        status++;
        if(status>i)
        {
            printf("not in a safe state\n");
            break;
        }
        for(x=0;x<i;x++)
        {
            flag=1;
            for(y=0;y<j;y++)
            {
                if(need[x][y]<= avail[y] && flag==1 && count<i && alloc[x][y]!=-1)
                {
                    if(y==j-1)
                    {
                        for(z=0;z<j;z++)
                           {
                             avail[z]+=alloc[x][z];
                             alloc[x][z]=-1;
                           }
                        count++;
                        printf("%d-> ",p[x]);
                    }
                }
                else
                   {
                       flag=0;
                   }
            }
        }
    }

}
int main()
{
	int i=N,j,x=0,y=0;
	//printf("Enter the number of processes:\n");
	//scanf("%d",&i);
	printf("Enter the number of resources:\n");
	scanf("%d",&j);
	int alloc[i][j], max[i][j], need[i][j],avail[j], p[i];

	printf("Enter the process IDs for %d processes respectively\n",N);
	for(x=0;x<i;x++)
		scanf("%d",&p[x]);
	printf("Enter the available units for resources:\n");
	for(x=0;x<j;x++)
		scanf("%d",&avail[x]);

	for(x=0;x<i;x++)
	{
		printf("Enter the allocated resources for process %d respectively:\n" ,x);
		for(y=0;y<j;y++)
			scanf("%d",&alloc[x][y]);
	}

	for(x=0;x<i;x++)
	{
		printf("Enter the maximum resources for process %d respectively:\n" ,x);
		for(y=0;y<j;y++)
			scanf("%d",&max[x][y]);
	}

	for(x=0;x<i;x++)
	{
		for(y=0;y<j;y++)
			need[x][y]=max[x][y]-alloc[x][y];
	}

	//printf("Process ID   ");
	//for (x = 0; x < i; x++)
		//printf("%d ", p[x]);
	//printf("\n");

	printf("Allocated:   ");
	for(x=0;x<i;x++)
		{for(y=0;y<j;y++)
			printf("%d ",alloc[x][y]);
        printf("\n             ");
		}
	printf("\n");
	printf("Maximum:     ");
	for(x=0;x<i;x++)
		{for(y=0;y<j;y++)
			printf("%d ",max[x][y]);
        printf("\n             ");
        }
	printf("\n");
	printf("Needed:      ");
	for(x=0;x<i;x++)
		{for(y=0;y<j;y++)
			printf("%d ",need[x][y]);
        printf("\n             ");
		}
	printf("\n");

	compute(i,j,p,avail,need,alloc);
}
