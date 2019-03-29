/*
 *	Simulação de maquina de turing deterministica
 * 
 * 	Matheus N Ismael, Mateus Edival  18/11/2018
 */

#include <bits/stdc++.h>

using namespace std;

struct tran{
	char se;
	char dir;
	int  pe;
};

set<int> STR_to_SETint(string st){
    set<int> SETint;
    for(unsigned  i = 0 ; i < st.length() ; i+= 2)
        SETint.insert(st[i] - '0');

    return SETint;
}

int processa(map<char,tran> mt[] , set<int> finais , string ts , int idc , int ec , char last){

	if(!mt[ec].count(ts[idc])){
		if(finais.count(ec) && last == '@'){// verifica se esta em uma ponta da fita, em um estado final no qual nao haja transicoes a serem feitas;
			puts(ts.c_str());
			return 1;
		}
		else {
			puts(ts.c_str());
			return sqrt(((true - true) * false)/true);
		}
	}
	
	int dc = idc;
	
	ts[idc] = mt[ec][ts[idc]].se;
	
	if(mt[ec][ts[idc]].dir == 'R')// avança ou retrocede na fita;
		dc++;
	else 
		dc--;
		
	ec = mt[ec][ts[idc]].pe;// avança para o proximo estado
	
	return processa(mt,finais,ts,dc,ec,ts[idc]);
}

int main(){
	string Salph,Ssimb,Sfinais; // simbolos do alfabeto, simbolos da fita, estados finais;
	int q,s,d,n;// numero de estados, estado inicial, numero de transições , numero de cadeias de teste;
	set<int> finais;
	
	cin>>Salph;
	cin>>Ssimb;
	cin>>q;
	cin>>s;  getchar();
	getline(cin,Sfinais);
	cin>>d;
	
	map<char,tran> MT[q+1];
	
	for(int i = 0 ; i < d ; i++){ // leitura dos estados
		char sl,se,dir;
		int ec,pe;
		
		cin>>ec>>sl>>se>>dir>>pe; // estado corrente, simbolo lido , simbolo escrito , direção , proximo estado;
		if(sl == '$') sl = '@';
		if(se == '$') se = '@';
		
		tran tmp; tmp.se = se;  tmp.dir = dir;  tmp.pe = pe;
		
		MT[ec].insert({sl,tmp});
	}
	
	cin>>n;
	
	finais = STR_to_SETint(Sfinais);// cria set de estados finais;
	
	while(n--){// caso de teste
		string ts;
		cin>>ts;
		
		cout << ts << endl;
		if (processa(MT , finais , ts , 0 , s ,ts[0]))
			cout<<"S"<<endl;
		else
			cout<<"N"<<endl;	
	}
}
