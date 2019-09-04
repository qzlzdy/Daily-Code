/**
 * File Name: IA$p105.java
 * Author: һֻ��������Ʈ����ʵ�����ض�M��
 * Version: 1
 * Date: Ver.1: 2016-12-3
 * Description: Counting-Sort( Acending Order)
 * Funcation List:
 *	1. IA8$2::public static void main(String[])
 *	2. IA8$2::private void countingSort()
 */
public class IA8$2{
	int[] A = new int[100];
	public static void main(String[] args){
		IA8$2 IA = new IA8$2();
		System.out.print("ԭ���飺");
		for(int i = 0; i < IA.A.length; i++){
			IA.A[i] = (int)(Math.random() * 100 + 1);
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
		IA.countingSort();
		System.out.print("�����");
		for(int i = 0; i < IA.A.length; i++){
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
	}
	private void countingSort(){
		int[] B = new int[101];
		int[] C = this.A;
		for(int i = 0; i < C.length; i++)
			B[C[i]]++;
		for(int i = 1; i < B.length; i++)
			B[i] += B[i - 1];
		for(int i = 0; i < this.A.length; i++){
			this.A[B[C[i]] - 1] = C[i];
			B[C[i]]--;
		}
	}
}