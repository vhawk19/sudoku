#include <iostream>
#include <cstdlib>
#include<vector>
#include<string>

##ifndef UNASSIGNED
#define UNASSIGNED value
#endif

##ifndef  N
#define N value
#endif

class sudokuSolve{
	std::vector<std::string> sudoku;
public:
	sudokuSolve(std::vector <std::string> input_matrix){
		for(std::auto& i: input_matrix ){
			string row_vector;
			for(std::auto& j: i){
				row_vector+=j;
			sudoku.std::push_back(row_vector);
			}
		}
	}
	bool unassignedPlaces(int row, int col);
	bool usedInRow(int row,int col);
	bool usedInCol(int row,int col);
	bool usedInBox(int row,int col);
	bool isTrue(int row,int col,int num);
	bool solve();
	void output();
};
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
