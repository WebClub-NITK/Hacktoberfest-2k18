def recur_sum_nat(n):
    if n <= 1:
        return n
    return n + recur_sum_nat(n - 1)
# Test
n = 100
print(recur_sum_nat(n))
