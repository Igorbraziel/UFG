package main

// Este exemplo cria um canal simples,
// envia um valor para o canal em uma goroutine e recebe o valor no programa principal.

import (
	"fmt"
)

func main() {
	ch := make(chan int) // cria um canal do tipo int, não bufferizado

	go func() { // essa operação de envio bloqueia a execução da main até que esteja pronta para receber o valor.
		ch <- 42 // envia um valor para o canal, atraves de uma goroutine anonima
	}()

	val := <-ch // recebe o valor do canal
	fmt.Println(val) 
}


