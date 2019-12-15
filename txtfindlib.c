//
// Created by amichai hadad on 09/12/2019.
//

#include "txtfindlib.h"
#include <stdio.h>

#define LINE 256

#define WORD 30


int sizeOfStr(char *s){
    int size = 0;
    for (int i = 0; *(s+i)!= '\0';i++){
        size = i;
    }
    return size;
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

int substringLike( char * str1, char * str2){
    int size2 = sizeOfStr(str2);
    int size1 = sizeOfStr(str1);
    int here = 0;

   if(size1<=size2) {
       return 0;
   }
   for (int i = 0; i<=size2;i++){
       for (int j = here; j <= size1; j++) {
           if(*(str1+j) == *(str2+i)){
               here = j+1;
               j = size1+1;
           }
       }
   }
   if(here == size2){
       return 1;
   }
    return 0;
}
int similar (char *s, char *t, int n){
    int ok = substringLike(s,t);
    if(ok){
        int size2 = 0;
        int size1 = 0;
        int here = 0;
        for (int i = 0; *(t+i)!= '\0';i++){
            size2 = i;
        }
        for (int i = 0; *(s+i)!= '\0';i++){
            size1 = i;
        }
        if (size1-size2>n) return 1;
        else return 0;
    }
    return 0;
}
void print_lines(char * str){
    char s[LINE];
    int j =0;
    int size=0;
    for (int i = 0; i <250 ; i++) {
        size = Getline(s);
        if(substring(s,str)){
            j = 0;
            for (int k = 0; k <=size ; k++) {
                printf("%c\n", *(s + k));
            }
        }
    }

}

void print_similar_words(char * str){
    while (!EOF){
        char s[WORD];
        int size = Getword(s);
        if(similar(s,str,1)){
            int j = 0;
            for (int k = 0; k <=size ; k++) {
                printf("%c\n", *(s + k));
            }
        }
    }

}

