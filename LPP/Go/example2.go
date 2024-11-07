package main

import (
    "fmt"
    "time"
)

func printNumbers() {
    for i := 1; i <= 5; i++ {
        fmt.Println(i)
        time.Sleep(500 * time.Millisecond)  // Simula algum trabalho
    }
}

func printLetters() {
    for _, letter := range []string{"A", "B", "C", "D", "E"} {
        fmt.Println(letter)
        time.Sleep(300 * time.Millisecond)  // Simula algum trabalho
    }
}

func main() {
    go printNumbers()  // Cria uma goroutine para imprimir números
    go printLetters()  // Cria uma goroutine para imprimir letras

    // Damos tempo para as goroutines terminarem antes de terminar o programa
    time.Sleep(3 * time.Second)
    fmt.Println("Main function finished!")
}