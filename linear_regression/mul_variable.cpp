#include<stdio.h>
#define p 4//变量个数
#define afa 0.01//学习率
#define m 10//每一批的数据组数
#define n 100000//步数

double x[p+1],y;
double x_sum[p+1][p+2];
double y_sum=0;
int main()
{
	x[0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=p;j++)
			scanf(" %lf",&x[j]);
		scanf(" %lf",&y);
		for(int k=1;k<=p;k++)
		{
			for(int j=0;j<=p;j++)
				x_sum[k][j]+=x[k]*x[j];
			x_sum[k][p+1]+=x[k]*y;
		}
		y_sum+=y;
	}
	/*
	x1 x1x1 x1x2 x1x3 ... x1y
	x2 x2x1 x2x2 x2x3 ... x2y
	.........................
	xp xpx1 xpx2 xpx3 ... xpy
	*/
	double w[p+1]={0},b=0;
	double w_hat[p+1],b_hat;
	for(int i=1;i<=n;i++)
	{
		b_hat=(1-afa)*b+afa*y_sum/m;
		for(int j=1;j<=p;j++)
			b_hat-=afa*w[j]*x_sum[j][0]/m;
		for(int j=1;j<=p;j++)
		{
			w_hat[j]=w[j]-afa*b*x_sum[0][j]/m+afa*x_sum[j][p+1]/m;
			for(int k=1;k<=p;k++)
				w_hat[j]-=afa*w[k]*x_sum[j][k]/m;
			w[j]=w_hat[j];
		}
		b=b_hat;
//			printf("\ny=");
//		for(int i=1;i<=p;i++)
//			printf("(%.2fx_%d)+",w[i],i);
//		printf("(%.2f)",b);
	}
	printf("\ny=");
	for(int i=1;i<=p;i++)
		printf("(%.2fx_%d)+",w[i],i);
	printf("(%.2f)",b);
	return 0;
}
/*
1 1 1 1 4
2 2 2 2 8
1 2 2 1 6
2 2 2 1 7
1 2 3 4 10
1 3 4 5 13
1 2 2 2 7
2 3 4 2 11
1 2 3 3 9
5 6 3 2 16
*/
