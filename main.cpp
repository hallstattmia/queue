// C++ program for the above approach
#include <bits/stdc++.h>
#include  "queue.hpp"
using namespace std;

// Driver Code
int main()  {
	// Queue initialization
	Queue<Order> q;

	int n = 50000000;
	for (int i = 0; i < n; i++)
		q.push(Order(i, i ,i));

	
	std::cout << q.size()   << std::endl;
	// for (int i = 0; i < n; i++)
	// 	q.pop();
	// std::cout << q.size()   << std::endl;
	// long long ans =  0;
	// for (int i = 0; i < n; i++) ans  += q.front().qty  + q.back().qty;
	// std::cout << ans <<std::endl;
	return 0;
}
