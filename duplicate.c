#include<stdio.h>
#include<memory.h>

void remove_duplicates(char str[]);

int main()
{
    char str[100];
    printf("enter the string\n");
    scanf("%s",str);
    printf("%x\n",str);
    remove_duplicates(str);
    printf("array with duplicate chars removed:%s\n",str);
}

void remove_duplicates(char *str)
{
    int bitfield = 0;
    int length=strlen(str);
    for(int i=0;i<length;i++)
    {
        int val = str[i] - 'a';
        if( ((1<<val) & bitfield) > 0)
        {
            for(int j=i;j<=length;j++)
            {
                str[j]=str[j+1];
            }
            i--;
            length--;
        }
        else
        {
            bitfield |= 1<<val;
        }
    }
}
