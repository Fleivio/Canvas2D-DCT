## Flavio Borin Júnior - Canvas 2D Trabalho 2

- O programa lê o arquivo input.dct de entrada especificado;

- O programa aplica a DCT nos valores do arquivo;

- O programa aplica uma quantização nos valores de amplitude, usando a seguinte regra:

´´´
vetor_de_quantização[i] = 1.0 + (i+1) * quantizationFactor
´´´

- A variável quantization factor pode ser alterada pelo usuário usando um slider na tela. Quando maior for o valor de quantization factor, maiores perdas haverão nos valores, e consequentemente a diferença será bem maior;

- O programa aplica a desquantização e a IDCT para recuperar os valores de amplitude;

- Além de plotar o input, dct quantizada, idct e diferença, o programa mostra a dct antes da quantização e a desquantização antes da idct;

- Os gráficos de adaptam horizontal e verticalmente dependendo da quantidade de amostras e de suas magnitudes;

- O programa salva o resultado da idct no arquivo output.dct;

### Botões

- O botão Load acessa o arquivo input.dct e aplica a dct. O que por padrão é sempre executado no início;

- O botão Save salva a saída de input.dct após a IDCT e armazena os dados recuperados em output.dct;

- O botão Random gera um grande quantidade de dados aleatórios e aplica a DCT + IDCT, esses dados foram implementados para testes e mentive porque gera um efeito interessante de ser observado;

- O slider controla o fator de quantização, que indica o quanto os dados serão comprimidos. Ele varia entre 0 e 2, pois a partir disso as diferenças ficam muito grandes;
