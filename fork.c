#include <unistd.h>
#include <stdio.h>
int main()
{
	int i;
	for (i=0;i<2;i++)
	{
			fork();
			printf("-\n");
	}
	return 0;


}
