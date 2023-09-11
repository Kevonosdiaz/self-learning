package main

import (
	"errors"
	"fmt"
	"log"
)

func main() {
	result, err := divide(111.0, 0)
	if err != nil {
		log.Println("Error: ", err)
		return
	}

	fmt.Println("Result of division is", result)
}

func divide(x, y float32) (float32, error) {
	var result float32
	if y == 0 {
		return result, errors.New("cannot divide by 0")
	}

	result = x / y
	return result, nil
}
