//
// Created by Jan Schumann on 23.10.18.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#ifndef UNTITLED_CARD_H
#define UNTITLED_CARD_H

#endif //UNTITLED_CARD_H

// try to avoid string literals,
// whenever they change, you would have to
// replace them all over the code base.
// use constants instead
static const char VISA[] = "Visa";
static const char MASTER[] = "MasterCard";
static const char AMEX[] = "American Express";

long long int get_card_number_from_stdin(void);
int get_next_digit(long long int n);
int get_product_of_next_digit(long long int n);
bool is_valid_length(long long int n);
int calculate_checksum(long long int n);
bool is_valid(long long int cnum);
int count_digets(long long int n);
char * card_type(long long int cnum);