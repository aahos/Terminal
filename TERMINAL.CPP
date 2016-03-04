#include<bits/stdc++.h>
using namespace std;
int main()
{
    string command,choice,echo="aaho>>";
    ifstream infile;
    infile.open("commandlist.txt",ios::in);
    map<string,string> knowncommands;
    map<string,string>::iterator pos;
    string var1,var2;
    while(!infile.eof())
    {
        getline(infile,var1);
        getline(infile,var2);
        knowncommands.insert(make_pair<string,string>(var1,var2));
    }
    infile.close();
    ofstream outfile;
    outfile.open("commandlist.txt",ios::app);
    cout<<echo;
    getline(cin,command);

    while(command!="exit")
    {
        pos=knowncommands.find(command);
        if(pos!=knowncommands.end())
            system(pos->second.c_str());
        else{
            cout<<"command not found!\nWant to save this '"<<command<<"' command: yes or no?\n";
            int valid=0;
            while(valid!=1)
            {
                cin>>choice;
                if(choice=="yes")
                {
                    cout<<"enter what is going to execute: ";
                    getline(cin,choice);
                    while(choice=="")getline(cin,choice);
                    knowncommands.insert(make_pair<string,string>(command,choice));
                    outfile<<command<<endl<<choice<<endl;
                    valid=1;
                }
                else if(choice=="no")
                {
                    valid =1 ;
                }
                else cout<<"!!! Not a valid choice !!!\nRe-enter your choice";
            }
        }
        cout<<echo;
        getline(cin,command);
        while(command=="")getline(cin,command);
    }
    outfile.close();
    return 0;
}
