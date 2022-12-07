#include <stdio.h>

int main() {
    int arr[10];
    FILE *f = fopen("f.dat", "rb");
    fread(arr, sizeof(int), 10, f);
    for (int i = 0; i < 10; i++) {
        if (arr[i] == 5) {
            arr[i] = 0;
        }
        printf("%d\n", arr[i]);
    }
    fclose(f);
    f = fopen("f.dat", "wb");
    fwrite(arr, sizeof(int), 10, f);
}