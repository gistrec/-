// crt_getchar_nolock.c  
// Use _getchar_nolock to read a line from stdin.   

#include <stdio.h>  

// Since it is not thread safe, all overheads of mutual exclusion are avoided and it is faster than getchar().
//
// Can be especially useful for competitive programming problems with “Warning: Large I/O data, be 
// careful with certain languages (though most should be OK if the algorithm is well designed)”. 
// 
// There is no issue with using getchar_unlocked() even in multithreaded environment as long as the
// thread using it is the only thread accessing file object
//
// It is a known fact than scanf() is faster than cin and getchar() is faster than scanf() in general.
// getchar_unlocked() is faster than getchar(), hence fastest of all.


int main() {
	char buffer[81];
	int i, ch;

	for (i = 0; (i < 80) && ((ch = _getchar_nolock()) != EOF)
		 && (ch != '\n'); i++) {
		buffer[i] = (char)ch;
	}

	// Terminate string with a null character   

	buffer[i] = '\0';
	printf("Input was: %s\n", buffer);
}