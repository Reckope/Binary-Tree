// Author: Joe Davis

#include <iostream>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

int menu();

class node{

	public:

		string key_value;
		node *left;
		node *right;
		int wordCount;

}; // End of node class

class binaryTree{

	public:
	
		binaryTree();
		void insertNode(string key);
		node *searchTree(string key);
		void deleteTree();
		void resetTree();
		void printPostOrder();
		void readFile();
		void ReadFromFile();

	private:
	
		void deleteTree(node *leaf);
		void insertNode(string key, node *leaf);
		void postOrder(node *leaf);
		node *searchTree(string key, node *leaf);
		node *root;
		
		
}; // End of binaryTree class

// --------------- Binary Tree Function ---------------

binaryTree::binaryTree(){

	root = NULL;

};

// --------------- Delete the tree function ---------------

void binaryTree::deleteTree(node *leaf){

	if( leaf != NULL){
		deleteTree(leaf -> left);
		deleteTree(leaf -> right);
		delete leaf;
	}
}; // End of Delete function

void binaryTree::deleteTree(){

	deleteTree(root);
	
}

// --------------- Initialise a new tree ---------------

void binaryTree::resetTree(){

	root = NULL;
	cout << "\n Tree deleted... " << endl;
	cout << " New tree created " << endl;

}


// --------------- Insert node function ---------------  

void binaryTree::insertNode(string key){

	if (root != NULL){
		cout << "\n Node: " << key << ", created. " << endl;
		insertNode(key, root);
	}
	else{
		// If there isn't any node in the first place, create a new (initial) one.
		root = new node;
   		root -> key_value = key;
    	root -> left = NULL;
    	root -> right = NULL;
    	root -> wordCount = 1;
    	cout << " Initial Node: " << key << ", created. " << endl;	
	}
	
}; // End of insert function

void binaryTree::insertNode(string key, node *leaf){

	if (key < leaf -> key_value){
	
		if(leaf -> left != NULL){
			cout << " " << key << " inserted into the left branch of " << leaf -> key_value << endl;
			insertNode(key, leaf -> left);
		}
		
		else{		
			cout << " " << key << " inserted into the left branch of " << leaf -> key_value << endl;
			leaf -> left = new node;
			leaf -> left -> key_value = key;
			leaf -> left -> wordCount = 1;
			leaf -> left -> left = NULL;		//Sets the left child of the child node to null
			leaf -> left -> right = NULL;		//Sets the right child of the child node to null
		}
		
	}
	else if(key > leaf -> key_value){
	
		if(leaf -> right != NULL){
			insertNode(key, leaf -> right);
			cout << " " << key << " inserted into the right branch of " << leaf -> key_value << endl;
		}	
		else{
			leaf -> right = new node;
			leaf -> right -> key_value = key;
			leaf -> right -> wordCount = 1;
			leaf -> right -> left = NULL;		//Sets the left child of the child node to null
			leaf -> right -> right = NULL;		//Sets the right child of the child node to null
			cout << " " << key << " inserted into the right branch of " << leaf -> key_value << endl;
		}	
	}	
		else if(key == leaf -> key_value){
			leaf -> wordCount = (leaf -> wordCount + 1);		
		}
		

}; // End of Insert Function

// --------------- Searching the tree ---------------

node *binaryTree::searchTree(string key, node *leaf){

	cout << " Searching..." << endl;
	if (leaf != NULL){
	
		if(key == leaf -> key_value){
			cout << " Node found: " << leaf -> key_value << endl;
			return leaf;
		}	
		if(key < leaf -> key_value){	
			cout << " Left branch of " << leaf -> key_value << endl;
			return searchTree(key, leaf -> left);
		}
		else	
			cout << " Right branch of " << leaf -> key_value << endl;
			return searchTree(key, leaf -> right);	
	}
	
	else
	cout << "\n Word not found! (remember that it's all in lower case)" << endl;
	return NULL;
	
	
}; // End of search function


node *binaryTree::searchTree(string key){
	
	return searchTree(key, root);

}; // End of search function


// --------------- Printing off the tree ---------------

void binaryTree::printPostOrder(){

    return postOrder(root);
    
}

void binaryTree::postOrder(node *leaf){

    if(leaf != NULL){	
	if(leaf -> left) 
      	postOrder(leaf -> left);
      	cout<<"     "<< leaf -> key_value << ": appears " << leaf -> wordCount << " time(s) " <<"\n ";
    if(leaf -> right) 
      	postOrder(leaf -> right);
   }
    else {
    	return;	
    }
    
} // End of posting in order function

void binaryTree::readFile(){

	binaryTree bTree;

  	int i;
  	string root;

  	ifstream reader( "className.txt" );

  		if( ! reader ){
    		cout << " Error opening input file" << endl;
    		// return -1;
  		}
  		else
  			//for( i = 0; !reader.eof() ; i++ ){
			while(getline(reader, root)){
    			getline( reader , root );
    			transform(root.begin(), root.end(), root.begin(), ::tolower); // Automatically converts any string to lower case
    			cout << " " << root << endl;
    			bTree.insertNode(root);
  }
  
  	reader.close();
  
  cout << "Iterations: " << i << endl;
  
	return;

}

void binaryTree::ReadFromFile(){

		ifstream stream("className.txt");

		if(!stream) cout << " *ERROR: cannot read from file*" << endl;
		else cout << " *File successfully read*" << endl;

		string line;
		
		while(getline(stream, line)){

			transform(line.begin(), line.end(), line.begin(), ::tolower); // Automatically converts any string to lower case
			insertNode(line);
			

		}

		stream.close();

		


	}

// ---------------------------------------------------------------------------

int menu(){

	binaryTree bTree;
	string root;
	char selection;


	do{
		cout << "\n --------------- Binary Tree (Part B) ---------------" << endl;
		cout << "\n 1. Insert an word into the tree";
		cout << "\n 2. Check if a given word is in the tree";
		cout << "\n 3. Print out the current tree in order";
		cout << "\n 4. Delete the tree";
		cout << "\n 5. Read words from a file";
		cout << "\n 6. Exit the program";
		cout << "\n Enter selection: ";

		cin >> selection;
 
			switch(selection)
			{
			case '1':
			{
				cout << "\n Insert word into the tree" << endl;
				cout << " -----------------------" << endl;
				cout << " Please type the word you wish to insert: ";
				cin >> root;
				transform(root.begin(), root.end(), root.begin(), ::tolower); // Automatically converts any string to lower case
				cout << endl;
				bTree.insertNode(root);
			}
			break;

			case '2':
			{
				cout << "\n Check if a word is in the tree" << endl;
				cout << " -----------------------" << endl;
				cout << " Please type the word you wish to check: ";
				cin >> root;
				cout << endl;
				bTree.searchTree(root);	
			}
			break;

			case '3':
			{
				cout << "\n Print current tree" << endl;
				cout << " -----------------------" << endl;
				bTree.printPostOrder();
			}
			break;

			case '4':
			{	
				cout << "\n Delete the tree" << endl;
				cout << " -----------------------" << endl;
				bTree.deleteTree();
				bTree.resetTree();
			}
			break;

			case '5':
			{
				cout << "\n Read words from a file" << endl;
				cout << " -----------------------" << endl;
				bTree.ReadFromFile();
			}
			break;
			
			case '6': 
			{
			cout << " Goodbye! :D";
			}
			break;

			// Display message if input is not 1, 2, 3, 4, 5 or 6

			default : cout << "\n Invalid selection";
			}
			cout << "\n";
		} while(selection != '6');

	return 0;

} // End of menu

//-------------------------------- MAIN -----------------------------------

int main(){

menu();

return 0;

}
