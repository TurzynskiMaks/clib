# Zmienne
CC = gcc
CFLAGS = -Wall -shared
TARGET_DLL = libdsa.dll
LIB_OUT = libdsa.dll.a
SRCS = dsa.c  # Twoje pliki .c
HEADERS = dsa.h # Twoje pliki .h

# 1. Cel domyślny: Po prostu buduje DLL w obecnym folderze
all: $(TARGET_DLL)

$(TARGET_DLL): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET_DLL) -Wl,--out-implib,./$(LIB_OUT)

# 2. Cel RELEASE: Buduje, przełącza branche i kopiuje pliki
release: all
	@echo "Zapisywanie binariów na branchu dsa..."
	git add -f $(TARGET_DLL) $(LIB_OUT) $(HEADERS) $(SRCS)
	git commit -m "Build do release" || echo "Brak nowych zmian"
	
	@echo "Przełączanie na main i kopiowanie..."
	git checkout main
	# Pobieramy pliki bezpośrednio z gałęzi dsa bez przełączania wszystkiego
	git restore --source=DSA $(TARGET_DLL) $(LIB_OUT) $(HEADERS)
	
	git add .
	git commit -m "Release build: $(shell date)"
	git checkout DSA

# 3. Czyszczenie
clean:
	rm -f *.dll *.dll.a