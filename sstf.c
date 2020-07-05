#include<stdio.h>
#include<stdlib.h>
void compute(int h,int n,int seq[])
{
    int min,i,j=0,count=0,total=0,x=n;

     while(count<x)
     {
          min=abs(h-seq[0]);

         for(i=1;i<n;i++)
         {

             if(abs(h-seq[i])<min)
               {
                    min=abs(h-seq[i]);
                    j=i;
               }
         }
                             printf("min=%d",min);

         total+=min;
         count++;
         h=seq[j];
         for(i=j;i<n;i++)
           if(i!=n-1)
                seq[i]=seq[i+1];
         n=n-1;
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
    compute(h,n,seq);
}
