package main

// Canal bufferizado permite que múltiplos valores sejam armazenados no canal sem 
// que uma goroutine tenha que esperar a outra consumir imediatamente.

import (
	"fmt"
)

func main() {
	ch := make(chan string, 2) // cria um canal bufferizado com capacidade 2

	ch <- "hello"
	ch <- "world"

	fmt.Println(<-ch) // imprime "hello"
	fmt.Println(<-ch) // imprime "world"
}
