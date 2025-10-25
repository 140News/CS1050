/*******************************************************
 * CS1050, Spring 2019
 * HW1
 * Jim Ries
 ******************************************************/
#include <stdio.h>

int main(void)
{
    int company, cartype, days;
    int keepgoing=1;
    int subtotal, tax, total;
    int rate;
    int running_subtotal, running_tax, running_total;

    running_subtotal = 0;
    running_tax = 0;
    running_total = 0;

    printf("**** Interpedia Car Rental System ****\n\n");

    while(1==keepgoing)
    {
        company = -1;
        cartype = -1;

        while (1>company || 3<company)
        {
            printf("\n\n");
            printf("1. Hurts\n");
            printf("2. Mavis\n");
            printf("3. International\n");
            printf("Please select a rental company (1-3): ");
            scanf("%d",&company);
        }

        while (1>cartype || 6<cartype)
        {
            printf("\n\n");
            printf("1. Economy\n");
            printf("2. Mid-Size\n");
            printf("3. Full-Size\n");
            printf("4. Luxury\n");
            printf("5. SUV\n");
            printf("6. Minivan\n");
            printf("Please select a car type (1-6): ");
            scanf("%d",&cartype);
        }

        printf("\n\n");
        printf("Enter the number of days you will rent the car: ");
        scanf("%d",&days);

        if (1==company)
        {
            if (1==cartype)
            {
                rate = 24;
            }
            else if (2==cartype)
            {
                rate = 31;
            }
            else if (3==cartype)
            {
                rate = 64;
            }
            else if (4==cartype)
            {
                rate = 97;
            }
            else if (5==cartype)
            {
                rate = 75;
            }
            else
            {
                rate = 79;
            }
        }
        else if (2==company)
        {
            if (1==cartype)
            {
                rate = 24;
            }
            else if (2==cartype)
            {
                rate = 24;
            }
            else if (3==cartype)
            {
                rate = 65;
            }
            else if (4==cartype)
            {
                rate = 98;
            }
            else if (5==cartype)
            {
                rate = 50;
            }
            else
            {
                rate = 77;
            }
        }
        else
        {
            if (1==cartype)
            {
                rate = 28;
            }
            else if (2==cartype)
            {
                rate = 30;
            }
            else if (3==cartype)
            {
                rate = 67;
            }
            else if (4==cartype)
            {
                rate = 89;
            }
            else if (5==cartype)
            {
                rate = 50;
            }
            else
            {
                rate = 75;
            }
        }

        printf("Daily rate = $%d\n",rate);
        subtotal = rate * days;
        printf("Sub-total = $%d\n",subtotal);
        tax = (8 * subtotal + 50) / 100;
        total = subtotal + tax;
        printf("Tax = $%d\n",tax);
        printf("Total = $%d\n",total);
        running_subtotal += subtotal;
        running_tax += tax;
        running_total += total;
        printf("\nKeep going (1 to continue or 2 to quit)? ");
        scanf("%d",&keepgoing);
        printf("\n\n");
        printf("BONUS: Running sub-total = $%d\n",running_subtotal);
        printf("BONUS: Running tax = $%d\n",running_tax);
        printf("Running total = $%d\n",running_total);
    }

    printf("\n\n*** Grand total = $%d ***\n",running_total);
}
