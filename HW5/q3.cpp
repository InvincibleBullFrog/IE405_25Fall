#include <iostream>
using namespace std;

int* MergeArrays(int* a, int* b, int sizea, int sizeb) {
    int* out = new int[sizea + sizeb];
    int i = 0, j = 0, k = 0;

    while (i < sizea && j < sizeb) {
        if (a[i] <= b[j]) out[k++] = a[i++];
        else              out[k++] = b[j++];
    }
    while (i < sizea) 
        out[k++] = a[i++];
    while (j < sizeb) 
        out[k++] = b[j++];

    return out;
}

int main() {
    
    int na, nb;
    cout << "Input the sizes of two arrays: ";
    cin >> na >> nb;
    int *A = new int[na];
    int *B = new int[nb];
    cout << "Input the first array: ";
    for (int i = 0; i < na; ++i) 
        cin >> A[i];
    
    cout << "Input the second array: ";
    for (int i = 0; i < nb; ++i) 
        cin >> B[i];

    int *C = MergeArrays(A, B, na, nb);
    cout << "Merged: ";
    for (int i = 0; i < na + nb; ++i) {
        cout << C[i] << ' ';
    }
    cout << '\n';

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}