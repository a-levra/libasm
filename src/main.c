#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

//extern long long ft_strlen(const char *s);
extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);

void	test_ft_strcpy();
void	test_ft_strlen();
void	test_ft_strcmp();

int main() {

	test_ft_strcpy();
	test_ft_strlen();
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
