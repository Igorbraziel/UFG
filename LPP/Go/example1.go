package main

import (
    "fmt"
    "time"
)

func sayHello() {
    fmt.Println("Hello from Goroutine!")
}

func main() {
    go sayHello()  // Isso cria uma goroutine

    // O código principal não espera a goroutine terminar
    // Então, colocamos uma pausa para garantir que a goroutine execute
    time.Sleep(time.Second)  // Damos tempo para a goroutine imprimir a mensagem
    fmt.Println("Hello from main function!")
}