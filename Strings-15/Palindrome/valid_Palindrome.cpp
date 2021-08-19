class Solution {
public:
    bool isPalindrome(string s) {
    // i define a new string
      string newS="";

      for(auto it:s){
          if(isalnum(it))
              newS+=tolower(it);
      } // i append in the new string only the alphanumeric letters (lowercase already)

      bool valid = true;

      // if s only contains not alphanumeric letters, newS will be empty
      if(newS == "") 
          return valid;

      int i=0,j=newS.size()-1;
      while(valid&&i<=j){
          if(newS[i]!=newS[j])
              valid = false;
          i++,j--;
      } //at this point we can just do the simple and usual iteration to find out if it's palindrome.

        return valid; //i return the value
    }
};
