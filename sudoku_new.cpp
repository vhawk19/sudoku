#include <iostream>
#include <cstdlib>
#include<vector>
#include<string>

#ifndef UNASSIGNED
#define UNASSIGNED 0
#endif

#ifndef  N
#define N 9
#endif

class sudokuSolve{
	std::vector<std::string> sudoku;
public:
	sudokuSolve(std::vector <std::string> input_matrix);
	bool unassignedPlaces(int& row,int& col);
	bool usedInRow(int row,int num);
	bool usedInCol(int col,int num);
	bool usedInBox(int row,int col,int num);
	bool isTrue(int row,int col,int num);
	bool solve();
	void output();

};
sudokuSolve::sudokuSolve(std::vector <std::string> input_matrix){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sudoku.at(i).at(j)=input_matrix.at(i).at(j);
		}
	}
}
bool sudokuSolve::unassignedPlaces(int& row,int& col ){
	for(row=0;row<N;row++){
		for(col=0;col<N;col++){
			if(sudoku.at(row).at(col)==UNASSIGNED){
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
	for(int i=0;i<N;i++){
		if(sudoku.at(i).at(col)==num){
			return true;
		}
	}
	return false;
}
bool sudokuSolve::usedInBox(int boxStartRow,int boxStartCol,int num){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(sudoku.at(i+boxStartRow).at(j+boxStartRow)==num){
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
	for(int num=1;num<=9;num++){
		if(isTrue(row,col,num)){
			sudoku.at(row).at(col)=num;
			if(solve()){
				return true;
			}
			sudoku.at(row).at(col)=UNASSIGNED;
		}
	}
	return false;
}
void sudokuSolve::output(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			std::cout<<sudoku.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
}
int main(){
	std::vector<std::string> input_matrix;
	std::cout<<"Enter the matrix!\n";
	for(int i=0;i<N;i++){
		std::string input_row_matrix="";
		char temp;
		for(int j=0;j<N;j++){
			std::cin>>temp;
			input_row_matrix.push_back(temp);
		}
		input_matrix.push_back(input_row_matrix);
	}
	sudokuSolve S(input_matrix);
	if(S.solve()){
		S.output();
	}
	else{
		std::cout<<"error";
	}
	return 0;
}
