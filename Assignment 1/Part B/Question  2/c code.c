#include <stdio.h>
int main() {
   int size;
   printf("Enter the number of  requests: ");
   int request;
   int current = 0;

   scanf("%d", &size);
   int number[size];
   for(int i = 0; i < size; i++) {
      printf("Enter request %d: ", i + 1);
      scanf("%d", &number[i]);
      request = number[i];

      if(request > current) {
         printf("moving up\n");
         
      } else if(request < current) {
         printf("moving down\n");   
         
      }
      else {
         printf("opening doors\n");
      }

      current = request;

   }



   return 0;
 }

