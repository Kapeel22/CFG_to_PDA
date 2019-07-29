/*  C++ code for Conversion from CFG to PDA  
    AUTHOR = KAPEEL SURYAVANSHI             ENROLLMENT NUMBER = BT16CSE084 */
    
/*Please Note : The input in the file should be space separated.(example : NT = S A B X Y) First Line of file (starting with NT) is set of
non terminal states, second line of file (starting with T) is set of final or terminal states, third line is set of input symbols
and its following lines are production rules.*/

#include<bits/stdc++.h>
#define breakline() cout<<"-------------------------------------------------------------------------\n"
using namespace std;

void CFG_to_PDA(vector<pair<string,vector<string> > >  &gram, vector<string> &nonterm_states, vector<string> &term_states, string start_state)
{
    int i,j;
    cout<<"Grammer given as input :\n";
    cout<<"Start State : "<<start_state<<endl;
    cout<<"Non Terminal States : \n";
    for(i=0 ; i<nonterm_states.size() ; i++)
    {
        cout<<nonterm_states[i]<<"  ";
    }
    cout<<endl;
    cout<<"Terminal States : \n";
    for(i=0 ; i<term_states.size() ; i++)
    {
        cout<<term_states[i]<<"  ";
    }
    cout<<endl;
    cout<<"Production Rule :\n";
    vector<string> t;
    for(i=0 ; i<gram.size() ; i++)
    {
        cout<<gram[i].first<<" -> ";
        t = gram[i].second;
        cout<<t[0];
        for(j=1 ; j<t.size() ; j++)
        {
            cout<<" | "<<t[j];
        }
        cout<<endl;
    }
    breakline();
    
    cout<<"\nCorresponding PDA :\n";
    for(i=0 ; i<gram.size() ; i++)
    {
        cout<<"δ(q,ε,"<<gram[i].first<<") = { (q,";
        t = gram[i].second;
        cout<<t[0]<<")";;
        for(j=1 ; j<t.size() ; j++)
        {
            cout<<" , (q,"<<t[j]<<")";
        }
        cout<<" }"<<endl;
    }
    cout<<endl;
    for(i=0 ; i<term_states.size() ; i++)
    {
        cout<<"δ(q,"<<term_states[i]<<","<<term_states[i]<<") = (q,ε)"<<endl;
    }
    
}

int main()
{
    vector<pair<string,vector<string> > >  gram;
    vector<string> nonterm_states;
    vector<string> term_states;
    
    int i,j;
    string start_state = "";
    string line,ch,t,state;
    ifstream fin;
    fin.open("gram_input");
    
    if(!fin)
    {
        cerr<<"Error in Opening File\n";
        exit(1);
    }  
    while(getline(fin,line))
    {
        istringstream ss(line);
        ss>>ch;
        if(ch == "NT")
        {
            ss>>ch;
            while(ss >> ch)
            {
                nonterm_states.push_back(ch);
            }
            start_state = nonterm_states[0];
        }
        else if(ch == "T")
        {
            ss>>ch;
            while(ss >> ch)
            {
                term_states.push_back(ch);
            }
        }
        else
        {
            state = ch;
            ss>>ch;
            vector<string> temp;
            while(ss >> ch)
            {
                if(ch != "|")
                {
                    temp.push_back(ch);
                }
            }
            gram.push_back(make_pair<string,vector<string> >(state,temp));
        }
    }
    CFG_to_PDA(gram,nonterm_states,term_states,start_state);

    return 0;
}

