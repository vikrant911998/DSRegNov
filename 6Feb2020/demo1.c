//Cocktail Sort

#include<stdio.h>
#include<stdbool.h>


void swapping(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int a[7] = {5, 1, 4, 2, 8, 0, 2};
    bool swap = true;
    int start = 0;
    int end = 6;
    int i=0;

    while(swap){
        swap = false;

        for(i=start ; i<end ; i++){
            if(a[i]> a[i+1]){
                swapping(&a[i],&a[i+1]);
                swap = true;
            }
        }

        if(!swap){
            break;
        }

        end--;

        swap = false;

        for(i = end-1; i>=start ;i--){
            if(a[i]>a[i+1]){
               swapping(&a[i],&a[i+1]);
                swap = true; 
            }
        }

        start++;
    }

    for(i=0;i<7;i++){
        printf("%d  ",a[i]);
    }

    return 0;
}

