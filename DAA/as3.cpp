#include <bits/stdc++.h>
using namespace std;

int main() {
    int numberOfItems, capacity;
    cout << "Enter number of items and capacity: ";
    cin >> numberOfItems >> capacity;

    int weight[101], profit[101], dp[101][101];

    cout << "Enter weight and profit of each item:\n";
    for (int item = 1; item <= numberOfItems; item++) {
        cin >> weight[item] >> profit[item];
    }

    for (int item = 0; item <= numberOfItems; item++) {
        for (int currentCapacity = 0; currentCapacity <= capacity; currentCapacity++) {

            if (item == 0 || currentCapacity == 0) {
                dp[item][currentCapacity] = 0;
            }
            else if (weight[item] <= currentCapacity) {
                dp[item][currentCapacity] = max(
                    profit[item] + dp[item - 1][currentCapacity - weight[item]],
                    dp[item - 1][currentCapacity]
                );
            }
            else {
                dp[item][currentCapacity] = dp[item - 1][currentCapacity];
            }
        }
    }

    cout << "Maximum profit = " << dp[numberOfItems][capacity];

    return 0;
}