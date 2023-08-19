t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    res = arr[0]
    for i in range(1, n):
        res ^= arr[i]
    bitLength = res.bit_length() 
    ans = 1 << bitLength - 1 if bitLength > 0 else 0
    print(ans)
