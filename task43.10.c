#include <stdio.h>
#include <malloc.h>

typedef long long unsigned int llu;


double sm(char *s) {
    FILE *f = fopen(s, "rb");
    double sm = 0;
    double tmp;
    while (fread(&tmp, sizeof(double), 1, f) != EOF) {
        sm += tmp;
    }
    return sm;
}

void change(char *s) {
    FILE *f = fopen(s, "r+b");
    double tmp;
    double sm = 0;
    fpos_t pos;
    fgetpos(f, &pos);
    for (int i = 0; i < 25; i++) {
        fread(&tmp, sizeof(double), 1, f);
        sm += tmp;
        fsetpos(f, &pos);
        fwrite(&sm, sizeof(double), 1, f);
        fgetpos(f, &pos);
    }
//    while (fread(&tmp, sizeof(double), 1, f) != 0) {
//        sm += tmp;
//        fsetpos(f, &pos);
//        fwrite(&sm, sizeof(double), 1, f);
//        fgetpos(f, &pos);
//        printf("%llu\n", pos);
//    }
    fclose(f);

}

void write(char *s) {
    FILE *f = fopen(s, "w+b");
    for (int i = 0; i < 100; i++) {
        double num = (double) i;
        fwrite(&num, sizeof(double), 1, f);
    }
    fclose(f);
}

void read(char *s) {
    FILE *f = fopen(s, "rb");
    double tmp;
    while (fread(&tmp, sizeof(double), 1, f) != 0) {
        printf("%lf\n", tmp);
    }
    fclose(f);
}

int main() {
    char *s = "nums.bin";
    write(s);
    read(s);
    change(s);
    printf("changed\n");
    read(s);

}