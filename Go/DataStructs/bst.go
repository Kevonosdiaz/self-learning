package main

import "fmt"

// Currently incomplete

type bst struct {
	item   int
	parent *bst
	left   *bst
	right  *bst
	size   int // Needs a lot more work to implement and maintain
}

func (b *bst) search(key int) *bst {
	if b.size == 0 {
		return nil
	}

	if b.item == key {
		return b
	}

	if key < b.item {
		return b.left.search(key)
	} else {
		return b.right.search(key)
	}
}

func (b *bst) min() *bst {
	if b.size == 0 {
		return nil
	}
	for b.left.size != 0 {
		b = b.left
	}
	return b
}

func (b *bst) max() *bst {
	if b.size == 0 {
		return nil
	}
	for b.right.size != 0 {
		b = b.right
	}
	return b
}

func (b *bst) pred() *bst {
	return b.left.max()
}

func (b *bst) succ() *bst {
	return b.right.min()
}

// Print all elements using in-order traversal
func (b bst) printIn() {
	if b.size != 0 {
		b.left.printIn()
		fmt.Println(b.item)
		b.right.printIn()
	}
}

func (b *bst) insert(key int, parent *bst) {
	// Empty case
	if b == nil {
		b.item = key
		b.parent = parent
		b.left, b.right = nil, nil
		b.size = 1
	}

	b.size += 1

	if key < b.item {
		b.left.insert(key, b)
	} else {
		b.right.insert(key, b)
	}
}

func (b *bst) delete(key int) {
	if b.size == 0 {
		// Unlink from parent (decrease size, remove )

	}
}
