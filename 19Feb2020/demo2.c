#include<stdio.h>

int main(){
    int str[12] = {3,3,4,4,5,7,7,7,6,6,9,2}; //ehjrnwa
    char output[10];
    char chars[8][4] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    int i=0,count=0,k=0;
    while(i < 12){
        count = 0;
        while(str[i] == str[i+1]){ //0,1
            i++;
            count++;
        }
        output[k] = chars[ str[i] - 2 ][count];
        k++;
        i++;
    }
    printf("%s \n",output);

    return 0;
}

