#pragma once
#include <cstring>
#include <cstdint>
#include <iostream>
#include <numeric>
struct Order {
	int64_t oid;
	int64_t price;
	int64_t qty;
	Order()  {}
	Order(int64_t x, int64_t   y, int64_t z):oid(x),price(y),qty(z){}
};

constexpr size_t CACHE_LINE_SIZE=64;
// Class definition for queue
template <typename X>
class Queue {

private:
	

	// Stores the array
	X* arr;

	// Stores the sizeof queue
	size_t sizeVar;

	// Stores the size of array
	size_t capacityVar;

	// Stores the frontIndex
	size_t frontIndex;

public:
	// Queue class constructor
	Queue()
	{
		capacityVar =  CACHE_LINE_SIZE /  std::gcd(CACHE_LINE_SIZE,  sizeof(X));
		arr = new (std::align_val_t(CACHE_LINE_SIZE))   X[capacityVar];
		frontIndex = sizeVar = 0;
		
	}

	// Function Methods

	// Function to check if
	// Queue is empty or not
	bool empty()  const{
		return frontIndex 
			== sizeVar;
	}
	// Function to check if the queue
	// is full or not
	bool full()  const
	{
		return capacityVar ==
			sizeVar;
	}

	// Find the capacity of queue
	size_t capacity() const  {
		return capacityVar;
	}
	// Find the number of elements
	// present in Queue
	size_t size() const{
		return sizeVar;
	};

	void push(const X &x) {
		push(std::move(x));
	}
	// Function to insert the element
	// to the rear end of the queue
	void push(X &&x)
	{
		if (full()) {

			// If the queue is full, then
			// double the capacity
			capacityVar  <<=  1;

			// Initialize new array of
			// double size
			X* temp = new (std::align_val_t(CACHE_LINE_SIZE)) X[capacityVar];

			// Copy the elements of the
			// previous array in the order of the queue
			for (int i = 0; i < sizeVar; i++){
				temp[i] = arr[i];
			}

			// Deallocate the memory
			// of previous array
			delete[] arr;
			arr = temp;
		}


		// Increment the backIndex
		arr[sizeVar++] = x;
	}
	// Function to find the front element
	// of the queue
	X &front()
	{
		// If queue is empty
		if (empty()) {
			std::cout << "Queue underflow"
				<< std::endl;
			abort();
		}

		return arr[frontIndex];
	}

	// Function to find the last element
	// of the Queue
	X &back()
	{
		if (empty()) {
			std::cout << "Queue underflow"
				<< std::endl;
			abort();
		}
		return arr[sizeVar-1];
	}



	// Function to pop an element from
	// front end of the queue
	void pop() {
		// If queue is empty
		if (empty()) {
			std::cout << "Queue underflow"
				<< std::endl;
			abort();
		}

		sizeVar--;
	}
};



