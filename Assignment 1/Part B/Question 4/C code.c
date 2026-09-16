#include <stdio.h>
int main (){
    int j,q;
    float total;
    printf("Enter quantity of items");
    scanf("%d",&j);

    float prices[j];
    for (int i=0;i<j;i++){
        printf("enter item price: ");
        scanf("%f",&prices[i]);
        printf("enter quantity of this item ");
        scanf("%d",&q);
        if (prices[i]<0){
            i--;
            printf("incorect enter again");
        }
        else {}
        total=total+(prices[i]*q);
    }
    float da,dis,tax,final,t;
    printf("Enter discount percentage(%): ");
    scanf("%f",&dis);
    da=total-(total*(dis/100));
    printf("Enter tax percentage: ");
    scanf("%f",&tax);
    t=da*tax;
    final=dis+((dis*tax)/100);
    printf("---------------BILL------------");
    printf("Discount: %f",da);
    printf("Tax ammount: %f",t);
    printf("Final loop:  %f",final);
    
    
    return 0;
}