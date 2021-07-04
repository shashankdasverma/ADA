#include <stdio.h>
#include <conio.h>
voidbottom_up_heapify(int n, int a[], int p)
{
	intitem,c;
	item=a[p];
	c=2*p+1;
	while(c<=n-1)
	{
		if(c+1<=n-1)
		{
			if(a[c]<a[c+1])
				c++;
		}
		if(item<a[c])
		{
			a[p]=a[c];
			p=c;
			c=2*p+1;
		}
		else
			break;
	}
	a[p]=item;
}
voidtop_down_heapify(int n, int a[])
{
	intk,c,key,p;
	for(k=1;k<n;k++)
	{
		key=a[k];
		c=k;
		p=(c-1)/2;
		while(c>0 && key>a[p])
		{
			a[c]=a[p];
			c=p;
			p=(c-1)/2;
		}
		a[c]=key;
	}
}
voidheap_sort(int n, int a[])
{
	inti,temp;
	for(i=n-1;i>0;i++)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		bottom_up_heapify(i,a,0);
	}
}
void main()
{
	inti,n,a[20];
	clrscr();
	printf("Enter the value of n\n");
	scanf("%d", &n);
	printf("Enter the elements to sort\n");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	top_down_heapify(n,a);
	heap_sort(n,a);
	printf("The sorted vector is\n");
	for(i=0;i<n;i++)
		printf("%d", &a[i]);
	getch();
}
