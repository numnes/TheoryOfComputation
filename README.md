# Theory Of Computation
Algoritmos de processamento de autômatos, gramáticas e máquinas de Turing.

## 1 - Simulador de autômatos finitos determinísticos

![alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/DFAexample.svg/250px-DFAexample.svg.png)

Um autômato finito determinístico é uma máquina de estados finita, que aceita ou rejeita cadeias de símbolos, gerando uma única linha de computação para o processamento. 

**(1)** Um autômato possui por um conjunto de estados e transições, que são definidas entre um par de estados cada transição é representada da forma: **(Ea, Sl, Es)**, sendo **Ea** o estado atual, **Sll** o símbolo lido e **Es** o estado seguinte. Autômatos são definidos como determinísticos quando cada estado não possui mais de uma transição para o mesmo símbolo em cada estado.

Um autômato termina sua execução caso chegue ao final da cadeia de entrada em um estado não final, caso não haja uma transição para o símbolo lido no estado atual ou caso a cadeia termine e o autômato tenha alcançado um estado final, apenas no último caso a cadeia é aceita.

Formalmente um autômato pode ser definido pela quíntupla **(Q, Σ, δ, q0, F)**, onde **Q** é o conjunto de estados do autômato, **Σ** é o conjunto de símbolos aceitos (alfabeto), **δ** é o conjunto de transições, **q0** é o estado inicial e **F** é o conjunto de estados finais.

Fonte: https://pt.wikipedia.org/wiki/Autômato_finito_determinístico

O algoritmo simula o processamento de uma cadeia de caracteres por um autômato finito determinístico. 

* Na primeira linha de entrada, deve ser informado o alfabeto **Σ** do autômato, formado apenas por dígitos de 0 a 9, letras minúsculas ou sublinhado (_);
* A segunda linha deve ser inserido um inteiro **N** indicando o número de estados do autômato;
* A terceira linha conterá um inteiro **q0** indicando o estado inicial;
* Na quarta linha conterá de 1 a **N** inteiros, indicando os estados finais do autômato;
* A quinta linha deve ser inserido um inteiro **D** (1 ≤ **D** ≤ **Q**) indicando o número de transições;
* Após seguem-se **Q** linhas indicando as transições do autômato no formato apresentado no trecho em destaque **(1)**;
* Deve ser inserido após isso um inteiro **I** indicando o número de cadeias serão testadas;
* As **I** linhas seguintes irão conter as cadeias;

As cadeias devem estar contidas entre dois símbolos **@**. Dois símbolos **@** seguidos indicarão uma cadeia vazia.
Para cada cadeia, o simulador imprime duas linhas, uma contendo a cadeia original e outra contendo a resposta do autômato para a análise, sendo **S** para aceitar e **N** para não aceita.

### Exemplos:

#### Entrada
0 1<br>
2<br>	
1<br>
1 2<br>
3<br>
1 0 1<br>
1 1 2<br>
2 1 2<br>
10<br>
@@<br>
@0@<br>
@1@<br>
@00@<br>
@01@<br>
@11@<br>
@000@<br>
@001@<br>
@010@<br>

#### Saida
@@<br>
S<br>
@0@<br>
S<br>
@1@<br>
S<br>
@00@<br>
S<br>
@01@<br>
S<br>
@10@<br>
N<br>
@11@<br>
S<br>
@000@<br>
S<br>
@001@<br>
S<br>
@010@<br>
N<br>





