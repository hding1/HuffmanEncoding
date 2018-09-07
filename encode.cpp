//
//  main.cpp
//  encode
//
//  Created by Peter Ding on 4/27/18.
//  Copyright © 2018 Peter Ding. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    ifstream source;
    source.open(argv[1]);
    string line;
    map<int,string> codes;
    while(getline(source,line)&&line.length()>0){
        int num1 = 0;
        string word = "";
        bool space = false;
        for(int i = 0; i<line.length();i++){
            if(!isspace(line[i])&&line[i]!='\t'){
                word += line[i];
                space = false;
            }else if(!space){
                num1 = stoi(word);
                word = "";
                space = true;
            }
        }
        codes.insert(make_pair(num1,word));
    }
    queue<char> inputs;
    int sum = 0;
    bitset<8> output;
    int count = 7;
    while(!cin.eof()){
        char c = cin.get();
        inputs.push(c);
        sum+=codes[int(c)].length();
    }
    unsigned char bytes[4];
    unsigned long n = sum;
    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = n & 0xFF;
    cout<<bytes[0]<<bytes[1]<<bytes[2]<<bytes[3];
    while(!inputs.empty()){
        char c = inputs.front();
        string code = codes[int(c)];
        for(int i = 0; i<code.length();i++){
            if(count<0){
                unsigned long i = output.to_ulong();
                unsigned char c = static_cast<unsigned char>( i );
                cout<<c;
                output.reset();
                count = 7;
            }
            output.set(count,int(code[i])-48);
            count--;
        }
        inputs.pop();
    }
    if(count!=7){
        unsigned long i = output.to_ulong();
        unsigned char c = static_cast<unsigned char>( i );
        cout<<c;
    }
    return 0;
}
