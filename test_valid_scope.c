/* Test Case 1.9: Nested Blocks and Scoping */
int main() {
    int x;
    x = 5;
    
    {
        int y;
        y = 10;
        {
            int z;
            z = 15;
        }
    }
    
    return 0;
}
