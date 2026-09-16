#include <stdio.h>
int main() {
    int N;
    int marks,avg,total=0;
    int flag = 0;
    printf("Enter number of students :  ");
    scanf("%d", &N);
 for(int i=0;i<N;++i){
        total=0;
        flag=0;
        for (int j=1;j<=5;j++){
        printf("Enter marks for subject %d: ", j);
        scanf("%d",&marks);
        if (marks < 33){
            flag =1;
        }
        else {
            total +=marks;
        }
        }
        if (flag == 1){
            printf("Fail-Subject Deficiency\n");
        }
        else {
            avg=total/5;
            if (avg >=80){
                printf("Distinction\n");
            }
            else if (avg <80 && avg>=60){
                printf("Pass\n");
            }
            else {
                printf("Pass\n");
            }

            
        }
 }
    return 0;
}