int*  maximum_address( int data[], unsigned int size){

  int * max_address;
  
  //Don't modify anything above this line
  //Your code will go below this line
  
    max_address = &data[0]; // Initialize max_address to the address of the first element

    for(unsigned int i = 1; i < size; ++i) {
        if (data[i] > *max_address) { // Compare values
            max_address = &data[i]; // Update max_address if a larger value is found
        }
    }

  //Your code should go above this line
  //Don't modify anything after this line
  return max_address;
}