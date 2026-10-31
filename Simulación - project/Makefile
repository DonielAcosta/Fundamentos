CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra
SFML_ROOT := deps/prefix/usr
SFML_LIB  := $(SFML_ROOT)/lib/x86_64-linux-gnu
INCLUDES := -I$(SFML_ROOT)/include -Ilinux
# -rpath + --disable-new-dtags: RPATH también resuelve deps transitivas (libstb vía SFML)
LDFLAGS  := -L$(SFML_LIB) \
	-lsfml-graphics -lsfml-window -lsfml-system \
	-Wl,-rpath,'$$ORIGIN/deps/prefix/usr/lib/x86_64-linux-gnu' \
	-Wl,--disable-new-dtags

SRC := linux/main.cpp linux/Animal.cpp linux/Conejo.cpp linux/Fondo.cpp \
	linux/Juego.cpp linux/Madriguera.cpp linux/Zorro.cpp
BIN := simulacion_linux

export LD_LIBRARY_PATH := $(CURDIR)/$(SFML_LIB):$(LD_LIBRARY_PATH)

.PHONY: all run clean

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $@ $(LDFLAGS)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)
