CC=gcc
SRC=src
ODIR=output

EXPR= ./src/expression/output/calc.o ./src/expression/output/calc.tab.o

libCED.a: expr CED.o
	@echo 'Building: $@'
	@ar -rcs $(ODIR)/libCED.a $(ODIR)/CED.o $(EXPR)

test: libCED.a
	@echo 'Building: $@'
	@$(CC) $(SRC)/test.c $(ODIR)/libCED.a -o $(ODIR)/test.exe

CED.o:
	@echo 'Building: $@'
	@$(CC) $(SRC)/CED.c -c -o $(ODIR)/CED.o

expr:
	@echo 'Building: $@'
	@$(MAKE) -C $(SRC)/expression

ex_ncurses:
	@echo 'Building: $@'
	@$(CC) ./example/ex_ncurses.c $(ODIR)/libCED.a -o $(ODIR)/ex_ncurses.exe -lncurses

GetKeyboardState:
	@echo 'Building: $@'
	@$(CC) ./example/GetKeyboardState.c $(ODIR)/libCED.a -o $(ODIR)/GetKeyboardState.exe

clean:
	@echo 'Removing all binaries'
	@rm -rf $(ODIR)/*.exe
	@rm -rf $(ODIR)/*.o