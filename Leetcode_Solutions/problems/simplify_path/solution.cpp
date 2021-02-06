class Solution {
public:
    string simplifyPath(string path) {
        string dir = "",ans="/";
        vector<string> path_dirs;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(dir.size()>0){
                    if(dir == ".");
                    else if(dir == ".."){
                        if(path_dirs.size()>0)
                            path_dirs.pop_back();
                    }
                    else 
                        path_dirs.push_back(dir);
                }
                dir = "";
            }
            else dir+=path[i];
        }
        if(dir.size()>0){
                    if(dir == ".");
                    else if(dir == ".."){
                        if(path_dirs.size()>0)
                            path_dirs.pop_back();
                    }
                    else 
                        path_dirs.push_back(dir);
        }
        for(int i=0;i<path_dirs.size();i++){
            //cout<<path_dirs[i]<<endl;
            ans+=path_dirs[i];
            if(i!=path_dirs.size()-1)ans+="/";
        }
        return ans;
    }
};