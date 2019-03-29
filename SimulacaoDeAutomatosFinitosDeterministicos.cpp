/*
 *	Simulação de automatos finitos deterministicos 
 * 
 * 	Matheus N Ismael 09/10/2018
 */


#include <bits/stdc++.h>

using namespace std;

set<char> alph;
set<int>  ef;

set<char> STRalph_to_SETalph(string Salph){
    set<char> SETal;
    for(unsigned i = 0 ; i < Salph.length(); i++)
        SETal.insert(Salph[i]);

    return SETal;
}

set<int> STRefs_to_SETefs(string Sef){
    set<int> SETefs;
    for(unsigned  i = 0 ; i < Sef.length() ; i+= 2)
        SETefs.insert(Sef[i]- '0');

    return SETefs;
}

int processa(map<char,int> autom[], string ts , int idc , int ec){

    if(ts[idc] == '@'){
        if(ef.count(ec))
            return 1;
        return 0;
    }
    if(autom[ec].find(ts[idc]) == autom[ec].end() || alph.find(ts[idc]) == alph.end())
        return 0;

    return processa(autom,ts,idc+1,autom[ec].find(ts[idc])->second);
}

int main(){
    string Salph,Sef;
    int Q,S,D,N;

    cin>>Salph; 
    cin>>Q;    
    cin>>S; getchar(); 
    getline(cin,Sef); 
    cin>>D;    

    map<char,int> autom[Q+1]; //diagrama de estados;

    for(int  i = 0 ; i < D ; i++){  //leitura dos estados
        int x,y;   char c;
        cin>>x>>c>>y;
        autom[x].insert({c,y});
    }

    alph = STRalph_to_SETalph(Salph); // passa os elemenos da string do alfabeto para um set
    ef   = STRefs_to_SETefs(Sef); // passa os elemenos da string dos estados terminais para um set

    cin>>N;

    while(N--){
        string ts;
        cin>>ts;

		cout << ts << endl;
        if(processa(autom,ts,1,S))
            cout<<"S\n";
        else
            cout<<"N\n";
    }
}
