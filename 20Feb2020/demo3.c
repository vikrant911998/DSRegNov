//Collision Handling -> Linear Probing
#include<stdio.h>


int main(){
    int a[5] = {15,85,33,42,68};
    int size = 5;
    int b[10] = {0};

    int i=0,mod =0,j=0,temp =0;
    for(i=0;i<5;i++){
        j=0;
        mod = a[i] %size; //0

        temp = (mod + j); //0
        while(b[temp] != 0 ){
            j++;
            temp = mod + j;
        }

        b[temp] = a[i];
    }


    int num;
    printf("Enter the Number to be searched\n");
    scanf("%d",&num);
    mod = num%size;
    if( b[mod] == num ){
        printf("Element = %d\n",b[mod]);
    }
    else{
        j=0;
        temp = mod +j;

        while(b[temp] != num){
            j++;
            temp = mod+j;
        }
        printf("Element = %d\n",b[temp]);
    }
    
    


    return 0;
}