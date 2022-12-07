#include <stdio.h>
#include <string.h>
#include <math.h>

void print_sin(int i) {
    char s[20] = "sin_", end[5];
    sprintf(end, "%.1lf", ((double) (i)) / 10);
    strcat(s, end);
    FILE *f = fopen(s, "w");
    fprintf(f, "    x          sin\n");
    double sm = 0;
    int cnt = 1;
    while (sm <= 20) {
        fprintf(f, "%4.1lf     %10lf\n", sm, sin(sm));
        sm = i / 10. * cnt;
        cnt++;
    }
    fclose(f);
}

int main() {
    for (int i = 1; i <= 10; i++) {
        print_sin(i);
    }
}