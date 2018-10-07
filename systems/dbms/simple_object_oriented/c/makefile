objects = main.o parsecsv.o vector/vector.o parser/parser.o table.o database.o \
	tuple.o

simple_object_orientated : $(objects)
	cc -o simple_object_orientated $(objects)

vector/gen_vector.h : vector/vector.h
	touch vector/gen_vector.h

vector/vector.o : vector/gen_vector.h
parsecsv.o : parsecsv.h  vector/gen_vector.h
parser/parser.o : parser/parser.h vector/gen_vector.h
tuple.o : tuple.h table.h database.h vector/gen_vector.h
table.o : table.h database.h vector/gen_vector.h
database.o: database.h table.h vector/gen_vector.h

.PHONY : clean
clean :
	-rm simple_object_orientated $(objects)
