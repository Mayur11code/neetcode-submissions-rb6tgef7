class Solution {
public:

    bool isValid(int index,int n){
        return (index>-1 && index<n);
    }

    string longestPalindrome(string s) {

        string p= "";
        int n = s.size();
        int streak =0;
        for(int i=0; i< s.size();i++){
            
            if(isValid(i-1,n) && s[i]==s[i-1]){
                streak++;
            }

            if(isValid(i-1,n) && (s[i]!=s[i-1] || i==s.size()-1 )){
                if( streak+1 > p.size()){
                    string t="";
                    for(int j=0; j<=streak;j++){
                        t+=s[i-1];

                    }
                    p=t;
                }
                    streak = 0;
                    
                }
            
               
            
            int l = i-1;
            int r = i+1;
            
if(isValid(r,n)&& isValid(l,n)){
            string temp ="";
            if(s[l]!=s[r] ){
                if(s[l]==s[i]){
                    r--;
                }
                else if(s[r]==s[i]){
                    l++;
                }
                else{
                    continue;
                }
            }
            else{

                temp+=s[i];

            }
            while(isValid(l,n) && isValid(r,n) && s[r]==s[l]){

                temp+=s[r];
                temp.insert(0,1,s[l]);
                l--;
                r++;

            }
            

            if(temp.size()>p.size()){
                p = temp;
            }

            }

          
        
                string temp ="";
                temp+=s[i];
                
                if(isValid(l,n) && s[l]==s[i]){
                    temp+=s[l];
                }
                else if(s[r]==s[i]){
                    temp+=s[r];
                }
                if(p.size()<temp.size() || p.size()==0) {
                    p=temp;
                }
                
            


        }
        

        return p;
    }
};
