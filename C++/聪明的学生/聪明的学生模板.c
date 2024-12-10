#include<stdio.h>
#include<stdlib.h>
int steps(int s1,int s2)
{
    if(s2>s1)
        return s2-s1;
    else
        return s2+3-s1;
}
int times(int i,int j,int s1,int s2,int s3)
{
    int number;
    number = i-j;
    if(number==0)
    return s3;
    if(number>0)
	return times(j,i-j,s2,s3,s1)+steps(s1,s3);
	if(number<0)
	return times(i,j-i,s1,s3,s2)+steps(s2,s3);
}
int main()
{
    int number,index,a,b,c;
    int max,dmax;
    int max_dex=-1,dmax_dex=-1;
    int arr[4]={-1};
    for(index=1;index<4;index++)
    {
        scanf("%d,",&arr[index]);
    }
    dmax=arr[0];
    for(index=1;index<4;index++)
    {
    	if(dmax<arr[index])
    	{
    		max=dmax;
    		max_dex=dmax_dex;
    		dmax=arr[index];
    		dmax_dex=index;
		}
	}
	b=max_dex;
	c=dmax_dex;
	if(b!=1&&c!=1)
	a=1;
	else if(b!=2&&c!=2)
	a=2;
	else a=3;
	number=times(arr[b],arr[c],a,b,c);
	printf("%d",number);
}