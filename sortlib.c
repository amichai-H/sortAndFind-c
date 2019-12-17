//
// Created by amichai hadad on 09/12/2019.
//

#include "sortlib.h"
#include <stdio.h>
void shift_element(int* arr, int i) {
    int temp1 = *(arr);
    for (int j = 1; j <= i; j++) {
        int temp2 = *(arr + j);
        *(arr + j) = temp1;
        temp1 = temp2;
    }
}
void insertion_sort(int* arr , int len) {
    for (int i = 0; i < len; i++) {
        int currentNumber = *(arr + i);
        int count = 0;
        int countDown = i;
        while (countDown > 0 && currentNumber < *(arr + countDown - 1)) {
            count++;
            countDown = countDown - 1;
        }
        if (count > 0) {
            shift_element((arr+i - count), count);
            *(arr+i - count) = currentNumber;
        }

    }
}