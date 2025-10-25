#include<stdio.h>
int main(void)
{   
    int subsum=0,taxsum=0,totalsum=0;
    int keepgoing=1;
    printf("\n");
    printf("**** Interpedia Car Rental System ****\n");
    while (keepgoing!=2)
    {
        if(keepgoing==1)
        {
            printf("\n");
            printf("1.Hurts\n");
            printf("2.Mavis\n");
            printf("3.International\n");
            printf("Please select a rental company (1-3):");
            int A;
            scanf("%d",&A);
            while(A!=1&&A!=2&&A!=3)
            {
                printf("\n\n");
                printf("1.Hurts\n");
                printf("2.Mavis\n");
                printf("3.International\n");
                printf("Please select a rental company (1-3):");
                scanf("%d",&A);
            }
            printf("\n\n");
            printf("1.Economy\n");
            printf("2.Mid-Size\n");
            printf("3.Full-Size\n");
            printf("4.Luxury\n");
            printf("5.SUV\n");
            printf("6.Minivan\n");
            printf("Please select a car type (1-6):");
            int B;
            scanf("%d",&B);
            while(B!=1&&B!=2&&B!=3&&B!=4&&B!=5&&B!=6)
            {
                printf("\n\n");
                printf("1.Economy\n");
                printf("2.Mid-Size\n");
                printf("3.Full-Size\n");
                printf("4.Luxury\n");
                printf("5.SUV\n");
                printf("6.Minivan\n");
                printf("Please select a car typr (1-6):"); 
                scanf("%d",&B);
            }
            printf("\n\n");
            printf("Enter the number of days you will rent the car:");
            int C;
            scanf("%d",&C);
            int D;
            if(A==1&&B==1)
            {
                printf("Daily rate= $24\n");
                D=24; 
            }
            else if(A==1&&B==2)
            {
                printf("Daily rate= $31\n");
                D=31;
            }
            else if(A==1&&B==3)
            {
                printf("Daily rate= $64\n");
                D=64;
            }
                
            else if(A==1&&B==4)
            {
                printf("Daily rate= $97\n");
                D=97;
            }
            else if(A==1&&B==5)
            {
                printf("Daily rate= $75\n");
                D=75;
            }
            else if(A==1&&B==6)
            {
                printf("Daily rate= $79\n");
                D=79;
            }


            if(A==2&&B==1)
            {
                printf("Daily rate= $24\n");
                D=24;
            }
            else if(A==2&&B==2)
            {
                printf("Daily rate= $24\n");
                D=24;
            }
            else if(A==2&&B==3)
            {
                printf("Daily rate= $65\n");
                D=65;
            }
            else if(A==2&&B==4)
            {
                printf("Daily rate= $98\n");
                D=98;
            }
            else if(A==2&&B==5)
            {
                printf("Daily rate= $50\n");
                D=50;
            }
            else if(A==2&&B==6)
            {
                printf("Daily rate= $77\n");
                D=77;
            }


            if(A==3&&B==1)
            {
                printf("Daily rate= $28\n");
                D=28;
            }
            else if(A==3&&B==2)
            {
                printf("Daily rate= $30\n");
                D=30;
            }
            else if(A==3&&B==3)
            {
                printf("Daily rate= $67\n");
                D=67;
            }
            else if(A==3&&B==4)
            {
                printf("Daily rate= $89\n");
                D=89;
            }
            else if(A==3&&B==5)
            {
                printf("Daily rate= $50\n");
                D=50;
            }
            else if(A==3&&B==6)
            {
                printf("Daily rate= $75\n");
                D=75;
            }
            //printf("Daily rate= $D\n");
            printf("Sub-total = $%d\n",(C*D));
            int tax=(C*D*8+50)/100;
            printf("Tax = $%d\n",tax);
            printf("Total = $%d\n",((C*D)+tax));
            printf("\n");


            printf("Keep going (1 to continue or 2 to quit)?");
            scanf("%d",&keepgoing);
            printf("\n");

            while (keepgoing!=1&&keepgoing!=2)
            {
                printf("Keep going (1 to continue or 2 to quit)?");
                scanf("%d", &keepgoing);
                printf("\n");
            }
            
            if(keepgoing==1)
            {
                subsum=subsum+C*D;
                taxsum=taxsum+tax;
                totalsum=subsum+taxsum;
                printf("BONUS: Running sub-total = $%d\n",subsum);
                printf("BONUS: Running tax = $%d\n",taxsum);
                printf("Running total = $%d\n",totalsum);
            }
    
            
        
            if(keepgoing==2)
            { 
                printf("BONUS: Running sub-total = $%d\n",subsum+(C*D));
                printf("BONUS: Running tax = $%d\n",taxsum+tax);
                printf("Running total = $%d\n\n",subsum+(C*D)+taxsum+tax);
                printf("*** Grand total = $%d ***\n\n",subsum+(C*D)+taxsum+tax);
            } 
        }
    }
    

     
    return 1;
    
}
