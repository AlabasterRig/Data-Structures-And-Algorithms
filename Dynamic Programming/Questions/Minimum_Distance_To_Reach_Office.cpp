/*
Minimum Distance to Reach Office

John works in an office which is on the same road as his home.
His workplace is at position X but there is a huge construction going on
at position Y which is on his way to work, and he cannot go beyond it.
But there is one way if John wants to halt the construction and that is
he can talk to the contractor who lives in position Z and then he can reach his office.

Your task is to help John find and return the minimum distance John needs to travel
in order to reach his office. Return -1, if he is unable to reach his office

Note:
• John's home, office, the construction and the contractor's home all lie in the same street
• The distance can be negative, which means the building lies on the other side of John's home.

Input Specification:
1) input1: An integer X, representing the distance of John's office from his home.
2) input2: An integer Y, representing the distance of construction from John's home.
3) input3: An integer Z, representing the distance of contractor's home from John's home.

Output Specification:
Return the minimum distance John needs to travel in order to reach his office. Return -1, if he is unable to reach his office.

*/

#include <iostream>
#include <cstdlib>
using namespace std;

int minDist(int input1, int input2, int input3) {
    // Check if the construction blocks the way to the office
    if ((input2 > 0 && input1 > input2) || (input2 < 0 && input1 < input2)) {
        // Check if the contractor is unreachable
        if (abs(input3) > abs(input2) && 
            ((input2 > 0 && input3 > 0) || (input2 < 0 && input3 < 0))) {
            return -1;
        }

        // Calculate the total distance:
        int totalDistance = abs(input3);             // Distance to contractor
        totalDistance += abs(input3 - input2);       // Distance contractor to construction
        totalDistance += abs(input2 - input1);       // Distance construction to office
        return totalDistance;
    }

    // If no construction blocking, direct distance to office
    return abs(input1);
}

int main() {
    // Test cases
    cout << "Test Case 1: " << minDist(20, 10, -10) << endl;  // Expected: 40
    cout << "Test Case 2: " << minDist(100, 1, 1000) << endl; // Expected: -1
    cout << "Test Case 3: " << minDist(5, 10, -5) << endl;    // Expected: 5
    return 0;
}
