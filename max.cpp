#include<stdio.h>
int Max(int x,int y);
void main()
{
	int a,b,c;
    scanf("%f,%f",&a,&b);
	c=Max(a,b);
	printf("Max=%f\n",c);
}

int Max(int x,int y)
{
    int z;
	if(x>y)
		z=x;
	else
		z=y;

	return z;
} 