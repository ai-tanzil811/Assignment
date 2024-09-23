#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define up 1
#define diagonal 2

// Motorcycle structure
struct moto {
    string name;
    int Wprice;
    int Rprice;
    int profit;
    
    moto(string a, int x, int b) : name(a), Wprice(x), Rprice(b), profit(b - x) {}
    
    void display() {
        cout << name << ", " << "wholesale price: " << Wprice << " lac, " << "Profit: " << profit << " lac" << endl;
    }
};

// Knapsack function to solve the problem
void finiteMotocycle(vector<moto>& motos, int budget) {
    int n = motos.size();
    
    // Sort motorcycles by profit in descending order
    // sort(motos.begin(), motos.end(), [](moto a, moto b) {
    //     return a.profit > b.profit;
    // });
    
    // DP arrays to store maximum profit and backtracking decisions
    int p[n+1][budget+1]; // profit table
    int b[n+1][budget+1]; // backtrack table
    
    // Initialize DP tables
    for (int i = 0; i <= budget; i++) p[0][i] = 0;
    for (int i = 0; i <= n; i++) p[i][0] = 0;

    // Fill DP tables using the knapsack logic
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= budget; j++) {
            if (j < motos[i-1].Wprice) {
                // Can't take this item as it exceeds current budget
                p[i][j] = p[i-1][j];
                b[i][j] = up;
            } else {
                // Either take the item or skip it
                if (motos[i-1].profit + p[i-1][j - motos[i-1].Wprice] >= p[i-1][j]) {
                    // Taking the item gives better profit
                    p[i][j] = motos[i-1].profit + p[i-1][j - motos[i-1].Wprice];
                    b[i][j] = diagonal;
                } else {
                    // Skip the item
                    p[i][j] = p[i-1][j];
                    b[i][j] = up;
                }
            }
        }
    }

    // Output the maximum profit
    cout << "Maximum profit: " << p[n][budget] << " lac" << endl;
    cout << "Selected motorcycles:" << endl;

    // Backtracking to find the selected motorcycles
    int i = n, j = budget;
    while (i > 0) {
        if (b[i][j] == diagonal) {
            motos[i-1].display(); // Display the selected motorcycle
            j -= motos[i-1].Wprice; // Reduce the budget by the selected motorcycle's wholesale price
        }
        i--; // Move to the previous motorcycle
    }
}

int main() {
    cout << "FOR QUESTION _O1" << endl;
    
    // List of motorcycles with wholesale and retail prices
    vector<moto> motorCycles = {
        {"Yamaha R15", 3, 5},       // Wholesale = 3 lac, Retail = 5 lac, Profit = 2 lac
        {"Harley Davidson", 6, 14}, // Wholesale = 6 lac, Retail = 14 lac, Profit = 8 lac
        {"Apache RTR 160", 1, 2},   // Wholesale = 1 lac, Retail = 2 lac, Profit = 1 lac
        {"Honda CBR 150R", 4, 6}    // Wholesale = 4 lac, Retail = 6 lac, Profit = 2 lac
    };
    
    int budget = 10; // Available budget
    
    // Solve the knapsack problem for the given motorcycles and budget
    finiteMotocycle(motorCycles, budget);
    
    return 0;
}
