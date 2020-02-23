#ifndef STRING_H
#define STRING_H

#include <string>
#include <sstream>

using namespace std;

class String
{
	public:
		String();
		String(int mNoElements);
		string& operator [](int index);
		void add(const string& newElement);
		int getnElements() const;
		int getSize() const;
		
		class IndexOutOfBounds
		{
			private:
				int indexOutOfBounds; // The index that is out of bounds.
				string message; // The error message.
			public:
				/*
				Overloaded constructor.
				Creates an IndexOutOfBounds object with index and message specified by parameters.
				@param mIndexOutOfBounds		The index that is out of bounds.
				@param mMessage					The error message.
				*/
				IndexOutOfBounds(int mIndexOutOfBounds, const string& mMessage)
				{
					this->indexOutOfBounds = mIndexOutOfBounds;
					this->message = mMessage;
				}
				
				/*
				Returns index that was out of bounds.
				@return			Index that was out of bounds.
				*/
				int getIndex() const
				{
					return this->indexOutOfBounds;
				}
				
				/*
				Returns error message.
				@return			The error message.
				*/
				string getMessage() const
				{
					return this->message;
				}
		};
		
		~String();
		
	private:
		int noElements; // Number of elements in array.
		int size; // Size of the array.
		string* dynamicArray; // Pointer to the first element of the array.
		
		void resizeIfNecessary();
		
};

#endif
