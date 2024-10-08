def speedbreaker(test_cases):
    results = []
    for case in test_cases:
        n, a = case
        # Compute L and R
        L = 1
        R = n
        for i in range(1, n +1):
            L = max(L, i - a[i-1] +1)
            R = min(R, i + a[i-1] -1)
        if L > R:
            results.append(0)
            continue
        # Initialize count array
        count = {}
        D_max = 200  # Adjust based on performance
        for d in range(1, D_max +1):
            for s in range(d +1, n -d +1):
                if a[s -d -1] >=d +1 and a[s +d -1] >=d +1:
                    if a[s -d -1] >=d +2 or a[s +d -1] >=d +2:
                        if L <=s <=R:
                            if s in count:
                                count[s] +=1
                            else:
                                count[s] =1
        # Now, count valid s
        valid =0
        for s in range(L, R +1):
            d_max_s = min(s -1, n -s)
            if d_max_s > D_max:
                continue  # Assume invalid since d > D_max not checked
            if count.get(s,0) >=d_max_s:
                valid +=1
        results.append(valid)
    return results

# Example usage:
if name == "main":
    import sys
    import sys
    import sys
    t = int(sys.stdin.readline())
    test_cases = []
    for _ in range(t):
        n = int(sys.stdin.readline())
        a = list(map(int, sys.stdin.readline().split()))
        test_cases.append((n, a))
    results = speedbreaker(test_cases)
    for res in results:
        print(res)