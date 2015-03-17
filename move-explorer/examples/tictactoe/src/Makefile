BIN=../bin
FLAGS=-g -Wall -std=c99

binaries=tic tics read-tics show-tics c-tic
reqd=tictactoe

objects= $(addprefix $(BIN)/, $(addsuffix .o, $(reqd)))

default: $(addprefix $(BIN)/, $(binaries))

# binaries
$(BIN)/%: $(BIN) $(objects) $(BIN)/%.o
	gcc $(FLAGS) -o $@ $@.o $(objects) 

# object files
$(BIN)/%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

$(BIN):
	mkdir $(BIN)

clean:
	rm -f $(BIN)/*

.SECONDARY:
