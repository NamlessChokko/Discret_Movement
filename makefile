CYAN  = \033[1;36m
PURPLE = \033[1;35m
GREEN = \033[1;32m
RESET = \033[0m

# Nombre del ejecutable
TARGET = bin/program

# Directorios
SRC_DIR = Dismov/src
ENTITIES_DIR = Dismov/entities
BASIC_DIR = Dismov/Basic
INC_DIR = Dismov/inc
OBJ_DIR = obj

# Buscar archivos fuente en subdirectorios
SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.cpp')
ENTITY_FILES := $(shell find $(ENTITIES_DIR) -type f -name '*.cpp') 
BASIC_FILES := $(wildcard $(BASIC_DIR)/*.cpp)
SRCS := $(SRC_FILES) $(ENTITY_FILES) $(BASIC_FILES)

# Generar la lista de archivos objeto (reemplazando rutas correctamente)
SRC_OBJS := $(patsubst Dismov/src/%.cpp, $(OBJ_DIR)/Dismov/src/%.o, $(SRC_FILES))
ENTITY_OBJS := $(patsubst Dismov/entities/%.cpp, $(OBJ_DIR)/Dismov/entities/%.o, $(ENTITY_FILES))
BASIC_OBJS := $(patsubst $(BASIC_DIR)/%.cpp, $(OBJ_DIR)/Dismov/Basic/%.o, $(BASIC_FILES))
OBJS := $(SRC_OBJS) $(ENTITY_OBJS) $(BASIC_OBJS)
MAIN_OBJ := $(OBJ_DIR)/main.o

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -fdiagnostics-color=always -I$(INC_DIR)

# Regla para compilar cada archivo fuente en obj/
$(OBJ_DIR)/Dismov/%.o: Dismov/%.cpp | obj_dirs
	@echo "$(CYAN)Compilando $(PURPLE)$<$(CYAN) -> $(PURPLE)$@$(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:
	make src 
	make main
	clear
	@echo "$(GREEN)Ejecutando programa...$(RESET)"
	./$(TARGET)

# Regla para compilar todas las dependencias (entities y src)
src: $(OBJS)

# Regla para compilar y linkear main.cpp después de src
main: src | bin
	@echo "$(CYAN)Compilando $(PURPLE)Main$(CYAN)...$(RESET)"
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(MAIN_OBJ) $(OBJS)
	@echo "$(GREEN)Main compilado correctamente.$(RESET)"

# Crear carpetas necesarias para obj/ (recursivamente)
obj_dirs:
	mkdir -p $(OBJ_DIR)/Dismov/src $(OBJ_DIR)/Dismov/entities $(OBJ_DIR)/Dismov/Basic
	mkdir -p $(patsubst Dismov/%, $(OBJ_DIR)/Dismov/%, $(shell find $(SRC_DIR) $(ENTITIES_DIR) $(BASIC_DIR) -type d)) 

# Crear carpeta para bin/
bin:
	mkdir -p bin

# Limpiar archivos compilados
clean:
	@echo "$(CYAN)Limpiando archivos compilados...$(RESET)"
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: src main clean obj_dirs
