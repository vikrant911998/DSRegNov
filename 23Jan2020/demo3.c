#include<stdio.h>

typedef struct Height{
    int feet;
    int inches;
}Height;

int convert(Height h){
    int total = (h.feet*12) + h.inches;

    return total;
}

void output(Height h)
{
    printf("Maximum height is %d feet and %d inches.",h.feet,h.inches);
}
void maximumHeight(Height a[]){
    int max = convert(a[0]);
    Height temp = a[0];
    int i=0;

    for(i=1; i<5; i++){
        if(max < convert(a[i])){
            max = convert(a[i]);
            temp = a[i];
        }
    }

    output(temp);
}



void input(Height *h){

    printf("Enter the Feet of Height\n");
    scanf("%d",&h->feet);
    printf("Enter the inches of Height\n");
    scanf("%d",&h->inches);

}

int main(){
    Height a[5];
    Height h;

    int i=0;

    for(i=0 ; i<5 ; i++){
        input(&h);
        a[i] = h;
    }
    maximumHeight(a);

    return 0;
}