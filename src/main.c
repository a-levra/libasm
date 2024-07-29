#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
//#include "ft_strcmp.c"
//extern long long ft_strlen(const char *s);
extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);

void	test_ft_write();
void	test_ft_strcpy();
void	test_ft_strlen();
void	test_ft_strcmp();

int main() {
	test_ft_write();
//	test_ft_strcmp();
//	test_ft_strcpy();
//	test_ft_strlen();
    return 0;
}

void	test_ft_strcpy(){
	char src[10];
	strcpy(src,"123456789");
	char dest[10];

	char * res = ft_strcpy(dest,src);

	if (res == &dest[0] && strcmp(dest,src) == 0 )
		write(1, "OK", 3);
}

void	test_ft_strlen(){
    char *str1 = "Hello, World!";
    char *str2 = "This is a test string.";
    char *str3 = ""; // Empty string
	
	char  *p[4] = {
		str1,str2,str3,0
	};
	int res = 0;
	int i = 0;
	while(p[i]){
		if (ft_strlen(p[i]) != strlen(p[i]))
		{
				printf("KO\n");
				return;
		}
		i++;
	}
	printf("OK\n");

}
void	test_ft_strcmp(){
	char s1[10] = "123456789";
	char s2[10] = "12345AAA";
	int a = strcmp(s1,s2);	
	int b = ft_strcmp(s1,s2);	
	if ( a == b)
		printf("a == b\n");
	if (strcmp(s1,s2) == -11)
		printf("OK\n");
	if (-11 == ft_strcmp(s1,s2))
		printf("OK\n");
	if (strcmp(s1,s2) == ft_strcmp(s1,s2))
		printf("OK1\n");
	if (ft_strcmp(s1,s2) == strcmp(s1,s2))
		printf("OK2\n");
	else{
		printf("strcmp : %d\nft_strcmp : %d\n", strcmp(s1,s2), ft_strcmp(s1,s2));
		printf("KO\n");
	}
}


void	test_ft_write(){
	char *msg = "Message to stdout";
	ft_write(1, msg, strlen(msg));
	perror("write");
	ft_write(1203971, msg, strlen(msg));
	perror("write");
}
