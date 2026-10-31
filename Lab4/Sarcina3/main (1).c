
#include <stdio.h>


int search_insert(int values[], int n, int target) {
    int lo = 0;
    int hi = n;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (values[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return lo;
}

// Test Search Insert Position
void test_search(const char *name, int values[], int n,
                 int target, int expected) {

    int result = search_insert(values, n, target);

    printf("%-25s : ", name);

    if (result == expected) {
        printf("PASSED");
    } else {
        printf("FAILED");
    }

    printf(" | Target: %d | Result: %d | Expected: %d\n",
           target, result, expected);
}

int main() {
    int values[] = {1, 3, 5, 6};
    int single[] = {5};
    int empty[1] = {0};

    printf("SEARCH INSERT POSITION TESTS\n");
  

    
    test_search("Target exists", values, 4, 5, 2);
    test_search("Target between values", values, 4, 2, 1);
    test_search("Target below all", values, 4, 0, 0);
    test_search("Target above all", values, 4, 7, 4);


    test_search("One value - equal", single, 1, 5, 0);
    test_search("One value - smaller", single, 1, 3, 0);
    test_search("One value - larger", single, 1, 8, 1);

   
    test_search("Empty array", empty, 0, 5, 0);

    return 0;
}
