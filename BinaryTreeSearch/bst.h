/***********************************************************************
 * Component:
 *    Week 09, Binary Search Tree (BST)
 *    Brother Helfrich, CS 235
 * Author:
 * Summary:
 *    
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include <stack>
#include <assert.h>
#include "bnode.h"

template<class T>
class BSTIterator;

template<class T>
class BST
{
private:
   BinaryNode<T> * root;
   int treeSize;

   BinaryNode<T> * copyHelper(const BinaryNode<T> * cpy)
   {
      if (cpy == NULL)
         return NULL;
      BinaryNode<T> * cbNode = new BinaryNode<T>();
      cbNode->data = cpy->data;
      cbNode->pLeft = copyHelper(cpy->pLeft);
      cbNode->pRight = copyHelper(cpy->pRight);
      return cbNode;
   }

   void insertTree(BinaryNode<T> * bNode, const T & data)
   {
      if (bNode == NULL)
         bNode = new BinaryNode<T>(data);
      else if (data < bNode->data)
         insertTree(bNode->pLeft, data);
      else if (data > bNode->data)
         insertTree(bNode->pRight, data);
      else
         std::cerr << "Item already in the tree" << std::endl;
   }

   void searchTree(T data, bool & found, BinaryNode<T> * deleteNode, BinaryNode<T> * parent)
   {
      deleteNode = root;
      parent = NULL;
      while (!found && deleteNode != NULL)
      {
         if (data < deleteNode->data)
         {
            parent = deleteNode;
            deleteNode = deleteNode->pLeft;
         }
         else if (deleteNode->data < data)
         {
            parent = deleteNode;
            deleteNode = deleteNode->pRight;
         }
         else
         {
            found = true;
         }

      }
   }
public:
   // default constructor
   BST() : root(NULL), treeSize(0) {}
   // copy constructor
   BST(const BST<T> & rbst) throw (const char *) {
      assert(rbst.treeSize >= 0);
      assert(rbst.root != NULL);
      treeSize = rbst.treeSize;
      try
      {
         root = copyHelper(rbst.root);
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a node";
      }
   }
   // deconstructor
   ~BST() {
      deleteBinaryTree(root);
      treeSize = 0;
      delete root;
   }
   
   // operator=
   BST operator = (const BST & rbst) throw (const char *)
   {
      assert(rbst.treeSize >= 0);
      treeSize = rbst.treeSize;
      try
      {
         root = copyHelper(rbst.root);
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a node";
      }
   }

   // empty
   bool empty()
   {
      if (treeSize == 0 || treeSize == NULL)
         return true;
      else
         return false;
   }

   // size
   int size()
   {
      return treeSize;
   }

   // clear
   void clear()
   {
      deleteBinaryTree(root);
      treeSize = 0;
   }

   // insert
   void insert(T data) throw (const char *)
   {
      // what is the approtiate location
      try
      {
         insertTree(root, data);
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a node";
      }
   }

   // remove
   void remove(BSTIterator<T> rhs)
   {
      bool found = false;
      BinaryNode<T> * deleteNode = new BinaryNode<T>();
      BinaryNode<T> * parent = new BinaryNode<T>();

      searchTree(*rhs, found, deleteNode, parent);

      if (!found)
      {
         std::cout << "Item not in the BST" << std::endl;
         return;
      }
      // if node has 2 children
      if (deleteNode->pLeft != NULL && deleteNode->pRight != NULL)
      {
         BinaryNode<T> * dSucc = deleteNode->pRight;
         BinaryNode<T> * tParent = deleteNode;
         while (dSucc->pLeft != NULL)
         {
            tParent = dSucc;
            dSucc = dSucc->pLeft;
         }

         deleteNode->data = dSucc->data;
         deleteNode = dSucc;
      }
      // proceed with case where node has 0 of 1 child
      BinaryNode<T> * subtree = deleteNode->pLeft;
      if (subtree == NULL)
         subtree = deleteNode->pRight;
      if (parent == NULL)
         root = subtree;
      else if (parent->pLeft == deleteNode)
         parent->pLeft = subtree;
      else
         parent->pRight = subtree;

      delete deleteNode;

   }

   // find
   BSTIterator<T> find(T data)
   {
      bool found = false;
      BinaryNode<T> * fNode = new BinaryNode<T>();
      BinaryNode<T> * parent = new BinaryNode<T>();
      searchTree(data, found, fNode, parent);
      if (!found)
      {
         std::cout << "Item not in the BST" << std::endl;
      }
      BSTIterator<T> * itNode = new BSTIterator<T>(fNode);
      return *itNode;
   }

   // begin
   BSTIterator<T> begin()
   {
      BSTIterator<T> temp(root);
      while (temp.getBNode()->pLeft != NULL)
      {
         //temp->p = temp->p->pLeft;
         temp.setBNode(temp.getBNode()->pLeft);
      }
      return temp;
   }

   // end
   BSTIterator<T> end()
   {
      BSTIterator<T> temp;
      return temp;
   }

   // rbegin
   BSTIterator<T> rbegin()
   {
      BSTIterator<T> temp(root);
      while (temp.getBNode()->pRight != NULL)
      {
         temp.setBNode(temp.getBNode()->pRight);
      }
      return temp;
   }

   // rend
   BSTIterator<T> rend()
   {
      BSTIterator<T> temp;
      return temp;
   }

};

template<class T>
class BSTIterator
{
private:
   BinaryNode<T> * p;
   std::stack< BinaryNode<T> * > nodes;

public:
   // default constructor
   BSTIterator() : p(NULL) {}
   // constructor BinaryNode
   BSTIterator(BinaryNode<T> * p) : p(p) 
   {
      nodes.push(p);
   }
   // constructor Stack BinaryNode
   BSTIterator(std::stack< BinaryNode<T> > * nodes) : nodes(nodes) {}
   // copy constructor
   BSTIterator(const BSTIterator<T> & rhs) { *this = rhs; }

   // operator =
   BSTIterator<T> & operator = (const BSTIterator<T> & rhs)
   {
      this->p = rhs.p;
      this->nodes = rhs.nodes;
      return *this;
   }

   // operator ==
   bool operator == (const BSTIterator<T> & rhs)
   {
      return rhs.p == this->p;
   }

   // operator !=
   bool operator != (const BSTIterator<T> & rhs)
   {
      return rhs.p != this->p;
   }

   // operator * dereference
   const T & operator * ()
   {
      return p->data;
   }

   BinaryNode<T> * getBNode()
   {
      return p;
   }
   void setBNode(BinaryNode<T> * bNode)
   {
      p = bNode;
   }

   // operator ++ prefix
   BSTIterator<T> & operator ++ ();

   // operator ++ postfix
   BSTIterator<T> & operator++ (int postfix);

   // operator -- prefix
   BSTIterator<T> & operator -- ();

   // operator -- postfix
   BSTIterator<T> & operator-- (int postfix);
};

template <class T>
BSTIterator <T> & BSTIterator <T> :: operator ++ ()
{
   return NULL;
}

template <class T>
BSTIterator <T> & BSTIterator <T> :: operator++ (int postfix)
{
   return NULL;
}

/**************************************************
 * BST ITERATOR :: DECREMENT PREFIX
 *     advance by one. Note that this implementation uses
 *     a stack of nodes to remember where we are. This stack
 *     is called "nodes".
 * Author:      Br. Helfrich
 * Performance: O(log n) though O(1) in the common case
 *************************************************/
template <class T>
BSTIterator <T> & BSTIterator <T> :: operator -- ()
{
   // do nothing if we have nothing
   if (nodes.top() == NULL)
      return *this;

   // if there is a left node, take it
   if (nodes.top()->pLeft != NULL)
   {
      nodes.push(nodes.top()->pLeft);

      // there might be more right-most children
      while (nodes.top()->pRight)
         nodes.push(nodes.top()->pRight);
      return *this;
   }

   // there are no left children, the right are done
   assert(nodes.top()->pLeft == NULL);
   BinaryNode <T> * pSave = nodes.top();
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == nodes.top()->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}

template <class T>
BSTIterator <T> & BSTIterator <T> :: operator-- (int postfix)
{}

#endif // BST_H