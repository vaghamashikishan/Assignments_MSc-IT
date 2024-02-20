#include <stdio.h>
#include <string.h>
int cnt = 0;
void len(char *str)
{
    if (strlen(str) == 0)
        return;
    str[strlen(str) - 1] = '\0';
    cnt++;
    len(str);
}

int main()
{
    // Write C code here
    char s[100];
    scanf("%[^\n]%*c", &s);
    len(s);
    printf("Length of word : %d", cnt);
    return 0;
}