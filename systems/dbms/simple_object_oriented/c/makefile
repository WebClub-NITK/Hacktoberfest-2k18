objects = main.o \
 parsecsv.o \
 vector/vector.o \
 parser/parser.o \
 relation.o \
 database.o \
 tuple.o \
 string.o \
 string_vec.o \

CFLAGS = -Wall -Werror

simple_object_orientated : $(objects)
	cc -o simple_object_orientated $(objects)



database.h : vector/gen_vector.h relation.h
relation.h : vector/gen_vector.h tuple.h
string.h : vector/gen_vector.h
string_vec.h : vector/gen_vector.h
tuple.h : vector/gen_vector.h
vector/gen_vector.h : vector/vector.h

database.o : database.h relation.h string_vec.h string.h
main.o : string_vec.h string.h database.h parser/parser.h vector/gen_vector.h
parsecsv.o : parsecsv.h  vector/gen_vector.h
parser/parser.o : parser/parser.h vector/gen_vector.h
relation.o : relation.h tuple.h string.h parsecsv.h
string.o : string.h
string_vec.o : string_vec.h string.h
tuple.o : tuple.h relation.h database.h vector/gen_vector.h string.h
vector/vector.o : vector/gen_vector.h

.PHONY : clean
clean :
	-rm simple_object_orientated $(objects)
