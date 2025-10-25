#include<stdio.h>
int main(void)
{
  int keepgoing = 1;
  while (keepgoing != 0)
   {
        int number;
        printf("Enter the highest factorial you wish to calculate:");
        scanf("%d", &number);
        printf("\n");
                switch (number)
                {
                    case 0:
                    {
                        printf("** Error: You must enter a positive number\n");
                        break;
                    }
                    
                    default:
                    {
                        unsigned long int res = 1;
                        printf("calculating factorials up to %d\n", number);

                        for (int i=1;i<=number;)
                        {
                            printf("%d!=%lu\n", i, res);
                            i++;
                            res = i*res;
                        }
                        break;
                    }
                }    
  
        printf("Enter 0 to quit or 1 to continue: ");
        scanf("%d", &keepgoing);
    
        switch(keepgoing)
        {
            case 0:
            {
                printf("Thanks for playing!");
                printf("\n");
                break;
            }
        }
    }

    
    return 1;

}

