/**
 * File Name: IA$Heap.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-11-27
 * Description: a Data Structure
 * Class List:
 * 	1. class IA$Heap
 * 	2. class IA$MaxHeap extends IA$Heap
 * 	3. class IA$MinHeap extends IA$Heap
 * Funcation List: 
 * 	1. IA$Heap::public static int parent(int i)
 * 	2. IA$Heap::public static int left(int i)
 * 	3. IA$Heap::public static int right(int i)
 * 	4. IA$MaxHeap::public void maxHeapify(int i)
 * 	5. IA$MaxHeap::public void buildMaxHeap()
 *	6. IA$MaxHeap::public int heapMaximum()
 *	7. IA$MaxHeap::public int heapExtractMax()throws IA$HeapExc
 *	8. IA$MaxHeap::public void heapIncreaseKey(int i,int key)throws IA$HeapExc
 *	9. IA$MaxHeap::public void maxHeapInsert(int key)throws IA$HeapExc
 * 	10. IA$MinHeap::public void minHeapify(int i)
 * 	11. IA$MinHeap::public void buildMinHeap()
 */
class IA$Heap{
	protected int[] heap;
	protected int heap_size;
	public IA$Heap(){
		this(new int[5]);
	}
	public IA$Heap(int[] A){
		this.heap = A;
		this.heap_size = A.length;
	}
	public static int parent(int i){
		return (i - 1) / 2;
	}
	public static int left(int i){
		return 2 * i + 1;
	}
	public static int right(int i){
		return (i + 1) * 2;
	}
}
class IA$MaxHeap extends IA$Heap{
	public IA$MaxHeap(){
		super();
	}
	public IA$MaxHeap(int[] A){
		super(A);
		this.buildMaxHeap();
	}
	public void maxHeapify(int i){
		int max = i;
		if((left(i) < this.heap_size)&&(this.heap[max] < this.heap[left(i)]))
			max = left(i);
		if((right(i) < this.heap_size)&&(this.heap[max] < this.heap[right(i)]))
			max = right(i);
		if(max != i){
			this.heap[i] += this.heap[max];
			this.heap[max] = this.heap[i] - this.heap[max];
			this.heap[i] -= this.heap[max];
			this.maxHeapify(max);
		}	
	}
	public void buildMaxHeap(){
		if(this.heap_size > 1){
			for(int i = this.heap_size / 2 - 1; i >= 0; i--)
				this.maxHeapify(i);
		}
	}
	public int heapMaximum(){
		return this.heap[0];
	}
	public int heapExtractMax()throws IA$HeapExc{
		if(this.heap_size < 1)
			throw new IA$HeapExc("HeapUnderFlow");
		int max = this.heap[0];
		this.heap[0] = this.heap[this.heap_size - 1];
		this.heap_size--;
		this.maxHeapify(1);
		return max;
	}
	public void heapIncreaseKey(int i,int key)throws IA$HeapExc{
		if(key <= this.heap[i])
			throw new IA$HeapExc("NewKeyIsSmallerThanCurrentKey");
		this.heap[i] = key;
		while((i > 0)&&(this.heap[parent(i)] < key)){
			this.heap[i] = this.heap[parent(i)];
			i = parent(i);
			this.heap[i] = key;
		}
	}
	public void maxHeapInsert(int key)throws IA$HeapExc{
		this.heap_size++;
		if(this.heap_size > this.heap.length)
			throw new IA$HeapExc("HeapOverFlow");
		this.heap[this.heap_size - 1] = -1;
		try{
			this.heapIncreaseKey(this.heap_size - 1,key);
		}
		catch(IA$HeapExc e){
			e.printStackTrace();
		}
	}
}
class IA$MinHeap extends IA$Heap{
	public IA$MinHeap(){
		super();
	}
	public IA$MinHeap(int[] A){
		super(A);
		this.buildMinHeap();
	}
	public void minHeapify(int i){
		int min = i;
		if((left(i) < this.heap_size)&&(this.heap[min] > this.heap[left(i)]))
			min = left(i);
		if((right(i) < this.heap_size)&&(this.heap[min] > this.heap[right(i)]))
			min = right(i);
		if(min != i){
			this.heap[i] += this.heap[min];
			this.heap[min] = this.heap[i] - this.heap[min];
			this.heap[i] -= this.heap[min];
			this.minHeapify(min);
		}	
	}
	public void buildMinHeap(){
		if(this.heap_size > 2){
			for(int i = this.heap_size / 2 - 1; i >= 0; i--)
				this.minHeapify(i);
		}
	}
}
class IA$HeapExc extends Exception{
	public IA$HeapExc(){
	}
	public IA$HeapExc(String s){
		super(s);
	}
}