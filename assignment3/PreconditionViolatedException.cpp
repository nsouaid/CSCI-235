/** Listing 7-6.
    @file PreconditionViolatedException.cpp */
#include "PreconditionViolatedException.h"  

PreconditionViolatedException::PreconditionViolatedException(const string& message): logic_error("Precondition Violated Exception: " + message) {
}

