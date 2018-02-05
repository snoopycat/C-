#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#define N 10010

using namespace std;

string preorder, inorder;

void rebuild(string pre, string in, int index, char tree[])
{
    char root = pre[0];
    int i = 0;
    while(in[i] != root)
        ++i;
    tree[index] = root;
    string leftin = in.substr(0,i), rightin = in.substr(i+1,in.length()-i-1);
    string leftpre = pre.substr(1,i), rightpre = pre.substr(i+1,pre.length()-i-1);
    if(leftin.length() && leftpre.length())
        rebuild(leftpre,leftin,2*index,tree);
    if(rightin.length() && rightpre.length())
        rebuild(rightpre,rightin,2*index+1,tree);
}

int main()
{
    cin >> preorder >> inorder;
    char tree[1010];
    memset(&tree,0,sizeof(tree));
    rebuild(preorder,inorder,1,tree);
    int i = 1, j = 2;
    cout << tree[1];
    while(i < preorder.length()){
        if(tree[j] == 0){
            cout << " NULL";
            ++j;
        }
        else{
            cout << " " << tree[j];
            ++j;
            ++i;
        }
    }
    return 0;
}
