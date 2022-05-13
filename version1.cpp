#include<bits/stdc++.h>
using namespace std;

int main(){
    int cur=0,f1=0,f2=0,i=0;
    char ch1[25],ch2[25],ch;
    ch1[24] = '\0';
    ch2[24] = '\0';
    string word="";
    for(int i=0;i<24;i++){;

        ch1[i] = ' ';
    }
    for(int i=0;i<24;i++){
        ch2[i] = ' ';
    }
    
    ofstream fout;
    ifstream fin;
    fout.open("output.txt");
    fin.open("input.txt");
    int char_count=0,line_count=0,word_count=0;

    //cout<<"here 4"<<endl;

    while(fin.get(ch)){
        //cout<<ch;
        //cout<<".";
        if((ch<='z' && ch>='a') || (ch<='Z' && ch>='A') || ch==' ' || ch=='\n'){
            if(f1 == 0){
                ch1[cur] = ch;
                cur++;
                if(ch1[cur] == '\0'){
                    f1=1;
                    cur=0;
                }
            }else{
                ch2[cur] = ch;
                cur++;
                if(ch2[cur] == '\0'){
                    f2=1;        
                }
            }
            if(f2 == 1){
            word="";
            // for(int i=0;i<24;i++){
            //     cout<<ch1[i];
            // }
            // cout<<"\n";
            // for(int i=0;i<24;i++){
            //     cout<<ch2[i];
            // }
                for(int i=0;ch1[i]!='\0';i++){
                    if(ch1[i] == ' '){
                        word_count++;
                        //cout<<word<<"\n";
                        fout<<word<<"\n";
                        word="";
                    }else if(ch1[i] == '\n'){
                        line_count++;
                        word_count++;
                        fout<<word<<"\n";
                        word="";
                    }else{
                        word+=ch1[i];
                        char_count++;
                    }
                }
                for(int i=0;ch2[i]!='\0';i++){
                    if(ch2[i] == ' '){
                        word_count++;
                        fout<<word<<"\n";
                        word="";
                    }else if(ch2[i] == '\n'){
                        line_count++;
                        word_count++;
                        fout<<word<<"\n";
                        word="";
                    }else{
                        word+=ch2[i];
                        char_count++;
                    }
                }
                f2=0;
                f1=0;
                cur=0;
                if(word!=""){
                    for(;cur<word.length();cur++){
                        ch1[cur] = word[cur];
                    }
                }
            }
        }
    }
    word="";
    //cout<<"here 5\n";
    if(f1 == 0){
        //cout<<"here 6\n";
        for(int i=0;i<cur;i++){
            if(ch1[i] == ' '){
                word_count++;
                //cout<<word<<"\n";
                fout<<word<<"\n";
                word="";
            }else if(ch1[i] == '\n'){
                line_count++;
                word_count++;
                fout<<word<<"\n";
                word="";
            }else{
                word+=ch1[i];
                char_count++;
            }
        }
        if(word != ""){
            fout<<word<<"\n";
            word_count++;
        }
    }else{
        //cout<<"here 7\n";
        for(int i=0;ch1[i]!='\0';i++){
            if(ch1[i] == ' '){
                word_count++;
                //cout<<word<<"\n";
                fout<<word<<"\n";
                word="";
            }else if(ch1[i] == '\n'){
                line_count++;
                word_count++;
                fout<<word<<"\n";
                word="";
            }else{
                word+=ch1[i];
                char_count++;
            }
        }
        for(int i=0;i<cur;i++){
            if(ch2[i] == ' '){
                word_count++;
                //cout<<word<<"\n";
                fout<<word<<"\n";
                word="";
            }else if(ch2[i] == '\n'){
                line_count++;
                fout<<word<<"\n";
                word="";
            }else{
                word+=ch2[i];
                char_count++;
            }
        }
        if(word!=""){
            fout<<word<<"\n";
            word_count++;
        }
    }
    fin.close();
    fout.close();
    //cout<<"here 1"<<endl;
    cout<<"\n line count = "<<line_count+1<<"\n";
    cout<<"\n Word count = "<<word_count<<"\n";
    cout<<"\n Charater count = "<<char_count<<"\n";
    cout<<"\nprocessing completed\n";
    cout<<endl;
}