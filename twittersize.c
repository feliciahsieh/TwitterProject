#include <stdio.h>
#include <string.h>
int main(void)
{
	char* str = "The quick brown fox jumps over the lazy dogS,! .}";
	char* newstr;
	int i = 0, len = 0;
	char delimiters[] = "\t\n;,.! ?(){}";

	printf("strlen:%d\n",(int)strlen(str));
	len = strlen(str) - 1;
	if (len <= 140)
	{
		for ( ; str[len]; len--)
		{
			printf("**str[len]:%c**  ",str[len]);
			for (i=0;delimiters[i];i++)
			{
				if ((str[len] == delimiters[i]) && ((str[len-1] >='a') && (str[len-1]<='z') || (str[len-1] >='A')&& (str[len-1]<='Z')))
				{
					printf("FOUND: len:%d   i:%d  str[len]:%c\n",len,i,str[len]);
					goto outerloop;
				}
			}
		}
	}
outerloop:
	newstr = strndup(str+0,len);

	printf("%s\n",newstr);
}
