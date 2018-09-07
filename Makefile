all: frequencies huffman encode decode

frequencies: frequencies.cpp
	g++ -o frequencies frequencies.cpp
huffman: huffman.cpp
	g++ -o huffman huffman.cpp
encode: encode.cpp
	g++ -o encode encode.cpp
decode: decode.cpp
	g++ -o decode decode.cpp
clean:
	rm -f frequencies huffman encode decode
	rm -fr *.dSYM