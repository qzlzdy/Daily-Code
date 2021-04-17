/**
 * File Name: IA8$3.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-12-11
 * Description: Radix-Sort(Acending Order)
 * Funcation List:
 *	1. IA8$3::public static void main(String[] args)
 *	2. IA8$3::private void radixSort()
 */
public class IA8$3{
	int[] A = new int[50];
	public static void main(String[] args){
		IA8$3 IA = new IA8$3();
		System.out.print("原数组：");
		for(int i = 0; i < IA.A.length; i++){
			IA.A[i] = (int)(Math.random() * 900 + 100);
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
		IA.radixSort();
		System.out.print("排序后：");
		for(int i = 0; i < IA.A.length; i++){
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
	}
	private void radixSort(){
		for(int k = 0; k <= 2; k++){
			for(int i = 1; i < this.A.length; i++){
				int p = this.A[i];
				int j = i - 1;
				while ((j >= 0)&&(this.A[j]  / Math.pow(10,k) % 10 > p / Math.pow(10,k) % 10)){
					this.A[j + 1] = this.A[j];
					j--;
				}
				if(j != i - 1)
					this.A[j + 1] = p;
			}
		}
	}
}