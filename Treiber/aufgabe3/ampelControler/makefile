# Author:   M. Thaler
# Version:  v.fs19

CMP=		gcc
CMPFLAGS=       -std=gnu99
EXENAM=		ampelController
LIBNAME=

compile:	$(EXENAM)

$(EXENAM):	$(EXENAM).o
		$(CMP)  $(CMPFLAGS) $(EXENAM).o -o $@.e

.c.o:
		$(CMP) -c $(CMPFLAGS) $<

clean:
		rm -f *.o 
		rm -f *.e

all:
		touch *.c*
		make
