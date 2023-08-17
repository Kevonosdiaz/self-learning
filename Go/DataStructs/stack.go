package main

type Stack []any // This stack is implemented using a generic slice

func (s *Stack) Push(val any) {
	*s = append(*s, val)
}

func (s *Stack) Pop() {
	*s = (*s)[:len(*s)-1]
}

func (s *Stack) Top() any {
	return (*s)[len(*s)-1]
}

func (s *Stack) IsEmpty() bool {
	return len(*s) == 0
}

func (s *Stack) Size() int {
	return len(*s)
}

// func (s *stack) print() {
// 	for _, val := range *s {
// 		fmt.Println(val)
// 	}
// }
