#include <stdio.h>
#include <string.h>


void computeLPSArray(char* pattern, int m, int* lps) {
    int length = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pattern, char* text) {
    int last_idx = -1;
    int count = 0;
    int m = strlen(pattern);
    int n = strlen(text);

    int lps[m];
    computeLPSArray(pattern, m, lps);

    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            last_idx = i-j;
            count++;
            j = lps[j - 1]; 
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; 
            } else {
                i++;
            }
        }
    }
    if(count){
    	printf("%d %d\n",last_idx,count);
    }
    else printf("-1\n");
}

int main() {
    char text[20];
    char pattern[100];
	scanf("%s %s",text,pattern);
    KMPSearch(pattern, text);

    return 0;
}

