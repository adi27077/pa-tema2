CC = g++
CFLAGS = -Wall -Wextra -std=c++17

# P1 = curatare
# P2 = fortificatii
# P3 = beamdrone
P4 = curse

build:
	# $(CC) $(CFLAGS) $(P1).cpp -o $(P1)
	# $(CC) $(CFLAGS) $(P2).cpp -o $(P2)
	# $(CC) $(CFLAGS) $(P3).cpp -o $(P3)
	$(CC) $(CFLAGS) $(P4).cpp -o $(P4)

# run-p1:
# 	./$(P1)

# run-p2:
# 	./$(P2)

# run-p3:
# 	./$(P3)

run-p4:
	./$(P4)

clean:
	rm -rf $(P4)
