#include <iostream>
using namespace std;

// Function to compute g^n in G
int fastPower(int g, int n) {
    int y = 1, N, z;
    if (n == 0) {
        return y;
    }
    else if (n < 0) {
        N = -n;
        z = 1;
        int tempG = g;
        // Calculate the inverse of g for negative exponent in a simple integer - like way
        while (N > 0) {
            if (N % 2 == 1) {
                z = z * tempG;
            }
            N = N / 2;
            if (N != 0) {
                tempG = tempG * tempG;
            }
        }
        if (z != 0) {
            y = 1 / z;
        }
    }
    else {
        N = n;
        z = g;
    }

    while (N > 0) {
        if (N % 2 == 1) {
            y = y * z;
        }
        N = N / 2;
        if (N != 0) {
            z = z * z;
        }
    }
    return y;
}

int main() {
    int g, n;
    cout << "Enter the value of g (element in G): ";
    cin >> g;
    cout << "Enter the value of n (exponent in Z): ";
    cin >> n;

    int result = fastPower(g, n);
    cout << "g^n is: " << result << endl;

    return 0;
}