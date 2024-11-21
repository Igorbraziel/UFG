package DesignPatterns.Decorator.Example;

// Essa é a interface ProductProtocol, 
// todas as outras classes envolvidas no padrão de projeto Decorator, 
// devem implementar essa interface 

public interface ProductProtocol {
    Double getPrice(); // Todo ProductProtocol deve implementar esses métodos
    String getName();
}
