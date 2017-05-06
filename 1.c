#include<stdio.h>
#include<stdlib.h>

unsigned calculate_power(unsigned, unsigned);

int main()
{
	unsigned a,b;
	printf("enter the numbers a and b \n");
	scanf("%d %d", &a,&b);
	printf("%d raise to %d is %d\n", a, b,calculate_power(a,b));
	return 0;
}

//a^b = (a^b/2)*(a^b/2) --> recursion
//also we can use dynamic programming
unsigned calculate_power(unsigned a, unsigned b)
{
	//declare an auxiliary array to hold 
	//intermediate results
	static int first_iter = 1;
	static unsigned * temp_array = NULL;
	if(first_iter == 1)
	{
		first_iter = 0;
		//allocate memory for aux array only once.
		temp_array = (unsigned *)calloc(sizeof(unsigned),b+1);
	}

	if(a == 0)
		return 0;

	//base case: ie, if b==0, then return 1
	if(b == 0)
		return 1;
	else if( b == 1)
	{
		return a;
	}
	else
	{
		//check whether the requred value
		//is available in the aux array
		if(temp_array[b] != 0 )
		{
			return temp_array[b];
		}
		else
		{
			//b - is odd or even? handle differently
			if(b % 2 == 0)//even
			{
				unsigned inter_val = calculate_power(a,b/2)*calculate_power(a,b/2);
				temp_array[b] = inter_val;//store intermediate value in
				//aux array , so that it can be used for other recursive calls
				return inter_val;
			}
			else//odd
			{
				unsigned inter_val = calculate_power(a,(b+1)/2)*calculate_power(a,(b-1)/2);
				temp_array[b] = inter_val;
				return inter_val;
			}
		}
	}
}
