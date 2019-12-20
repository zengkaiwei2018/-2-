#include <stdio.h>
#include <iostream>
#include <stdlib.h>//mallocº¯Êý
using namespace std;
int s[1000];
int a[100];
int main()
{
	int n;
	long long i=0;
	scanf("%d",&n);
	while(1)
	{
		if(n==-1)
		{
			break;
		}
		if(n%2==1)
		{
			s[i]=n;
			i++;
		}
		scanf("%d",&n);
	}
	printf("%d",s[0]);
	for(i=1;s[i]!=NULL;i++)
	{
		printf(" %d",s[i]);
	}
	return 0;
 } 
