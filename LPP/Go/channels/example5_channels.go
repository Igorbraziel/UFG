package main

// Este exemplo usa canais para compartilhar 
// valores entre goroutines e realizar cálculos em paralelo.

import (
	"fmt"
)

func soma(a int, b int, ch chan int) {
	ch <- a + b
}

func main() {
	ch := make(chan int)
	go soma(1, 2, ch)
	go soma(3, 4, ch)

	resultado1 := <-ch
	resultado2 := <-ch

	fmt.Println("Resultados:", resultado1, resultado2)
}
