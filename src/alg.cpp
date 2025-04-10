// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_val = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }

        if (num > max_val) {
            max_val = num;
        }
    }

    return max_val;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }

    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int current_max_len = 0;
    unsigned int result_num = lbound;
    for (uint64_t num = lbound; num <= rbound; ++num) {
        unsigned int len = collatzLen(num);

        if (len > current_max_len) {
            current_max_len = len;
            result_num = num;
        }
    }
    *maxlen = current_max_len;
    return result_num;
}
