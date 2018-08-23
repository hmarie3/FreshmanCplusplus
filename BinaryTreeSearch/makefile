###############################################################
# Program:
#     Week 09, Binary Search Tree
#     Brother Kirby, CS235
# Author:
#     Jon Crawford & Heather Brune
# Summary:
#     Full functional BST and iterator complete with Binary
#     nodes.
# Time:
#     Jon Crawford: 13 hours
#
#     With this assignment, understanding how the BST iterator
#     works was a very big struggle and took quite some time to
#     look into and figure out how it all works together with
#     the binary nodes themselves.
#
#     Additionally the only thing we couldn't figure out for
#     this assignment so far was the remove() function for the
#     BST which also involves using the BST iterator as a means
#     of removing a node from the BST.
#
#     With all that being said the Binary Sort was really easy
#     once everything else was in place.
#
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week09.o
	g++ -o a.out week09.o -g
	tar -cf week09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week09.o     : the driver program
##############################################################
week09.o: bnode.h bst.h stack.h week09.cpp sortBinary.h
	g++ -c week09.cpp -g

