/*
	C++ rewrited optimised stack library
	Ayoub Lakrad, 2022
*/


// Preprocessor commands
#ifndef __STACK__
#define __STACK__

// Including C/C++ librairies
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// Definition of a Stack  
typedef struct StackElement
{
	double (*pointer)(double, double); // 1 function pointer
	struct StackElement *next; // next pointer which points to the next Stack struct
}StackElement, *Stack; // Hide using a Stack * return in the functions (This line allows us to use Stack type return without *)
class StackManager // Definition of the class
{
	// All the data/methods will be public because we wanna access to the data and functions in the class
	public:
		StackManager() // Simple constructor (no parameter)
		{
   			printf("StackManager is launched.\n");
		}
		// Function to create a new stack
		// Basically just returns nullptr to the stack struct which means that the new stack is null
		Stack new_stack(void)
		{
			return nullptr;
		}
		// Tests if the stack is empty
		// @param Stack st
		bool is_empty(Stack st)
		{
			if (st == nullptr) return true; 
			return false;
		}
		// Adds a StackElement struct to the Stack st
		// @param Stack st, long double a, b
		Stack add(Stack st, double (*p)(double, double))
		{
			// Allocates the correct space and converts the return of the function to a StackElement * (I experienced an issue with this because I didn't convert the void * return to StackElement *)
			StackElement *element = (StackElement *)malloc(sizeof(*element));
			// Checks if the allocation was done properly (I experienced an issue like this in the Queue's project)
			if (element == NULL)
			{
				fprintf(stderr, "DynamicMemoryAllocationError : Permission denied or not avaiable memory.\n");
				exit(EXIT_FAILURE);
			}
			// Print some adresses and size of the stack element (nvm its just update) - ha ha.
			printf("Adresss of the stack element allocated %p\n", &element);
			printf("Size of one element in the Stack : %u bytes.\n", sizeof(*element));
			// Give the values to the struct
			element->pointer = p;
			// The next of that element is the stack, if it was empty, it will be nullptr 
			// Because the stack when we created it, It was nullptr
			element->next = st;
			printf("Adresses of the struct elements : %p, %p\n", &element->pointer, &element->next);
			// Returns the element to the stack
			return element;	
		}
		// Print values in the stack
		void execute(Stack st, double a, double b)
		{
			if (is_empty(st)) return;

			while (!is_empty(st))
			{
				double r = st->pointer(a, b);
				printf("%f\n", r);
				st = st->next;
			}
		}
		// Pop off an element from stack
		// @param Stack st
		Stack remove(Stack st)
		{
			if(is_empty(st)) return new_stack();

			StackElement *element;
			printf("Adress of a stack copy to delete : %p\n", &element);
			element = st->next;
			printf("Adress of st->next : %p\n", &st->next);
			free(st);

			return element;
		}
		// Deletes all the stack and returns a nullptr stack
		Stack del(Stack st)
		{
			while (!is_empty(st))
				st = remove(st);
			return new_stack();
		}
};


#endif
