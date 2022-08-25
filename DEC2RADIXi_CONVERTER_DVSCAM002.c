#include <stdio.h>
#include <math.h>



#define TITLE "DECIMAL TO RADIX-i converter"                //Define TITLE, AUTHOR, Year
#define AUTHOR "Cameron Davis"
#define YEAR 2022
int main()
{
        printf("*****************************\n %s\n Written by: %s\n Date: %d\n*****************************\n", TITLE, AUTHOR, YEAR); //prints heading



        int radix, list[20], n;                                                                 //initiates integers for radix and n(decimal number) and an array of 20 values
        printf("Enter a decimal number: ");                                                     //prints question about decimal input
        scanf("%d",&n);                                                                         //Scans and saves input from user
        while (n>=0){                                                                           //While the user keeps inputting positive integers, the code continues to run


            printf("The number you have entered is %d \n",n);                                   //prints the decimal that was entered

            printf("Enter a radix for the converter between 2 and 16: ");                       //prints question asking radix values
            scanf("%d", &radix );                                                               //scans and saves input from user
            printf("The radix you have entered is %d \n",radix);                                //Prints the radix you have entered

            printf("The log2 of the number is %.2f \n", log2f((float)n));                       // The log2f() is used to calculate the float value of log base 2 of the decimal number input (Note: n needs to be converted to a float
            printf("The integer result of the number divided by %d is %d \n",radix,n/radix);    //calculates the integer result of decimal number divided by the radix
            printf("The remainder is %d",n%radix);                                              //prints remainder using modulus operator

            Dec2RadixI(n,radix);
            printf("Enter a decimal number: ");
            scanf("%d",&n);
        }
        printf("EXIT");
        return 0;
}
void Dec2RadixI(int decValue, int radValue)
{       int i,list[20];                     //initiates a list of 20 integers
        for(i=0;decValue>0;i++)
        {
        int rem=decValue%radValue;          //remainder is found using modulus operator
        if(rem<10)
            rem=rem+48;                     //if remainder<10, 48 is added to retain the ASCII value of the numeric representation
        else
            rem=rem+55;                     // If remainder>=10. 55 is added to get the ASCII value associated to the LETTERS (A B C D E F) of the numeric values
        list[i]=rem;                        // Numeric values of desired ASCII characters are appended to the list. List is in reverse order
        decValue=decValue/radValue;         // new decimal value is now set to the floor division of the old decimal value divided by the radix
        }
        printf("\nThe radix-%d value is ",radValue); // print statement about radix-i value
        for(i=i-1;i>=0;i--)                          //for loop to print the array in reverse order, to obtain the correct radix-i value of the original decimal numer
        {
        printf("%c",list[i]);

        }
        printf("\n");
}







