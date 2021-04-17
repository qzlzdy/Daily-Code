/**
 * File Name: IA7$1.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-12-3
 * Description: QuickSort( Acending Order)
 * Funcation List:
 * 	1. IA7$1::public static void main(String[])
 * 	2. IA7$1::private void quickSort(int r,int p)
 * 	3. IA7$1::private int partition(int r,int p)
 */
public class IA7$1{
	int[] A = new int[100];
	public static void main(String[]args){
		IA7$1 IA = new IA7$1();
		System.out.print("原数组：");
		for(int i = 0; i < IA.A.length; i++){
			IA.A[i] = (int)(Math.random() * 100 + 1);
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
		IA.quickSort( 0, IA.A.length - 1);
		System.out.print("排序后：");
		for(int i = 0; i < IA.A.length; i++){
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
	}
	private void quickSort(int r,int p){
		if(p > r){
			int q = this.partition( r, p);
			this.quickSort(r, q - 1);
			this.quickSort(q + 1, p);
		}
	}
	private int partition(int r,int p){
		int i = r;
		for(int j = r; j < p; j++){
			if(this.A[j] <= this.A[p]){
				int k = this.A[i];
				this.A[i] = A[j];
				this.A[j] = k;
				i++;
			}
		} 
		int k = this.A[i];
		this.A[i] = A[p];
		this.A[p] = k;
		return i;
	}
}