//
// Created by amichai hadad on 09/12/2019.
//

#include "txtfindlib.h"
#include <stdio.h>
#include <string.h>

#define LINE 256

#define WORD 30


int sizeOfStr(char *s){
    int i = 0;
    while (*(s+i)){
        i++;
    }

    return i-1;
}

int Getline(char s[]){
    int i = 0;
    char  c ;
    scanf("%c" , &c);
    while (c != '\n'&& i < LINE && c != '\0'){
        s[i] = c;
        i++;
        scanf("%c" , &c);
    }
    s[i] = '\0';
    return i;
}

int Getword(char w[]){
    int i = 0;
    char c;
    scanf("%c" , &c);
    while ((c != '\n')&& (i < WORD )&&( c != '\0' )&& (c != '\t' )&&(c != ' ')){
        w[i] = c;
        i++;
        scanf("%c" , &c);
    }
    w[i] = '\0';
    return i;
}

int substring( char * str1, char * str2){
    int size2 = sizeOfStr(str2);
    int size1 = sizeOfStr(str1);
    int flag = 1;
    for(int i = 0; i<=size1;i++){
        if(*(str1+i) == *(str2)){
            flag = 1;
            for (int j = 0, k = i; j <= size2 && flag == 1 && k<=size1 ; j++,k++) {
                if((*(str1+k) != *(str2+j))){
                    flag = 0;
                }
            }
            if(flag){
                return 1;
            }
        }
    }
    return 0;


}


int similar (char *s, char *t, int n){
    if(strcmp(s,t)==0){
        return 1;
    } else{
        int sizeS = sizeOfStr(s);
        int sizeT = sizeOfStr(t);
        int is = 0;
        int it = 0;
        int count = 0;
        while (is<=sizeS && it<=sizeT){
            if(*(s+is) == *(t+it)){
                is++;
                it++;
            } else{
                is++;
                count++;
            }
        }
        if(it-1==sizeT && sizeS-is+count<=n ){
            return 1;
        } else return 0;
    }

}
void print_lines(char * str){
    char s[LINE];
    int size=0;
    for (int i = 0; i <250 ; i++) {
        size = Getline(s);
        if(substring(s,str)){
            printf("%s\n", s);
        }
    }

}

void print_similar_words(char *str){
    int i=0;
    while (i<250*256){
        i++;
        char s[WORD];
        Getword(s);
        if(similar(s,str,1)){
            printf("%s\n", s);
        }
    }

}
