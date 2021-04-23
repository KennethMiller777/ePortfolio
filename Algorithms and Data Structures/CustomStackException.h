#ifndef CUSTOM_STACK_EXCEPTION
#define CUSTOM_STACK_EXCEPTION

#include <iostream>
using namespace std;

 
class CustomStackException {
public:
   CustomStackException(const string& whereThrown,
                  const string& message) { 
       myLocation = whereThrown; 
       myMessage = message; 
   }

   string asString() const {
       return "*** StackException in " +
               myLocation + ": " + myMessage; 
   }

private:
   string myLocation;
   string myMessage;
};  // StackException


/* Function to allow a CustomStackException (or a subclass) to be displayed
 * via an ostream.
 * Parameters: out, an ostream;
 *             se, a StackException.
 * Postcondition: the string representation of se has been inserted
 * into out
 *             && return-value == out.
 */
inline ostream& operator<<(ostream& out, const CustomStackException& se) {
      out << se.asString();
      return out;
}

#endif

