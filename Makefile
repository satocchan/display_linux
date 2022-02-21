CCFLAGS=-std=c++17 -Wall -O2 -g -I../freetype-2.11.0/include\
       $(shell pkg-config --cflags opencv4) \

LDFLAGS=$(shell pkg-config --libs opencv4) -L../freetype-2.11.0/build -lfreetype\
		-lpng16 -lz 

main: main.o
	g++ -o $@ $^ $(LDFLAGS) 

random: random.cc
	g++ -o $@ $^ 

main.o: main.cc
	g++ $(CCFLAGS) -c -o $@ $^

main_ver2: main_ver2.o
	g++ -o $@ $^ $(LDFLAGS) 

main_ver2.o: main_ver2.cc
	g++ $(CCFLAGS) -c -o $@ $^

0125: 0125.o
	g++ -o $@ $^ $(LDFLAGS) 

0125.o: 0125.cpp
	g++ $(CCFLAGS) -c -o $@ $^

sobel: sobel.o
	g++ -o $@ $^ $(LDFLAGS) 

sobel.o: sobel.cc
	g++ $(CCFLAGS) -c -o $@ $^


sobel_example: sobel_example.o
	g++ -o $@ $^ $(LDFLAGS) 

sobel_example.o: sobel_example.cc
	g++ $(CCFLAGS) -c -o $@ $^

clean:
	rm main main.o main2 main2.o