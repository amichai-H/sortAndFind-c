//
// Created by amichai hadad on 15/12/2019.
//
#include <stdio.h>
#include "txtfindlib.h"
#define MYWORD 30
int main() {
    char in;
    char s[MYWORD];
    printf("OK");
    scanf(" %c\n" , &in);
    int index = 0;
    while(in != ' '){
        s[index] = in;
        index++;
        scanf(" %c\n" , &in);
    }
    s[index] = '\0';
    scanf(" %c\n" , &in);

    if(in == 'a'){
        print_lines(s);
    }
    else{
        print_similar_words(s);
    }
    return 0;
}