#include<unistd.h>
#include<stdio.h>
int main()
{
	pid_t  pid=fork();
	if(pid==0)
		printf("Child");
	else
		printf("pid is %d",pid);
}
