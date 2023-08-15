package main

import "testing"

func TestPush(t *testing.T) {
	s := stack{}
	s.push(12)
	s.push(24)
	s.push(0)

	if len(s) != 3 {
		t.Errorf("Expected stack length of 3, but got %v", len(s))
	}

	if s.top() != 0 {
		t.Errorf("Expected top value of 0, but got %v", s.top())
	}
}

func TestPop(t *testing.T) {
	s := stack{12, 13, 14}
	s.pop()

	if len(s) != 2 {
		t.Errorf("Expected stack length of 2, but got %v", len(s))
	}

	if s.top() != 13 {
		t.Errorf("Expected top value of 13, but got %v", s.top())
	}

	s.pop()
	s.pop()

	if len(s) != 0 {
		t.Errorf("Expected stack length of 0, but got %v", len(s))
	}

	if s.isEmpty() != true {
		t.Errorf("Expected isEmpty() to return true")
	}

	if s.size() != 0 {
		t.Errorf("Expected stack length of 0, but got %v", s.size())
	}
}
