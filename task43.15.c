#include <stdio.h>
#include <malloc.h>

int main() {
    FILE *f1 = fopen("arr.txt", "r");
    FILE *f2 = fopen("ans.txt", "w");
    int cnt = 0, tmp;
    while (fscanf(f1, "%d", &tmp) != EOF) {
        cnt++;
    }
    fclose(f1);
    f1 = fopen("arr.txt", "r");
    int *arr = (int *) malloc(cnt * sizeof(int));
    for (int i = 0; i < cnt; i++) {
        fscanf(f1, "%d", &arr[i]);
    }
    for (int i = 0; i < cnt; i++) {
        int sum = 0;
        for (int j = i; j < cnt; j++) {
            if (sum + arr[j] < 1000) {
                sum += arr[j];
            }
        }
    }
}