#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long cc_num, cc_num_len, iso_cc;
    int a, c, e, f;
    int last_sum, next_last_sum, total_sum, total_len;
    
    // Ask for user input
    do
    {
        cc_num = get_long("Number: ");
    }
    while (cc_num < 0);
    
    cc_num_len = cc_num;
    iso_cc = cc_num;
    
    last_sum = 0;
    next_last_sum = 0;
    total_len = 0;
    
    // Check length tool
    for (c = 0; 0 < cc_num_len; c++)
    {
        // Check length tool
        total_len = total_len + 1;
        cc_num_len = (cc_num_len / 10);
    }
    
    // Check sum tool
    for (c = 0; c <= total_len; c++)
    {
        // Check sum tool
        a = (cc_num % 10);
        last_sum = (last_sum + a);
        cc_num = (cc_num - a);
        cc_num = (cc_num/10);
        e = (cc_num % 10);
        cc_num = (cc_num - e);
        cc_num = (cc_num/10);
        f = (e * 2);
        // If f is > 1 digit, add each digit together
        if ((f / 10) >= 1)
        {
            f = (f / 10) + (f % 10);
        }
        next_last_sum = (next_last_sum + f);
    }
   total_sum = (last_sum + next_last_sum);
   
   // Isolate first two digits
   for (c = 0; iso_cc > 99; c++)
   {
       iso_cc = iso_cc / 10;
   }

   // Identify CC type
    if (total_sum % 10 == 0)
    {
        if (total_len >= 13 && total_len <= 19)
        {
            if (iso_cc / 1 == 34 || iso_cc / 1 == 37)
            {
                printf("AMEX\n");
            }
            else if (iso_cc / 1 <= 55 && iso_cc / 1 >= 51)
            {
                printf("MASTERCARD\n");
            }
            else if (iso_cc / 10 == 4)
            {
                printf("VISA\n");
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
    else
    {
        printf("INVALID\n");
    }
}

// #s for checking tool: 
// 4003600000000014 (VISA)
// 371449635398431 (AMEX)
// 5105105105105100 (MASTERCARD)
// 1234 , 53789789789493598 , 398754875439587434 (INVALID) 