#include <stdio.h>

void save(double *arr, char *s) {
    FILE *f = fopen(s, "wb");
    fwrite(arr, sizeof(double), 15, f);
}

void load(double *arr, char *s) {
    FILE *f = fopen(s, "rb");
    fread(arr,sizeof(double),15,f);
}

int main() {

}