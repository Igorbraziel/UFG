package main

// O select em Go permite que você escute múltiplos canais ao mesmo tempo, 
// respondendo ao primeiro que estiver pronto.
// Isso é útil para gerenciar comunicação entre múltiplas goroutines.

import (
	"fmt"
	"time"
)

func main() {
	ch1 := make(chan string)
	ch2 := make(chan string)

	go func() {
		time.Sleep(1 * time.Second)
		ch1 <- "mensagem de ch1"
	}()

	go func() {
		time.Sleep(2 * time.Second)
		ch2 <- "mensagem de ch2"
	}()

	for i := 0; i < 2; i++ {
		select {
		case message1 := <-ch1:
			fmt.Println("Recebido:", message1)
		case message2 := <-ch2:
			fmt.Println("Recebido:", message2)
		}
	}
}
