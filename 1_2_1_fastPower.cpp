#include <iostream>
using namespace std;

int fastPower(int g, int n);

// Function to compute g^n in G
int fastPower(int g, int n) {
    int y = 1, N, z;

    // Handle negative exponent
    if (n == 0) {
        return y; // If n = 0, output y (which is 1) and terminate.
    }
    else if (n < 0) {
        N = -n;
        z = g; // If negative exponent, g^-1 (inverse) isn't handled in integer math.
        // You might need to adjust this if g is not 1 or -1 (or handle division for non-integer cases).
    }
    else {
        N = n;
        z = g;
    }

    // Step 2: Multiply (if N is odd)
    while (N > 0) {
        if (N % 2 == 1) {
            y = y * z; // Multiply y by z if N is odd
        }

        // Step 3: Halve N
        N = N / 2;
        if (N != 0) {
            z = z * z; // Square z (z = z * z)
        }
    }

    return y; // Return result
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

