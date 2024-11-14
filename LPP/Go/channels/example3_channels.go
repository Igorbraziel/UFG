package main

// Canais também são úteis para sinalizar o término de uma tarefa,
// especialmente ao esperar que uma goroutine termine antes de continuar.

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
	done := make(chan bool, 1) // Criamos um canal do tipo bool com capacidade 1.
	go worker(done) // inicia a goroutine worker
	fmt.Println(<-done) // espera até receber o sinal, por isso a main não acaba
}
