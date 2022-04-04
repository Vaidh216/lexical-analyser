#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int cur=0,f1=0,f2=0,i=0;
    char ch1[25],ch2[25],ch;
    ch1[24] = '\0';
    ch2[24] = '\0';
    for(int i=0;i<24;i++){;
        ch1[i] = ' ';
    }
    for(int i=0;i<24;i++){
        ch2[i] = ' ';
    }
    
    ofstream fout;
    //ifstream fin;
    fout.open("output.txt");
    //fin.open("input.txt");
    FILE *fin;
    fin = fopen("input.txt","r");
    int char_count=0,line_count=0,word_count=0,ind_first=0,ind_second=0;

    string word="";

    while(fgets(ch2,24,fin) ){
        word="";
        for(int i=0;i<ind_first && ch1[i]!= '\0';i++){
            if((ch1[i]<='Z' && ch1[i]>='A')||(ch1[i]<='z' && ch1[i]>='a')){
                word+= ch1[i];
                char_count++;
            }else if(ch1[i] == ' ' && word!=""){
                fout << word << "\n";
                word_count++;
                word="";
            }else if(ch1[i] == '\n' && word!=""){
                fout << word << "\n";
                word_count++;
                line_count++;
                word="";
            }
        }
        for(int i=0;i<25 && ch2[i]!='\0';i++){
            if((ch2[i]<='Z' && ch2[i]>='A')||(ch2[i]<='z' && ch2[i]>='a')){
                word+= ch2[i];
                char_count++;
            }else if(ch2[i] == ' ' && word!=""){
                fout << word << "\n";
                word_count++;
                word="";
            }else if(ch2[i] == '\n' && word!=""){
                fout << word << "\n";
                word_count++;
                line_count++;
                word="";
            }
        }
        for(int i=0;i<word.length();i++){
            ch1[i] = word[i];
        }
        ind_first = word.length();
    }
    word = "";
    for(int i=0;i<ind_first && ch1[i]!= '\0';i++){
            if((ch1[i]<='Z' && ch1[i]>='A')||(ch1[i]<='z' && ch1[i]>='a')){
                word+= ch1[i];
                char_count++;
            }else if(ch1[i] == ' ' && word!=""){
                fout << word << "\n";
                word="";
                word_count++;
            }else if(ch1[i] == '\n' && word!=""){
                fout << word << "\n";
                word_count++;
                word="";
                line_count++;
            }
        }
        if(word != ""){
            fout<<word<<"\n";
            word_count++;
        }


    fout.close();
    fclose(fin);

    cout<<"line count = "<<line_count+1<<"\n";
    cout<<"Word count = "<<word_count<<"\n";
    cout<<"Charater count = "<<char_count<<"\n";
    cout<<"processing completed\n";


    // int count = 500;
    // char str[500];
    // FILE *fp;
    
    // fp = fopen("input.txt","r");
    // // fputs("An example file\n", fp);
    // // fputs("Filename is file.txt\n", fp);
    
    // cout<<"here1\n";
    
    // while(fgets(str,count,fp)){
    //     cout << str << endl;
    // }
    // cout<<"here2\n";
    
    // fclose(fp);
    // return 0;

}