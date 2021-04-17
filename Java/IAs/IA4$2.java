/**
 * File Name: IA4$2.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-12-11
 * Description: Strassen-Square-Matrix-Multiply
 * Class List:
 *	1. public class IA4$2
 *	2. class SquareMatrix
 * Funcation List:
 *	1. IA4$2::public static void main(String[] args)
 */
public class IA4$2{
	Matrix A = new Matrix(3,3);
	Matrix B = new Matrix(3,3);
	public static void main(String[] args){
		IA4$2 IA = new IA4$2();
		System.out.println("矩阵A：");
		IA.createMatrix(IA.A);
		System.out.println("矩阵B：");
		IA.createMatrix(IA.B);
		try{
			Matrix C = Matrix.matrixMul(IA.A,IA.B);
			System.out.println("矩阵C：");
			for(int i = 0; i < C.getRows(); i++){
				for(int j = 0; j < C.getColumns(); j++){
					System.out.print(C.matrix[i][j] + " ");
				}
				System.out.println("");
			}
			System.out.println("");
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
	public void createMatrix(Matrix A){
		for(int i = 0; i < A.getRows(); i++){
			for(int j = 0; j < A.getColumns(); j++){
				A.matrix[i][j] = (int)(Math.random() * 10);
				System.out.print(A.matrix[i][j] + " ");
			}
			System.out.println("");
		}
		System.out.println("");
	}
}