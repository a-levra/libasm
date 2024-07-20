#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

//extern long long ft_strlen(const char *s);
extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);

void	test_ft_strcpy();

int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "This is a test string.";
    const char *str3 = ""; // Empty string

    printf("Length of \"%s\": %zu\n", str1, ft_strlen(str1));
    printf("Length of \"%s\": %zu\n", str2, ft_strlen(str2));
    printf("Length of \"%s\": %zu\n", str3, ft_strlen(str3));

	test_ft_strcpy();
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

