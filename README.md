# Matrizes Esparsas
Matrizes esparsas são matrizes nas quais a maioria das posições é preenchida por zeros (ou nulos). Para
essas matrizes, podemos economizar um espaço significativo de memória se apenas os termos diferentes
de zero (ou nulo) forem armazenados. As operações usais sobre essas matrizes (somar, multiplicar,
inverter, pivotar) também podem ser feitas em tempo muito menor se não armazenarmos as posições que
contêm zeros.

Uma maneira eficiente de apresentar estruturas com tamanho variável e/ou desconhecido é comemprego de alocação encadeada, utilizando listas. Vamos usar essa representação para armazenar as
matrizes esparsas. Cada coluna da matriz será representada por uma lista linear circular com uma célula
cabeça. Da mesma maneira, cada linha da matriz também será representada por uma lista linear circular
com uma célula cabeça.
