#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int sqr(char *s1, char *s2) {
    strcat(s1, s2);
    int a = atoi(s1);
    return a * a;
}

int comp(int a, int b) {
    return a * (int) pow(10, (int) log10(b) + 1) + b;
}

int main() {
    for (int a = 1; a < 1000; a++) {
        for (int b = 1; b < 1000; b++) {
            char s1[10], s2[10];
            sprintf(s1, "%d", a);
            sprintf(s2, "%d", b);
            int cp = comp(a, b);
            if (sqr(s1, s2) != cp * cp) {
                printf("%d %d \n", a, b);
            }
        }
    }
}