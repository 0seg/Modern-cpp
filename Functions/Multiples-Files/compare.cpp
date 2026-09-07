/*this file contains the implementation of the max function, which compares two integers and returns the maximum value.
*/

int max(int x, int y) {
    // Compare two integers and return the maximum
    if(x > y){
        return x;
    } else {
        return y;
    }
}

int min(int x, int y) {
    // Compare two integers and return the minimum
    if(x < y){
        return x;
    } else {
        return y;
    }
}