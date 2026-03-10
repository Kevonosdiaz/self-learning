package main

import (
	"encoding/json"
	"fmt"
	"log"
)

type Person struct {
	Firstname string `json:"first_name"`
	LastName  string `json:"last_name"`
	HairColor string `json:"hair_color"`
}

func main() {
	// Reading a struct from json
	myJson := `
	[
		{
			"first_name": "James",
			"last_name": "Peterson",
			"hair_color": "black"
		},
		{
			"first_name": "Michael",
			"last_name": "Jackson",
			"hair_color": "black"
		}
	]`

	var unmarshalled []Person

	err := json.Unmarshal([]byte(myJson), &unmarshalled)
	if err != nil {
		log.Fatal("Error unmarshalling json", err)
	}
	fmt.Printf("Unmarshalled: %v\n", unmarshalled)

	// Write json from a struct
	mySlice := []Person{}
	m1 := Person{
		Firstname: "Michael",
		LastName:  "Jordan",
		HairColor: "black",
	}
	m2 := Person{
		Firstname: "John",
		LastName:  "Smith",
		HairColor: "black",
	}

	mySlice = append(mySlice, m1)
	mySlice = append(mySlice, m2)

	newJson, err := json.MarshalIndent(mySlice, "", "	")
	if err != nil {
		log.Fatal("Error mashalling", err)
	}

	fmt.Println(string(newJson))
}
