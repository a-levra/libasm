#include <stdio.h>
#include <stdint.h>

//extern long long ft_strlen(const char *s);
extern size_t ft_strlen(const char *s);

int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "This is a test string.";
    const char *str3 = ""; // Empty string

    printf("Length of \"%s\": %zu\n", str1, ft_strlen(str1));
    printf("Length of \"%s\": %zu\n", str2, ft_strlen(str2));
    printf("Length of \"%s\": %zu\n", str3, ft_strlen(str3));

    return 0;
}
