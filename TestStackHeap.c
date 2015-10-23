#include<stdio.h>
//这里是可以用来测试栈或者堆的生长的方向的 //
//
void func2();
void func1()
{

	int * a=(int *)malloc(sizeof(int));
	printf("a is %x\n",a);
	//int a ;
	//printf("stack a is %x\n",&a);
	func2();
}

void func2()
{
int *b=(int *)malloc(sizeof(int));
	printf("b is %x\n",b);
	//int b;
	//printf("stack b is %x\n",&b);
}

int main()
{
	func1();
}
