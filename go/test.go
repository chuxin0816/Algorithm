package main

import "fmt"

func main() {
	a := [...]string{"a", "b", "c"}
	b := a
	b[0] = "d"
	fmt.Println(a)
}
