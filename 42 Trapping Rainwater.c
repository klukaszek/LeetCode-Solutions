//10/17/2022 06:45	Accepted	28 ms	7.1 MB	c

int max(int a, int b)
{
    if(a>b) return a;
    else return b;
}

int trap(int* height, int heightSize){
        
    if (height == NULL) return 0;
    
    int l = 0;
    int r = heightSize - 1;
    int lmax = height[l];
    int rmax = height[r];
    int result = 0;
    
    //iterate through 2D heightmap while left pointer <  right pointer
    while(l < r)
    {
        //if left maximum is greater than right maximum, we increment pointer, set new left maximum depending on current maximum and current height,
        //and increase result based on difference between left maximum and current height at left pointer
        if(lmax < rmax)
        {
            l += 1;
            lmax = max(lmax, height[l]);
            result += lmax - height[l];
        }
        //else, do the same thing but with the right pointer...
        else
        {
            r -= 1;
            rmax = max(rmax, height[r]);
            result += rmax - height[r];
        }
    }
    
    return result;
    
}
