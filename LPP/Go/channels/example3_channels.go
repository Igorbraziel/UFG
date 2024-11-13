package main

// Esse padrão é comum para sinalizar o término de uma tarefa.

import (
	"fmt"
	"time"
)

func worker(done chan bool) {
	fmt.Print("Trabalhando...")
	time.Sleep(time.Second)
	fmt.Println("Feito")
	done <- true // sinaliza que terminou
}

func main() {
	done := make(chan bool, 1)
	go worker(done)
	<-done // espera até receber o sinal
}
