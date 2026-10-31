
#include <stdio.h>
int binary_search(int values[], int n, int target) {
    int lo = 0;
    int hi = n;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (values[mid] == target) {
            return mid;
        }

        if (values[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return -1;
}

// Test Binary Search
void test_search(const char *name, int values[], int n, int target, int expected) {
    int result = binary_search(values, n, target);

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
    int values[] = {-1, 0, 3, 5, 9, 12};
    int single[] = {7};
    int empty[1] = {0};

    printf("BINARY SEARCH TESTS:\n");
    

 
    test_search("Target found", values, 6, 9, 4);
    test_search("Target not found", values, 6, 2, -1);

   
    test_search("First index", values, 6, -1, 0);
    test_search("Last index", values, 6, 12, 5);

   
    test_search("One value - found", single, 1, 7, 0);
    test_search("One value - missing", single, 1, 5, -1);

  
    test_search("Below all values", values, 6, -5, -1);
    test_search("Above all values", values, 6, 15, -1);
    test_search("Between values", values, 6, 4, -1);

    
    test_search("Empty array", empty, 0, 5, -1);

    return 0;
}
