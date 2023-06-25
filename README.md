## Autores/Alunos

- João Eduardo Quinteiro
- João Pedro Barbosa
- Nicolas
- Lerry
- Lucas 

# Titulo do Projeto

### GEA - Gerenciador de estoque de autopeças

---

## Descricao

O projeto _GEA - Gerenciador de estoque de autopeças_ é uma aplicação desenvolvida para facilitar o controle e gerenciamento de peças de automóveis. Através desse sistema, é possível cadastrar peças, listar o estoque atual, identificar peças faltantes e realizar a baixa de peças, além de permitir a organização e salvamento por montadora de carro.

A funcionalidade principal do sistema é o cadastro de peças, onde o usuário poderá inserir informações detalhadas sobre cada componente, como nome da peça, número de série, montadora, preço, quantidade em estoque, entre outros dados relevantes. Com base nessas informações, o vendedor será capaz de rastrear e controlar a disponibilidade de cada item.

Além disso, o sistema oferece a opção de listar todas as peças presentes no estoque, proporcionando uma visão geral dos componentes disponíveis para uso. Essa funcionalidade permite ao usuário ter uma noção clara das peças disponíveis e auxilia no planejamento de compras ou na alocação adequada dos recursos.

Outro recurso importante é a identificação de peças faltantes. O sistema será capaz de analisar o estoque atual e identificar quais componentes estão em falta, gerando uma lista de peças que precisam ser adquiridas ou repostas. Essa funcionalidade auxilia na manutenção de um estoque adequado e evita problemas de falta de peças em momentos cruciais.

Além disso, o sistema permite a realização da baixa de peças. Quando uma peça é utilizada ou vendida, o usuário poderá registrar essa informação no sistema, atualizando automaticamente a quantidade disponível em estoque. Essa funcionalidade auxilia na precisão das informações e na manutenção de registros atualizados.

Por fim, o sistema também oferece a opção de salvar peças por montadora de carro. Isso permite que o usuário organize as peças de acordo com a montadora a qual pertencem, facilitando a busca e o acesso rápido aos componentes relacionados a cada fabricante. Essa funcionalidade contribui para uma gestão mais eficiente e organizada das peças de carro.

Em resumo, o GEA é um projeto que visa facilitar o controle e gerenciamento de peças de automóveis. Com suas funcionalidades de cadastro, listagem, identificação de peças faltantes, baixa de peças e organização por montadora, o sistema proporciona uma gestão eficiente e organizada do estoque, contribuindo para a manutenção adequada dos componentes e garantindo o bom funcionamento dos processos relacionados à manutenção de veículos.

---

## Requisitos

### _Sobre o acesso, cadastro e exclusão de usuário_

|ID    | Descrição do Requisito  |
|------|-----------------------------------------|
|R01| O sistema terá login com usuário e senha. Para restrição de acesso de usuários |
|R02| Usuários do tipo administrador poderão realizar a criação de novos usuários  |
|R03| Usuários do tipo administrador poderão realizar a remoção de usuários cadastrados  |

### _Sobre o cadastro de peças_

|ID    | Descrição do Requisito  |
|------|-----------------------------------------|
|R01| Implementar uma estrutura de dados para representar uma peça de carro, contendo campos como nome, número de série, montadora, preço e quantidade em estoque;  |
|R02| Desenvolver uma função para permitir o cadastro de peças, recebendo os dados como entrada e armazenando-os adequadamente.  |

### _Sobre a listagem de peças_

|ID    | Descrição do Requisito  |
|------|-----------------------------------------|
|R01| Implementar uma função para exibir a lista de todas as peças cadastradas no estoque, mostrando os detalhes de cada uma. |
|R02| Utilizar laços de repetição e formatação adequada para apresentar as informações de cada peça.|

### _Sobre a identificação de peças faltantes_

|ID    | Descrição do Requisito  |
|------|-----------------------------------------|
|R01| Desenvolver uma função que analise o estoque atual e gere uma lista das peças que estão em falta. |
|R02| Exibir as peças faltantes, destacando a quantidade necessária para reposição.|

### _Sobre a baixa de peças_

|ID    | Descrição do Requisito  |
|------|-----------------------------------------|
|R01| Implementar uma função que permita a baixa de peças no estoque quando forem utilizadas ou vendidas. |
|R02| Atualizar automaticamente a quantidade disponível após a baixa.|

### _Sobre a organização por montadora_

|ID    | Descrição do Requisito  |
|------|-----------------------------------------|
|R01| Utilizar uma estrutura de dados adicional para organizar as peças por montadora, como uma lista ou uma árvore de peças para cada montadora. |
|R02| Implementar funções para adicionar peças à estrutura organizada por montadora e permitir a filtragem das peças por montadora.|

### _Sobre o armazenamento persistente de dados_

|ID    | Descrição do Requisito  |
|------|-----------------------------------------|
|R01| Utilizar um arquivo para armazenar as informações das peças, permitindo salvar e carregar os dados entre diferentes execuções do programa. |
|R02| Implementar funções para escrever os dados no arquivo ao cadastrar ou baixar peças e para ler os dados do arquivo durante a inicialização do programa.|

### _Sobre a Interface de usuário_

|ID    | Descrição do Requisito  |
|------|-----------------------------------------|
|R01| Utilizar mensagens claras e concisas para orientar o usuário e exibir informações relevantes. |
|R02| Utilizar menus ou prompts interativos para coletar os dados necessários e permitir a interação com o sistema.|

### _Sobre a Interface de usuário_

|ID    | Descrição do Requisito  |
|------|-----------------------------------------|
|R01| Implementar verificações de entrada para garantir que os dados inseridos pelo usuário sejam válidos.|
|R02| Exibir mensagens de erro informativas e tratar exceções ou condições inesperadas adequadamente.|

---

## Instruções de uso do código

A utilização do código será divida em seis passos, ficando da seguinte forma:

## Instruções de Uso do Código

1. **Compilação:**
   - Abra o terminal ou prompt de comando.
   - Navegue até o diretório onde o arquivo do código-fonte (ex: main.c) está localizado.
   - Execute o comando de compilação para gerar o executável do programa. Por exemplo:

     ```
     gcc -Wall -Wextra -g3 main.c ../lib/users.c ../lib/client.c ../lib/pecas.c ../lib/config.c -o main.exe
     ```

2. **Execução:**
   - No terminal ou prompt de comando, execute o programa compilado. Por exemplo:

     ```
     ./main.exe
     ```

3. **Opções do Menu:**
   - Ao executar o programa, será exibido a tela de login, e após efetuar um login com sucesso, então um menu com as opções disponíveis será exibido.
   - Utilize as teclas ou números correspondentes para selecionar a opção desejada.

4. **Cadastro de Peças:**
   - Selecione a opção para cadastrar uma nova peça.
   - Siga as instruções fornecidas pelo programa para inserir os detalhes da peça, como nome, número de série, montadora, preço e quantidade em estoque.

5. **Listagem de Peças:**
   - Selecione a opção para listar todas as peças cadastradas no estoque.
   - As informações de cada peça serão exibidas, mostrando detalhes como nome, montadora e quantidade disponível.

6. **Identificação de Peças Faltantes:**
   - Selecione a opção para identificar as peças faltantes no estoque.
   - O programa analisará o estoque atual e exibirá uma lista das peças em falta, destacando a quantidade necessária para reposição.

7. **Baixa de Peças:**
   - Selecione a opção para dar baixa em uma peça.
   - Siga as instruções do programa para informar qual peça será utilizada ou vendida.
   - A quantidade disponível da peça será atualizada automaticamente no estoque.

8. **Organização por Montadora:**
   - Selecione a opção para organizar as peças por montadora.
   - Utilize as opções fornecidas para filtrar ou visualizar as peças relacionadas a cada montadora.

9. **Finalização do Programa:**
   - Para encerrar o programa, selecione a opção correspondente no menu principal ou utilize um comando específico indicado pelo programa.

Essa é apenas uma instrução básica de uso levando em conta as funções primordiais do projeto, podendo ser expandida conforme a complexidade do projeto aumente.

---

## Devs, Bugs, Novas func

### Funcionalidades essenciais

1. `cadastrarPeca`: Função responsável por cadastrar uma nova peça no estoque. Recebe como parâmetros os dados da peça, como nome, número de série, montadora, preço e quantidade em estoque. Adiciona a nova peça à estrutura de dados de peças cadastradas.

2. `listarPecas`: Função para listar todas as peças cadastradas no estoque. Percorre a estrutura de dados das peças e exibe as informações de cada uma, como nome, montadora e quantidade disponível.

3. `identificarPecasFaltantes`: Função que analisa o estoque atual e identifica as peças que estão em falta. Percorre a estrutura de dados das peças, verifica a quantidade disponível de cada uma e gera uma lista das peças que precisam ser repostas, destacando a quantidade necessária.

4. `darBaixaPeca`: Função responsável por dar baixa em uma peça no estoque quando ela for utilizada ou vendida. Recebe como parâmetro a peça a ser baixada e a quantidade a ser removida do estoque. Atualiza a quantidade disponível da peça na estrutura de dados.

5. `organizarPorMontadora`: Função que organiza as peças cadastradas por montadora. Cria uma estrutura de dados adicional, como uma lista ou árvore, para cada montadora e atribui cada peça à montadora correspondente. Pode incluir a opção de filtrar ou visualizar as peças por montadora.

6. `salvarDados`: Função para salvar os dados das peças em um arquivo, permitindo a persistência das informações entre diferentes execuções do programa. Percorre a estrutura de dados das peças e escreve as informações no arquivo.

7. `carregarDados`: Função para carregar os dados das peças a partir de um arquivo, permitindo a recuperação dos dados salvos anteriormente. Lê as informações do arquivo e preenche a estrutura de dados das peças com os dados carregados.

### Bugs Encontrados

- N/A

### Novas funcionalidades

- N/A

## Imagens

- O projeto ainda não possui imagens.
