#include <iostream>
#include <ctime>
using namespace std;
int table[300];

void tablulate(string x){
    for(int i =0;i<300;i++){
        table[i] = x.length();
    }
    for (int  j = 0; j < x.length()-1; j++)
    {
        table[x[j]] = x.length() - 1 - j;
    }
}

int search(string seq, string pattern){
    tablulate(pattern);
    int i = pattern.length()-1;
    if(pattern.length()>seq.length()){
        return -1;
    }
    while(i<seq.length()){
        int k = 0;
        while (k<=pattern.length()-1 && pattern[pattern.length()-1-k] == seq[i-k])
        {
            k +=1;
        }
        if(k==pattern.length()){
            return i - pattern.length() +1;
        }
        else{
            i += table[seq[i]];
        }
    }
    return -1;
}

int main(){
    string seq = "jimsawmeinabarbershop";
    string pat = "shop";
    int index = search(seq,pat);
    cout << index << endl;
    return 1;
}



