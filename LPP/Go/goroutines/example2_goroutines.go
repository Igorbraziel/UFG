package main

import (
    "fmt"
    "time"
)

func printNumbers() {
    for i := 1; i <= 6; i++ {
        fmt.Println(i)
        time.Sleep(500 * time.Millisecond)  // Segura um pouco de tempo de execução
    }
}

func printLetters() {
    for _, letter := range []string{"A", "B", "C", "D", "E"} {
        fmt.Println(letter)
        time.Sleep(300 * time.Millisecond)  // Segura um pouco de tempo de execução
    }
}

func main() {
    go printLetters()  // Cria uma goroutine para imprimir letras
    go printNumbers()  // Cria uma goroutine para imprimir números

    
    time.Sleep(3 * time.Second) // Damos tempo para as goroutines, elas executarão ao mesmo tempo
    fmt.Println("Main function finished!")
}

