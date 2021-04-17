/**
 * File Name: IA$BinarySearchTree.java
 * Author:  一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-12-24
 * Description: A Data Structure
 * Funcation List: 
 *	1. IA$BinarySearchTree::public void inorderTreeWalk(int x)
 *	2. IA$BinarySearchTree::public int treeSearch(int k)
 *	3. IA$BinarySearchTree::public int treeMinimum(int x)
 *	4. IA$BinarySearchTree::public int treeMaximum(int x)
 *	5. IA$BinarySearchTree::public int treeSuccessor(int x)
 *	6. IA$BinarySearchTree::public int treePredecessor(int x)
 *	7. IA$BinarySearchTree::public void treeInsert(int k)
 *	8. IA$BinarySearchTree::public void treeDelete(int z)
 *	9. IA$BinarySearchTree::private void transPlant(int u;int v)
 *	10. IA$BinarySearchTree::private int allocateObject()
 *	11. IA$BinarySearchTree::private void freeObject(int x)
 */
class IA$BinarySearchTree{
	int[] left;
	int[] right;
	int[] parent;
	int[] key;
	static final int NIL = 0;
	protected int free;
	int root;
	protected int size;
	protected int num;
	public IA$BinarySearchTree(){
		this.left = new int[5];
		this.right = new int[5];
		this.parent = new int[5];
		this.key = new int[5];
		this.free = NIL;
		this.root = NIL;
		this.num = 0;
		this.size = 4;
		for(int i = 1; i < 5; i++){
			this.freeObject(i);
		}
	}
	public int getNum(){
		return this.num;
	}
	public void inOrderTreeWalk(int x){
		if(x != NIL){
			this.inOrderTreeWalk(this.left[x]);
			System.out.print(this.key[x] + " ");
			this.inOrderTreeWalk(this.right[x]);
		}
	}
	public int treeSearch(int k){
		int x = this.root;
		while((x != NIL)&&(this.key[x] != k)){
			if(this.key[x] > k)
				x = this.left[x];
			else
				x = this.right[x];
		}
		return x;
	}
	public int treeMinimum(int x){
		while(this.left[x] != NIL)
			x = this.left[x];
		return x;
	}
	public int treeMaximum(int x){
		while(this.right[x] != NIL)
			x = this.right[x];
		return x;
	}
	public int treeSuccessor(int x){
		if(this.right[x] != NIL)
			return this.treeMinimum(this.right[x]);
		int y = this.parent[x];
		while((y != NIL)&&(x == this.right[y])){
			x = y;
			y = this.parent[y];
		}
		return y;
	}
	public int treePredecessor(int x){
		if(this.left[x] != NIL)
			return this.treeMaximum(this.left[x]);
		int y = this.parent[x];
		while((y != NIL)&&(x == this.left[y])){
			x = y;
			y = this.parent[y];
		}
		return y;
	}
	public void treeInsert(int k){
		int temp = this.allocateObject();
		this.key[temp] = k;
		int y = NIL;
		int x = this.root;
		while(x != NIL)	{
			y = x;
			if(k < this.key[x])
				x = this.left[x];
			else
				x = this.right[x];
		}
		this.parent[temp] = y;
		if(this.root == NIL)
			this.root = temp;
		if(k < this.key[y])
			this.left[y] = temp;
		else
			this.right[y] = temp;
	}
	private void transPlant(int u,int v){
		if(this.root == u)
			this.root = v;
		else if(u == this.left[this.parent[u]])
			this.left[this.parent[u]] = v;
		else
			this.right[this.parent[u]] = v;
		if(v != NIL)
			this.parent[v] = this.parent[u];
	}
	public void treeDelete(int z){
		if(this.left[z] == NIL)
			this.transPlant(z,this.right[z]);
		else if(this.right[z] == NIL)
			this.transPlant(z,this.left[z]);
		else{
			int y = this.treeMinimum(this.right[z]);
			if(this.parent[y] != z){
				this.transPlant(y,this.right[y]);
				this.right[y] = this.right[z];
				this.parent[this.right[y]] = y;
			}
			this.transPlant(z,y);
			this.left[y] = this.left[z];
			this.parent[this.left[y]] = y;
		}
		this.freeObject(z);
	}
	private int allocateObject(){
		if(this.free == NIL){
			int[] temp_parent = new int[2 * this.size + 1];
			int[] temp_key = new int[2 * this.size + 1];
			int[] temp_left = new int[2 * this.size + 1];
			int[] temp_right = new int[2 * this.size + 1];
			for(int i = 0; i < 2 * this.size + 1; i++){
				temp_parent[i] = this.parent[i];
				temp_key[i] = this.key[i];
				temp_left[i] = this.left[i];
				temp_right[i] = this.right[i];
			}
			this.parent = temp_parent;
			this.key = temp_key;
			this.left = temp_left;
			this.right = temp_right;
			this.size *= 2;
			for(int i = this.size / 2 + 1; i < this.size + 1; i++){
				this.freeObject(i);
			}
		}
		int rs = this.free;
		this.free = this.parent[this.free];
		this.parent[rs] = NIL;
		this.left[rs] = NIL;
		this.right[rs] = NIL;
		this.key[rs] = -1;
		return rs;
	}
	protected void check(EXStack st,int x){
		if(x != NIL){
			st.push(x);
			this.check(st,this.left[x]);
			this.check(st,this.right[x]);
		}
	}
	private void freeObject(int x){
		this.parent[x] = this.free;
		this.free = x;
		if((this.num != 0)&&(this.num / this.size <= 0.25)){
			int[] temp_parent = new int[this.size / 2 + 1];
			int[] temp_key = new int[this.size / 2 + 1];
			int[] temp_left = new int[this.size / 2 + 1];
			int[] temp_right = new int[this.size / 2 + 1];
			EXStack temp = new EXStack();
			this.check(temp,this.root);
			int j = 1;
			try{
				for(int i = temp.pop(); j <= this.num; i = temp.pop()){
					temp_parent[j] = this.parent[i];
					temp_key[j] = this.key[i];
					temp_left[j] = this.left[i];
					temp_right[j] = this.right[i];
					j++;
				}
			}
			catch(Exception e){
				e.printStackTrace();
			}
			this.root = 1;
			this.parent = temp_parent;
			this.key = temp_key;
			this.left = temp_left;
			this.right = temp_right;
			this.size /= 2;
			this.free = NIL;
			for(int i = j; i < this.size; i++){
				this.freeObject(i);
			}
		}
	}
}