### CRUD feito em C usando Lista Encadeada =)

O software é responsável por cadastrar, imprimir, editar, excluir, salvar e fazer backup dos arquivos todas as vezes que inicializa.<br/>Garantindo a integridade das informações


### Inicialização do Programa: ```crud.exe```

Ao executar esta ação, o programa verificará se existe o arquivo:<br/>
```
clientes.txt
```
Caso exista, o programa fará backup das informações, salvando os dados coletados em uma nova lista encadeada<br/>mantendo a estrutura do programa, logo depois inicializando o menu principal.<br/>
Caso não exista, o programa inicializará com o menu principal:


#### Novo Cadastro de Cliente ```[1]```:
```
ID           - int
NOME         - string
EMPRESA      - string
DEPARTAMENTO - string
TELEFONE     - string
EMAIL        - string
```
#### Imprimir Lista de Clientes ```[2]```:

Função responsável por imprimir todos os usuários cadastrados no arquivo: 
```
clientes.txt
```
Ou usuários cadastrados anteriormente do salvamento das informações.

#### Editar Cadastro de Cliente ```[3]```:

Aqui é necessário passar o ```ID``` do usuário que deseja Editar
```
ID           - int
NOME         - string
EMPRESA      - string
DEPARTAMENTO - string
TELEFONE     - string
EMAIL        - string
```
#### Excluir Cadastro de Cliente ```[4]```:

Aqui é necessário passar o ```ID``` do usuário que deseja Excluir
```
ID           - int
NOME         - string
EMPRESA      - string
DEPARTAMENTO - string
TELEFONE     - string
EMAIL        - string
```

#### Salvar informações e Sair  ```[0]```:


Ao realizar esta operação, o programa salvará todos os usuários cadastrados em dois arquivos:
```
   clientes.txt
   clientes.json
```

##### Obrigado pela compreensão ;)
