#include<stdio.h>
#include<stdbool.h>

int min(int status[],int f)
{
    int m=0,c;
    for (c = 1; c < f; c++)
    if (status[c] < status[m])
      m = c;
 return m;
}
void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

}

void pg_fault(int n, int f, int pg[], int fr[])
{
    int i,j,count=0,status[f],a=0;
    bool flag;
    for(i=0;i<f;i++)
		status[i]=0;

    for(i=0;i<n;i++)
    {
        flag=true;
		for(j=0;j<f;j++)
               if(fr[j]==pg[i])
                    {
                        flag=false;
                        a+=1;
                        status[j]=a;
                    }

        if(flag)
        {
            j=min(status,f);
            fr[j]=pg[i];
            a+=1;
            status[j]=a;
            count++;
        }
        else
            continue;

    }
printf("No.of page faults are %d",count);
}

int main()
{
	int n,f,i;
	printf("Enter the no. of pages:");
	scanf("%d",&n);
	printf("Enter the no. of frames:");
	scanf("%d",&f);
	printf("Enter the page references:");
	int pg[n], fr[f];
	for(i=0;i<n;i++)
		scanf("%d",&pg[i]);
	for(i=0;i<f;i++)
		fr[i]=-1;
    printf("page references:");print(pg,n);
    pg_fault(n,f,pg,fr);
}
