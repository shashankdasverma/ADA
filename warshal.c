#include<stdio.h>
#include<conio.h>
int n,a[10][10],p[10][10];

void warshall(int n,int a[10][10],int p[10][10])
{
int i,j,k;
for(i=0;i<n;i++)
      for(j=0;j<n;j++)
	  p[i][j]=a[i][j];

    for(k=0;k<n;k++)
       for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	     if((p[i][j]==0) && (p[i][k]==1 && p[k][j]==1))
		p[i][j]=1;
}
void main()
{
    int i,j;
    clrscr();
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
	 scanf("%d",&a[i][j]);
       }
     }
     warshall(n,a,p);
     printf("trasitive closure\n");
     for(i=0;i<n;i++)
     {
	 for(j=0;j<n;j++)
	 {
	      printf("%d\t",p[i][j]);
	 }
	 printf("\n");
     }
     getch(); 
}
