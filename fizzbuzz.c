#include<stdio.h>

int main()
{

	for(unsigned int i=3;i<=1000;i++)
	{
		if(i%15 == 0)
		{
			printf("fizz buzz\n");
			continue;
		}

		if(i%5 == 0)
			printf("fizz\n");

		if(i%3 == 0)
			printf("buzz\n");

	}
}
