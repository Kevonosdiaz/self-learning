package leetcode

import (
	"strconv"
	"strings"
)

func evalRPN(tokens []string) int {
	var st []int
	ops := "+-/*"

	for _, t := range tokens {
		if !strings.Contains(ops, t) {
			// The current character is not an operator
			i, _ := strconv.Atoi(t)
			st = append(st, i)
		} else {
			a, b := st[len(st)-2], st[len(st)-1]
			st = st[:len(st)-2]
			var c int

			if t == "+" {
				c = a + b
			} else if t == "-" {
				c = a - b
			} else if t == "/" {
				c = a / b
			} else {
				c = a * b
			}

			st = append(st, c)
		}
	}

	return st[0]
}
