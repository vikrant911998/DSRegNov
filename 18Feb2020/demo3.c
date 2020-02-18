//Hashing Methods->Direct Method 

#include<stdio.h>

int main(){
    
    int b[25] = {0};
    int value = 0;
    printf("Enter the NUmber\n");
    scanf("%d",&value);

    while(value != -1){

        b[ value ] = value;

        printf("Enter the NUmber\n");
        scanf("%d",&value);
    }


    int num;
    printf("Enter the Number to be searched\n");
    scanf("%d",&num);

    if(b[num] != 0)
        printf("Element Found = %d\n",b[num]);
    else{
        printf("Element Not exists\n");
    }


    return 0;
}
