  CC = gcc 

  CFLAGS = \
           -std=c99 -Wall -pedantic -Wmaybe-uninitialized -Wuninitialized \
	   -march=native -O3 -imacros namespacing -fPIC -mtune=native -fomit-frame-pointer -fwrapv
  LDFLAGS = -lm 
  INCLUDES = -I.
  SRCDIR = .
  OBJDIR = ../bin

# Gathers the names of all C files 
    CSRC = $(wildcard $(SRCDIR)/*.c) 
# Produces in $(COBJS) the names of .o object files for all C files
   COBJS = $(CSRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	$(CC) -c $(CFLAGS) $(INCLUDES)  $< -o $@ 

.PHONY : all clean

all: $(COBJS) 
	ar rcs $(OBJDIR)/libLEDApkc.a $(COBJS) 
clean:
	$(RM) $(OBJDIR)/*.o  $(OBJDIR)/*.a