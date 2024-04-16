#include <iostream>
using namespace std;

int main()
{
    int array[10], i, search;
    
    // Input array elements
    cout << "Enter array elements:" << endl;
    for (i = 0; i < 10; i++) {
        cin >> array[i];
    }
    
    cout << "Enter the element you want to search:" << endl;
    cin >> search;
    
    // Binary search algorithm
    int l = 0; // Lower bound of the search range
    int up = 9; // Upper bound of the search range
    int mid = (l + up) / 2; // Midpoint of the search range
    
    while (l <= up) {
        if (search > array[mid]) {
            l = mid + 1; // Update lower bound if the search element is greater than the middle element
        } else if (search == array[mid]) {
            cout << "Element found at index " << mid << endl; // Element found
            break;
        } else {
            up = mid - 1; // Update upper bound if the search element is less than the middle element
        }
        mid = (l + up) / 2; // Update midpoint
    }
    
    if (l > up) {
        cout << "Element not found" << endl; // Element not found
    }
    
    return 0;
}


/*
Output:-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 1.binary_search.cpp
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ ./a.out
Enter array elements:
1
3
6
8
9
11
14
16
22
29
Enter the element you want to search:
14
Element found at index 6
*/
