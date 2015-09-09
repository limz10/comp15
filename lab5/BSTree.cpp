#include "BSTree.h"

BST::BST()
{
    root = NULL;	
}

//
// Insert: public version of Insert takes a value only and
// 	   inserts in the tree at the root
//
void BST::unbalancedInsert(int v)
{
    root = unbalancedInsert(root, v);
}

//
// Insert: private version inserts a value at any subtree
//         given by the 'root' of that tree
//
//   returns: the current tree NOW WITH the value inserted
//   note: ALWAYS adds a leaf
//

BSTNode* BST::unbalancedInsert(BSTNode* r, int v)
{
    //Base Case for recursion:
    //We have reached the end of the
    //tree and we are at NULL. We
    //create a node with the correct
    //information and return a pointer
    //to the new data. This return sets
    //the value for the parent which made
    //the function call
        
    if (r == NULL)
    {
	r = new BSTNode;
	r->value = v;
	r->left = NULL;
	r->right = NULL;
	return r;
    }
        
    //notice we asked NULL first so that
    //r->left and r->right will not seg fault
        
    else if (v < r->value)
    {
	r->left = unbalancedInsert(r->left, v);
	return r;
            
    }
        
    else
    {
	r->right = unbalancedInsert(r->right, v);
	return r;
            
            
    }
}


//****************** inorder *****************//

void BST::inOrder()
{
    inOrder(root);		// calls the next one
}


void BST::inOrder(BSTNode* root)
{
    if (root == NULL) 
	return;
    else {
	inOrder(root->left);
	cout << " " << root->value;
	inOrder(root->right);
    }
}



//****************** postorder *****************//



void BST::postOrder()
{	
    postOrder(root);	// calls the next one
}

void BST::postOrder(BSTNode* root)
{
    //your code here --- if you want

}



//****************** preorder *****************//



// print the tree in preOrder using the next function
// Question to ponder: can we do this without a helper function?
void BST::preOrder()
{
    preOrder(root);		// calls the next one (really needed?)
}

//
// preOrder traversal using a stack of our own, not
// the one from the compiler

void BST::preOrder(BSTNode* root)
{
    //preorder with a stack
    //stack defined here:
    stack<BSTNode*> s;
    s.push(root);
  	
    //your code here
    while (!s.empty()) {
	// step 1
	BSTNode* top = s.top();
	s.pop(); 

	// step 2
	cout << top->value << " ";

	// step 3
	if (top->right != NULL)
	    s.push(top->right);
	if (top->left != NULL)
	    s.push(top->left);
    }
}



//****************** levelorder *****************//



void BST::levelOrder()
{
    levelOrder(root);
}


void BST::levelOrder(BSTNode* root)
{
   
    //preorder with a stack
    //stack defined here:
    queue<BSTNode*> q;
    q.push(root);
  	
    //your code here
    while (!q.empty()) {
	// step 1
	BSTNode* top = q.front();
	q.pop(); 

	// step 2
	cout << top->value << " ";

	// step 3
	if (top->left != NULL)
	    q.push(top->left);
 	if (top->right != NULL)
	    q.push(top->right);
    }
}




