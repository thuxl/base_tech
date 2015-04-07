all: psortedListToBST ptest0001 ptest0002 ptest0002 ptest0004g++ ptest0004gcc ptest0005 ptest0006 ptest0007
clean:
	rm p*

psortedListToBST: sortedListToBST.cc 
	g++ -g sortedListToBST.cc -o psortedListToBST
ptest0001: test0001.cc 
	g++ test0001.cc -o ptest0001
ptest0002: test0002.cc 
	g++ test0002.cc -o ptest0002
ptest0003: test0003.cc 
	g++ test0003.cc -o ptest0003
ptest0004g++: test0004.cc 
	g++ test0004.cc -o ptest0004g++
ptest0004gcc: test0004gcc.cc 
	gcc test0004gcc.cc -o ptest0004gcc
ptest0005: test0005.cc 
	g++ test0005.cc -o ptest0005
ptest0006: test0006.cc 
	g++ test0006.cc -o ptest0006
ptest0007: test0007.cc 
	g++ test0007.cc -o ptest0007
