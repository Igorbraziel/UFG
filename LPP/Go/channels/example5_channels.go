package main

// Este exemplo usa canais para compartilhar 
// valores entre goroutines e realizar cálculos em paralelo.

import (
	"fmt"
)

func soma(x int, y int, ch chan int) {
	ch <- x + y
}

func main() {
	ch := make(chan int)
	go soma(1, 2, ch)
	go soma(3, 4, ch)

	resultado1 := <-ch
	resultado2 := <-ch

	fmt.Println("Resultados:", resultado1, resultado2)
}
