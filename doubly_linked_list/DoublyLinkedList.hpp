#ifndef MY_DOUBLY_LINKED_LIST_HPP
#define MY_DOUBLY_LINKED_LIST_HPP


/**
 * TODO: Implement DoublyLinkedList, its Node, and its Iterator!
 * 
 * I've left some methods filled out for you,
 * 	and stubbed out some structure, to reduce difficulty.
 * 
 * You may add or remove methods as you see fit,
 * 	as long as you can still pass all unit tests.
 * Although, it may be more difficult to do so. Your choice!
 * 
 * Notice we're inside a namespace here.
 * The DLL is inside a namespace called DoublyLinkedList,
 * 	which is itself inside a namespace called CPSC131
 * This means, if you'd like to play around with your class later,
 * 	you'll need to access it like so:
 * ::CPSC131::DoublyLinkedList::DoublyLinkedList<int> list;
 * 
 * Look into main.cpp and CPP_Tests.cpp for examples of using
 * 	the DLL and your BookStore. But don't worry too much, as you
 * 	only need to implement these classes
 * (main and tests are already done for you)
 */


//
#include <iostream>
#include <stdlib.h>
#include <stdexcept>


/**
 * Namespace for our classroom !
 */
namespace CPSC131
{
	/**
	 * Namespace to hold all things related to our DLL
	 */
	namespace DoublyLinkedList
	{
		/**
		 * Node class, which our DLL will use
		 * 
		 * The Professor realizes he could have made this an inline class (like the Iterator),
		 * but he is lazy.



		 * That alright ill just suffer a lil more !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		 */
		template <class T>
		class Node
		{
			public:
				
				/// CTORS
				Node() : prev_(nullptr), next_(nullptr) {}
				Node(T element) : element_(element), prev_(nullptr), next_(nullptr){}
				Node(T element, Node* prev, Node* next) : element_(element), prev_(prev), next_(next){}
				
				/// Set the pointer to the previous element
				void setPrevious(Node* prev) { this->prev_ = prev; }
				
				/// Set the pointer to the previous element
				void setPrev(Node* prev) { this->prev_ = prev; }
				
				/// Get a pointer to the previous element
				Node* getPrevious() { return this->prev_; }
				
				/// Get a pointer to the previous element
				Node* getPrev() { return this->prev_; }
				
				/// Set the pointer to the next node
				void setNext(Node* next) { this->next_ = next; }
				
				/// Get a pointer to the next node
				Node* getNext() { return this->next_; }
				
				/// Set the element this node holds
				void setElement(T element) { this->element_ = element; }
				
				/// Get the element this node holds
				T& getElement() { return this->element_; }
				
				/// Return a reference to the element
				T& operator*() { return &this->element_; }
				
			private:
				T element_;
				Node* prev_;
				Node* next_;
		};
		
		/**
		 * Implement our DoublyLinkedList class !


		 * ok :(
		 */
		template <class T>
		class DoublyLinkedList
		{
			public:
				
				/**
				 * Nested Iterator class.
				 * This allows user code to refer to the Iterator's type as:
				 * 
				 * CPSC131::DoublyLinkedList::DoublyLinkedList<int>::Iterator
				 * 
				 * (as opposed to specifying the template argument two times)
				 */
				class Iterator
				{
					public:
						
						///	Constructor taking a head and tail pointer; YOUR WELCOME
						// OMG TY!!!!!!!!!!!!!!!!!!!!
						Iterator(Node<T>* head, Node<T>* tail) : head_(head), tail_(tail)
						{
							this->cursor_ = this->end();
						}
						
						///	Constructor taking a head, tail, and cursor pointer; YOUR WELCOME
						Iterator(Node<T>* head, Node<T>* tail, Node<T>* cursor) : head_(head), tail_(tail), cursor_(cursor) {}
						
						///	Get a pointer to the head node, or end() if this list is empty
						Node<T>* begin()
						{
							if(this->size_ == 0){return end();}
							return this->head_;
						}
						
						///	Get a node pointer representing "end" (aka "depleted"). Probably want to just use nullptr.
						Node<T>* end()
						{
							Node<T>* END = new Node<T>(nullptr);
							return END;
						}
						
						///	Get the node to which this iterator is currently pointing
						Node<T>* getCursor()
						{
							return this->cursor_;
						}
						
						/**
						 * Assignment operator
						 * Return a copy of this Iterator, after modification
						 */
						Iterator& operator=(const Iterator& other)
						{
							return assign(other);
						}
						
						///	Comparison operator
						bool operator==(const Iterator& other)
						{
							return this->cursor_ == other.cursor_;
						}
						///	Inequality comparison operator
						bool operator!=(const Iterator& other)
						{
							return !(*this == other);
						}
						
						/**
						 * Prefix increment operator
						 * Return a copy of this Iterator, after modification
						**/
						Iterator& operator++()
						{
							if(this->cursor_ == nullptr){return *this;}
							this->cursor_ = this->cursor_->getNext();
							return *this;						}
						
						/**
						 * Postfix increment
						 * Return a copy of this Iterator, BEFORE it was modified
						 */
						Iterator operator++(int)
						{
							if(this->cursor_ == nullptr || this->cursor_->getNext() == nullptr){
								return *this;
							}
							
							Iterator itrCopy = Iterator(this->head_, this->tail_, this->cursor_);
							this->cursor_ = this->cursor_->getNext();
							return itrCopy;
						}
						
						/**
						 * Prefix decrement operator
						 * Return a copy of this Iterator, after modification
						 */
						Iterator& operator--()
						{
							if(this->cursor_ == this->head_){
								return *this;
							}

							this->cursor_ = this->cursor_->getPrev();
							return *this;
						}
						
						/**
						 * Postfix decrement operator
						 * Return a copy of this Iterator BEFORE it was modified
						 */
						Iterator operator--(int)
						{
							if(this->cursor_ == this->head_){
								return *this;
							}

							Iterator itrCopy = Iterator(this->head_, this->tail_, this->cursor_);
							this->cursor_ = this->cursor_->getPrev();
							return itrCopy;
						}
						
						/**
						 * AdditionAssignment operator
						 * Return a copy of the current iterator, after modification
						*/
						Iterator operator +=(size_t add)
						{
							if(this->cursor_ == nullptr){
								return Iterator(this->head_, this->tail_, nullptr);
							}

							for(size_t i = 0; i < add; i++){
								if(this->cursor_ == nullptr){
									break;
								}
								this->cursor_ = this->cursor_->getNext();
							}
							return *this;
						}
						/**
						 * SubtractionAssignment operator
						 * Return a copy of the current iterator, after modification
						 */
						Iterator operator -=(size_t add)
						{
							if(this->cursor_ == nullptr){
								return Iterator(this->head_, this->tail_, nullptr);
							}

							for(size_t i = 0; i < add; i++){
								if(this->cursor == this->head_){
									break;
								}
								this->cursor_ = this->cursor_->prev_;
							}
							return *this;
						}
						
						/**
						 * AdditionAssignment operator, supporting positive or negative ints
						 */
						Iterator operator +=(int add)
						{
							if(this->cursor_ == nullptr){
								return *this;
							}


							size_t n = add > 0 ? add : -add;

							for(size_t i = 0; i < n; i++){
								if(add > 0){
									if(this->cursor_== nullptr){
										break;
									}
									this->cursor_ = this->cursor_->getNext();
								}else{
									if(this->cursor_ == this->head_){
										break;
									}
									this->cursor_ = this->cursor_->getPrev();
								}
							}return *this;
						}
						
						/**
						 * SubtractionAssignment operator, supporting positive or negative ints
						 */
						Iterator operator -=(int subtract)
						{
							if(this->cursor_ == nullptr){
								return *this;
							}

							size_t n = subtract > 0 ? subtract : -subtract;

							for(size_t i = 0; i < n; i++){
								if(subtract < 0){
									if(this->cursor_== nullptr){
										break;
									}
									this->cursor_ = this->cursor_->getNext();
								}else{
									if(this->cursor_ == this->head_){
										break;
									}
									this->cursor_ = this->cursor_->getPrev();
								}
							}return *this;
						}
						
						/**
						 * Dereference operator returns a reference to the ELEMENT contained with the current node
						 */
						T& operator*()
						{
							return this->cursor_->getElement();
						}
					
					private:
						
						/// Pointer to the head node
						Node<T>* head_ = nullptr;
						
						/// Pointer to the tail node
						Node<T>* tail_ = nullptr;
						
						/**
						 * Pointer to the cursor node.
						 * This is only one way of letting the iterator traverse the linked list.
						 * You can change to a different method if you wish (and can still pass unit tests)
						 */
						Node<T>* cursor_ = nullptr;
						
					//WHAT IS THIS???????? Is this like some sort of polymorphism or inheritance????
					//Please go over this im begging now
					//im gonna say its inheritance?????
					friend class DoublyLinkedList;
				};
				
				/// Your welcome
				DoublyLinkedList()
				{
					this->head_ = nullptr;
					this->tail_ = nullptr;
					this->size_ = 0;
				}
				
				///	Copy Constructor
				DoublyLinkedList(DoublyLinkedList& other)
				{
					//clear, then loop iteating over every node
					this->clear();
					for(Node<T>* i = other.head_; i != nullptr; i = i->getNext()){
						this->push_back(i->getElement());
					}
					//this->head_ = other.head_;
					//this->tail_ = other.tail_;
					//this->size_ = other.size_;
				}
				
				/// DTOR: Your welcome
				~DoublyLinkedList()
				{
					this->clear();
				}
				
				/**
				 * Clear the list and assign the same value, count times.
				 * If count was 5, T was int, and value was 3,
				 * 	we'd end up with a list like {3, 3, 3, 3, 3}
				 */
				void assign(size_t count, const T& value)
				{
					this->clear();
					for(size_t i = 0; i < count; i++){
						this->push_back(value);
					}
				}





				
				/**
				 * Clear the list and assign values from another list.
				 * The 'first' iterator points to the first item copied from the other list.
				 * The 'last' iterator points to the last item copied from the other list.
				 * 
				 * Example:
				 * 	Suppose we have a source list like {8, 4, 3, 2, 7, 1}
				 * 	Suppose first points to the 4
				 *	Suppose last points to the 7
				 * 	We should end up with our list becoming: {4, 3, 2, 7}
				 *
				 * If the user code sends out-of-order iterators,
				 * 	just copy from 'first' to the end of the source list
				 * Example: first=7, last=4 from the list above would give us:
				 * 	{7, 1}
				 */



				void assign(Iterator first, Iterator last)
				{
					this->clear();
					if(last < first){
						last = this->last();
					}

					for(auto i = first; first != last; i++){
						this->push_back(*i);
					}
				}
				
				/// Return a pointer to the head node, if any
				Node<T>* head() { return this->head_;}
				
				/// Return a pointer to the tail node, if any
				Node<T>* tail() { return this->tail_; }
				
				/**
				 * Return an iterator that points to the head of our list
				 */
				Iterator begin()
				{
					return Iterator(this->head(), this->tail(), this->head());
				}
				
				/**
				 * Return an iterator that points to the last element (tail) of our list
				 */
				Iterator last()
				{
					return Iterator(this->head(), this->tail(), this->tail());
				}
				
				/**
				 * Should return an iterator that represents being past the end of our nodes,
				 * or just that we are finished.
				 * You can make this a nullptr or use some other scheme of your choosing,
				 * 	as long as it works with the logic of the rest of your implementations.
				 */
				Iterator end()
				{
					return Iterator(this->head(), this->tail(), nullptr);
				}
				
				/**
				 * Returns true if our list is empty
				 */
				bool empty() const
				{
					return this->size_ == 0;
				}
				
				/**
				 * Returns the current size of the list
				 * Should finish in constant time!
				 * (keep track of the size elsewhere)

				* IM GOING TO GUESS THAT IS WHEN YOU ADD OR REMOVE FROM THE DBL LINKED LIST?!?!?!?

				 */
				size_t size() const
				{
					return this->size_;
				}
				
				/**
				 * Clears our entire list, making it empty
				 * Remember: All removal operations should be memory-leak free.
				 */
				void clear()
				{
					Node<T>* cursor = this->head_;
					while(cursor != nullptr){
						Node<T>* temp = cursor;
						cursor = cursor->getNext();
						delete temp;
					}
					this->head_ = nullptr;
					this->tail_ = nullptr;
					this->size_ = 0;
					delete cursor;
				}
				
				/**
				 * Insert an element after the node pointed to by the pos Iterator
				 * 
				 * If the list is currently empty,
				 * 	ignore the iterator and just make the new node at the head/tail (list of length 1).
				 * 
				 * If the incoming iterator is this->end(), insert the element at the tail
				 * 
				 * Should return an iterator that points to the newly added node
				 * 
				 * To avoid repeated code, it might be a good idea to have other methods
				 * 	rely on this one.
				 */
				Iterator insert_after(Iterator pos, const T& value)
				{
					//create new node
					//cursor is the cursor of the new node
					//if(empty){}
					//if(pos >= size) add element at the end of the list
					
					//return Iterator(nullptr, nullptr, cursor);
					if(this->empty()){
						Node<T>* newNode = new Node<T>(value);
						this->head_ = newNode;
						this->tail_ = newNode;
						this->size_++;
						return Iterator(this->head_, this->tail_, newNode);
					}
					if(pos == this->end()){
						this->push_back(value); //push back should increminet size
						return Iterator(this->head_, this->tail_, this->push_back(value).getCursor());
					}
					Node<T>* newNode = new Node<T>(value, pos.cursor_, pos.cursor_->getNext());
					pos.getCursor()->setNext(newNode);
					newNode->getNext()->setPrev(newNode);
					this->size_++;
					return Iterator(this->head_, this->tail_, newNode);
				}
				
				/**
				 * Insert a new element after the index pos.
				 * Should work with an empty list.
				 * 
				 * Should return an iterator pointing to the newly created node
				 * 
				 * To reduce repeated code, you may want to simply find
				 * 	an iterator to the node at the pos index, then
				 * 	send it to the other overload of this method.
				*/
				Iterator insert_after(size_t pos, const T& value)
				{
					//iterator to begin and then incerement by pos, return overload
					if(this->empty()){
						this->push_front(value);
						Node<T>* newNode = new Node<T>(value);
						this->head_ = newNode;
						this->tail_ = newNode;
						this->size_++;
						return Iterator(this->head_, this->tail_, newNode);
					}

					auto itr = this->begin();

					itr+=pos;
					return insert_after(itr,value);
					//grab an iterator from the beginning, then increase it by pos, then use the other overload (call it abnd return its result)
				}
				
				/**
				 * Erase the node pointed to by the Iterator's cursor.
				 * 
				 * If the 'pos' iterator does not point to a valid node,
				 * 	throw an std::range_error
				 * 
				 * Return an iterator to the node AFTER the one we erased,
				 * 	or this->end() if we just erased the tail
				 */
				Iterator erase(Iterator pos)
				{
					if(this->size_ == 0) { return Iterator(nullptr, nullptr, nullptr); }
					if(this->size_ == 1){
						this->head_ = nullptr;
						this->tail_ = nullptr;

					}
					if(pos == this->begin()){

					}
					if(pos == this->last()){

					}


					
					
					return Iterator(nullptr, nullptr, nullptr);


					//next pointer will point to the node that came before the iterator  
				}
				
				/**
				 * Add an element just after the one pointed to by the 'pos' iterator
				 * 
				 * Should return an iterator pointing to the newly created node
				 */
				Iterator push_after(Iterator pos, const T& value)
				{
					return this->insert_after(pos, value);
				}
				
				/**
				 * Add a new element to the front of our list.
				 */
				void push_front(const T& value)
				{
					if(this->empty()){
						Node<T>* newNode = new Node<T>(value);
						this->head_ = newNode;
						this->tail_ = newNode;
						this->size_++;
					}else{
						Node<T>* newNode = new Node<T>(value);
						newNode->setNext(this->head_);
						this->head_->setPrev(newNode);
						this->head_ = newNode;
						this->size_++;
					}

				}
				
				/**
				 * Add an element to the end of this list.
				 * 
				 * Should return an iterator pointing to the newly created node.
				 */
				Iterator push_back(const T& value)
				{
					if(this->empty()){
						Node<T>* newNode = new Node<T>(value);
						this->head_ = newNode;
						this->tail_ = newNode;
						this->size_++;	
						return Iterator(this->head_, this->tail_, newNode);
					}

					Node<T>* newNode = new Node<T>(value);
					newNode->setPrev(this->tail_);
					
					this->tail_->setNext(newNode);
					this->tail_ = newNode;
					this->size_++;
					return Iterator(this->head_, this->tail_, newNode);
				}
				
				/**
				 * Remove the node at the front of our list
				 * 
				 * Should throw an exception if our list is empty
				 */
				void pop_front()
				{
					if(this->empty()){
						throw std::out_of_range("List is empty, can not pop");
					}
					Node<T>* old = this->head_;
					this->head_ = this->head_->getNext();
					this->head_->setPrev(nullptr);
					this->size_--;
					delete old;
				}
				
				/**
				 * Remove the node at the end of our list
				 * 
				 * Should throw an exception if our list is empty
				 */
				void pop_back()
				{
					if(this->empty()){
						throw std::out_of_range("List is empty, can not pop");
					}else if(this->size_ == 1){
						delete this->head_;
						this->head_ = nullptr;
						this->tail_ = nullptr;
						this->size_ = 0;
					}else{

					Node<T>* old = this->tail_;
					this->tail_ = this->tail_->getPrev();
					this->tail_->setNext(nullptr);
					this->size_--;
					delete old;
					}
				}
				
				/**
				 * Return a reference to the element at the front.
				 * 
				 * Throw an exception if the list is empty
				 */
				T& front()
				{
					if(this->empty()){
						throw std::out_of_range("List is empty"); 
					}
					return this->head_->getElement();
				}
				
				/**
				 * Return a reference to the element at the back.
				 * 
				 * Throw an exception if the list is empty
				 */
				T& back()
				{
					if(this->empty()){
						throw std::out_of_range("List is empty"); 
					}
					return this->tail_->getElement();
				}
				
				/**
				 * Return the element at an index
				 * 
				 * Should throw a range_error is out of bounds
				 */
				T& at(size_t index)
				{
					if(index >= this->size_) throw std::out_of_range("Out of Range");
					auto iterateToElement = this->begin();
					iterateToElement += index;
					return *iterateToElement;
				}
				
				/**
				 * Reverse the current list
				 * 
				 * It might be easy to consider the following:
				 * - Create a temp empty list
				 * - Iterate through the current list
				 * - For each item in the current list, push to the FRONT (not back)
				 * - Assign the current list to the temp list
				 * - Discard the temp list
				 */
				void reverse()
				{
					DoublyLinkedList<T> temp;
					for(Node<T>* cursor = this->head_; cursor != nullptr; cursor = cursor->getNext()){
						temp.push_front(cursor->getElement());
					}
					*this = temp;
				}

				//OPTIONAL
				void sort()
				{
					//BUBBLE
				}
				
				/**
				 * Assignment operator
				 * 
				 * Clear this list and fill it with the others' values
				 * (by value, not by reference)
				 * 
				 * Return a reference to this list
				 */
				DoublyLinkedList<T>& operator =(DoublyLinkedList<T>& other)
				{
					this->clear();
					for(size_t i = 0; i < other.size(); i++){
						this->push_back(other.at(i));
					}
					return *this;
				}
				
				/**
				 * Return true if the lists are "equal"
				 * 
				 * "Equal" here is defined as:
				 * - Same size
				 * - Elements at the same indexes would return true for their own comparison operators
				 * 
				 * In other words: "They contain all the same values"
				 * (no need to be references to each other)
				 */
				bool operator ==(DoublyLinkedList<T>& other)
				{
					if(this->size_ != other.size_) return false;

					for(size_t i = 0; i < this->size_; i++){
						if(this->at(i) != other.at(i)){
							return false;
						}
					}return true;
				}
				
				/**
				 * Return true if the lists are "not equal"
				 * 
				 * See the operator== stub for definition of "equal"
				 * 
				 * Probably want to avoid repeated code by relying on the other operator
				 */
				bool operator !=(DoublyLinkedList<T>& other)
				{
					if(!(*this == other)){
						return true;
					}return false;
				}
				
			private:
				
				Node<T>* head_ = nullptr;
				Node<T>* tail_ = nullptr;
				size_t size_ = 0;
		};
	}
}

#endif
