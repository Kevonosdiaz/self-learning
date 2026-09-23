def areBracketsProperlyMatched(code_snippet):
    # Write your code here
    st = []
    valid_pairing = {'(': ')', '{': '}', '[': ']'}

    for c in code_snippet:
        if c in valid_pairing.keys():
            st.append(c)
        elif c in valid_pairing.values():
            if not st:
                return False
            top = st.pop()
            if valid_pairing[top] != c:
                return False

    return len(st) == 0
