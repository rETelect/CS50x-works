#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long credit_card_number = get_long("Number: ");


    int length = 0;
    long length_checker = credit_card_number;

    while (length_checker > 0)
    {
        length_checker = length_checker / 10;
        length = length + 1;
    }

    long start_checker = credit_card_number;


    while (start_checker >= 100)
    {
        start_checker = start_checker / 10;
    }

    int first_two_digits = start_checker;
    int first_digit = first_two_digits / 10;


    int sum = 0;
    long math_checker = credit_card_number;
    int position_counter = 0;

    while (math_checker > 0)
    {

        int current_digit = math_checker % 10;


        if (position_counter % 2 != 0)
        {
            int product = current_digit * 2;


            if (product > 9)
            {
                sum = sum + (product % 10);
                sum = sum + (product / 10);
            }
            else
            {
                sum = sum + product;
            }
        }
        else
        {

            sum = sum + current_digit;
        }


        math_checker = math_checker / 10;
        position_counter = position_counter + 1;
    }


    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }


    if (first_digit == 4)
    {

        if (length == 13 || length == 16)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55)
    {

        if (length == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (first_two_digits == 34 || first_two_digits == 37)
    {

        if (length == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
