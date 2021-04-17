/**
 * File Name: IA$LinkedList.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 2
 * Date: Ver.1:2016-12-7 Ver.2:2017-1-2
 * Description: A Data Structure
 * Funcation List:
 *	1. IA$LinkedList::public void listInsert(int x)
 *	2. IA$LinkedList::public void listDelete(int x)
 *	3. IA$LinkedList::public int listSearch(int k)
 *	4. IA$LinkedList::private int allocateObject()
 *	5. IA$LinkedList::private void freeObject(int x)
 */
class IA$LinkedList{
	private int[] prev;
	private int[] key;
	private int[] next;
	static final int NIL = 0;
	private int free;
	private int num;
	private int size;
	public IA$LinkedList(){
		this.size = 4;
		this.prev = new int[5];
		this.key = new int[5];
		this.next = new int[5];
		for(int i = 1; i < 5; i++){
			this.freeObject(i);
		}
		this.num = 0;
	}
	public int getNum(){
		return this.num;
	}
	public int getKey(int x){
		return this.key[x];
	}
	public int getNext(int x){
		return this.next[x];
	}
	public void listInsert(int x){
		int temp = this.allocateObject();
		this.key[temp] = x;
		this.prev[this.next[NIL]] = temp;
		this.next[temp] = this.next[NIL];
		this.next[NIL] = temp;
		this.prev[temp] = NIL;
		this.num++;
	}
	public void listDelete(int x){
		this.next[this.prev[x]] = this.next[x];
		this.prev[this.next[x]] = this.prev[x];
		this.num--;
		this.freeObject(x);
	}
	public int listSearch(int k){
		int x = this.next[NIL];
		while((x != NIL)&&(this.key[x] != k))
			x = this.next[x];
		return x;
	}
	private int allocateObject(){
		if(this.free == NIL){
			int[] temp_prev = new int[2 * this.size + 1];
			int[] temp_key = new int[2 * this.size + 1];
			int[] temp_next = new int[2 * this.size + 1];
			for(int i = 0; i < 2 * this.size + 1; i++){
				temp_prev[i] = this.prev[i];
				temp_key[i] = this.key[i];
				temp_next[i] = this.next[i];
			}
			this.prev = temp_prev;
			this.key = temp_key;
			this.next = temp_next;
			this.size *= 2;
			for(int i = this.size / 2 + 1; i < this.size + 1; i++){
				this.freeObject(i);
			}
		}
		int temp = this.free;
		this.free = this.next[this.free];
		return temp;
	}
	private void freeObject(int x){
		this.next[x] = this.free;
		this.free = x;
		if((this.num != 0)&&(this.num / this.size <= 0.25)){
			int[] temp_prev = new int[this.size / 2 + 1];
			int[] temp_key = new int[this.size / 2 + 1];
			int[] temp_next = new int[this.size / 2 + 1];
			int j = 0;
			for(int i = NIL; j <= this.num; i = this.next[i]){
				temp_prev[j] = this.prev[i];
				temp_key[j] = this.key[i];
				temp_next[j] = this.next[i];
				j++;
			}
			this.prev = temp_prev;
			this.key = temp_key;
			this.next = temp_next;
			this.size /= 2;
			this.free = NIL;
			for(int i = j; i < this.size; i++){
				this.freeObject(i);
			}
		}
	}
}