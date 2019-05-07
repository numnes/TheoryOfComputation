/*
 *	Simulação de gramaticas regulares
 * 
 * 	Mateus Edival 09/10/2018
 * 
 */

#include <bits/stdc++.h>

using namespace std;

map<char,vector<string> > gram;
set<char> alph;

set<char> STR_to_SET(string str){
    set<char> st;
    for(unsigned i = 0 ; i < str.length(); i++)
        st.insert(str[i]);
    return st;
}

int processa(string stTST , unsigned idc , char Nterm){
	
	int ret = 0;
	
    if(stTST[idc] == '@'){
		int vazio = 0;
		
		for(unsigned  i = 0 ; i < gram.find(Nterm)->second.size() ; i++)
			if(gram.find(Nterm)->second[i] == "#")
				vazio = 1;
        if(vazio)
            return 1;
        return 0;
    }
    if(idc == stTST.length() - 2){
        for(unsigned  i = 0 ; i < gram.find(Nterm)->second.size() ; i++)
            if(gram.find(Nterm)->second[i][0] == stTST[idc] && gram.find(Nterm)->second[i].length() == 1)
                return 1;
    }
    if(!alph.count(stTST[idc]))
		return 0;

    for(unsigned i = 0 ; i < gram.find(Nterm)->second.size() ; i++){
        if(gram.find(Nterm)->second[i][0] == stTST[idc])
            ret += processa( stTST , idc+1 ,gram.find(Nterm)->second[i][1]);
    }

    return ret;
}

int main(){
    
    string nterm,Salph;
    char Sini;
    int P,C;

    cin>>nterm;
    cin>>Salph;
    cin>>Sini;
    cin>>P;

    alph = STR_to_SET(Salph);

    for(unsigned i = 0 ; i < nterm.size() ; i++){
        vector<string> temp;
        gram.insert({nterm[i],temp});
    }
  
    for(int  i = 0 ; i < P ; i++){
        string c,d,e;
        
        cin >> c >> d >> e;
        gram[c[0]].push_back(e);
    }
    
    cin>>C;
    
    while(C--){
        string ts;
        cin>>ts;
    
        cout << ts << endl;
        if(processa(ts,1,Sini))
             cout<<"S\n";
        else
            cout<<"N\n";
    }
}
