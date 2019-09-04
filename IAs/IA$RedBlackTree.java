/**
 * File Name:IA$RedBlackTree.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-12-25
 * Description: A Data Structure
 * Funcation List:
 *	1. IA$RedBlackTree::private void leftRotate(int x)
 *	2. IA$RedBlackTree::private void rightRotate(int x)
 *	3. IA$RedBlackTree::public void treeInsert(int k)
 *	4. IA$RedBlackTree::private void RBInsertFixUp(int x)
 *	5. IA$RedBlackTree::private void RBTransPlant(int u;int v)
 *	6. IA$RedBlackTree::public void treeDelete(int z)
 *	7. IA$RedBlackTree::private void RBDeleteFixUp(int x)
 *	8. IA$RedBlackTree::private int allocateObject()
 *	9. IA$RedBlackTree::private void freeObject(int x)
 */
class IA$RedBlackTree extends IA$BinarySearchTree{
	private boolean[] color;
	static final boolean RED = false;
	static final boolean BLACK = true;
	public IA$RedBlackTree(){
		this.left = new int[5];
		this.right = new int[5];
		this.parent = new int[5];
		this.key = new int[5];
		this.color = new boolean[5];
		this.free = NIL;
		this.root = NIL;
		for(int i = 1; i < 5; i++){
			this.freeObject(i);
		}
	}
	private void leftRotate(int x){
		int y = this.right[x];
		this.right[x] = this.left[y];
		if(this.left[y] != NIL)
			this.parent[this.left[y]] = x;
		this.left[y] = x;
		this.parent[y] = this.parent[x];
		if(this.root == x)
			this.root = y;
		else if(x == this.left[this.parent[x]])
			this.left[this.parent[x]] = y;
		else
			this.right[this.parent[x]] = y;
		this.left[y] = x;
		this.parent[x] = y;
	}
	private void rightRotate(int x){
		int y = this.left[x];
		this.left[x] = this.right[y];
		if(this.right[y] != NIL)
			this.parent[this.right[y]] = x;
		this.parent[y] = this.parent[x];
		if(this.root == x)
			this.root = y;
		else if(x == this.left[this.parent[x]])
			this.left[this.parent[x]] = y;
		else
			this.right[this.parent[x]] = y;
		this.right[y] = x;
		this.parent[x] = y;
	}
	public void treeInsert(int k){
		try{
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
			this.RBInsertFixUp(x);
			this.num++;
		}
		catch(IA$RedBlackTreeExc e){
			e.printStackTrace();
		}
	}
	private void RBInsertFixUp(int x){
		while(this.color[this.parent[x]] == RED){
			if(this.parent[x] == this.left[this.parent[this.parent[x]]]){
				int y = this.right[this.parent[this.parent[x]]];
				if(this.color[y] == RED){
					this.color[y] = BLACK;
					this.color[this.parent[x]] = BLACK;
					this.color[this.parent[this.parent[x]]] = RED;
					x = this.parent[this.parent[x]];
				}
				else{
					if(x == this.right[this.parent[x]]){
						x = this.parent[x];
						this.leftRotate(x);
					}
					this.color[this.parent[x]] = BLACK;
					this.color[this.parent[this.parent[x]]] = RED;
					this.rightRotate(this.parent[this.parent[x]]);
				}
			}
			else{
				int y = this.left[this.parent[this.parent[x]]];
				if(this.color[y] == RED){
					this.color[y] = BLACK;
					this.color[this.parent[x]] = BLACK;
					this.color[this.parent[this.parent[x]]] = RED;
					x = this.parent[this.parent[x]];
				}
				else{
					if(x == this.left[this.parent[x]]){
						x = this.parent[x];
						this.rightRotate(x);
					}
					this.color[this.parent[x]] = BLACK;
					this.color[this.parent[this.parent[x]]] = RED;
					this.leftRotate(this.parent[this.parent[x]]);
				}
			}
			this.color[this.root] = BLACK;
		}
	}
	private void RBTransPlant(int u,int v){
		if(this.root == u)
			this.root = v;
		else if(u == this.left[this.parent[u]])
			this.left[this.parent[u]] = v;
		else
			this.right[this.parent[u]] = v;
		this.parent[v] = this.parent[u];
	}
	public void treeDelete(int z){
		int x;
		int y = z;
		boolean y_original_color = this.color[y];
		if(this.left[z] == NIL){
			x = this.right[z];
			this.RBTransPlant(z,this.right[z]);
		}
		else if(this.right[z] == NIL){
			x = this.left[z];
			this.RBTransPlant(z,this.left[z]);
		}
		else{
			y = this.treeMinimum(this.right[z]);
			y_original_color = this.color[y];
			x = this.right[y];
			if(this.parent[y] != z){
				this.RBTransPlant(y,this.right[y]);
				this.right[y] = this.right[z];
				this.parent[this.right[y]] = y;
			}
			else
				this.parent[x] = y;
			this.RBTransPlant(z,y);
			this.left[y] = this.left[z];
			this.parent[this.left[y]] = y;
			this.color[y] = this.color[z];
		}
		if(y_original_color == BLACK)
			this.RBDeleteFixUp(x);
		this.num--;
	}
	private void RBDeleteFixUp(int x){
		while((x != this.root)&&(this.color[x] == BLACK)){
			if(x == this.left[this.parent[x]]){
				int w = this.right[this.parent[x]];
				if(this.color[w] == RED){
					this.color[w] = BLACK;
					this.color[this.parent[x]] = RED;
					this.leftRotate(this.parent[x]);
					w = this.right[this.parent[x]];
				}
				if((this.color[this.left[w]] == BLACK)&&(this.color[this.right[w]] == BLACK)){
					this.color[w] = RED;
					x = this.parent[x];
				}
				else{
					if(this.color[this.right[w]] == BLACK){
						this.color[this.left[w]] = BLACK;
						this.color[w] = RED;
						this.rightRotate(w);
						w = this.right[this.parent[x]];
					}
					this.color[w] = this.color[this.parent[x]];
					this.color[this.parent[x]] = BLACK;
					this.color[this.right[w]] = BLACK;
					this.leftRotate(this.parent[x]);
					x = this.root;
				}
			}
			else{
				int w = this.left[this.parent[x]];
				if(this.color[w] == RED){
					this.color[w] = BLACK;
					this.color[this.parent[x]] = RED;
					this.rightRotate(this.parent[x]);
					w = this.left[this.parent[x]];
				}
				if((this.color[this.left[w]] == BLACK)&&(this.color[this.right[w]] == BLACK)){
					this.color[w] = RED;
					x = this.parent[x];
				}
				else{
					if(this.color[this.left[w]] == BLACK){
						this.color[this.right[w]] = BLACK;
						this.color[w] = RED;
						this.leftRotate(w);
						w = this.left[this.parent[x]];
					}
					this.color[w] = this.color[this.parent[x]];
					this.color[this.parent[x]] = BLACK;
					this.color[this.left[w]] = BLACK;
					this.rightRotate(this.parent[x]);
					x = this.root;
				}
			}
			this.color[x] = BLACK;
		}
	}
	private int allocateObject()throws IA$RedBlackTreeExc{
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
		this.color[rs] = RED;
		this.key[rs] = -1;
		return rs;
	}
	private void freeObject(int x){
		this.parent[x] = this.free;
		this.free = x;
		if((this.num != 0)&&(this.num / this.size <= 0.25)){
			int[] temp_parent = new int[this.size / 2 + 1];
			int[] temp_key = new int[this.size / 2 + 1];
			int[] temp_left = new int[this.size / 2 + 1];
			int[] temp_right = new int[this.size / 2 + 1];
			boolean[] temp_color = new boolean[this.size / 2 + 1];
			EXStack temp = new EXStack();
			this.check(temp,this.root);
			int j = 1;
			try{
				for(int i = temp.pop(); j <= this.num; i = temp.pop()){
					temp_parent[j] = this.parent[i];
					temp_key[j] = this.key[i];
					temp_left[j] = this.left[i];
					temp_right[j] = this.right[i];
					temp_color[j] = this.color[i];
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
			this.color = temp_color;
			this.size /= 2;
			this.free = NIL;
			for(int i = j; i < this.size; i++){
				this.freeObject(i);
			}
		}
	}
}