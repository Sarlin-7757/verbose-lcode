bool backspaceCompare(string s, string t) {
       
        s = processBackspaces(s);
        t = processBackspaces(t);

       
        return s == t;
    }

    string processBackspaces(string str) {
        string result;

        for (char c : str) {
            if (c == '#') {
                
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                
                result.push_back(c);
            }
        }

        return result;
    }