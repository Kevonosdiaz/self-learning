package leetcode

import "sort"

func groupAnagrams(strs []string) [][]string {
	mp := map[string][]string{}
	for _, word := range strs {
		b := []byte(word)
		sort.Slice(b, func(i int, j int) bool { return b[i] < b[j] })
		s := string(b)
		mp[s] = append(mp[s], word)
	}
	var ans [][]string
	for _, value := range mp {
		ans = append(ans, value)
	}

	return ans
}
