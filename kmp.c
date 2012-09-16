#include <stdio.h>
#include <string.h>

#define PATTERN_MAX_LEN 100

int *compute_pi(const char *pattern){
    static int pi[PATTERN_MAX_LEN];
    int k, q, m;

    pi[0] = -1;
    k = -1;
    m = strlen(pattern);
    /* loop invariants:
     * Pk ] Pq
     * P0 = -1
     */
    for(q = 1; q < m; q ++){
        while(k >= 0 && pattern[k+1] != pattern[q])
            k = pi[k];
        if(pattern[k+1] == pattern[q])
            k ++;
        pi[q] = k;
    }
    return pi;
}

int kmp_search(const char *text, const char *pattern){
    int *pi;
    int n, m, i, q;
    
    n = strlen(text);
    m = strlen(pattern);
    
    pi = compute_pi(pattern);
    q = -1;
    /* loop invariants:
     * Pq ] Ti
     */
    for(i = 0; i < n; i ++){
        while(q >= 0 && pattern[q+1] != text[i])
            q = pi[q];
        if(pattern[q+1] == text[i])
            q ++;
        if(q+1 == m){
            return i - m + 1;
        }
    }
    return -1;
}

int main(){
    char text[] = "ABCABCABABCD";
    char pattern[] = "ABCD";

    printf("%d\n", kmp_search(text, pattern));
    return 0;
}
