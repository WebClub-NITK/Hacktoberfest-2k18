int minval(int *A, int n) {
    int curr_min=A[0];
    for (int i=0; i<n; i++)
        if (A[i] < curr_min)
            curr_min = A[i];
    return curr_min;
}
