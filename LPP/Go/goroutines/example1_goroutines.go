package main

import (
    "fmt"
    "time"
)

func showMessage() {
    fmt.Println("Hello!")
}

func main() {
    go showMessage()  // criação de uma goroutine

    time.Sleep(time.Second)  // tempo para que a execução da goroutine possa acontecer
    fmt.Println("Hello main!")
}


