package main

type stack []any // This stack is implemented using a generic slice

func (s *stack) push(val any) {
	*s = append(*s, val)
}

func (s *stack) pop() {
	*s = (*s)[:len(*s)-1]
}

func (s *stack) top() any {
	return (*s)[len(*s)-1]
}

func (s *stack) isEmpty() bool {
	return len(*s) == 0
}

func (s *stack) size() int {
	return len(*s)
}

// func (s *stack) print() {
// 	for _, val := range *s {
// 		fmt.Println(val)
// 	}
// }
