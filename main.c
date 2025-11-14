#include <stdio.h>    // printf
#include <stdlib.h>   // qsort

static int cmpIntAsc(const void *a, const void *b);

int findContentChildren(int *greedFactors, int greedFactorArrSize, int *cookies, int cookieArrSize);

// Main function which demonstrates the working algorithm
int main(void) {
    // Example 1
    int greedFactors1[] = {1, 2, 3};
    int cookiesArray1[] = {1, 1};
    int answer1 = findContentChildren(greedFactors1, 3, cookiesArray1, 2);
    printf("Example 1. Answer: %d\n", answer1); // expected 1

    // Example 2
    int greedFactors2[] = {1, 2};
    int cookiesArray2[] = {1, 2, 3};
    int answer2 = findContentChildren(greedFactors2, 2, cookiesArray2, 3);
    printf("Example 2. Answer: %d\n", answer2); // expected 2

    return 0;
}

// Helper function for sorting in ascending order, using qsort
static int cmpIntAsc(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

/*
Steps:
1) Sort both arrays in ascending order
2) Walk using two indexes in while loop
*/
int findContentChildren(int *greedFactors, int greedFactorArrSize, int *cookies, int cookieArrSize) {
    // Sort GreedFactor and Cookies Array
    qsort(greedFactors, greedFactorArrSize, sizeof(int), cmpIntAsc);
    qsort(cookies, cookieArrSize, sizeof(int), cmpIntAsc);

    // Current index for Greed Factor array
    int currentGreedIndex = 0;

    // Current index for Cookie array
    int currentCookieIndex = 0;

    // Number of children who get cookies (each child gets at most one cookie)
    int result = 0;

    // Try to match smallest need child with smallest enough cookie
    while (currentGreedIndex < greedFactorArrSize && currentCookieIndex < cookieArrSize) {
        if (cookies[currentCookieIndex] >= greedFactors[currentGreedIndex]) {
            // Cookie satisfies this child count it, move to next child and next cookie
            result++;
            currentGreedIndex++;
            currentCookieIndex++;
        } else {
            // Cookie too small so try a larger cookie
            currentCookieIndex++;
        }
    }
    return result;
}
