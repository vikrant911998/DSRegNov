//Merge two sorted arrays
#include<stdio.h>

int main(){
    int a1[5] = {10,12,14,16,18};
    int a2[4] = {11,13,15,17};

    int a3[10] = {0};

    int i=0,j=0,k=0;

    while(i<5 && j<4){

        if( a1[i] < a2[j] ){
            a3[k] = a1[i];
            i++;
            k++;
        }
        else{
            a3[k] = a2[j];
            j++;
            k++;
        }

    }

    while(i<5){
        a3[k] = a1[i];
        i++;
        k++;
    }

    while(j<4){
        a3[k] = a2[j];
        j++;
        k++;        
    }

    printf("\nFinal Array\n");
    for(i=0;i<10;i++){
        printf("%d  ",a3[i]);
    }



    return  0;
}
