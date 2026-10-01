def maxDistinctSubstringLengthInSessions(sessionString):
    # Write your code here
    d = defaultdict(int)
    lengths = [0]
    length = 0
    for i in range(0, len(sessionString)):
        c = sessionString[i]
        if c == '*' or d[c] >= 1:
            lengths.append(length)
            length = 0
            d.clear()
        else:
            d[c] += 1
            length += 1
    lengths.append(length)
    return max(lengths)
