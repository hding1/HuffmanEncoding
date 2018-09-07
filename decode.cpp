//
//  main.cpp
//  decode
//
//  Created by Peter Ding on 4/28/18.
//  Copyright © 2018 Peter Ding. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    ifstream source;
    source.open(argv[1]);
    string line;
    map<string,int> codes;
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
        codes.insert(make_pair(word,num1));
    }
    unsigned char ascii;
    string result = "";
    unsigned char a[4];
    cin.get( reinterpret_cast <char&> (a[3]) );
    cin.get( reinterpret_cast <char&> (a[2]) );
    cin.get( reinterpret_cast <char&> (a[1]) );
    cin.get( reinterpret_cast <char&> (a[0]) );
    int x = *(int*)a;
    while (cin.get( reinterpret_cast <char&> (ascii) ))
    {
        bitset<8> mySet(ascii);
        for(int i = 7;i>=0;i--){
            if(x>0){
                if(mySet[i]==1){
                    result+='1';
                }else{
                    result+='0';
                }
                if(codes.find(result)!=codes.end()){
                    char x = char(codes[result]);
                    cout<<x;
                    result = "";
                }
            }
            x--;
        }
    }
}
