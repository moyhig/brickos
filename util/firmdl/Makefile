### ==========================================================================
###  $Id: Makefile,v 1.9 2003/03/02 18:00:42 paolom Exp $
###  FILE: util/firmdl/Makefile - make firmware download utility
###  brickOS - the independent LEGO Mindstorms OS
### --------------------------------------------------------------------------

# specify environment before including the common stuff
BUILDING_HOST_UTILS = true
include ../../Makefile.common

ifneq (,$(findstring $(OSTYPE),Darwin))
	LDFLAGS   += -m32
	CFLAGS    += -m32 -DNQC_RCXLIB -DUSE_TRANSPORT -I..
	CXXFLAGS  += $(CFLAGS) -I$(NQC_ROOT)/rcxlib -I$(NQC_ROOT)/platform
	LIBS      += -lstdc++
	LIBS      += -Wl,-framework -Wl,IOKit -Wl,-framework -Wl,CoreFoundation
	NQC_OBJS  += nqc_rcxlib.o \
		$(NQC_ROOT)/rcxlib/RCX_USBTowerPipe_osx.o \
		$(NQC_ROOT)/rcxlib/RCX_Pipe.o \
		$(NQC_ROOT)/rcxlib/RCX_PipeTransport.o \
		$(NQC_ROOT)/rcxlib/RCX_Transport.o
endif

FIRMDL3 = firmdl3$(EXT)
MKIMG = mkimg$(EXT)
MAN1 = firmdl3.1

ALL_TARGETS = ../$(FIRMDL3) $(MKIMG) 

all:: fastdl.h $(ALL_TARGETS)
	@# nothing to do here but do it silently

$(MKIMG): mkimg.o srec.o
	$(CC) $^ -o $@ $(CFLAGS)

ifneq (,$(findstring $(OSTYPE),Darwin))
../$(FIRMDL3): firmdl.o srec.o rcx_comm.o $(NQC_OBJS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIBS)
else
../$(FIRMDL3): firmdl.o srec.o rcx_comm.o
	$(CC) $^ -o $@ $(CFLAGS)
endif

fastdl.h: $(MKIMG) fastdl.srec
	./$(MKIMG) fastdl.srec > $@

nqc_rcxlib.o: ../nqc_rcxlib.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

depend::
	@# nothing to do here but do it silently

install: install-stamp 
	@# nothing to do here but do it silently

install-stamp: $(ALL_TARGETS) $(MAN1)
	cp -f ../$(FIRMDL3) $(bindir)
	@if [ ! -d ${mandir}/man1 ]; then \
		mkdir -p ${mandir}/man1; \
	fi
	cp -f $(MAN1) $(mandir)/man1/$(MAN1)
	@touch $@

uninstall:
	rm -f $(mandir)/man1/$(MAN1) $(bindir)/$(FIRMDL3) install-stamp

clean:
	rm -f *.o *~ *.bak

realclean: clean
	rm -f fastdl.h $(ALL_TARGETS)
	@rm -f install-stamp

# remove debug symbols
strip:
	strip $(ALL_TARGETS)

.PHONY: realclean clean install depend all


### --------------------------------------------------------------------------
###                   End of FILE: util/firmdl/Makefile
### ==========================================================================
