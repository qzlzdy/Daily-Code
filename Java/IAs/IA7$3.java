/**
 * File Name: IA7$3.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-12-3
 * Description: Randomize-QuickSort( Acending Order)
 * Funcation List:
 * 	1. IA7$3::public static void main(String[])
 * 	2. IA7$3::private void rQuickSort(int r,int p)
 * 	3. IA7$3::private int rPartition(int r,int p)
 */
public class IA7$3{
	int[] A = new int[100];
	public static void main(String[]args){
		IA7$3 IA = new IA7$3();
		System.out.print("原数组：");
		for(int i = 0; i < IA.A.length; i++){
			IA.A[i] = (int)(Math.random() * 100 + 1);
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
		IA.rQuickSort( 0, IA.A.length - 1);
		System.out.print("排序后：");
		for(int i = 0; i < IA.A.length; i++){
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
	}
	private void rQuickSort(int r,int p){
		if(p > r){
			int q = this.rPartition( r, p);
			this.rQuickSort(r, q - 1);
			this.rQuickSort(q + 1, p);
		}
	}
	private int rPartition(int r,int p){
		int x = (int)(Math.random() * (p - r + 1) + r);
		int temp; //用于数据交换
		temp = this.A[x];
		this.A[x] = A[p];
		this.A[p] = temp;
		int i = r;
		for(int j = r; j < p; j++){
			if(this.A[j] <= x){
				temp = this.A[i];
				this.A[i] = A[j];
				this.A[j] = temp;
				i++;
			}
		} 
		temp = this.A[i];
		this.A[i] = A[p];
		this.A[p] = temp;
		return i;
	}
}