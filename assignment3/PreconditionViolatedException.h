/** Listing 7-5.
    @file PreconditionViolatedException.h */

#ifndef TEACH_CSCI235_STACKADT__PRECONDITIONVIOLATEDEXCEPTION_H
#define TEACH_CSCI235_STACKADT__PRECONDITIONVIOLATEDEXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;

// A simple exception class as a child of logic_error.
class PreconditionViolatedException : public logic_error {
	public:
	PreconditionViolatedException(const string& message = "");
};
#endif
