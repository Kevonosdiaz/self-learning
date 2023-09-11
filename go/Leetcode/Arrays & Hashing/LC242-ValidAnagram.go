package leetcode

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	sMap := map[byte]int{}
	tMap := map[byte]int{}

	for i := range s {
		sMap[s[i]]++
		tMap[t[i]]++
	}

	for byte, count := range sMap {
		if count != tMap[byte] {
			return false
		}
	}

	return true
}
