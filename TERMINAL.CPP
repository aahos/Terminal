#include<bits/stdc++.h>
using namespace std;
int main()
{
    string command,choice,echo="aaho>>",action;
    ifstream infile;
    infile.open("commandlist.txt",ios::in);
    map<string,string> knowncommands;
    map<string,string>::iterator pos;
    string var1,var2;
    while(!infile.eof())
    {
        getline(infile,var1);
        getline(infile,var2);
        if(var1!="")
        knowncommands.insert(make_pair<string,string>(var1,var2));
    }
    infile.close();
    ofstream outfile;
    //outfile.open("commandlist.txt",ios::app);
    cout<<echo;
    getline(cin,command);

    while(command!="exit")
    {
        if(command== "list")
            {
                cout<<endl<<endl;
                for(pos=knowncommands.begin();pos!=knowncommands.end();pos++)
                    cout<<pos->first<<"\t- "<<pos->second<<endl;
                    cout<<endl<<endl;
            }
        else if(command=="modify")
            {
                cout<<"Enter the command to be modified : ";
                cin>>command;
                pos=knowncommands.find(command);
                if(pos!=knowncommands.end())
                {
                    cout<<"Enter 'delete' to remove command or anything else to change action : ";
                    getline(cin,action);
                    while(action=="")getline(cin,action);
                    if(action=="delete")
                        knowncommands.erase(pos);
                    else knowncommands[command]=action;
                    outfile.open("commandlist.txt",ios::out);
                    for(pos=knowncommands.begin();pos!=knowncommands.end();pos++)
                        outfile<<pos->first<<endl<<pos->second<<endl;
                    outfile.close();
                }
                else   cout<<"Command doesn't exist"<<endl;
           }

            else{
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
                            outfile.open("commandlist.txt",ios::app);
                            outfile<<command<<endl<<choice<<endl;
                            outfile.close();
                            valid=1;
                        }
                        else if(choice=="no")
                        {
                            valid =1 ;
                        }
                        else cout<<"!!! Not a valid choice !!!\nRe-enter your choice";
                    }
                }
            }
        cout<<echo;
        getline(cin,command);
        while(command=="")getline(cin,command);
    }
    outfile.close();
    return 0;
}
