/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
class Solution {
public:
    //string longestPalindrome(string s) {
    //   int max_len = -1;
    // 	string result = "";
    // 	int s_length = s.length();
    //     for(int i = 0; i < s_length; i++) {
    //     	if(i + 1 < s.length() && s[i] == s[i + 1]) {
    //     		int tmp_len = 2;
    //     		int tmp_step = min(i, s_length - i - 2);
    //     		for(int j = 0; j < tmp_step; j++) {
    //     			if(s[i - j - 1] == s[i + j + 2]) 
    //     				tmp_len += 2;
    //     			else
    //     				break;
	// 			}
	// 			if(max_len < tmp_len) {
	// 				max_len = tmp_len;
	// 				result = s.substr(i - max_len / 2 + 1, max_len);
	// 			}
	// 		}
			
	// 		int tmp_len = 1;
	// 		int tmp_step = min(i, s_length - i - 1);
	// 		for(int j = 0; j < tmp_step; j++) {
	// 			if(s[i - j - 1] == s[i + j + 1]) 
    // 				tmp_len += 2;
    // 			else
    // 				break;
	// 		}
	// 		if(max_len < tmp_len) {
	// 			max_len = tmp_len;
	// 			result = s.substr(i - max_len / 2, max_len);
	// 		}
	// 		if(i + max_len / 2  >= s_length - 1)
	// 			break;
	// 	}
	// 	return result;



  string getC(string s) {
		s = "$" + s + "^";
		string new_s;
		for(int i = 0; i < s.length() * 2 - 1; i++) {
			if(i % 2 == 0)
				new_s += s[i / 2];
			else
				new_s += "#"; 
		}
		return new_s;
	}
    string longestPalindrome(string s) {
    	string new_s = getC(s);
    	cout<<new_s<<endl;
        int s_length = s.length(), v_length = s_length * 2 + 3;
        string result = "";
        int mx = 0, id = 0, max_num = 0, max_pos = 0;
        int p[v_length];
		for(int i = 1; i < v_length - 1; i++) {
			//cout<<getC(s, i);
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while(new_s[i + p[i]] == new_s[i - p[i]]) {
				p[i]++;
			}
			if(i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
			//cout<<" i: "<<i<<" mx: "<<mx<<" p[i]: "<<p[i]<<" id: "<<id<<endl;
			if(max_num < p[i]) {
				max_num = p[i];
				max_pos = i;
			}
		}
		result = s.substr((max_pos - p[max_pos]) / 2, p[max_pos] - 1);
        return result;
    }
};

