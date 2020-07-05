#include<stdio.h>
#include<stdlib.h>

void insertsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void compute(int h,int n,int seq[])
{
    int min,i,j=0,count=0,total=0;
    printf("Seek sequence is:");
    while(count<=n)
    {
        for(i=0;i<n;i++)
        {
            if(count<=n)
            {
                if(h==0)
                    total+=199;
                if(seq[i]<h)
                    continue;
                if(h<seq[i])
                {
                    total+=seq[i]-h;
                    h=seq[i];
                    printf("%d\n",h);
                    count++;
                }
                if(i==n-1)
                  {
                    total+=199-seq[i];
                    h=0;
                  }
            }
            else
                break;
        }
    count++;
    }
    printf("total seek count = %d",total);
}
int main()
{
    int n,i,h;
    printf("Enter the no. of requests:\n");
    scanf("%d",&n);
    int seq[n];
    printf("Enter the request sequence\n");
    for(i=0;i<n;i++)
        scanf("%d",&seq[i]);
    printf("Enter the head pointer:\n");
    scanf("%d",&h);
    insertsort(seq,n);
    compute(h,n,seq);
}

