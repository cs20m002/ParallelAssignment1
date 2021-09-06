#include<iostream>
#include<algorithm>
using namespace std;

void KeyMapPair(float sf1, int rightbound, int* rangeMap){
	int zRange = sf1*rightbound;
	int incre = (rightbound - zRange)/9;
	for (int i = 0; i < 10; ++i)
	{	
		if(i==9) rangeMap[i] = rightbound;
		else rangeMap[i] = zRange + i*incre;
	}

	// Testing the cumulative array  
	// for (int i = 0; i < 10; ++i)
	// {
	// 	cout << rangeMap[i] << " ";
	// }
}

int getVal(int x, int *rangeMap){
	if(binary_search(rangeMap, rangeMap+10, x)){
		int ans = (lower_bound(rangeMap, rangeMap+10, x) - rangeMap);
		return ans;
	}else{
		int ans = (lower_bound(rangeMap, rangeMap+10, x) - rangeMap);
		if(ans==0) return ans;
		else return ans-1;
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	// row and column for Mat [A]
	int row1, col1;
	cin >> row1 >> col1;

	// my random number can lie within [0,rightbound] range with equal prob.
	int rightbound=1000;

	// sparsity for Mat[A]
	float sf1;
	cin >> sf1;

	// create keyMapPair
	int rangeMap1[10];
	KeyMapPair(sf1,rightbound, rangeMap1);

	// elements of Mat[A] will fall in range [0,10]
	int A[row1][col1];
	for(int i=0; i<row1; i++){
		for(int j=0; j<col1; j++){
			int temp = rand()%rightbound;
			A[i][j] = getVal(temp,rangeMap1);
		}
	}


	// {Print the value of A}
	for(int i=0; i<row1; i++){
		for(int j=0; j<col1; j++){
			cout << A[i][j] << "\t";
		}cout << "\n";
	}

	// row and column for Mat [B]
	int row2, col2;
	cin >> row2 >> col2;

	// sparsity for Mat[B]
	float sf2;
	cin >> sf2;

	// create keyMapPair
	int rangeMap2[10];
	KeyMapPair(sf2,rightbound, rangeMap2);

	// elements of Mat[B] will fall in range [0,10]
	int B[row2][col2];
	for(int i=0; i<row2; i++){
		for(int j=0; j<col2; j++){
			int temp = rand()%rightbound;
			B[i][j] = getVal(temp,rangeMap2);
		}
	}

	// {Print the value of A}
	for(int i=0; i<row2; i++){
		for(int j=0; j<col2; j++){
			cout << B[i][j] << "\t";
		}cout << "\n";
	}

	int C[row1][col2];
	for (int i = 0; i < row1; ++i)
	{
		for (int j = 0; j < col2; ++j)
		{
			for (int k = 0; k < col1; ++k)
			{
				C[i][j] = A[i][k] + B[k][j]; 
			}
		}
	}

	// {Print the value of C}
	for(int i=0; i<row1; i++){
		for(int j=0; j<col2; j++){
			cout << C[i][j] << "\t";
		}cout << "\n";
	}

	return 0;
}