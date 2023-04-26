#include<stdio.h>
#include<conio.h>
void optimal(int s[10][10],int i,int j);
void mcm(int n, int p[10])
{
int k,i,j,m[10][10],temp,s[10][10];
for(j=1;j<=n;j++)
{
for(i=n;i>=1;i--)
{
if(i==j)
{
m[i][j]=0;
}
else if(i<j)
{
m[i][j]=9999;
for(k=i;k<=j-1;k++)
{
temp=m[i][k]+m[k+1][j]+(p[i-1]*p[j]*p[k]);
if(temp<m[i][j])
{
m[i][j]=temp;
s[i][j]=k;
}
}
}
}
}
printf("\n M-Table \n");
for(i=1;i<n;i++)
{
for(j=1;j<n;j++)
{
if(i>j)
{
printf("\t");
}
else
{
printf("%d\t",m[i][j]);
}
}
printf("\n");
}
printf("\n S-Table \n");
for(i=1;i<n;i++)
{
for(j=2;j<n;j++)
{
if(i>=j)
{
printf("\t");
}
else
{
printf("%d\t",s[i][j]);
}
}
printf("\n");
}
printf("\n Answer \n");
optimal(s,1,n-1);
}
void optimal(int s[10][10],int i,int j)
{
if(i==j)
{
printf("A%d ",i);
}
else
{
printf(" ( ");
optimal(s,i,s[i][j]);
optimal(s,s[i][j]+1,j);
printf(" ) ");
}
}
void main()
{
int n,p[10],i;
printf("Enter the number of elements");
scanf("%d",&n);
printf("Enter value of elements\n");
for(i=0;i<n;i++)
{
printf("Enter value of element[%d]:",i);
scanf("%d",&p[i]);
}
mcm(n,p);
getch();
}
