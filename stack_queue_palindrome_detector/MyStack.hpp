#ifndef CPSC131_MYSTACK_HPP
#define CPSC131_MYSTACK_HPP


/**
 * TODO: Complete this class
 */


//
#include <forward_list>
#include <stdexcept>


//
namespace CPSC131
{
	///	Complete your custom MyStack using an std::forward_list under the hood.
	template <class T>
	class MyStack
	{
		//
		public:
			
			/// YOUR WELCOME
			MyStack() {}
			
			/**
			 * push()
			 * 
			 * Takes an item and pushes it onto the stack.
			 */
			void push(const T& item)
			{
				list.push_front(item);
				this->size_++;
			}
			
			/**
			 * Removes the next item from the stack
			 * 
			 * Does not return a value
			 * 
			 * If the stack is empty: throw an std::range_error
			 */
			void pop()
			{
				if(this->size_ == 0) throw std::out_of_range("Out of Range");
				list.pop_front();
				this->size_--;
			}
			
			/**
			 * Peek at the top of the stack
			 * 
			 * Does not remove anything.
			 * 
			 * If the stack is empty: throw an std::range_error
			 */
			T& top()
			{
				if(this->size_ == 0) throw std::out_of_range("Out of Range");
				return this->list.front();
			}
			
			/**
			 * Remove all items from the stack
			 */
			void clear()
			{
				this->list.clear();
				this->size_ = 0;
			}
			
			/**
			 * Return the number of items in the stack
			 */
			size_t size()
			{
				return this->size_;
			}
			
			/**
			 * Return true if the stack is empty, false otherwise
			 */
			bool empty()
			{
				return this->list.empty();
			}
			
		//
		private:
			
			/**
			 * Do not change these privates.
			 * You may add additional privates below this block, if you wish.
			 */
			std::forward_list<T> list;
			size_t size_ = 0;
			/******************************/
	};
}







#endif
