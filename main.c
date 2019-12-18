//
// Created by amichai hadad on 15/12/2019.
//
#include <stdio.h>
#include "sortlib.h"
#define Len 50
int main(){
    int arr[Len];
    int temp;
    for(int i  = 0; i<Len;i++){
        scanf(" %d",&temp);
        *(arr+i) = temp;
    }
    insertion_sort(arr,Len);
    for(int y =0;y<Len-1;y++){
        printf("%d,", *(arr+y) );
    }
    printf("%d\n" , *(arr+49));

    return 0;
}