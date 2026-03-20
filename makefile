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
	git checkout main
	git checkout DSA -- $(TARGET_DLL) $(LIB_OUT) $(HEADERS)
	git add $(TARGET_DLL) $(LIB_OUT) $(HEADERS)
	git commit -m "Automatyczny build release: $(shell date)"
	git checkout DSA
	@echo "Gotowe! Pliki binarne są na branchu main, a Ty wróciłeś na dev."

# 3. Czyszczenie
clean:
	rm -f *.dll *.dll.a