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
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET_DLL) -Wl,--out-implib,$(LIB_OUT)

# 2. Cel RELEASE: Buduje, przełącza branche i kopiuje pliki
release: all
	@echo "Rozpoczynam proces release..."
	# 1. Najpierw dodajemy pliki na obecnym branchu (dsa)
	git add -f $(TARGET_DLL) $(LIB_OUT) $(HEADERS)
	git commit -m "Automatyczny build: $(shell date)" || echo "Brak zmian do commitowania"
	
	# 2. Przełączamy się na main
	git checkout main
	
	# 3. Wyciągamy pliki z brancha dsa
	git checkout dsa -- $(TARGET_DLL) $(LIB_OUT) $(HEADERS)
	
	# 4. Finalizujemy na main
	git add .
	git commit -m "Release: $(shell date)"
	
	# 5. Powrót
	git checkout dsa

# 3. Czyszczenie
clean:
	rm -f *.dll *.dll.a