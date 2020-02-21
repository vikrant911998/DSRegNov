//Collision Handling in Direct Access Method
#include<stdio.h>

int main(){
    int b[5] = {3,4,-3,2,-4};
    int a[5][2] ={0};

    int i =0;
    for(i=0;i<5;i++){
        if(b[i] < 0){
            a[ -(b[i]) ][0] = b[i];
        }
        else{
            a[ b[i] ][1] = b[i];
        }
    }

    int num;
    printf("Enter the Number to be searched\n");
    scanf("%d",&num); //-3

    if(num < 0){
        num = -num; // 3
        printf("Element = %d\n",a[num][0]); //a[3][0]
    }
    else{
        printf("Element = %d\n",a[num][1]);
    }


    

    return 0;
}

