class Solution {
public:
    int numDecodings(string s) {

    // 1. Create an empty dictionary (hash map)
    std::unordered_map<char, int> alphabet_dict;

    // 2. Loop from 'A' to 'Z' to fill it
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        alphabet_dict[letter] = letter - 'A' + 1;
    }
        if(s.size()==1 && s[0]!='0'){return 1;}
        if(s[0]=='0' || (((s[0] - '0') * 10 + (s[1] - '0'))>26 && s[1]=='0') ){ return 0;}
        int wn1=s[1]=='0'? 0: 1;
        int wn2=1;

        for(int i=1; i<s.size();i++){
            if(s[i]=='0'){
                wn1 = 0;
            }
            if(((s[i - 1] - '0') * 10 + (s[i] - '0'))>26){
                 wn2=0;
            }
            if(!wn2 && !wn1){
                return 0;
            }

            int am = wn1 + wn2;
            wn2=wn1;
            wn1=am;

        }

        return wn1;

        




    }
};
