def findNextGreaterElementsWithDistance(readings):
    # Write your code here
    # Initialize placeholders that can be replaced
    res = [[-1, -1] for _ in range(len(readings))]
    # Store idx, val of any leftward values missing a greater
    st = []
    # Init stack
    if readings:
        st.append((0, readings[0]))
    for i in range(len(readings)):
        val = readings[i]
        # Curr val is greater than ToS's val
        # Keep popping until no more stack, or value no longer exceeds ToS
        while st and val > st[-1][1]:
            si, sval = st.pop()
            res[si] = [val, i - si]

        st.append((i, val))

    return res
