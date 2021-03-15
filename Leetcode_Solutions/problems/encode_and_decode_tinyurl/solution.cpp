class Solution {
public:
    map<string,string> hash;
    string curr = "";
    
    
    string getRand(int n){
        string s="";
        for(int i=0;i<n;i++){
            char c = rand()%26+98;
            s+=c;
        }
        return s;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encode;
        while(1){
            encode=getRand(6);
            if(hash.find(encode)==hash.end())
                break;
        }
        //cout<<encode<<endl;
        encode = "http://tinyurl.com/"+encode;
        hash[encode]=longUrl;
        return encode;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        //cout<<shortUrl<<endl;
        return hash[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));