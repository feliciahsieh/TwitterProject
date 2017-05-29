#include <stdio.h>
#include <string.h>
int main(void)
{
                  /* 12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890 */
	char* str = "The quick brown fox jumps over the lazy dogS,! .}The quick brown fox jumps over the lazy dogS,! .}The quick brown fox jumps over the lazy dogS,! .}";
	char* newstr;
	int i = 0, len = 0;
	char delimiters[] = "\t\n;,.! ?(){}";

	printf("strlen:%d\n",(int)strlen(str));
	if (strlen(str) >= 139)
		len = 139;
	else
	{
		for (len = 140 ; str[len]; len--)
		{
			printf("**str[len]:%c**  ",str[len]);
			for (i=0;delimiters[i];i++)
			{
				if ((str[len] == delimiters[i]) && ((str[len-1] >='a') && (str[len-1]<='z') || (str[len-1] >='A')&& (str[len-1]<='Z')))
				{
					goto outerloop;
				}
			}
		}
	}
outerloop:
	newstr = strndup(str+0,len);

	printf("%s\n",newstr);
}
