package main

import (
	"fmt"
	"math/rand"
	"time"
)

const NUM_POOL = 10

func calculateValue(intChan chan int) {
	src := rand.NewSource(time.Now().UnixNano())
	r := rand.New(src)
	randomNum := r.Intn(NUM_POOL)
	intChan <- randomNum
}

func other() {
	intChan := make(chan int)
	defer close(intChan) // This will execute close(intChan) after it has been used and done with (good practice)

	go calculateValue(intChan)

	num := <-intChan
	fmt.Println(num)
}
