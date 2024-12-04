#include<stdio.h>
int length(char *s)
{
    int x=0;;
    while(*s!='\0')
    {
        x++;
        s++;
    }
    return x;
}
int main()
{
    char str[50];
    printf("Enter a string: ");
    gets(str);

    int n=length(&str[0]);
    printf("Length of string: %d",n);

    return 0;
}
