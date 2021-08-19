class Solution {
public int longestCommonSubsequence(String text1, String text2) {
if(text1.length()==0 || text2.length()==0){
return 0;
}
int[][] table = new int[text1.length()+1][text2.length()+1];

    for(int i=0;i<=text1.length();i++){
        
      for(int j=0;j<=text2.length();j++){
         table[i][j] = -1;
    }
    }

   findLongest(text1,text2,text1.length(),text2.length(),table);
   
   return table[text1.length()][text2.length()];
   }

public int findLongest(String s1,String s2,int end1,int end2,int[][] table){
    
    if(end1 <= 0 || end2 <= 0){
         return 0;
    }
    if(table[end1][end2]!= -1){
         return table[end1][end2];
    }
    else{
         int value=0;
        if(s1.charAt(end1-1)==s2.charAt(end2-1)){
            value =1+findLongest(s1,s2,end1-1,end2-1,table);
            }
        
        else {
            
             value=Math.max(findLongest(s1,s2,end1,end2-1,table),findLongest(s1,s2,end1-1,end2,table));
        }
        table[end1][end2] = value;
        return value;
    }
    


 }
}
