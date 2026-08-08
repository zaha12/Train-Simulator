CC = g++

WARN_FLAGS = -Wall -Wextra

DEBUG_FLAGS = -g3 -Og -fno-omit-frame-pointer -fstack-protector-all

CONTROL_FLAGS = -fno-optimize-sibling-calls -fno-ipa-icf -fno-common

SANITIZE_FLAGS = -fsanitize=address \
	-fsanitize=pointer-compare \
	-fsanitize=pointer-subtract \
	-fsanitize=undefined \
	-fsanitize=shift \
	-fsanitize=shift-exponent \
	-fsanitize=shift-base \
	-fsanitize=integer-divide-by-zero \
	-fsanitize=unreachable \
	-fsanitize=vla-bound \
	-fsanitize=null \
	-fsanitize=return \
	-fsanitize=signed-integer-overflow \
	-fsanitize=bounds \
	-fsanitize=bounds-strict \
	-fsanitize=alignment \
	-fsanitize=object-size \
	-fsanitize=float-divide-by-zero \
	-fsanitize=float-cast-overflow \
	-fsanitize=bool \
	-fsanitize=enum \
	-fsanitize=vptr \
	-fsanitize=pointer-overflow \
	-fsanitize=builtin \
	-fsanitize-address-use-after-scope \
	-fno-sanitize-recover=all

CFLAGS = $(WARN_FLAGS) $(DEBUG_FLAGS) $(CONTROL_FLAGS) $(SANITIZE_FLAGS)
LFLAGS = $(CFLAGS)
EXE = exe
SRC = main.cpp
OBJS = main.o
$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

$(OBJS):$(SRC) LinkedList.hpp car.hpp
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJS)

clean:
	rm -v $(OBJS) $(EXE)
