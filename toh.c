#include <stdio.h>

void toh(char, char, char, int);

void main(){

    int n = 2;
    char source = 'A';
    char helper = 'B';
    char dest = 'C';

    toh(source, dest, helper, n);
}

void toh(char s, char d, char h, int n){
    if(n == 1){
        printf("Move from %c to %c\n", s, d);
        return;
    }

    toh(s, h, d, n - 1);
    printf("Move from %c to %c\n", s, d);
    toh(h, d, s, n - 1);
}
