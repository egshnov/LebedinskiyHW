#include <stdio.h>
#include <stdlib.h>

_Bool used[1000001];

int main() {
    int tmp;
    FILE *f = fopen("arr.txt", "r");
    while (fscanf(f, "%d", &tmp) != EOF) {
        used[tmp] = 1;
    }
    fclose(f);
    f = fopen("arr_sorted.txt", "w");
    for (int i = 0; i < 1000001; i++) {
        if (used[i]) {
            fprintf(f, "%d\n", i);
        }
    }
}