CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)

ENCABEZADOS = SerpienteJuego/Archivos\ de\ encabezado
ORIGEN = SerpienteJuego/Archivos\ de\ origen
TARGET = serpiente

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(ORIGEN)/MyForm.cpp $(ENCABEZADOS)/MyForm.h $(ENCABEZADOS)/Nodo.h $(ENCABEZADOS)/Lista.h $(ENCABEZADOS)/Serpiente.h $(ENCABEZADOS)/recursos.h
	$(CXX) $(CXXFLAGS) -I"SerpienteJuego/Archivos de encabezado" "SerpienteJuego/Archivos de origen/MyForm.cpp" -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
