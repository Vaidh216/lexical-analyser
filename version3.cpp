#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,string> p1,pair<int,string> p2){
    return p1.first > p2.first;
}

int main(){
    char ch1[25],ch2[25];
    ch1[24] = '\0';
    ch2[24] = '\0';
    for(int i=0;i<24;i++){;
        ch1[i] = ' ';
    }
    for(int i=0;i<24;i++){
        ch2[i] = ' ';
    }
    
    map<string,int> mp;

    ofstream fout;
    //ifstream fin;
    fout.open("output.txt");
    //fin.open("input.txt");
    FILE *fin;
    fin = fopen("input.txt","r");
    int char_count=0,line_count=0,word_count=0,lexeme_begin=0,forward_pointer=0,flag=0,BUF_SIZE=24,f1=0;

    string word="";

    fout<<"\t\t\t\tAll The lexems are : \n\n";

    while(true){
        f1=0;
        if((flag&1)){
            while(fgets(ch1,BUF_SIZE,fin)){
                f1=1;
                for(forward_pointer=lexeme_begin;forward_pointer<BUF_SIZE && ch1[forward_pointer]!='\0';forward_pointer++){
                    if((ch1[forward_pointer]<='Z' && ch1[forward_pointer]>='A')||(ch1[forward_pointer]<='z' && ch1[forward_pointer]>='a')){
                        word+= ch1[forward_pointer];
                        char_count++;
                    }else if(ch1[forward_pointer] == ' ' && word!=""){
                        fout << word << "\n";
                        word_count++;
                        mp[word]++;
                        word="";
                    }else if(ch1[forward_pointer] == '\n' && word!=""){
                        fout << word << "\n";
                        word_count++;
                        line_count++;
                        mp[word]++;
                        word="";
                    }else if(word!=""){
                        fout << word << "\n";
                        word_count++;
                        mp[word]++;
                        word="";
                    }
                }
            }
            if(f1 == 0){
                break;
            }
        }else{
            while(fgets(ch2,BUF_SIZE,fin)){
                f1=1;
                
                for(forward_pointer=lexeme_begin;forward_pointer<BUF_SIZE && ch2[forward_pointer]!='\0';forward_pointer++){
                    if((ch2[forward_pointer]<='Z' && ch2[forward_pointer]>='A')||(ch2[forward_pointer]<='z' && ch2[forward_pointer]>='a')){
                        word+= ch2[forward_pointer];
                        char_count++;
                    }else if(ch2[forward_pointer] == ' ' && word!=""){
                        fout << word << "\n";
                        word_count++;
                        mp[word]++;
                        word="";
                    }else if(ch2[forward_pointer] == '\n' && word!=""){
                        fout << word << "\n";
                        word_count++;
                        line_count++;
                        mp[word]++;
                        word="";
                    }else if(word!=""){
                        fout << word << "\n";
                        word_count++;
                        mp[word]++;
                        word="";
                    }
                }
            }
            if(f1 == 0){
                break;
            }

        }
        flag = (flag+1)%2;
    }
    if(word != ""){
        fout<<word<<"\n";
        mp[word]++;
        word_count++;
    }

    vector<pair<int,string>> vp;

    for(auto &x:mp){
        vp.push_back({x.second,x.first});
    }
    sort(vp.begin(),vp.end(),comp);

    fout<<"\n\n\t\t\tThe lexems and their number of occurances are as follows : \n";
    
    for(auto &x:vp){
        fout << x.second;
        f1=x.second.length();
        for(;f1<30;f1++){
            fout << " ";
        }
        fout << x.first<<"\n";
    }

    fout<< "\n\n\t\t\t\t\t Code ends \n";


    fout.close();
    fclose(fin);

    cout<<"line count = "<<line_count+1<<"\n";
    cout<<"Word count = "<<word_count<<"\n";
    cout<<"Charater count = "<<char_count<<"\n";
    cout<<"processing completed\n";

}