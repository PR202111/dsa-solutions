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
    int i, j;
    int d = 256,q = 101;
    int p = 0;  
    int t = 0;  
    int h = 1;  
    int found = 0;

    
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (found == 0)
            {
                printf("%d ", i);
            }
            if (j == m) {
                found += 1;
            }
            
            
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }

    if (!found){
        printf("-1");
        return 0;
    }
    else{
        printf("%d\n",found);
    }
    


    return 0;
}