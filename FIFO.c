#include<stdio.h>
#include<stdbool.h>

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

}


void pg_fault(int n, int f,int pg[],int fr[])
{
	int count=0,i,j,k;
	bool flag;
	for(i=0;i<n;i++)
	{
	    flag=true;
		k=i%f;
		for(j=0;j<f;j++)
           if(fr[j]==pg[i])
               flag=false;

        if(flag)
        {
            fr[k]=pg[i];
            count++;
        }
        else
            continue;
	}
printf("The no. of page faults are %d",count);

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
