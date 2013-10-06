# @file Makefile

.cpp.o:
	g++ -g -o $@ -c $<

Operator1: Operator1.o IntArray.o
	g++ -g -o $@ Operator1.o IntArray.o

Average2: Average2.o InputStream.o Stream.o 
	g++ -g -o $@ Average2.o InputStream.o Stream.o 

Average3: Average3.o ArrayStream.o Stream.o 
	g++ -g -o $@ Average3.o ArrayStream.o Stream.o

Override2: Override2.o ArrayStream.o InputStream.o Stream.o 
	g++ -g -o $@ Override2.o ArrayStream.o InputStream.o Stream.o

Constructor3: Constructor3.o InputStream.o Stream.o
	g++ -g -o $@ Constructor3.o InputStream.o Stream.o

New3: New3.o ArrayStream.o Stream.o 
	g++ -g -o $@ New3.o ArrayStream.o Stream.o

New4: New4.o ArrayStream.o InputStream.o Stream.o 
	g++ -g -o $@ New4.o ArrayStream.o InputStream.o Stream.o

