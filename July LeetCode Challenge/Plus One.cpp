class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(n==0){
            digits.push_back(1);
            return digits;
        }
        int i=n-1;
        while(i>=0){
            if(digits[i]==9){
                digits[i]=0;
                i--;
            }
            else{
                digits[i]++;
                return digits;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};