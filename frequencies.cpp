//
//  main.cpp
//  CS130b-pa1
//
//  Created by Peter Ding on 4/24/18.
//  Copyright © 2018 Peter Ding. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    int arr[256] = {};
    string line = " ";
    while(!cin.eof()){
        char c = cin.get();
        arr[int(c)]++;
    }
//    while(getline(cin,line)&&line.length()>0){
//        arr[10]++;
//        for(int i = 0; i<line.length();i++){
//            char c = line[i];
//            arr[int(c)]++;
//        }
//    }
    for(int i = 0; i < 256;i++){
        if(arr[i]>0){
            cout<<i<<"\t"<<arr[i]<<endl;
        }
    }
    
    return 0;
}

