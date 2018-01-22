#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]){
	int val, result;

	stack usedStack = newStack();

	val = 1;
	result = stackPush(usedStack, val);

	free(usedStack);

	return EXIT_SUCCESS;
}