#include<iostream>
#include<fstream>
#include<string.h>
#include <cstdio>  // for fgets()
using namespace std;

#include<iostream>
#include<fstream>
#include<string.h>
#include <cstdio>  // for fgets()
using namespace std;
void write(string filename,string str)
{
    ofstream fout;
    fout.open(filename,ios::out);
    fout<<str;
    fout.close();
    cout<<"\nyour content has been written \n";
}
void read(string filename)
{
    char ch;
    ifstream fin;
    fin.open(filename,ios::in);
    if(!fin)
        cout<<filename<<"file not found"<<endl;
    else{
        ch=fin.get();
        while(!fin.eof())
        {
            cout<<ch;
            ch=fin.get();
        }
    }
    fin.close();
}
void append(string filename,string str)
{
    ofstream fout;
    fout.open(filename,ios::app);
    fout<<str;
    fout.close();
    cout<<"\nyour content has been written \n";
}
string get_multi_line_input()
{   
    cout<<"Enter your content (type '<--end-->' on a new line to finish)\n";
    string str,multi_line;
    getline(cin,str);
    while(str != "<--end-->")
    {
        multi_line+=str+'\n';
        getline(cin,str);
    }
    return multi_line;
}
int main()
{
    int x;
    while(1)
    {
        cout<<"\nPlease enter your choice from the following : "<<endl;
        cout<<"\n1. Write in a file\n2. Append in a file\n3. Read a file\n4. Exit\n";
        cin>>x;
        switch(x)
        {
            case 1:{
                string filename,content;
                cout<<"\nenter the name of file :\n";
                fflush(stdin);
                getline(cin,filename);
                content=get_multi_line_input();
                write(filename,content); 
                break;
            }
            case 2:{
                string filename,content;
                cout<<"\nenter the name of file :\n";
                fflush(stdin);
                getline(cin,filename);
                content=get_multi_line_input();
                append(filename,content);    
                break;
            }
            case 3:{
                char filename[30];
                cout<<"enter the name of file : \n";
                fflush(stdin);
                fgets(filename,sizeof(filename),stdin);
                filename[strlen(filename)-1]='\0';
                read(filename);
                break;
            }
            case 4:{
                exit(0);
                break;
            }
            default:
                cout<<"invalid choice ! please try again \n";
        }
    }
}     

// ************* for manuall memory allocation ********************

/*
void write(char filename[],char str[])
{
    ofstream fout;
    fout.open(filename,ios::out);
    fout<<str;
    fout.close();
    cout<<"\nyour content has been written \n";
}
void read(char filename[])
{
    char ch;
    ifstream fin;
    fin.open(filename,ios::in);
    if(!fin)
        cout<<filename<<"file not found"<<endl;
    else{
        ch=fin.get();
        while(!fin.eof())
        {
            cout<<ch;
            ch=fin.get();
        }
    }
    fin.close();
}
void append(char filename[],char str[])
{
    ofstream fout;
    fout.open(filename,ios::app);
    fout<<str;
    fout.close();
    cout<<"\nyour content has been written \n";
}
int main()
{
    int x;
    while(1)
    {
        cout<<"\nPlease enter your choice from the following : "<<endl;
        cout<<"\n1. Write in a file\n2. Append in a file\n3. Read a file\n4. Exit\n";
        cin>>x;
        switch(x)
        {
            case 1:{
                char ch;
                char *q,*p;
                int i=1;
                char filename[30];
                cout<<"enter the file name\n";
                fflush(stdin);
                fgets(filename,sizeof(filename),stdin);
                filename[strlen(filename)-1]='\0';
                cout<<endl;
                cout<<"file name is "<<filename;
                cout<<"write your content and press enter at the end :\n";
                ch=getchar();
                p=new char[1];
                q=new char[1];
                p[0]=ch;
                q[0]=p[0];
                delete[] p;
                while(ch!='\n')
                {
                    ch=getchar();
                    p=new char[i+1];
                    for(int j=0;j<i;j++){
                        p[j]=q[j];
                    }
                    p[i]=ch;
                    delete[] q;
                    q=new char[i+1];
                    for(int j=0;j<=i;j++){
                        q[j]=p[j];
                    }
                    delete[] p;
                    i++;
                }   
                char *str=new char[i-1];
                for(int j=0;j<i-1;j++)
                    str[j]=q[j];
                str[i-1]='\0';
                delete[] q;
                write(filename,str);
                delete[] str;
                break;
            }
            case 2:{
                char ch;
                char *q,*p;
                int i=1;
                char filename[30];
                cout<<"enter the file name\n";
                fflush(stdin);
                fgets(filename,sizeof(filename),stdin);
                filename[strlen(filename)-1]='\0';
                cout<<endl;
                cout<<" write your content and press enter at the end :\n";
                ch=getchar();
                p=new char[1];
                q=new char[1];
                p[0]=ch;
                q[0]=p[0];
                delete[] p;
                while(ch!='\n')
                {
                    ch=getchar();
                    p=new char[i+1];
                    for(int j=0;j<i;j++){
                        p[j]=q[j];
                    }
                    p[i]=ch;
                    delete[] q;
                    q=new char[i+1];
                    for(int j=0;j<=i;j++){
                        q[j]=p[j];
                    }
                    delete[] p;
                    i++;
                }   
                char *str=new char[i-1];
                for(int j=0;j<i-1;j++)
                    str[j]=q[j];
                str[i-1]='\0';
                delete[] q;
                append(filename,str);
                delete[] str;
                break;
            }
            case 3:{
                char filename[30];
                cout<<"enter the name of file : \n";
                fflush(stdin);
                fgets(filename,sizeof(filename),stdin);
                filename[strlen(filename)-1]='\0';
                read(filename);
                break;
            }
            case 4:{
                exit(0);
                break;
            }
            default:
                cout<<"invalid choice ! please try again \n";
        }
    }
}
*/