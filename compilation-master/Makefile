LDFLAGS	      = -fPIC 

all: compiler robot

compiler:
	@echo "Compilation des fichiers d'analyses lexicale/semantique..."
	@make -C src/ -s


robot: robot-bin

robot-llvm: src/parse enseirbot.bot
	@echo -n "Generation llvm..."	
	@src/parse enseirbot.bot > drive.ll
	@echo "OK"

robot-bin: robot-llvm obj/drive.o obj/driver.o
	@echo -n "Generation du binaire..."
	@gcc -shared -Wl,-soname,-enseirBOT obj/drive.o obj/driver.o -o enseirBOT.so $(LDFLAGS)
	@echo "OK"

obj/drive.o: drive.ll
	@echo -n "Compilation llvm..."
	@clang -c -o $@ $^ $(LDFLAGS)

clean:
	@rm -f drive.ll *~ obj/drive.o *.so
	@make clean -C src -s
