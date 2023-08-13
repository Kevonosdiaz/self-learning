package main

import "fmt"

type contactInfo struct {
	email string
	zipCode int
}

type person struct {
	firstName string
	lastName string
	contact contactInfo // Could have just specified the struct type
}

func main() {
	var alex person
	alex.firstName = "Alex"
	alex.lastName = "Anderson"
	fmt.Printf("%+v", alex)

	jim := person {
		firstName: "Jim",
		lastName: "Party",
		contact: contactInfo {
			email: "jim@gmail.com",
			zipCode: 94000,
		},
	}
	// jimPtr := &jim				// Get address pointing to jim
	// jimPtr.updateName("Jimmy")	// Pass by reference
	jim.updateName("Jimmy")
	jim.print()
}

func (p person) print() {
	fmt.Printf("%+v", p)
}

func (ptr *person) updateName(newName string) {
	(*ptr).firstName = newName
}