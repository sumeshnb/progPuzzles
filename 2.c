/*In a given string of 0s and 1s, you are allowed to flip one 0 to 1, what would be the longest contiguous string of 1s? E.g. {00110001011001}, the answer is 4, this is obtained by flipping 9th zero to one.*/

#include<stdio.h>
int find_longest_sequence(char *);
int main()
{
	char bits[100];
	printf("Enter a bit string containing only zeros and ones..\n");
	gets(bits);
	printf(" You entered : %s", bits);
	printf("The longest sequence of 1 is: %d",find_longest_sequence(bits));
	return 0;
}

int find_longest_sequence(char *bits)
{
	int longest_sequence = 1;

	int at_least_one_zero = 0;

	for(int i=0;i<strlen(bits);i++)
	{
		if(bits[i] == '0')
		{
			at_least_one_zero = 1;
			int my_count = 1;

			//traverse left side of current zero
			for(int j=i-1;j>=0;j--)
			{
				if(bits[j] == '0')
					break;
				else
					my_count++;
			}

			//traverse right side of current zero
			for(int k=i+1;k<strlen(bits);k++)
			{
				if(bits[k] == '0')
					break;
				else
					my_count++;
			}

			if( my_count > longest_sequence)
				longest_sequence = my_count;
		}
	}

	if(!at_least_one_zero)
		return strlen(bits);

	return longest_sequence;
}
