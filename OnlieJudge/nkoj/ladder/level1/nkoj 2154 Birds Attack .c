/*
*nkoj 2154 Birds Attack
*author:wmpeng 
*/ 
#include"stdio.h"
#include"math.h"
int main()
{
	double h,v,g;
	scanf("%lf%lf%lf",&h,&v,&g);
	printf("%.4lf",sqrt((v*v+g*h)*(v*v+g*h)/(g*g)-h*h));
	return 0;
} 
