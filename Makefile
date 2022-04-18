CC = gcc
CFLAGS = -W -Wall
TARGET = product
DTARGET = product debug
OBJECTS = main.c product.o manage.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^ 
clean:
	rm *.o product
