package main

import "fmt"

func main() {
	// var colors map[string]string
	// colors := make(map[string]string)
	colors := map[string]string{
		"red":   "#ff0000",
		"green": "#91d88e",
		"blue":  "#405daf",
	}
	// colors["white"] = "#FFFFFF"
	// delete(colors, "white")
	printMap(colors)
}

func printMap(c map[string]string) {
	for color, hex := range c {
		fmt.Println(color, "has the hex code", hex)
	}
}
