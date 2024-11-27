# Nome do executável
TARGET = ted

# Nome do aluno
ALUNO = andreschettini

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -std=c99 -fstack-protector-all -Wall -Wextra -O3 -g -ggdb

# Diretório de código-fonte
SRC_DIR = .

# Diretório de cabeçalhos
INC_DIR = .

# Lista de arquivos de origem
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Lista de arquivos de objeto
OBJS = $(SRCS:.c=.o)

# Incluir diretórios
INC_FLAGS = -I$(INC_DIR)

# Regra de compilação dos arquivos de objeto
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

# Regra de compilação do executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Limpar arquivos intermediários e o executável
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)