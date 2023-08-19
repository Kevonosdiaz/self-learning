package main

import "testing"

/*
Commands to run tests in the terminal:
go test -v
go test -coverprofile=coverage.out && go tool cover -html=coverage.out
*/

// A way to run tests in a clean and short manner
var tests = []struct {
	name     string
	dividend float32
	divisor  float32
	expected float32
	isErr    bool
}{
	{"valid-data", 100.0, 10.0, 10.0, false},
	{"invalid-data", 100.0, 0.0, 0.0, true},
	{"expect-5", 50.0, 10.0, 5.0, false},
	{"expect-fraction", -1.0, -777.0, 0.0012870013, false},
}

// Compare expected (above) to actual (by calling divide()) for all test cases in "tests"
func TestDivision(t *testing.T) {
	for _, tt := range tests {
		got, err := divide(tt.dividend, tt.divisor)
		if tt.isErr {
			if err == nil {
				t.Error("expected error but did not get one")
			}
		} else {
			if err != nil {
				t.Error("did not expect an error but got one:", err.Error())
			}
		}

		if got != tt.expected {
			t.Errorf("expected %f but got %f", tt.expected, got)
		}
	}
}

// The following two test functions are valid, but can be slower than the above approach
func TestDivide(t *testing.T) {
	_, err := divide(10.0, 1.0)
	if err != nil {
		t.Error("Got an error when unexpected")
	}

}

func TestDivideError(t *testing.T) {
	_, err := divide(10.0, 0)
	if err == nil {
		t.Error("No errors when dividing by 0 should have produced one")
	}
}
