#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip> // for setw
using namespace std;

// Function to print a matrix
void printMatrix(const vector<vector<int>>& M) {
    for (const auto& row : M) {
        for (int val : row)
            cout << setw(5) << val;
        cout << endl;
    }
    cout << endl;
}

// 1. Read matrices from a file
void readMatricesFromFile(vector<vector<int>>& A, vector<vector<int>>& B, int& N) {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) {
        cerr << "Error: could not open file.\n";
        exit(1);
    }

    fin >> N;
    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            fin >> A[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            fin >> B[i][j];

    fin.close();

    cout << "\nMatrix A:\n";
    printMatrix(A);
    cout << "Matrix B:\n";
    printMatrix(B);
}

// 2. Add matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            C[i][j] = A[i][j] + B[i][j];
    cout << "A + B:\n";
    printMatrix(C);
    return C;
}

// 3. Multiply matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
    cout << "A × B:\n";
    printMatrix(C);
    return C;
}

// 4. Diagonal sums
void diagonalSums(const vector<vector<int>>& M) {
    int N = M.size();
    int mainSum = 0, secSum = 0;
    for (int i = 0; i < N; ++i) {
        mainSum += M[i][i];
        secSum += M[i][N - 1 - i];
    }
    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Secondary diagonal sum: " << secSum << endl << endl;
}

// 5. Swap rows
void swapRows(vector<vector<int>>& M, int r1, int r2) {
    int N = M.size();
    if (r1 < 0 || r2 < 0 || r1 >= N || r2 >= N) {
        cout << "Invalid row indices.\n";
        return;
    }
    swap(M[r1], M[r2]);
    cout << "After swapping rows " << r1 << " and " << r2 << ":\n";
    printMatrix(M);
}

// 6. Swap columns
void swapCols(vector<vector<int>>& M, int c1, int c2) {
    int N = M.size();
    if (c1 < 0 || c2 < 0 || c1 >= N || c2 >= N) {
        cout << "Invalid column indices.\n";
        return;
    }
    for (int i = 0; i < N; ++i)
        swap(M[i][c1], M[i][c2]);
    cout << "After swapping columns " << c1 << " and " << c2 << ":\n";
    printMatrix(M);
}

// 7. Update matrix element
void updateElement(vector<vector<int>>& M, int r, int c, int newVal) {
    int N = M.size();
    if (r < 0 || c < 0 || r >= N || c >= N) {
        cout << "Invalid indices.\n";
        return;
    }
    M[r][c] = newVal;
    cout << "After updating element (" << r << "," << c << ") to " << newVal << ":\n";
    printMatrix(M);
}

// ------------------- MAIN -------------------
int main() {
    vector<vector<int>> A, B;
    int N;

    readMatricesFromFile(A, B, N);

    auto sum = addMatrices(A, B);
    auto product = multiplyMatrices(A, B);

    cout << "Diagonal sums for Matrix A:\n";
    diagonalSums(A);

    int r1, r2;
    cout << "Enter two rows to swap (0-based): ";
    cin >> r1 >> r2;
    swapRows(A, r1, r2);

    int c1, c2;
    cout << "Enter two columns to swap (0-based): ";
    cin >> c1 >> c2;
    swapCols(A, c1, c2);

    int r, c, val;
    cout << "Enter row, column, and new value: ";
    cin >> r >> c >> val;
    updateElement(A, r, c, val);

    return 0;
}

