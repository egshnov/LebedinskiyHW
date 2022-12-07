#include <stdio.h>

int main() {
    char s1[40];
    char s2[40];
    scanf("%s", s1);
    scanf("%s", s2);
    FILE *f1 = fopen(s1, "rb");
    FILE *f2 = fopen(s2, "ab"); //wb Для 3
    int c;
    while ((c = fgetc(f1)) != EOF) {
        fputc(c, f2);
    }
}