main: main.cc main.hh
	env LDFLAGS="$(pkg-config --libs zlib)" make main.o
	g++ main.cc main.hh -o main
