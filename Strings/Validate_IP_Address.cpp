class Solution {
public:
    string validIPAddress(string queryIP) {
        if (count(queryIP.begin(), queryIP.end(), '.') == 3) {
            return isIPv4(queryIP) ? "IPv4" : "Neither";
        }
        if (count(queryIP.begin(), queryIP.end(), ':') == 7) {
            return isIPv6(queryIP) ? "IPv6" : "Neither";
        }
        return "Neither";
    }

private:
    bool isIPv4(string ip) {
        stringstream ss(ip);
        string part;
        int count = 0;

        while (getline(ss, part, '.')) {
            if (++count > 4) return false;

            if (part.empty() || part.size() > 3) return false;

            // leading zero
            if (part.size() > 1 && part[0] == '0') return false;

            for (char c : part)
                if (!isdigit(c)) return false;

            int num = stoi(part);
            if (num < 0 || num > 255) return false;
        }

        return count == 4;
    }

    bool isIPv6(string ip) {
        stringstream ss(ip);
        string part;
        int count = 0;

        while (getline(ss, part, ':')) {
            if (++count > 8) return false;

            if (part.empty() || part.size() > 4) return false;

            for (char c : part) {
                if (!isxdigit(c)) return false;
            }
        }

        return count == 8;
    }
};
