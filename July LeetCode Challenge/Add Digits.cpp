class Solution {
public:
    int sum=0;
    int addDigits(int num) {
        if (num== 0)  
            return 0; 
        return (num % 9 == 0) ? 9 : (num % 9); 
    }
};