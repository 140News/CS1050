#include<stdio.h>
int main(void)
{
    int keepgoing=1;
    while(keepgoing!=0)
    {
        int number;
        printf("Enter the high limit of the summation you wish to calculate:");
        scanf("%d",&number);
        printf("\n");

        switch(number<0)
            {
                case 1:
                    {
                        printf("** Error: You must enter a non-negative number\n");
                        break;
                    }
                default:
                    {
                         unsigned long int res=0;
                         printf("Calculating summations up to:%d\n", number);

                         for (int i=0;i<=number;)
                         {
                             printf("Summation(0..%d) = %lu\n", i, res);
                             i++;
                             res=i+res;

                         }
                         break;
                    }            
             }

            printf("\n");
            printf("Enter 0 to quit or 1 to continue:");
            scanf("%d",&keepgoing);

      switch(keepgoing)

      { 
          case 0:
          {
            int i;
            int sum=0;
            for(i=1;i<=number;i++)
               {
                   sum+=i;
               }
            printf("The largest summation you calculated was %d", sum);
            printf("\n");
             
             break;
          }

         
     }       
    }
      return 1;
    
}


