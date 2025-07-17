

/**
 * TODO: Complete these class definitions
 */

/// Starter includes (YW)
#include "MyDetector.hpp"
#include "MyStack.hpp"
#include "MyQueue.hpp"
#include <cctype>

//
namespace CPSC131::PalindromeDetector
{
	/// YOUR WELCOME
	MyDetector::MyDetector() {}
	
	//
	bool MyDetector::isPalindrome(std::string s) {
		MyStack<char> stk;
		MyQueue<char> q;

		for(char c : s){
//   _____                       _                 _     _____ _   
//  / ____|                /\   | |               | |   |_   _| |  
// | |     _ __ _   _     /  \  | |__   ___  _   _| |_    | | | |_ 
// | |    | '__| | | |   / /\ \ | '_ \ / _ \| | | | __|   | | | __|
// | |____| |  | |_| |  / ____ \| |_) | (_) | |_| | |_   _| |_| |_ 
//  \_____|_|   \__, | /_/    \_\_.__/ \___/ \__,_|\__| |_____|\__|
//               __/ |                                             
//              |___/                                              
			if(isalpha(c)){ // did not feel like comparing ascii values so i did an ascii art instead
				stk.push(tolower(c));
		 		q.enqueue(tolower(c));
			}
		}

		while(stk.size() != 0){
			if(stk.top() != q.front()) {
				return false;
			}
			stk.pop();
			q.dequeue();
		}
		return true;
	}
}












