def debounceTimestamps(timestamps, K):
    # Write your code here
    if len(timestamps) == 0:
        return 0
    prev_kept = timestamps[0]
    # l indicates where we write when overwriting to-be-removed values
    # and replacing them with values which would exceed K distance
    l = 1
    for r in range(1, len(timestamps)):
        diff = timestamps[r] - prev_kept
        if diff >= K:
            # Override val at l with curr val, which will be kept
            timestamps[l] = timestamps[r]
            prev_kept = timestamps[r]
            l += 1

    # Remove remaining "invalid" values
    del timestamps[l:]
    return len(timestamps)
