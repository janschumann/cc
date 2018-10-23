#include "card.h"

int main(void) {
    long long int cnum = get_card_number_from_stdin();

    if (is_valid(cnum)) {
        printf("Card type is '%s'", card_type(cnum));
    } else {
        printf("This is not a valid card number.");
    }

    return 0;
}

long long int get_card_number_from_stdin(void) {
    long long int cnum = 0;

    do {
        printf("Enter Credit-Card Number: ");
        scanf("%lli", &cnum);
    } while (cnum <= 0);

    printf("\nThe number is %lld\n", cnum);

    return cnum;
}

int count_digets(long long int n) {
    int nd;

    for (nd = 0; n > 1; nd++) {
        n = n / 10;
    }

    printf("Number of digits is %d\n", nd);

    return nd;
}

bool is_valid_length(long long int n) {
    int nd = count_digets(n);
    return nd > 13 && nd < 16;
}

int get_next_digit(long long int n) {
    return (int) (n % 10);
}

int get_product_of_next_digit(long long int n) {
    int rem = get_next_digit(n);
    return ((rem * 2) % 10) + ((rem * 2) / 10);
}

int calculate_checksum(long long int n) {
    int sumes = 0;
    while (n > 1) {
        sumes += get_next_digit(n);
        n /= 10;

        sumes += get_product_of_next_digit(n);
        n /= 10;
    }

    printf("Checksum is = %d\n", sumes);

    return sumes;
}

bool is_valid(long long int cnum) {
    return is_valid_length(cnum) && calculate_checksum(cnum) % 10 == 0;
}

char *card_type(long long int cnum) {
    switch (count_digets(cnum)) {
        case 13:
            return (char *) VISA;
        case 15:
            return (char *) AMEX;
        default:
            // value of type double my not fit
            // in long long int, so lets cast
            // the expression
            cnum = (long long int) (cnum / 1e14);
            if (cnum > 49) {
                return (char *) MASTER;
            } else {
                return (char *) VISA;
            }
    }
}
