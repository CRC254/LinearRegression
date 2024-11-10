#include<stdio.h>
#define afa 0.01
#define m 10

double x,y;
int main(){
	double x_sum=0,y_sum=0,xsq_sum=0,xy_sum=0;
	for(int i=0;i<m;i++)
	{
		scanf("%lf%lf",&x,&y);
		x_sum+=x,y_sum+=y,xsq_sum+=x*x,xy_sum+=x*y;
	}
	double w=0,b=0,w_hat,b_hat;
	for(int i=1;i<1000000;i++)
	{
		w_hat=(1-afa*xsq_sum/m)*w-afa*x_sum*b/m+afa*xy_sum/m;
		b_hat=(1-afa)*b-afa*x_sum*w/m+afa*y_sum/m;
		w=w_hat,b=b_hat;
	}
	printf("y=%.2lfx+%.2lf",w,b);
	return 0;
}
/*
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 10
*/

