#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char pattern[100];
    char text[500];
    scanf("%[^\n] %[^\n]", text, pattern);
    int n = strlen(text);
    int m = strlen(pattern);

    int badMatch[256];
    for (int i = 0; i < 256; i++)
        badMatch[i] = m;  

    for (int i = 0; i < m - 1; i++)
        badMatch[(unsigned char)pattern[i]] = m - i - 1;

    int s = 0;
    int found = 0;

    while (s <= n - m)
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0)
        {
            printf("%d ", s);
            found = 1;
            s += m;  
        }
        else
        {
            unsigned char temp = text[s + j];
            int shift = badMatch[temp];
            if (shift <= 0) shift = 1;
            s += shift;
        }
    }

    if (!found)
        printf("-1");
    
    printf("\n");

    return 0;
}