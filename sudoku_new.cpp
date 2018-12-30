#include <iostream>
#include <cstdlib>
#include<vector>
#include<string>

##ifndef UNASSIGNED
#define UNASSIGNED 0
#endif

##ifndef  N
#define N 9
#endif

class sudokuSolve{
	std::vector<std::string> sudoku;
public:
	sudokuSolve(std::vector <std::string> input_matrix);
	bool unassignedPlaces();
	bool usedInRow(int row,int num);
	bool usedInCol(int row,int col);
	bool usedInBox(int row,int col);
	bool isTrue(int row,int col,int num);
	bool solve();
	void output();
		
};
sudokuSolve::sudokuSolve(std::vector <std::string> input_matrix){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sudoku.at(i).at(j)=input_matrix.at(i).at(j)
		}
	}	
}
bool sudokuSolve::unassignedPlaces(){
	for(auto& i:sudoku){
		for(auto& j:i){
			if(j==UNASSIGNED){
				return true;
			}
		}
	}
	return false;
}
bool sudokuSolve::usedInRow(int row,int num){
	for(int i=0;i<N;i++){
		if(sudoku.at(row).at(i)==num){
			return true;
		}
	}
	return false;
}
bool sudokuSolve::usedInCol(int col,int num){
	for(int =0;i<n;i++){
		if(sudoku.at(i).at(col)==num){
			return true;
		}
	}
	return false;
}
bool sudokuSolve::usedInBox(int boxStartRow,intboxStartCol,int num){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(sudoku.at(i+boxStartRow).at(j+boxStartRow]==num)){
				return true;
			}
		}
	}
	return false;
}

bool sudokuSolve::isTrue(int row,int col,int num ){
	bool usedRow=usedInRow(row,num);
	bool usedCol=usedInCol(col,num);
	bool usedBox=usedInBox(row-row%3,col-col%3,num);
	bool is_True=!(usedRow&&usedBox&&usedCol);
	return is_True;
}
bool sudokuSolve::solve(){
	int row,col;
	if(!unassignedPlaces(row,col)){
		return true;
	}
	for(int num=1,num<=9;num++){
		if(isTrue(row,col,num)){
			sudoku.at(row).at(col)=num;
			if(solve()){
				return true;
			}
			sudoku.at(i).at(j)=UNASSIGNED
		}
	}
	return false;
}
int main(){
	std::vector<std::string> input_matrix;
	std::cout<<"Enter the matrix!"<<endl;
	for(int i=0;i<N;i++){
		std::string input_row_matrix="";
		char temp;
		for(int j=0;j<N;j++){
			cin>>temp;
			input_row_matrix.std::push_back(temp);
		}
	}
	sudokuSolve S(input_row_matrix);
	if(S.solve()){
		S.output();
	}
	else{
		std::cout<<"error"<<endl;
	}
	return 0;
}
