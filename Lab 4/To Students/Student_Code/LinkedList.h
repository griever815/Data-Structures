#pragma once
#include "LinkedListInterface.h"
#include "Factory.h"
#include <iostream>
#include <stdexcept>

template <class T>

class LinkedList : public LinkedListInterface<T>
{
private:

	struct Node
	{
		Node* next;
		T data;

		Node(const T& insert_data)
		{
			next = NULL;
			data = insert_data;
		};
	};


	int count;
	Node* head;
	Node* tail; ///////We know its the tail because it points to NULL


public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		count = 0;

	};

	~LinkedList() 
	{
		clear();
	};


	bool find(T value)  //// Passing in a value that we are going to look for in each of the nodes.
	{
		Node* currentNode = head;  ////Makes a node pointer that will step through the nodes.
		while (currentNode != NULL)  ////As long as currentNode points to something, it will do the while loop.
		{
			if (currentNode->data == value)  //// If the currentNodes data == value passed in, then it returns true.
			{
				return true;
			}
			else   //// If the current node does not == value, then it makes currentNode point to the next node.
			{
				currentNode = currentNode->next;  
			}
		}
		return false; //// If currentNode-> data never == value, then it returns false. 
	}



	void insertHead(T value)
	{
		/*
		insertHead
		A node with the given value should be inserted at the beginning of the list.
		Do not allow duplicate values in the list.
		*/
		bool found = find(value);  ////Looks for the value that is passed into find. Returns false if not found, true if found.
		
		if (found == false)  //// If value is not found, then it will make a new node. If value is found, nothing happens.
		{
			
			if (count == 0) ////This is what happens if there currently are no nodes in the linked list.
			{
				Node* nh = new Node(value);  //// Makes a new node with the given value. Makes Node* pointing to the new node.
				
				head = nh;  //// Sets the head pointer to point to this new node.
				tail = nh;  //// Sets the tail pointer to point to this new node.
				count++;    //// Increases count of nodes in Linked list by 1.
			}
			else  ////If count doesnt == 0, it does this
			{
				if (count > 0) //// If count > 0, it does this. If count < 0, it does nothing.
				{
					Node* nh = new Node(value);  //// Makes a new node with the given value. Makes Node* pointing to the new node.

					nh->next = head; ////Sets the new nodes next pointer to point at the old head node.
					head = nh;  //// Sets the head pointer to point to this new node.
					count++;    //// Increases count of nodes in Linked list by 1.
				}
			}
		}
	}



	void insertTail(T value)
	{
		/*
		insertTail
		A node with the given value should be inserted at the end of the list.
		Do not allow duplicate values in the list.
		*/

		bool found = find(value);////Looks for the value that is passed into find. Returns false if not found, true if found.
		Node* currentNode = head;

		if (found == false)
		{
			if (count == 0) ////This is what happens if there currently are no nodes in the linked list.
			{
				Node* nh = new Node(value);  //// Makes a new node with the given value. Makes Node* pointing to the new node.

				head = nh;  //// Sets the head pointer to point to this new node.
				tail = nh;  //// Sets the tail pointer to point to this new node.
				count++;    //// Increases count of nodes in Linked list by 1.
			}
			else  ////If count doesnt == 0, it does this
			{
				if (count > 0) //// If count > 0, it does this. If count < 0, it does nothing.
				{
					while (currentNode != NULL)////As long as currentNode points to something, it will do the while loop.
					{
						if (currentNode->next == NULL)////If currentNode->next == NULL, it means it is the tail node.
						{
							Node* nt = new Node(value);  //// Makes a new node with the given value. Makes Node* pointing to the new node.
							
							currentNode->next = nt; ////Makes the currentNode->next point to the newly made Node.
							tail = nt;  //// Sets the tail pointer to point to this new node.

							count++;//// Increases count of nodes in Linked list by 1.

							return;
						}
						else  //// If the currentNode-> does not == NULL, then it makes currentNode point to the next node.
						{
							currentNode = currentNode->next;  ////Use this statement to get to the right node
						}
					}
				}
			}
		}
	}



	void insertAfter(T value, T inAfter)
	{
		/*
		insertAfter
		A node with the given value should be inserted immediately after the
		node whose value is equal to insertionNode.
		A node should only be added if the node whose value is equal to
		insertionNode is in the list. Do not allow duplicate values in the list.
		*/

		bool found = find(value);  //////Looks for the value that is passed into find. Returns false if not found, true if found.
		bool nodeExists = find(inAfter);  ////Returns true if a node with a certain data value is found. False if not.


		Node* currentNode = head; ////Makes a node pointer that will step through the nodes.

		if (found == false) //// If found == false, it means that there were no dupicates.
		{
			if (nodeExists == true) ////If nodeExists == true, then it means that there is a node with that same data. We insert after this node.
			{
				while (currentNode != NULL)////As long as currentNode points to something, it will do the while loop.
				{
					if (currentNode->data == inAfter) //// If the currentNode->data == inAfter, it means that we insert after currentNode.
					{
					
						Node* na = new Node(value);  //// Makes a new node with the given value. Makes Node* pointing to the new node.

						Node* temp = currentNode->next;  ////Makes a node pointer that is pointing to the currentNode->next so we can change currentNode->next.

						currentNode->next = na;  ////Sets the currentNode->next to point to the newly made node.

						na->next = temp;  ////Sets the newly made node to point to what currentNode was pointing at. 

						count++;  //// Increases count of nodes in Linked list by 1.

						return;
					}
					else  //// If the currentNode-> does not == inAfter, then it makes currentNode point to the next node.
					{
						currentNode = currentNode->next;  ////Use this statement to get to the right node
					}
				}
			}
		}
	}



	void remove(T value)
	{
		/*
		remove
		The node with the given value should be removed from the list.
		The list may or may not include a node with the given value.
		*/

		bool found = find(value);  //////Looks for the value that is passed into find. Returns false if not found, true if found.

		Node* currentNode = head; ////Makes a node pointer that will step through the nodes.

		if (found == true) ////If found == true, then it means that there is a node with that same data. We delete this node.
		{
			while (currentNode != NULL)////As long as currentNode points to something, it will do the while loop.
			{
				if (head->data == value)
				{
					Node* temp = head->next;  ////Makes a node pointer that is pointing to the currentNode->next so we can delete currentNode.
					Node* toDelete = head;  ////Makes a pointer that points to the node to be deleted.
					head = temp;  ////Sets the currentNode->next to point to the node after the one to be deleted.

					delete  toDelete;

					count--;  //// Decreases count of nodes in Linked list by 1.

					return;
				}
				if (currentNode->next->data == value) //// If the currentNode->data == found, it means that we delete this currentNode.
				{

					Node* temp = currentNode->next->next;  ////Makes a node pointer that is pointing to the currentNode->next so we can delete currentNode.
					Node* toDelete = currentNode->next;  ////Makes a pointer that points to the node to be deleted.
					currentNode->next = temp;  ////Sets the currentNode->next to point to the node after the one to be deleted.
					
					delete  toDelete;

					count--;  //// Decreases count of nodes in Linked list by 1.

					return;
				}
				
				else  //// If the currentNode-> does not == inAfter, then it makes currentNode point to the next node.
				{
					currentNode = currentNode->next;  ////Use this statement to get to the right node
				}
			}	
		}
	}



	void clear()
	{
		/*
		clear
		Remove all nodes from the list.
		*/

		while (head != NULL)
		{
				Node* currentNode = head;
				Node* temp = currentNode->next;
				head = temp;
				delete currentNode;
				count--;
		}
	}



	T at(int index)
	{
		/*
		at
		Returns the value of the node at the given index. The list begins at
		index 0.
		If the given index is out of range of the list, throw an out of range exception.
		*/
		Node* currentNode = head;

		while (currentNode != NULL)
		{
			if (index >= 0)
			{
				if (currentNode != NULL && index != 0)
				{
					currentNode = currentNode->next;
					index--;
				}
				if (currentNode != NULL && index == 0)
				{
					return currentNode->data;
				}
			}
			else
			{
				throw out_of_range("");
			}
		}
		throw out_of_range("");
	}



	int size()
	{
		/*
		size
		Returns the number of nodes in the list.
		*/

		return count;
	}


	
};

  