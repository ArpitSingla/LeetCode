class Solution {
public:
    bool valid4(string IP) {
        if (count(IP.begin(), IP.end(), '.') != 3) {
            return false;
        }
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4) {
            return false;
        }
        for (string part : parts) {
            if (part.empty() || part.size() > 3 || part.size() > 1 && part[0] == '0') {
                return false;
            }
            for (char c : part) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            if (stoi(part) > 255) {
                return false;
            }
        }
        return true;
    }
    bool valid6(string IP) {
        if (count(IP.begin(), IP.end(), ':') != 7) {
            return false;
        }
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8) {
            return false;
        }
        for (string part : parts) {
            if (part.empty() || part.size() > 4) {
                return false;
            }
            for (char c : part) {
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) {
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> split(string s, char c) {
        vector<string> parts;
        string part;
        istringstream in(s);
        while (getline(in, part, c)) {
            parts.push_back(part);
        }
        return parts;
        // int j,k;
        // while()
        // vector<string> parts;
        // char arr[s.length()+1];
        // strcpy(arr,s.c_str());
        // char *token=strtok(arr,".");
        // while(token!=NULL){
        //     parts.push_back(token);
        //     token=strtok(NULL,c);
        // }
        // return parts;
    }
    string validIPAddress(string IP) {
        return valid4(IP)?"IPv4":(valid6(IP)?"IPv6":"Neither");
    }
};