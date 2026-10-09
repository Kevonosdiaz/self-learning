def processCouponStackOperations(operations: list[str]) -> list[int]:
    # Write your code here
    st: list[int] = []
    mins: list[int] = [101 for _ in range(len(operations))]
    res: list[int] = []
    for op in operations:
        if op == "top":
            res.append(st[-1])
        elif op == "getMin":
            res.append(mins[len(st)])
        elif op == "pop":
            _ = st.pop()
        else:
            val = int(op.split(" ")[1])
            st.append(val)
            n = len(st)
            mins[n] = min(mins[n - 1], val)
    return res
