#ifndef BNODE_H
#define BNODE_H

template <class T>
class BinaryNode
{
  public:
   T data;                     //data in each node
   BinaryNode<T>*pLeft;
   BinaryNode<T>*pRight;
   
   BinaryNode<T>*pParent;

   //brings back the size of the tree
   int size() const
   {
      return 1 +
         (pLeft == NULL? 0: pLeft->size()) +
         (pRight == NULL? 0: pRight->size());
   }

   //constructs empty node
  BinaryNode(): pParent(NULL), pRight(NULL), pLeft(NULL){}    //Empty Node 

   //constructs node with data in it
  BinaryNode(T data): data(data), pParent(NULL), pRight(NULL), pLeft(NULL){}
   
   //adds to the left side of tree
   BinaryNode<T> addLeft(T data)
   {
         
      pLeft = new BinaryNode<T>(data);
      pLeft->pParent = this;
     
      return *this;
   }

   //adds to the left side of tree based on a node
   BinaryNode<T> addLeft(BinaryNode<T>* node)
   {
       pLeft = node;

       if (node != NULL)
          pLeft->pParent = this;
       
       return *this;
   }

   
   //adds to the right side of tree
   BinaryNode<T> addRight(T data)
   {
      pRight = new BinaryNode(data);

      pRight->pParent = this;
      
      return *this;
   }

   //adds to the right side of tree based on node
   BinaryNode<T> addRight(BinaryNode<T>* node)
   {
      pRight = node;

      if(node != NULL)
         pRight->pParent = this;
      
      return *this;
   }
   
};

//deletes the whole tree and everything rooted to it
template <class T>
BinaryNode<T>* deleteBinaryTree(BinaryNode<T>* root)
{
   if (root->pLeft == NULL && root->pRight == NULL)
   {
      delete root;
      return root;
   }
   else if (root->pLeft == NULL)
   {
      root->pRight = deleteBinaryTree(root->pRight);
      delete root;
      return root;
   }
   else if (root->pRight == NULL)
   {
      root->pLeft = deleteBinaryTree(root->pLeft);
      delete root;
      return root;
   }
   else
   {
      root->pLeft = deleteBinaryTree(root->pLeft);
      root->pRight = deleteBinaryTree(root->pRight);
      delete root;
      return root;
   }
}

//outputs the nodes
template <class T>
std::ostream & operator << (std::ostream & out, const BinaryNode<T>* root)
{
   if (root->pLeft != NULL)
      out << root->pLeft;
      
      out << root->data << " ";
   
   if (root->pRight != NULL)
      out << root->pRight;
   

   return out;
   
}

#endif
