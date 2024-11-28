Padrões de projeto (design patterns) são soluções típicas 
para problemas comuns em projeto de software.
Cada padrão é como uma planta de construção que você 
pode customizar para resolver um problema de projeto 
particular em seu código.

O Decorator é um padrão de projeto estrutural 
que permite que você acople novos comportamentos para objetos 
ao colocá-los dentro de invólucros de objetos que contém os comportamentos.

Neste exemplo: Todas as classes herdam de ProductProtocol, 
uma interface com os métodos getPrice() e setPrice(), 
indicando que todas as classes devem ter esses métodos, 
a classe TShirt se refere a um componente concreto, 
que terá um comportamento base, a classe abstrata ProductDecorator 
vai ser uma classe base para os Decorators concretos do problema, 
ela vai possuir um referência ao objeto envolvido, 
que no caso será uma instância de TShirt, 
ela chama os métodos e delega todo o trabalho para o objeto envolvido.
Os Decorators concretos (ProductStampDecorator e ProductCustomizedDecorator) 
estendem o ProductDecorator e adicionam funcionalidades e comportamento aos objetos. 
a Classe Main cria instãncia desses objetos e testa  eles.