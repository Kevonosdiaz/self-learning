package main

import "testing"

func TestPush(t *testing.T) {
	s := Stack{}
	s.Push(12)
	s.Push(24)
	s.Push(0)

	if len(s) != 3 {
		t.Errorf("Expected stack length of 3, but got %v", len(s))
	}

	if s.Top() != 0 {
		t.Errorf("Expected top value of 0, but got %v", s.Top())
	}
}

func TestPop(t *testing.T) {
	s := Stack{12, 13, 14}
	s.Pop()

	if len(s) != 2 {
		t.Errorf("Expected stack length of 2, but got %v", len(s))
	}

	if s.Top() != 13 {
		t.Errorf("Expected top value of 13, but got %v", s.Top())
	}

	s.Pop()
	s.Pop()

	if len(s) != 0 {
		t.Errorf("Expected stack length of 0, but got %v", len(s))
	}

	if s.IsEmpty() != true {
		t.Errorf("Expected isEmpty() to return true")
	}

	if s.Size() != 0 {
		t.Errorf("Expected stack length of 0, but got %v", s.Size())
	}
}
