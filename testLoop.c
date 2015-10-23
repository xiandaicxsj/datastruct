#include<time.h>
#include<stdio.h>
#include<sys/time.h>
int main()
{
		int array[10][1024];
		struct timeval start_time,end_time;
		float time_use;
		int i;
		int j;

		gettimeofday(&start_time,NULL);
		for(i=0;i<1024;i++)
				for(j=0;j<10;j++)
					{
					}
		gettimeofday(&end_time,NULL);
		time_use=1000000*(end_time.tv_sec-start_time.tv_sec)+(end_time.tv_usec-start_time.tv_usec);
		time_use/=100000;
		printf("Timeuse=%f\n",time_use);

}

