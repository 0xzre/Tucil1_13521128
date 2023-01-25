
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cstdlib>


using namespace std;

int jumlahSolusi = 0;
string solusi;
stringstream ss;

bool isCardValid(int * cards){
    for(int i = 0; i < 4; i++){
        
        if(cards[i] < 1 || cards[i] > 13){
            cout << "Masukan kartu tidak valid" << endl;
            return false;
        }
    }
    return true;
}


int convertToValue(char X){
    if (X == 'J'){
        return 11;
    }
    else if(X == 'Q'){
        return 12;
    }
    else if(X == 'K'){
        return 13;
    }
    else if(X == 'A'){
        return 1;
    }
    else if(X - '0' > 0 && X - '0' < 10){
        return X - '0';

    }
    else{
        return 999999999;
    }
}

char convertToChar(int X){
    if(X == 1){
        return 'A';
    }
    else if(X == 11){
        return 'J';
    }
    else if(X == 12){
        return 'Q';
    }
    else if(X == 13){
        return 'K';
    }
    else{
        return X + '0';
    }
}


float operateOp(float a, float b, int op){
    if( a == 999999999 || b == 999999999){
        return 999999999;
    }
    else{
        if(op == 0){
            return a + b;
        }
        else if(op == 1){
            return a - b;
        }
        else if(op == 2){
            return a * b;
        }
        else if(op == 3){
            if( b == 0)
                return 999999999;
            else
                return a / b;
        }
    }
}

bool is24(float result){
    if( result > 23.9 && result < 24.1){
        return true;
    }
    else{
        return false;
    }
}

char charOp(int op){
    if(op == 0){
        return '+';
    }
    else if(op == 1){
        return '-';
    }
    else if(op == 2){
        return '*';
    }
    else if(op == 3){
        return '/';
    }
}


void calculateCard(int a, int b, int c, int d, int op1, int op2, int op3, int * listCards){
    float w,x, y, z;
    
    w = float(listCards[a]);
    x = float(listCards[b]);
    y = float(listCards[c]);
    z = float(listCards[d]);

    float result = 0;

    /* Kurung ke 1 */
 

    result = operateOp(operateOp(operateOp(w, x, op1), y, op2), z, op3);
    if(is24(result)){
        cout << "((" << convertToChar(listCards[a]) << " " << charOp(op1) << " " << convertToChar(listCards[b]) << ") " << charOp(op2) << " " << convertToChar(listCards[c]) << ") " << charOp(op3) << " " << convertToChar(listCards[d]) << endl;
        ss << "((" << convertToChar(listCards[a]) << " " << charOp(op1) << " " << convertToChar(listCards[b]) << ") " << charOp(op2) << " " << convertToChar(listCards[c]) << ") " << charOp(op3) << " " << convertToChar(listCards[d]) << '\n';
        
        jumlahSolusi++;
    }

    result = operateOp(operateOp(w, operateOp(x, y, op2), op1), z, op3);
    if(is24(result)){
        cout << "(" << convertToChar(listCards[a]) << " " << charOp(op1) << " (" << convertToChar(listCards[b]) << " " << charOp(op2) << " " << convertToChar(listCards[c]) << ")) " << charOp(op3) << " " << convertToChar(listCards[d]) << endl;
        ss << "(" << convertToChar(listCards[a]) << " " << charOp(op1) << " (" << convertToChar(listCards[b]) << " " << charOp(op2) << " " << convertToChar(listCards[c]) << ")) " << charOp(op3) << " " << convertToChar(listCards[d]) << '\n';
        jumlahSolusi++;
    }

    result = operateOp(w, operateOp(operateOp(x, y, op2), z, op3), op1);
    if(is24(result)){
        cout << convertToChar(listCards[a]) << " " << charOp(op1) << " ((" << convertToChar(listCards[b]) << " " << charOp(op2) << " " << convertToChar(listCards[c]) << ") " << charOp(op3) << " " << convertToChar(listCards[d]) << ")" << endl;
        ss << convertToChar(listCards[a]) << " " << charOp(op1) << " ((" << convertToChar(listCards[b]) << " " << charOp(op2) << " " << convertToChar(listCards[c]) << ") " << charOp(op3) << " " << convertToChar(listCards[d]) << ")" << '\n';
        jumlahSolusi++;
    }

    result = operateOp(w, operateOp(x, operateOp(y, z, op3), op2), op1);
    if(is24(result)){
        cout << convertToChar(listCards[a]) << " " << charOp(op1) << " (" << convertToChar(listCards[b]) << " " << charOp(op2) << " (" << convertToChar(listCards[c]) << " " << charOp(op3) << " " << convertToChar(listCards[d]) << "))" << endl;
        ss << convertToChar(listCards[a]) << " " << charOp(op1) << " (" << convertToChar(listCards[b]) << " " << charOp(op2) << " (" << convertToChar(listCards[c]) << " " << charOp(op3) << " " << convertToChar(listCards[d]) << "))" << '\n';
        jumlahSolusi++;
    }

    result = operateOp(operateOp(w, x, op1), operateOp(y, z, op3), op2);
    if(is24(result)){
        cout << "(" << convertToChar(listCards[a]) << " " << charOp(op1) << " " << convertToChar(listCards[b]) << ") " << charOp(op2) << " (" << convertToChar(listCards[c]) << " "<< charOp(op3) << " " << convertToChar(listCards[d]) << ")" << endl;
        ss << "(" << convertToChar(listCards[a]) << " " << charOp(op1) << " " << convertToChar(listCards[b]) << ") " << charOp(op2) << " (" << convertToChar(listCards[c]) << " "<< charOp(op3) << " " << convertToChar(listCards[d]) << ")" << '\n';
        jumlahSolusi++;
    }



}


int main(){
	char opsiInput;
	int cards [4];
    char cardsChar [4];
    int counter;
    

    /* Memilih masukan dari kartu yang akan dipakai */
	cout << "Input Keyboard? (Y/N)\n";
	cin >> opsiInput;
    do{
	if(opsiInput == 'Y'){
		
		cout << "Masukkan Input 4 Kartu\n";
		
		ws(cin);
		

        string S, T;
  
        getline(cin, S);
  
        stringstream X(S);

        counter = 0;
        while (getline(X, T, ' ')) {
            counter++;
        }

        if(counter != 4){
            cout << "Inputan tidak valid" << endl;
            continue;
        }

        else{
            stringstream Y(S);
            for(int i = 0; i < 4; i++){
                getline(Y, T, ' ');
                cardsChar[i] = T[0];
                cards[i] = convertToValue(cardsChar[i]);
            }
        }


	}
	else if(opsiInput == 'N'){
        srand(time(NULL));
		for(int i = 0; i < 4 ; i++){
			cards[i] = (rand())%13 + 1;
            cardsChar[i] = convertToChar(cards[i]);
			
		}
        cout << "Kartu yang dipakai adalah: " << cardsChar[0] << " " << cardsChar[1] << " " << cardsChar[2] << " " << cardsChar[3] << endl;
	}
	else{
		cout << "Mohon Masukan Input Yang Valid\n";
		cout << "Input Keyboard? (Y/N)\n";
		cin >> opsiInput;
		continue;
	}
    } while(isCardValid(cards) == false);
	

    /* Brute Force */

    /* Looping Cards*/
    double startT = time(0);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(j != i){
                for(int k = 0; k < 4; k++){
                    if(k != i && k != j){
                        for(int l = 0; l < 4; l++){
                            if(l != i && l != j && l != k){


                                /* Operation Loops*/
                                for(int m = 0; m < 4 ; m++){
                                    for(int n = 0; n < 4; n++){
                                        for(int o = 0; o < 4 ; o++){
                                            calculateCard(i,j,k,l,m,n,o,cards);
                                        }
                                    }
                                }
                            }
                        }

                        
                    }
                }
            }
        }
    }
    double endT = time(0);
    printf("Waktu yang dibutuhkan : %f detik\n", endT-startT);
    if(jumlahSolusi == 0){
        cout << "Tidak ada solusi" << endl;
        cout << "Apakah Anda ingin menyimpannya?(Y/N)\n";
        cin >> opsiInput;
        if(opsiInput == 'Y'){
            cout << "Masukkan nama file: \n";
            string namaSolusi;
            ws(cin);
            getline(cin,namaSolusi);
            namaSolusi = "../test/" + namaSolusi + ".txt";
            int length = namaSolusi.length();
            char* namaSolusiChar = new char[length + 1];
            strcpy(namaSolusiChar, namaSolusi.c_str());
            ofstream file;
            
            file.open(namaSolusiChar);
            file << "Kartu yang dipakai adalah: " << cardsChar[0] << " " << cardsChar[1] << " " << cardsChar[2] << " " << cardsChar[3] << endl;
            file << "Tidak Ditemukan solusi" << endl;
           
            
            file.close();
            cout << "Solusi disimpan di " << namaSolusi << endl;
        }
        else if(opsiInput == 'N'){
            cout << "Solusi tidak disimpan" << endl;
        }
        else{
            cout << "Input tidak valid" << endl;
        }
    }
    else {
        cout << "Ditemukan " << jumlahSolusi << " solusi" << endl;
        cout << "Apakah Anda ingin menyimpan solusi?(Y/N)\n";
        cin >> opsiInput;
        if(opsiInput == 'Y'){
            cout << "Masukkan nama file solusi: \n";
            string namaSolusi;
            ws(cin);
            getline(cin,namaSolusi);
            namaSolusi = "../test/" + namaSolusi + ".txt";

            int length = namaSolusi.length();
            char* namaSolusiChar = new char[length + 1];
            strcpy(namaSolusiChar, namaSolusi.c_str());
            ofstream file;
            solusi = ss.str();
            file.open(namaSolusiChar);
            file << "Kartu yang dipakai adalah: " << cardsChar[0] << " " << cardsChar[1] << " " << cardsChar[2] << " " << cardsChar[3] << endl;
            file << "Ditemukan " << jumlahSolusi << " solusi" << endl;
            file << "Solusi: " << endl;
            file << solusi;
            file.close();
            cout << "Solusi disimpan di " << namaSolusi << endl;
        }
        else if(opsiInput == 'N'){
            cout << "Solusi tidak disimpan" << endl;
        }
        else{
            cout << "Input tidak valid" << endl;
        }
    }
   


}
