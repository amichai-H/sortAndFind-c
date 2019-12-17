//
// Created by amichai hadad on 15/12/2019.
//
#include <stdio.h>
#include "txtfindlib.h"
#define MYWORD 30
int main() {
    char in;
    char s[MYWORD];
    Getword(s);
    scanf(" %c\n" , &in);

    if(in == 'a'){
        print_lines(s);
    }
    if(in == 'b'){
        print_similar_words(s);
    }
    return 0;
}