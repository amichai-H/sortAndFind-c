//
// Created by amichai hadad on 09/12/2019.
//
#define LINE 256
#define WORD 30

#ifndef UNTITLED2_TXTFINDLIB_H
#define UNTITLED2_TXTFINDLIB_H




int Getline(char s[]);

int Getword(char w[]);

int substring( char * str1, char * str2);
int sizeOfStr(char *s);

int similar (char *s, char *t, int n);

void print_lines(char * str);

void print_similar_words(char * str);




#endif //UNTITLED2_TXTFINDLIB_H
