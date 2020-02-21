//Subtraction Method ->Hashing Method
#include<stdio.h>

int main(){
    int a[5] = {2010,1970,1885,2100,1925};
    int b[400] = {0}; //b[2101]

    int i=0,number = 2000,index = 0;

    for(i=0 ; i<5 ; i++){
        index = a[i]-number; // 1970-2000 = -30
        
        if(index < 0){
            index = -index;
            b[index] = a[i];
        }
        else{
            b[index] = a[i];
        }
    }

    int num = 0;

    printf("Enter the Number to be searched\n");
    scanf("%d",&num); //1970

    if( (num-number) < 0){
        printf("Element = %d\n",b[-(num-number)]);
    }
    else{
        printf("Element = %d\n",b[(num-number)]);
    }



    return 0;
}