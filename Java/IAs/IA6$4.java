/**
 * File Name: IA6$4.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: 2016-11-27
 * Description: HeapSort( Acending Order)
 * Funcation List:
 * 	1. IA6$4::public static void main( String[])
 * 	2. IA$MaxHeap::heapSort(int[])
 */
public class IA6$4{
	int[] A = new int[100];
	public static void main(String[] args){
		IA6$4 IA = new IA6$4();
		System.out.print("原数组：");
		for(int i = 0; i < IA.A.length; i++){
			IA.A[i] = (int)(Math.random() * 100 + 1);
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
		int[] RS = IA.heapSort(IA.A);
		System.out.print("排序后：");
		for(int i = 0; i < RS.length; i++){
			System.out.print(RS[i] + " ");
		}
		System.out.println("");
	}
	private int[] heapSort(int[] A){
		IA$MaxHeap temp = new IA$MaxHeap(A);
		for(int i = temp.heap_size; i >= 2; i--){
			temp.heap[i - 1] += temp.heap[0];
			temp.heap[0] = temp.heap[i - 1] - temp.heap[0];
			temp.heap[i - 1] -= temp.heap[0];
			temp.heap_size--;
			temp.maxHeapify(0);
		}
		return temp.heap;
	}
}