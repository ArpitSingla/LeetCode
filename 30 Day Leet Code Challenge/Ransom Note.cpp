class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()==0 && magazine.size()==0){
            return true;
        }
        else if(ransomNote.size()==0){
            return true;
        }
        map<char,int> m;
        for(int i=0;i<magazine.size();i++){
            m[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(m[ransomNote[i]]>=1){
                m[ransomNote[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};