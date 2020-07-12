CXX = g++
WARN = -Wall
CFLAGS = $(WARN)
LDFLAGS = $(WARN) -lecf

OBJS = FastaParser.o \
       MsaEvalOp.o \
       MsaGenotypeCrsOnePoint.o \
       MsaGenotypeMut.o \
       MsaGenotypeMutInsertGap.o \
       MsaGenotypeMutDeleteGap.o \
       MsaGenotype.o \
       main.o

BINFILE = funcmin

.PHONY = all clean

all: $(BINFILE)

$(BINFILE): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(BINFILE)

%.o: %.cpp  MsaGenotype.h MsaGenotypeMut.h MsaGenotypeCrsOnePoint.h FastaParser.h MsaEvalOp.h
	$(CXX) $(CFLAGS) $< -c -o $@

clean:
	rm -f *~ $(OBJS) $(BINFILE)
