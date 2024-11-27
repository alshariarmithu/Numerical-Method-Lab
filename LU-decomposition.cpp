#include <bits/stdc++.h>
using namespace std;

void luFactorization(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    // Initialize L and U matrices
    L = vector<vector<double>>(n, vector<double>(n, 0));
    U = vector<vector<double>>(n, vector<double>(n, 0));

    // Perform the factorization
    for (int i = 0; i < n; i++) {
        // Upper triangular matrix U
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        // Lower triangular matrix L
        for (int k = i; k < n; k++) {
            if (i == k) {
                L[i][i] = 1; // Diagonal of L is 1

	            } else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}
// Function to perform forward substitution: Solve L*y = b
vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n, 0);

    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    return y;
}
// Function to perform backward substitution: Solve U*x = y
vector<double> backwardSubstitution(const vector<vector<double>>& U, const vector<double>& y) {
    int n = U.size();
    vector<double> x(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    return x;
}
// Function to print a vector
void printVector(const vector<double>& v) {
    for (double val : v) {
        cout << setw(10) << val << " ";
    }
    cout << endl;
}

int main() {
    // Example matrix A and vector b
    vector<vector<double>> A = {
        {2, -1, -2},
        {-4, 6, 3},
        {-4, -2, 8}
    };

    vector<double> b = {-2, 9, 8}; // Example b

    int n = A.size();
    vector<vector<double>> L(n), U(n);

    // Perform LU factorization
    luFactorization(A, L, U);
    // Step 1: Solve L*y = b using forward substitution
    vector<double> y = forwardSubstitution(L, b);

    // Step 2: Solve U*x = y using backward substitution
    vector<double> x = backwardSubstitution(U, y);

    // Print the solution vector x
    cout << "Solution vector x:" << endl;
    printVector(x);

    return 0;
}