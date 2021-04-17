/**
 * File Name: Matrix.java
 * Author:  一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-12-31
 * Description: A Math Class
 * Funcation List:
 *	1. Matrix::public int getRows()
 *	2. Matrix::public int getColumns()
 *	3. Matrix::public static Matrix matrixAdd(Matrix A,Matrix B)
 *	4. Matrix::private static Matrix matrixAdd(Matrix A,int[] posA,int[] posB)
 *	5. Matrix::public static Matrix matrixSub(Matrix A,Matrix B)
 *	6. Matrix::private static Matrix matrixSub(Matrix A,int[] posA,int[] posB)
 *	7. Matrix::public static Matrix matrixMul(Matrix A,int x)
 *	8. Matrix::public static Matrix matrixDiv(Matrix A,int x)
 *	9. Matrix::public static Matrix squareMatrixLargen(Matrix A,int rows)throws MatrixExc
 *	10. Matrix::public static Matrix matrixMul(Matrix A,Matrix B)throws MatrixExc
 *	11. Matrix::private static Matrix StrassenMul(Matrix A,Matrix B)
 */
class Matrix{
	private int rows;
	private int columns;
	double[][] matrix;
	public Matrix(){
	}
	public Matrix(int rows,int columns){
		this.rows = rows;
		this.columns = columns;
		this.matrix = new double[rows][columns];
	}
	private Matrix(Matrix A,int[] pos){
		this.rows = pos[2];
		this.columns = pos[2];
		this.matrix = new double[pos[2]][pos[2]];
		for(int i = 0; i < pos[2]; i++){
			for(int j = 0; j < pos[2]; j++){
				this.matrix[i][j] = A.matrix[i + pos[0]][j + pos[1]];
			}
		}
	}
	public int getRows(){
		return this.rows;
	}
	public int getColumns(){
		return this.columns;
	}
	public static Matrix matrixAdd(Matrix A,Matrix B){
		Matrix temp = new Matrix(A.rows,A.columns);
		for(int i = 0; i < A.rows; i++){
			for(int j = 0; j < A.columns; j++){
				temp.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
			}
		}
		return temp;
	}
	private static Matrix matrixAdd(Matrix A,int[] posA,int[] posB){
		Matrix temp = new Matrix(posA[2],posA[2]);
		for(int i = 0; i < posA[2]; i++){
			for(int j = 0; j < posA[2]; j++){
				temp.matrix[i][j] = A.matrix[i + posA[0]][j + posA[1]] + A.matrix[i + posB[0]][j + posB[1]];
			}
		}
		return temp;
	}
	public static Matrix matrixSub(Matrix A,Matrix B){
		Matrix temp = new Matrix(A.rows,A.columns);
		for(int i = 0; i < A.rows; i++){
			for(int j = 0; j < A.columns; j++){
				temp.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
			}
		}
		return temp;
	}
	private static Matrix matrixSub(Matrix A,int[] posA,int[] posB){
		Matrix temp = new Matrix(posA[2],posA[2]);
		for(int i = 0; i < posA[2]; i++){
			for(int j = 0; j < posA[2]; j++){
				temp.matrix[i][j] = A.matrix[i + posA[0]][j + posA[1]] - A.matrix[i + posB[0]][j + posB[1]];
			}
		}
		return temp;
	}
	public static Matrix matrixMul(Matrix A,int x){
		Matrix temp = new Matrix(A.rows,A.columns);
		for(int i = 0; i < A.rows; i++){
			for(int j = 0; j < A.columns; j++){
				temp.matrix[i][j] = A.matrix[i][j] = x;
			}
		}
		return temp;
	}
	public static Matrix matrixDiv(Matrix A,int x){
		Matrix temp = new Matrix(A.rows,A.columns);
		for(int i = 0; i < A.rows; i++){
			for(int j = 0; j < A.columns; j++){
				temp.matrix[i][j] = A.matrix[i][j] / x;
			}
		}
		return temp;
	}
	public static Matrix squareMatrixLargen(Matrix A,int rows)throws MatrixExc{
		if((rows < A.rows)||(rows < A.columns))
			throw new MatrixExc("NewRowsIsSmallerThanCurrentRowsOrColumns");
		Matrix temp = new Matrix(rows,rows);
		for(int i = 0; i < A.rows; i++){
			for(int j = 0; j < A.columns; j++){
				temp.matrix[i][j] = A.matrix[i][j];
			}
		}
		return temp;
	}
	public static Matrix matrixMul(Matrix A,Matrix B)throws MatrixExc{
		if(A.columns != B.rows)
			throw new MatrixExc("IncompatibleDimensions");
		int original_rows = A.rows;
		int original_columns = B.columns;
		Matrix RS = new Matrix(original_rows,original_columns);
		int k = 1;
		while(k < IA$Math.max(A.rows,B.rows,B.columns))
			k *= 2;
		try{
			A = squareMatrixLargen(A,k);
			B = squareMatrixLargen(B,k);
			Matrix temp = StrassenMul(A,B);
			for(int i = 0; i < RS.rows; i++){
				for(int j = 0; j < RS.columns; j++){
					RS.matrix[i][j] = temp.matrix[i][j];
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
		return RS;
	}
	private static Matrix StrassenMul(Matrix A,Matrix B){
		Matrix RS = new Matrix(A.rows,A.columns);
		if(A.rows == 1)
			RS.matrix[0][0] = A.matrix[0][0] * B.matrix[0][0];
		else{
			int[] pos11 = {0,0,A.rows / 2};
			int[] pos12 = {0,A.rows / 2,A.rows / 2};
			int[] pos21 = {A.rows / 2,0,A.rows / 2};
			int[] pos22 = {A.rows / 2,A.rows / 2,A.rows / 2};
			Matrix[] S = new Matrix[10];
			S[0] = matrixSub(B,pos12,pos22);	//S0 = B12 - B22
			S[1] = matrixAdd(A,pos11,pos12);	//S1 = A11 + A12
			S[2] = matrixAdd(A,pos21,pos22);	//S2 = A21 + A22
			S[3] = matrixSub(B,pos21,pos11);	//S3 = B21 - B11
			S[4] = matrixAdd(A,pos11,pos22);	//S4 = A11 + A22
			S[5] = matrixAdd(B,pos11,pos22);	//S5 = B11 + B22
			S[6] = matrixSub(A,pos12,pos22);	//S6 = A12 - A22
			S[7] = matrixAdd(B,pos21,pos22);	//S7 = B21 + B22
			S[8] = matrixSub(A,pos11,pos21);	//S8 = A11 - A21
			S[9] = matrixAdd(B,pos11,pos12);	//S9 = B11 + B12
			Matrix[] P = new Matrix[7];
			P[0] = StrassenMul(new Matrix(A,pos11),S[0]);	//P0 = A11·S0 = A11·B12 - A11·B22
			P[1] = StrassenMul(S[1],new Matrix(B,pos22));	//P1 = S1B·22 = A11·B22 + A12·B22
			P[2] = StrassenMul(S[2],new Matrix(B,pos11));	//P2 = S2·B11 = A21·B11 + A22·B11
			P[3] = StrassenMul(new Matrix(A,pos22),S[3]);	//P3 = A22·S3 = A22·B21 - A22·B11
			P[4] = StrassenMul(S[4],S[5]);	//P4 = S4·S5 = A11·B11 + A11·B22 + A22·B11 + A22·B22
			P[5] = StrassenMul(S[6],S[7]);	//P5 = S6·S7 = A12·B21 + A12·B22 - A22·B21 - A22·B22
			P[6] = StrassenMul(S[8],S[9]);	//P6 = S8·S9 = A11·B11 + A11·B12 - A21·B11 - A21·B12
			for(int i = 0; i < pos11[2]; i++){
				for(int j = 0; j < pos11[2]; j++){
					RS.matrix[i + pos11[0]][j + pos11[1]] = P[4].matrix[i][j] + P[3].matrix[i][j] - P[1].matrix[i][j] + P[5].matrix[i][j];
					RS.matrix[i + pos12[0]][j + pos12[1]] = P[0].matrix[i][j] + P[1].matrix[i][j];
					RS.matrix[i + pos21[0]][j + pos21[1]] = P[2].matrix[i][j] + P[3].matrix[i][j];
					RS.matrix[i + pos22[0]][j + pos22[1]] = P[4].matrix[i][j] + P[0].matrix[i][j] - P[2].matrix[i][j] - P[6].matrix[i][j];
				}
			}
		}
		return RS;
	}
}
class MatrixExc extends Exception{
	public MatrixExc(){
	}
	public MatrixExc(String s){
		super(s);
	}
}