CFLAGS=-g 
LIBS=
INCLUDE= ./XDR_V1.0.9/ 
srcPATH=./XDR_V1.0.9
src =  xdrfile.cpp $(srcPATH)/xdrBaseType_xdr.c $(srcPATH)/xdrDCP_xdr.c
src+= $(srcPATH)/xdrEOD_xdr.c $(srcPATH)/xdrSLE_xdr.c
all:
	g++ -o a.out  $(src) $(CFLAGS)  $(LIBS)  