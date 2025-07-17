
/**
 * TODO: Complete this class!
 */

// Your welcome
#include <assert.h>
#include <iostream>
#include <string>



template <typename T>
class MyVector
{
	public:
		
		/*******************
		 * Static constants
		 ******************/
		
		/// Default capacity
		static constexpr size_t DEFAULT_CAPACITY = 64;
		
		/// Minimum capacity
		static constexpr size_t MINIMUM_CAPACITY = 8;
		
		/*****************************
		 * Constructors / Destructors
		 ****************************/
		
		/// Normal constructor
		MyVector(size_t capacity = MyVector::DEFAULT_CAPACITY) {
			
			// TODO: Your code here
			this->elements_ = new T[capacity];
			this->size_ = 0;
			this->capacity_ = capacity;
		}
		
		/// Copy constructor
		MyVector(const MyVector& other) {
			
			// TODO: Your code here
			
			this->elements_ = new T[other.capacity_];
			copyOther(other);
			//PUT IN HELPER FUNCTION
			//CALL CHANGE CAPACITY INSTEAD OF using new
		}
		
		/**
		 * Destructor
		 * Should call clear() so each element gets its destructor called.
		 * Then, de-allocate the internal array and make it a nullptr, if its not already a nullptr.
		 */
		~MyVector() {
			
			// TODO: Your code here
			clear();
			delete [] this->elements_;
			/*
			??????????
			??????????
			??????????
			??????????
			*/
		}
		
		/************
		 * Operators
		 ************/
		
		///	Assignment operator
		MyVector& operator=(const MyVector& rhs) {
			
			// TODO: Your code here
			// create new pointer / new memory allocation
			copyOther(rhs);	//warning no return statement error when doing make build.
			/*
			??????????
			??????????
			??????????
			??????????
			*/
			return *this;
		}
		
		/// Operator overload to at()
		T& operator[](size_t index) const {
			
			// TODO: Your code here
			return this->at(index);
		}
		
		/************
		 * Accessors
		 ************/
		
		/// Return the number of valid elements in our data
		size_t size() const {
			
			// TODO: Your code here
			return this->size_;
		}
		
		/// Return the capacity of our internal array
		size_t capacity() const {
			
			// TODO: Your code here
			return this->capacity_;
		}
		
		/**
		 * Check whether our vector is empty
		 * Return true if we have zero elements in our array (regardless of capacity)
		 * Otherwise, return false
		 */
		bool empty() const {
			return this->size_ <= 0;
		}
		
		/// Return a reference to the element at an index
		T& at(size_t index) const {
			
			// TODO: Your code here
			//Check if it is out of bounds and then throw an exception if it is if not return index
				if(index >= this->size_){
					throw std::out_of_range("Out Of Bounds");
				}
				return elements_[index];
		}
		
		/***********
		 * Mutators
		 ***********/
		
		/**
		 * Reserve capacity in advance, if our capacity isn't currently large enough.
		 * Useful if we know we're about to add a large number of elements, and we'd like to avoid the overhead of many internal changes to capacity.
		 */
		void reserve(size_t capacity) {
			
			// TODO: Your code here
			if(capacity < MINIMUM_CAPACITY){capacity_ = MINIMUM_CAPACITY;}
			//try as long i\as cap is > size if tests dont pass
			if(capacity > this->capacity_){
				changeCapacity(capacity);
			}
			/*
			??????????
			??????????
			??????????
			??????????
			*/
			
		}

		
		/**
		 * Set an element at an index.
		 * Throws range error if outside the size boundary.
		 * Returns a reference to the newly set element (not the original)
		 */
		T& set(size_t index, const T& element) {
			
			// TODO: Your code here
			if(index >= this->size_){throw std::out_of_range("Out Of Range");}
			this->elements_[index].~T();
			this->elements_[index] = element;
			return this->elements_[index];
			
		}
		
		/**
		 * Add an element onto the end of our vector, increasing the size by 1
		 * Should rely on the insert() function to avoid repeating code.
		 * Returns a reference to the newly inserted element
		 */
		T& push_back(const T& element) {
			
			// TODO: Your code here
			return insert(size(), element);
		}
		
		/**
		 * Remove the last element in our vector, decreasing the size by 1
		 * Should rely on the erase() function to avoid repeating code.
		 * Returns the new size.
		 */
		size_t pop_back() {
			
			// TODO: Your code here
			return erase(size()-1);
		}
		
		/**
		 * Insert an element at some index in our vector, increasing the size by 1
		 * 
		 * Scoot all elements at index and beyond, one to the right. This
		 * makes a "hole" available at the index, where you can then place
		 * the new element.
		 * 
		 * Returns a reference to the newly added element (not the original).
		 */
		T& insert(size_t index, const T& element) {

			//increase size first, then move elements to the right creating a hole which you fill with param &T element
			//return this->elements_[index];
			//never going to be blank spots
			//slideshow 19 6-7
			// TODO: Your code here
			// index6 9 
			// 1,2,3,4,5,6,7,8,9,0, , , , 
			//change capacity if index >= size???
			
			if(index > this->size_){
				throw std::out_of_range("Out of Range");
			}
			increaseSize();
			//size_t calc = (size() - index) - 1;
			for(size_t i = this->size_-1; i > index; i--){ // size_t i = index; i < calc; i++
				//size_t sourceIndex = size()-2-i;
				//size_t destinationIndex = size()-1-i;
				//myb out of bounds when at end
				//cave man debug with values

				this->elements_[i] = elements_[i-1]; 
			}
			this->elements_[index] = element; //fills hole
			return this->elements_[index];

			/*
			??????????
			??????????
			??????????
			??????????
			*/
		}
		
		/**
		 * Erase one element in our vector at the specified index, decreasing the size by 1.
		 * 
		 * This means you'd then have to scoot elements to the left to fill the "hole"
		 * 	left by the erased element.
		 * 
		 * Throws std::range_error if the index is out of bounds.
		 * 
		 * Calls the erased element's destructor.
		 * 
		 * Returns the new size.
		 */
		size_t erase(size_t index) {
			
			// TODO: Your code here
			if(index >= this->size_){
				throw std::out_of_range("Out of Range");
			}
			this->elements_[index].~T(); // destructs element
			for(size_t i = index; i < this->size_-1; i++){
				this->elements_[i] = this->elements_[i+1]; 
			}
			this->elements_[size()].~T(); // destructs the space.
			decreaseSize();
			return size_;
			/*
			??????????
			??????????
			??????????
			??????????
			*/
		}
		
		/**
		 * Calls each elem_ent's destructor, then clears our internal
		 * data by setting size to zero and resetting the capacity.
		*/
		void clear() {
			
			// TODO: Your code here

			while(!this->empty())
			this->pop_back(); 


			/*
			??????????
			??????????
			??????????
			??????????
			*/
		}
	
	/**
	 * Begin private members and methods.
	 * Private methods can often contain useful helper functions,
	 * or functions to reduce repeated code.
	*/
	private:
		
		/// Number of valid elements currently in our vector
		size_t size_ = 0;
		
		/// Capacity of our vector; The actual size of our internal array
		size_t capacity_ = 0;
		
		/**
		 * Our internal array of elements of type T.
		 * Starts off as a null pointer.
		 */
		T* elements_ = nullptr; // THIS WILL BE INSTANTIATED AS A ARRAY USING" [] "
		
		/**
		 * Helper function that is called whenever we need to change the capacity of our vector
		 * Should throw std::range_error when asked to change to a capacity that cannot hold our existing elements.
		 * It's probably a good idea to make an additional helper function that decides
		 * 	whether to change capacity at all (and to what new capacity), that your public functions can rely upon.
		 */
		void changeCapacity(size_t c) {
			
			// TODO: Your code here
			//Double capacity if there is no room.
			T* newArr = new T[c];
			capacity_ = c;
			for (size_t i = 0; i < this->size_; i++) {
        		newArr[i] = elements_[i];
			}
    		delete [] elements_;
			elements_ = newArr;
		}

		void increaseSize(){
			this->size_++;
			if(this->size_ > this->capacity_){
				changeCapacity(this->capacity_*2);
			}
		}

		void decreaseSize(){
			if(empty()) throw std::out_of_range("Out of Range");
			this->size_--;
			if(this->size_ < this->capacity_/3){
				changeCapacity(this->capacity_/2);
			}
		}
		
		/**
		 * Copy another vector's elements into our own, by value.
		 * Does not simply copy the other vector's array's pointer
		 * Does not care about matching the capacity exactly.
		 * This is a helper function relied upon by the copy constructor and the assignment operator,
		 * 	to avoid repeated code.
		 * 
		 * You will probably want to make additional helper functions to make this one easier.
		 * Here is a suggested strategy for copying the internal array:
		 * 1. Deallocate the current array for 'this' (if it is already allocated)
		 * 2. Allocate a new array for 'this' of the appropriate size
		 * 3. Use a loop to copy elements one-by-one (by value)
		 * 4. Copy other relevant properties from the 'other' to 'this'
		 */
		void copyOther(const MyVector& other) {
			
			// TODO: Your code here
			delete [] this->elements_;
			this->elements_ = new T[other.capacity_];
			this->size_ = other.size_;
			this->capacity_ = other.capacity_;
			for(size_t i = 0; i < this->size_; ++i){this->elements_[i] = other[i];}
		}
};


