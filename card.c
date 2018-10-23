#include <stdio.h>
#include <math.h>
#include <cs50.h>

// MAster 16 digit 51 to 55
// Visa 13 or 16 digit start with 4
// Amex 15 start with 34 or 37

int main(void)

{
    long long int cnum = 0, t;
    int nd, es , eo, sumes = 0, sum =0, rem, rem1, rem2;
    do
    {
        printf("Enter Credit-Card Number: ");
        cnum = get_long_long();
    }
    while (cnum <= 0 );

    printf("\nThe number is %lld\n",cnum);
    t = cnum;

    // count number of digits
    for (nd=0; t > 1;nd++ )
    {
        t = t / 10;
    }

    printf("Number of digits is %d\n",nd);
    if (nd < 13)
    {
        printf("INVALID\n");
    }
    else if (nd > 16)
    {
        printf("INVALID\n");
    }
    else
    {
    // checksum
    t = cnum;
    while ( t > 1 )
    {
        rem = t % 10;
        sumes = sumes + rem;
        t = t / 10;
        //printf("%d,%d ", rem, sumes);
        rem = t % 10;
        rem1 = (rem * 2) % 10;
       // printf("%d,",rem);
        rem2 = (rem*2) / 10;
        sumes = sumes + rem1 + rem2;
        t = t / 10;
        //printf("%d,%d,%d ", rem1, rem2, sumes);
    }

    printf("Checksum is = %d\n",sumes);
    if ( sumes % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if ( nd == 13 )
        {
            printf("VISA\n");
        }
        else if ( nd == 15 )
        {
            printf("AMEX\n");
        }
        else
        {
            t = cnum / 1e14;
            if ( t > 49 )
            {
                printf("MASTER\n");
            }
            else
            {
                printf("VISA\n");
            }
        }
    }
    }
    return 0;
}
