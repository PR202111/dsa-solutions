#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeZArray(char concatenated[], int Z[]) {
    int n = strlen(concatenated);
    int L = 0, R = 0;
    Z[0] = 0;

    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && concatenated[R - L] == concatenated[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R < n && concatenated[R - L] == concatenated[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

int main() {
    char pattern[100];
    char text[500];
    scanf("%[^\n] %[^\n]", text, pattern);

    int n = strlen(text);
    int m = strlen(pattern);
    int c = n + m + 1;

    char concatenated[c];
    int k = 0, found = 0;

    for (int i = 0; i < m; i++, k++)
        concatenated[k] = pattern[i];
    
    concatenated[k++] = '$';  
    
    for (int i = 0; i < n; i++, k++)
        concatenated[k] = text[i];
    
    concatenated[k] = '\0';

    int z[c];
    for (int i = 0; i < c; i++)
    {
        z[i] = 0;
    }
    
    computeZArray(concatenated, z);

    for (int i = m + 1; i < c; i++) {
        if (z[i] == m) {
            int index = i - m - 1;
            printf("%d ", index);
            found++;
        }
    }

    if (!found)
        printf("-1");
    

    return 0;
}
