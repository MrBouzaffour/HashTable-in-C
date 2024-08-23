CFLAGS=-g -Wall -Wextra -std=c11 -pedentic 
hash: main.c
	$(CC) $(CLAGS) -o hash main.c
clean:
	rm -f hash
