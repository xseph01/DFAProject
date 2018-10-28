#include<iostream> 
#include<string>
#include<sstream>
#include<math.h>
using namespace std;
int main() {
	char sym[10][10];
	int table[10][10];
	string input;
	char inp[3], option[10], option1[10];
	int state = 0,  final[10]; 
	int in = 0, path =0, first = 0, stringCount = 0, stateHolder = 0, cnvrtdOpt, cnvrtdOpt1,ctr = 0;
	cout << "Enter number of symbols: ";
	cin >> in;
	
	for(int i = 0; i<in; i++ ){
			cin.ignore();
			cin >> sym[i][0];
	}
	
	cout << "\n";
	cout << "Enter number of states: ";
	cin >> state;
	stateHolder = state;
	cout << "Start state is q0\n";
	for(int i=0; i<state; i++){
		for(int a = 0; a < in; a++){
			cout << "(q" << i << ", " << sym[a][0] << ") = q";
			cin >> path;
			table[i][a] = path; // dito ka gagawa ng transition table base sa symbols mo. Halimbawa 2 symbols mo tapos 3 states. So 6 transitions yon
			cout << "\n";		// STATES MULTIPLIED BY SYMBOLS(ALPHABET) = TRANSITION
			
			
			if(a == 1){
				cout << "Is q" <<i << " final state? [Y/N]: ";
				cin >> option1;
				cnvrtdOpt1 = (int) option1[0];
				
				if(cnvrtdOpt1 == 89 || cnvrtdOpt1 == 121){
					cout << "HEY! " << i;
			 		final[ctr]= i;
			 		ctr++;
			 	}
			 	
			 	else{
			 		continue;
				}
				
			}	
			
		}	
	}
	first = (int)sym[0][0]; // typecasting para kahit char yung input magagamit
	
	do{
		state = 0;
		cout << "Enter a String: "; cin >> input;
	for (int i = 0; i<input.length(); i++){
		cout<<"(q"<<state<<", "<<input[i]<<") = q";
		state = table[state][input[i] - first]; // para makuha yung state ichecheck sa table for example state0 ka [0][0 - 0] = yung value ng [0][0] sa table 
		cout<<state<<endl;						// diba sa example ni sir 1 yung first transition edi yung unang traverse nya is sa state 1. So yung state = 1.
	}
	
	for(int i = 0; i < ctr; i++){
		cout << "Hey: " << final[i] + in;
		if(state == final[i]){ 
		
			 cout<<input<<" String accepted!\n";
			 cout << "Do you want to continue [Y/N]: ";
			 cin >> option;
			 cnvrtdOpt = (int)option[0];//typecasting ulet di kase direktang nababasa yung input sa ganitong compiler
			 if(cnvrtdOpt == 110 || cnvrtdOpt == 78){
			 	return 0;
			 }
			 }
		else {
		
			cout<<"\nNot accepted!";
			cout << "Do you want to continue [Y/N]: ";
			cin >> option;
			cnvrtdOpt = (int)option[0];
			if(cnvrtdOpt == 110 || cnvrtdOpt == 78){
			 	return 0;
			 }
	}
	
	}
	}while(option != "N" || option != "n");
	
}
