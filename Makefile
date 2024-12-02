# Nome do compilador e das variáveis
CC = gcc
CFLAGS = -Wall -std=c99
OBJ = main.o pizza.o ingrediente.o
EXEC = pizzaria.exe

# Regra padrão (all)
all: $(EXEC)

# Regra para compilar o arquivo principal e os arquivos de objeto
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compilando cada arquivo .c em um arquivo objeto .o
main.o: main.c pizza.h ingrediente.h
	$(CC) $(CFLAGS) -c main.c

pizza.o: pizza.c pizza.h ingrediente.h
	$(CC) $(CFLAGS) -c pizza.c

ingrediente.o: ingrediente.c ingrediente.h
	$(CC) $(CFLAGS) -c ingrediente.c

# Regra para limpar os arquivos objetos e o executável
clean:
	rm -f $(OBJ) $(EXEC)

# Regra para executar o programa
run: $(EXEC)
	./$(EXEC)

# Regra para executar o make apenas em caso de necessidade
.PHONY: all clean run
