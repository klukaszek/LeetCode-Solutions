//10/17/2022 21:22	Accepted	0 ms	5.7 MB	c

bool checkIfPangram(char * sentence){
    if(strlen(sentence) < 1 || strlen(sentence) < 26 || strlen(sentence) > 1000) return false;
    
    int storage = 0; 
    
    //iterate through string and convert characters to respective index in the alphabet 
    //and set corresponding bit in bitmask "storage"
    for(int i = 0; i < strlen(sentence); i++)
    {
        int c = ((int)sentence[i]) - 97;
        if(c >= 0 && c <= 26)
        {
            if((storage & (1 << c)) == 0)
            {
                storage |= 1 << c;
            }
        }
    }
    
    //iterate through all 26 bits in bitmask to see if every character has been located
    for(int i = 0; i < 26; i++)
    {
        int bit = storage &(1 << i);
        if(bit == 0)
        {
            return false;
        }
    }
    
    return true;
}
