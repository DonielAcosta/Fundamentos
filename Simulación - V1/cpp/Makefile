# Modelo Predador-Presa — puerto C++ (SDL2) para Linux
CXX      ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra
TARGET   := predador_presa

# Rutas relativas (evita rotura por espacios en el path del proyecto)
DEPS_INC := deps/usr/include
DEPS_LIB := deps/usr/lib/x86_64-linux-gnu

# Usa deps locales si existen; si no, paquetes del sistema
ifeq ($(wildcard $(DEPS_INC)/SDL2/SDL.h),)
  CPPFLAGS += $(shell pkg-config --cflags sdl2 SDL2_image SDL2_ttf 2>/dev/null)
  LDLIBS   += $(shell pkg-config --libs sdl2 SDL2_image SDL2_ttf 2>/dev/null)
  RPATH    :=
else
  CPPFLAGS += -I$(DEPS_INC) -I$(DEPS_INC)/x86_64-linux-gnu -I$(DEPS_INC)/SDL2
  LDLIBS   += -L$(DEPS_LIB) -lSDL2 -lSDL2_image -lSDL2_ttf -lfreetype -lpng16 -lm -ldl -lpthread
  # Relativo al ejecutable (soporta espacios en la ruta del proyecto)
  RPATH    := -Wl,-rpath,'$$ORIGIN/$(DEPS_LIB)'
endif

SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)

.PHONY: all clean run setup-deps

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(RPATH) $(LDLIBS)

%.o: %.cpp Animal.hpp Conejo.hpp Fondo.hpp Juego.hpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

setup-deps:
	@mkdir -p deps /tmp/sdl_debs_pp
	cd /tmp/sdl_debs_pp && apt-get download \
		libsdl2-dev libsdl2-2.0-0 \
		libsdl2-image-dev libsdl2-image-2.0-0 \
		libsdl2-ttf-dev libsdl2-ttf-2.0-0 \
		libfreetype6 libfreetype-dev libpng16-16t64
	cd /tmp/sdl_debs_pp && for d in *.deb; do dpkg-deb -x "$$d" "$(CURDIR)/deps"; done
	@echo "Deps listas en deps/"

clean:
	rm -f $(OBJS) $(TARGET)
