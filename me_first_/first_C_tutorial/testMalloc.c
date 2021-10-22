// TEST 

int* itob(int num, int size) // Returns an int array, not a char array
{
//  int binary[size];
//  binary[size] = (int*)malloc(size);
    int* binary = malloc(size * sizeof(int)); // Note: Don't cast the malloc return!
    for (int i = 0; i < size; i++) {
        binary[i] = 0;
    }
    int decimal = num;
    int counter = size - 1; // Your code will return the digits in reverse order!

    if (decimal > -32768 && decimal < 32767) {
        if (decimal < 0) {
            decimal = 65536 + decimal;
        }
        while (decimal > 0) {
            binary[counter] = decimal % 2;
            decimal = decimal / 2;
            counter--; // See the comment on the initialization of counter
        }
    }

    return binary;
}
