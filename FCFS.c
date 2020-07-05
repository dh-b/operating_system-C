#include<stdio.h>

void insertsort(int arr[], int n,int p[], int burst[]) 
{ 
    int i, key,key1,key2, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        key1=p[i];
        key2=burst[i];
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            p[j + 1] = p[j]; 
            burst[j + 1] = burst[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key;
        p[j + 1] = key1;
        burst[j + 1] = key2; 
    } 
} 

void avg(int n, int arr[])
{
	int i;
	float sum = 0;
	for(i =0; i<n; i++)
	{
		sum = sum + arr[i];
	}

	float a = sum / n;
	
	printf("%f \n", a);
} 
 
void WT(int n, int t[], int b[])
{
	int i;
	int w[n];
	
	for(i=0; i<n; i++)
	{
		w[i] = t[i] - b[i] ;
	}
	
	printf("The waiting time of the processes are : \n");
	print(w, n);
	
	printf("The average waiting time is : \n");
	avg(n, w);
}

void TAT(int n, int c[], int a[], int b[])
{
	int i;
	int t[n];
	
	for(i=0; i<n; i++)
	{
		t[i] = c[i] - a[i] ;
	}
	
	printf("The turn around time of the processes are : \n");
	print(t, n);

	printf("The average Turn around time is : \n");
	avg(n, t);
	
	WT(n, t, b);
}
 

void print(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void completion_time(int burst[],int n,int arr[])
{

	int c[n];
	int i,count=0;
	for(i=0;i<n;i++)
		c[i]=0;
	
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			if(arr[i]!=0)
			c[i]=burst[i]+count+arr[i];
			count=count+burst[i]+arr[i];
		}
		
		
		else 
		{
			if(arr[i]==c[i-1])
			{
				c[i]=burst[i]+count;
				count=count+burst[i];
			}
			else
			{	
				if(arr[i]>c[i-1])
				{
					c[i]=burst[i]+count+(arr[i]-c[i-1]);
					count=count+burst[i]+(arr[i]-c[i-1]);
				}
				if(arr[i]<c[i-1])
				{
					c[i]=burst[i]+count;
					count=count+burst[i];
				}
			}
		}
	}
	print(c,n);
	TAT(n, c, a, b);
	
	float x = c[n-1];
	//printf("%d", x);
	float tp;
	tp = n/x;
	
	printf("The throughput of the processes is : \n");
	printf("%f \n", tp);
}
int main()
{
	int n,i;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	int p[n],arr[n],burst[n];
	printf("Enter the process IDs of each respectively\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	printf("Enter the arrival times of each respectively\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the burst times of each respectively\n");
	for(i=0;i<n;i++)
		scanf("%d",&burst[i]);
	insertsort(arr,n,p,burst);
	printf("Process ID:     ");print(p,n);
	printf("Arrival time:   ");print(arr,n);
	printf("Burst time:     ");print(burst,n);
	printf("Completion time:");completion_time(burst,n,arr);
	
	

}
