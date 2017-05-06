#include<stdio.h>
#include<memory.h>

int checkuniqueness(char *ptr);

int main()
{
    char ch[]="sumesh";
    int unique = checkuniqueness(ch);
    if(unique)
	printf("Yes, all characters are unique\n");
    else
	printf("No, duplicate characters found\n");
    return 0;
}

int checkuniqueness(char *ptr)
{
    //initialize all the aux arrays to zero
    int lowerchar[26]={0};
    int upperchar[26]={0};
    int digits[10]={0};
    //iterate through each character in the input
    //and mark the corresponding index in auxarray
    // a dup character can be detected by checking
    //the aux array

    while(*ptr)
    {
	int ch = *ptr;
	if(ch >='A' && ch <='Z')
	{
	    if(upperchar[ch-65])
	    {
		printf("%c\n",ch);
		return 0;
	    }
	    else{
		upperchar[ch-65] = 1;
	    }
	}

	if(ch >='a' && ch <='z')
	{
	    if(lowerchar[ch-97])
	    {
		printf("%c\n",ch);
		return 0;
	    }
	    else{
		lowerchar[ch-97] = 1;
	    }
	}
	if(ch >='0' && ch <='9')
	{
	    if(digits[ch-48])
	    {
		printf("%c\n",ch);
		return 0;
	    }
	    else{
		digits[ch-48] = 1;
	    }
	}
	ptr++;
    }
    return 1;
}
