#include <unistd.h>
#include <stdlib.h>


char *ft_strcpy(char *dest, const char *src){
	char *res = dest; //we can save dest into rax
	while(*src){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (res);
}
