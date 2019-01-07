# Tool invocations
CC=cc
YACC=yacc
LEX=lex
SRC=src
ODIR=output

CFLAGS=-I$(SRC) -I$(ODIR)
LIBS=

calc3:
	@echo 'Building: $@'
	@mkdir -p $(ODIR)
	@$(YACC) -v -db $(ODIR)/calc3 $(SRC)/calc3.y
	@$(LEX) -o $(ODIR)/calc3.c $(SRC)/calc3.l
	@$(CC) $(CFLAGS) $(LIBS) -o $(ODIR)/calc3 $(ODIR)/calc3.c $(ODIR)/calc3.tab.c

calc:
	@echo 'Building: $@'
	@mkdir -p $(ODIR)
	@$(YACC) -v -db $(ODIR)/calc $(SRC)/calc.y
	@$(LEX) -o $(ODIR)/calc.c $(SRC)/calc.l
	@$(CC) $(CFLAGS) $(LIBS) -c -o $(ODIR)/calc.o $(ODIR)/calc.c
	@$(CC) $(CFLAGS) $(LIBS) -c -o $(ODIR)/calc.tab.o $(ODIR)/calc.tab.c

package: calc
	@echo 'Building: $@'
	@ar -rcs $(ODIR)/libcalc.a $(ODIR)/calc.o $(ODIR)/calc.tab.o

main: calc package
	@echo 'Building: $@'
	@$(CC) $(CFLAGS) $(LIBS) -o $(ODIR)/calc $(SRC)/main.c $(ODIR)/libcalc.a

clean:
	@echo 'Removing all binaries'
	@rm -rf $(ODIR)/