#include <stdio.h>
#include <string.h>

int substringSearch(const char* s, const char* s1)
{
    int count = 0;
    const char* pos = s;
    while ((pos = strstr(pos, s1)) != NULL) {
        count++;
        pos += strlen(s1);
    }
    return count;
}

int main()
{
    char s[] = "ababa";
    char s1[] = "ba";
    int result = substringSearch(s, s1);
    printf("Количество вхождений '%s' в '%s': %d\n", s1, s, result);
    return 0;
}