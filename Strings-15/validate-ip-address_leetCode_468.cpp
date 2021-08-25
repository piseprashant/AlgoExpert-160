class Solution {
public:
    
   bool checkIp4Block(string octate) 
{
        if(octate.length() == 0  || octate.length() > 3 ||
				(octate.length() > 1 && octate[0] == '0'))
            return false;
        
        for(auto ch : octate) {
            if(!isdigit(ch))
                return false;            
        }
        
        if(stoi(octate) > 255)
            return false;
        
        return true;
    }
    
    bool checkIp6Block(string octate)
    {
        if(octate.length() == 0 || octate.length() > 4)
            return false;
        
        for(auto ch : octate) {            
            if(!isdigit(ch) && !(ch >= 'a' && ch <= 'f') && !(ch >= 'A' && ch <= 'F') )
                return false;
        }
        
        return true;
    }
    
   
    vector<string> split(string str, char splitChar)
    {
        istringstream iss(str);
        string temp;
        vector<string> res;
        
        while(getline(iss, temp, splitChar))
			res.push_back(temp);
			
        return res;
    }
    
    string validIPAddress(string IP) 
    {
        // v4 
        if(IP.find('.') != string::npos) {            
            if(count(IP.begin(), IP.end(), '.')  != 3) // count STL API
                return "Neither";
            
            vector<string> parts = split(IP, '.');            
            if(parts.size() != 4 )
                return "Neither";
            
            for(auto ch : parts) {
                if(!checkIp4Block(ch))
                    return "Neither";                
            }
            
            return "IPv4";
        }
        else if(IP.find(':') != string::npos) {  // v6            
            if(count(IP.begin(), IP.end(), ':')  != 7) // count STL API
                return "Neither";
            
            vector<string> parts = split(IP, ':');            
            if(parts.size() != 8 )
                return "Neither";
            
            for(auto ch : parts) {
                if(!checkIp6Block(ch))
                    return "Neither";                
            }
			
            return "IPv6";
        }
            
        
        return "Neither";
    }
};
