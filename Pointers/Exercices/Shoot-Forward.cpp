/*
Shoot-Forward

You are given an array of 10 integral elements and an offset value of type unsigned int
Your job is to figure out which element we would hit if we went offset slots from the beginning of the array

For example if your input array is int data[] {1,3,6,3,9,3,5,7,2,11};

and your offset is 3, then your code should prin the message exactly as shown below:

"The element 3 slots away from the beginning of the array is 3"

*/

int main(){
    int data[] {1,3,6,3,9,3,5,7,2,11};

    std::cout << "The element 3 slots away from the beginning of the array is " << *(data + 3) << std::endl;

}