<div align="center"  >
  <h1 align="center" >
    Merge Files
    <br />
  </h1>
 <img src="https://skillicons.dev/icons?i=c" alt=""> &nbsp; &nbsp;
 <img src="https://skillicons.dev/icons?i=vscode" alt="">
</div>

## Introdução
O presente repositório contempla o Laboratótio: Merge da disciplina de OSA(Orgaização e Sistemas de Arquivos). A presente tarefa objetiva fixar o conteúdo abordado sobre organização e manipulação de arquivos na linguagem de programação C.

## Código
Esta implementação realiza o processo de fusão de dois arquivos cujos registros estão ordenados, gerando um único arquivo cujos registros são a união dos registros originais dos dois arquivos ordenados. O programa recebe, como entrada padrão, os nomes dos dois arquivos nos quais a operação de mesclagem deve ser aplicada. O formato de cada registro nos arquivos é composto por dois campos, sendo o primeiro um inteiro escrito em modo binário, através de uma chamada à função fwrite com um ponteiro para um C long long int. O segundo campo de cada registro é uma sequência de letras que pode ser impressa na tela, sem o final de linha \n, cujo tamanho é exatamente o número inteiro armazenado no primeiro campo. O programa imprime na saída padrão a sequência de strings dos segundos campos dos registros do arquivo resultante do Merge gerado, na ordem em que estão no arquivo de saída (ordenados).
