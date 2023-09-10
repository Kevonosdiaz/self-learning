package leetcode

type Pair struct {
    a string
    b int
}

type TimeMap struct {
    mp map[string][]Pair
}


func Constructor() TimeMap {
    return TimeMap{mp: map[string][]Pair{}}
}


func (this *TimeMap) Set(key string, value string, timestamp int)  {
    mp := this.mp
    mp[key] = append(mp[key], Pair{a: value, b: timestamp,})
}


func (this *TimeMap) Get(key string, timestamp int) string {
    mp := this.mp
    res := ""
    ls := mp[key]

    // Perform binary search for timestamp (or its predecessor)
    l := 0
    r := len(ls) - 1

    for l <= r {
        mid := l + (r-l)/2 
        if ls[mid].b <= timestamp {
            res = ls[mid].a
            if ls[mid].b == timestamp {
                return res
            }
            l = mid + 1
        } else {
            r = mid - 1
        }
    }

    return res
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */


/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */
