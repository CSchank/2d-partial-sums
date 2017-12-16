CFLAGS = -Wall -O2 -std=c99 -pedantic
all: example_constant example_mean_filt

example_constant: example_constant.o partialsums.o
	$(CC) $(CFLAGS) -o $@ $?

example_mean_filt: example_mean_filt.o partialsums.o
	$(CC) $(CFLAGS) -o $@ $?

c: clean

clean:
	rm *.o example_constant example_mean_filt