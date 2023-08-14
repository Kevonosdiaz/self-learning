package main

import (
	"fmt"
	"io"
	"log"
	"os"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Please give a filename as argument!")
		os.Exit(1)
	}
	filename := os.Args[1]
	file, err := os.Open(filename)
	if err != nil {
		//fmt.Println("Error:", err)
		//os.Exit(1)
		log.Fatal(err)
	}
	io.Copy(os.Stdout, file)
}