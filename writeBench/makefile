
ifeq ($(VENDOR),cray)
        CC=cc -dynamic
else
        CC=mpic++
endif

CCFLAGS=
LDFLAGS=-lcasa_tables -lcasa_casa -ladiosstman
TARGET=write_benchmark \
	generate_table

LIB=../libParallelTable.so

all: $(TARGET) cl

$(LIB):
	cd ..; make;

$(TARGET): $(TARGET:=.cc) $(LIB)
	$(CC) $@.cc -o $@ $(CCFLAGS) $(LDFLAGS) $(LIB)

cl: 
	rm -rf *.tab* *.eps *.e* *.o* *.log *.ER *.OU

clean:cl 
	rm -rf $(TARGET) "$(TARGET) 2" "$(TARGET) 3" *.dSYM *.so log

re: clean all

