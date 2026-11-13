
/* 
programmer: Yusra Kamal
Section: BDS-1A
Roll NO: 26K-2518
Assignment: 2
Question: 1
Topic: Cinema Hall Seat booking management System
       -> The program takes the number of rows and seats in a cinema hall as input from the user. It will then take the booking status of each seat (booked or available) as input. The program will display the seating arrangement, count the total number of booked seats, and check for the availability of consecutive seats in a specified row.
       -> The program  outputs the seating arrangement, the total number of booked seats, and whether consecutive seats are available in the specified row.
    
*/

#include <stdio.h>

int main(){
   
    printf("Enter the number of rows in the cinema hall: ");
    int rows;
    scanf("%d", &rows);
    printf("Enter the number of seats in a row : ");
    int seats;
    scanf("%d", &seats);
    

    // taking input 
    int cinema [rows][seats];
    for (int i = 0; i < rows; i++){
        printf("Enter the data  of seats in row %d below : \n", i );
        for (int j = 0; j < seats; j++){
            
            printf("Enter 1 if seat %d is booked, 0 if it is available: ", j);
            scanf("%d", &cinema[i][j]);
            
        }//end for
        printf("\n");
    }//end for

    //output the seating arrangement

    printf("Seating arrangement:\n");
    printf("      ");
    for(int i =0;i<seats;i++){
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < rows; i++){
        printf("Row %d |", i);
        for (int j = 0; j < seats; j++){
            if (cinema[i][j] == 1){
                printf("X|");
            } else {
                printf("_|");
            }//end if
        }//end for
        printf("\n");
    }//end for

    printf("\n\n");

    int total_count=0;
    int row_count=0;
    
    //counting seats 
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < seats; j++){
            if (cinema[i][j] == 1){
                total_count++;
                row_count++;
            }//end if
           
        }//end for
         printf("Row %d has %d booked seats.\n", i, row_count);
         row_count=0;
    }//end for

    printf("Total booked seats in the cinema hall: %d\n", total_count);
    
    //checking consective seats
    printf("Enter the number of consecutive seats you want to book: ");
    int consecutive;
    scanf("%d", &consecutive);
    printf("Enter the row number you want to book in: ");
    int row;
    scanf("%d", &row);

        int flag =0;
        for(int j = 0; j < seats; j++){
            if (cinema[row][j] == 0){
                int count = 1;
                for (int k = j + 1; k < seats && cinema[row][k] == 0; k++){
                    count++;
                }//end for
                if (count >= consecutive){
                     flag =1;
                    break;
                }//end if
            }//end if
        }//end for
        

        //to output consective seats
      ( flag == 1 )? printf("Consecutive seats are available in row %d.\n", row) : printf("Consecutive seats are not available in row %d.\n", row);



    
    
    


    return 0;

}
