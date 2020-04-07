class Solution {
public:
    int countElements(vector<int>& arr) {
        int n=arr.size();
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
        }
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        set<int>::iterator it=s.begin();
        set<int>::iterator it1=s.begin();
        it1++;
        int count=0;
        while(it1!=s.end()){
            if(*it1-*it==1){
                count+=m[*it];
            }
            it1++;
            it++;
        }
        return count;
    }
};