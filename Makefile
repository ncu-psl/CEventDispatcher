CC=gcc
SRC=src
ODIR=output

EXPR= ./src/expression/output/calc.o ./src/expression/output/calc.tab.o

libCED.a: expression CED.o
	@echo 'Building: $@'
	@ar -rcs $(ODIR)/libCED.a $(ODIR)/CED.o $(EXPR)

test: libCED.a
	@echo 'Building: $@'
	@$(CC) $(SRC)/test.c $(ODIR)/libCED.a -o $(ODIR)/test.exe

CED.o:
	@echo 'Building: $@'
	@$(CC) $(SRC)/CED.c -c -o $(ODIR)/CED.o

expression:
	@echo 'Building: $@'
	@$(MAKE) -C $(SRC)/expression

ex1_KeyboardEvent:
	@echo 'Building: $@'
	@$(CC) ./example/ex1_KeyboardEvent.c $(ODIR)/libCED.a -o $(ODIR)/ex1_KeyboardEvent.exe -lncurses

ex2_KeyboardCED:
	@echo 'Building: $@'
	@$(CC) ./example/ex2_KeyboardCED.c $(ODIR)/libCED.a -o $(ODIR)/ex2_KeyboardCED.exe -lncurses

ex3_TrafficLight:
	@echo 'Building: $@'
	@$(CC) ./example/ex3_TrafficLight.c $(ODIR)/libCED.a -o $(ODIR)/ex3_TrafficLight.exe

ex4_VendingMachine:
	@echo 'Building: $@'
	@$(CC) ./example/ex4_VendingMachine.c $(ODIR)/libCED.a -o $(ODIR)/ex4_VendingMachine.exe

ex5:
	@echo 'Building: $@'
	@$(CC) -c ./example/ex5/E_Insert_coin.c -o $(ODIR)/ex5/E_Insert_coin.o
	@$(CC) -c ./example/ex5/E_Select_option.c -o $(ODIR)/ex5/E_Select_option.o
	@$(CC) -c ./example/ex5/E_Coffee_ready.c -o $(ODIR)/ex5/E_Coffee_ready.o
	@$(CC) -c ./example/ex5/VenderSubscribe.c -o $(ODIR)/ex5/VenderSubscribe.o
	@$(CC) ./example/ex5/ex5_VendingMachine2.c -o $(ODIR)/ex5/ex5_VendingMachine2.exe \
	$(ODIR)/ex5/VenderSubscribe.o $(ODIR)/ex5/E_Insert_coin.o $(ODIR)/ex5/E_Select_option.o $(ODIR)/ex5/E_Coffee_ready.o \
	$(ODIR)/libCED.a


GetKeyboardState:
	@echo 'Building: $@'
	@$(CC) ./example/GetKeyboardState.c $(ODIR)/libCED.a -o $(ODIR)/GetKeyboardState.exe

clean:
	@echo 'Removing all binaries'
	@rm -rf $(ODIR)/*.exe
	@rm -rf $(ODIR)/*.o