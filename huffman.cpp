//
//  huffman.cpp
//  CS130b-pa1
//
//  Created by Peter Ding on 4/25/18.
//  Copyright © 2018 Peter Ding. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <map>
using namespace std;

class node
{
public:
    node(){
        data = -1;
    };
    node(int input){
        data = input;
        left = NULL;
        right = NULL;
    }
    node(int input,node* myLeft, node* myRight){
        data = input;
        left = myLeft;
        right = myRight;
    }
    int data;
    struct node *left;
    struct node *right;
};

struct tree{
    node* root;
};

class Compare
{
public:
    bool operator()(pair<int,node* > n1,pair<int,node*> n2) {
        return n1.first>n2.first;
    }
};
// function to print leaf
// nodes from left to right
void printLeafNodes(node* root, string code, ofstream& out,map<int,string> &codes)
{
    // if node is null, return
    if (!root)
        return;
    string left_code = code;
    string right_code = code;
    // if node is leaf node, print its data
    if (!root->left && !root->right)
    {
        codes.insert(make_pair(root->data,code));
        out << root->data << " "<< code<< endl;
        return;
    }
    
    // if left child exists, check for leaf
    // recursively
    if (root->left){
        left_code += '0';
        printLeafNodes(root->left,left_code,out,codes);
    }
    
    // if right child exists, check for leaf
    // recursively
    if (root->right){
        right_code = code +'1';
        printLeafNodes(root->right,right_code,out,codes);
    }
}

int main(int argc, const char * argv[]) {
    int arr[256] = {};
    priority_queue<pair<int,node*>,vector< pair<int,node*> >,Compare> result;
    string line = " ";
    while(getline(cin,line)&&line.length()>0){
        int num1 = 0;
        int num2 = 0;
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
        num2 = stoi(word);
        arr[num1] = num2;
        result.push(make_pair(num2,new node(num1)));
    }
    while(result.size()>=2){
        pair<int,node*> node1= result.top();
        result.pop();
        pair<int,node*> node2= result.top();
        result.pop();
        int freq_sum = node1.first + node2.first;
        node* newNode = new node();
        if(node1.first<node2.first){
            newNode->left = node1.second;
            newNode->right = node2.second;
        }else{
            newNode->left = node2.second;
            newNode->right = node1.second;
        }
        result.push(make_pair(freq_sum,newNode));
    }
    ofstream out("codewords.txt");
//    out.open("codewords.txt");
    map<int, string> codes;
    line ="";
    printLeafNodes(result.top().second,line,out,codes);
    int sum = 0;
    out<<endl;
    for(int i = 0;i<256;i++){
        if(arr[i]>0){
            sum += arr[i]*codes[i].length();
        }
    }
    cout<<sum<<endl;
    out.close();
    return 0;
}
//32    5
