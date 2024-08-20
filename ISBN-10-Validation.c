#include <stdbool.h>
#include <string.h>

int convertChar(char c) {
    return c - '0';
}

bool is_X(const char c) {
    if (c == 'X') {
        return true;
    }
    return false;
}

bool is_not_X(const char c) {
    if (c >= 'A' && c <= 'Z' && c != 'X') {
        return true;
    }
    return false;
}

bool is_valid_ISBN_10(const char *ISBN) {
    int sum = 0;
    const int numbersList[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int firstNumber;
    const char *ptr = ISBN;
    if (strlen(ISBN) != 10) {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (is_not_X(*ptr)) {
            return false;
        }
        if (is_X(*ptr)) {
            if (i == 9) {
                firstNumber = 10;
                ptr++;
            } else {
                return false;
            }
        } else {
            firstNumber = convertChar(*ptr);
            ptr++;
        }
        sum += firstNumber * numbersList[i];
    }
    if (sum % 11 == 0) {
        return true;
    }
    return false;
}
