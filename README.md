## Flavio Borin Júnior - Canvas 2D Trabalho 2

### Gráficos e DCT:
- Lê o arquivo input.dct de entrada;
- Aplica a DCT nos valores do arquivo;
- Aplica uma quantização nos valores de amplitude, usando a seguinte regra:

```
vetor_de_quantização[i] = 1.0 + (i+1) * quantizationFactor
``` 

- Aplica a desquantização;
- Aplica a IDCT, recuperando parte da informação original do arquivo de input;
- Calcula a diferença entre os dados da IDCT e o Input;

- Todos esses gráficos são computados e plotados na tela, devidamente escalados no eixo X e Y para deixar visível curvas mais sutis;
- São plotados:

-- Input
-- DCT do input
-- Quantização da DCT
-- Desquantização
-- IDCT
-- Diferença entre a IDCT e o Input

- O programa salva o resultado da idct no arquivo output.dct, e por padrão, ao iniciar, lê o arquivo input.dct;

### Botões

- O botão "Load" acessa o arquivo input.dct e aplica a dct. O que por padrão é sempre executado no início;

- O botão "Save from input" salva a saída da IDCT e armazena os dados recuperados em output.dct;

- O botão "Save as input" salva a nova entrada do código em input.dct, fazendo um novo input random, por exemplo;

- O botão "Random" gera dados aleatórios e aplica a DCT + IDCT;

- O botão "Sine" gera dados distribuidos conforme a funcao seno*100;

- O primeiro slider controla o fator de quantização, que indica o quanto os dados serão comprimidos. Ele varia entre 0 e 2, pois a partir disso as diferenças ficam muito grandes;
- Quanto maior o valor do fator, maior será a perda de dados durante o processo e consequentemente espera-se que o gráfico da diferença tenha maiores valores;
```
vetor_de_quantização[i] = 1.0 + (i+1) * quantizationFactor
``` 

- O segundo slider controla a quantidade de valores de entrada que serão gerados pelos botões Random e Sine, este slider tem como valor mínimo 32 e máximo 512, como constava na especificação do trabalho;

### Disclaimer
- O programa utiliza muitas classes do trabalho anterior, como Input, Drawer e toda a implementação de UI e Panel;