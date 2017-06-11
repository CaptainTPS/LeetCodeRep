//127
class Solution {
public:
	unordered_map<string, unordered_set<string>> adtable;
    unordered_map<string, int> flags;
    unordered_map<string, unordered_set<string>> parents;

    int cnt;
    bool letsfind(string begin, string end){
        unordered_set<string> n1,n2;
        unordered_set<string> *now = &n1;
        unordered_set<string> *next = &n2;
        unordered_set<string> *temp;

        bool re = false;

        now->insert(begin);
        flags[begin] = 1;
        cnt = 1;
        while (!now->empty()){
            cnt++;
            bool f = false;
            for (auto i = now->begin(); i != now->end(); ++i) {
                for (auto itr = adtable[*i].begin(); itr != adtable[(*i)].end(); itr++){
                    if(flags[*itr] == 0){
                        next->insert(*itr);
                        parents[*itr].insert((*i));
                    }
                }
            }

            for (auto itr = next->begin(); itr != next->end(); ++itr) {
                if ((*itr).compare(end)!= 0)
                    flags[*itr] = 1;
                else{
                    f = true;
                    re = true;
                }
            }

            now->clear();
            if (!f){
            temp = now;
            now = next;
            next = temp;
            }
        }
        return re;
    }
    vector<vector<string>> output;
    void dfs(string now, vector<string>& temp){
        if (parents[now].empty()){
            output.push_back(temp);
        }
        for (auto itr = parents[now].begin(); itr != parents[now].end(); itr++){
            temp.push_back(*itr);
            dfs(*itr, temp);
            temp.pop_back();
        }
    }

    void swap(vector<string> &t){
        int left = 0;
        int right = t.size() - 1;
        string s;
        while(left < right){
            s = t[left];
            t[left] = t[right];
            t[right] = s;
            left++;right--;
        }
    }

    void findRoute(string begin, string end){
        vector<string> t(1, end);
        dfs(end,t);
        for (int i = 0; i < output.size(); ++i) {
            swap(output[i]);
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        adtable.insert(make_pair(beginWord, unordered_set<string>()));
        //adtable.insert(make_pair(endWord, unordered_set<string>()));

        for (int i = 0; i < wordList.size(); ++i) {
            adtable.insert(make_pair(wordList[i], unordered_set<string>()));
        }

        for(auto itr = adtable.begin(); itr != adtable.end(); itr++){
            flags.insert(make_pair(itr->first, 0));
            parents.insert(make_pair(itr->first, unordered_set<string>()));
            for(auto itr2 = adtable.begin(); itr2 != adtable.end(); itr2++){
                if (itr2 == itr)
                    continue;
                int mark = 0;
                for (int i = 0; i < itr->first.length(); ++i) {
                    if (itr->first[i] == itr2->first[i])
                        continue;
                    mark++;
                    if (mark >=2)
                        break;
                }
                if (mark == 1)
                    itr->second.insert(itr2->first);
            }
        }

        bool x = letsfind(beginWord, endWord);
        if (x)
            return cnt;
        return 0;
    }
};