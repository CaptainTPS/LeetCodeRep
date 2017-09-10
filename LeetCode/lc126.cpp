//126. Word Ladder II
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution126 {
public:
	unordered_map<string, unordered_set<string>> adtable;
    unordered_map<string, int> flags;
    unordered_map<string, unordered_set<string>> parents;

    bool letsfind(string begin, string end){
        unordered_set<string> n1,n2;
        unordered_set<string> *now = &n1;
        unordered_set<string> *next = &n2;
        unordered_set<string> *temp;

        bool re = false;

        now->insert(begin);
        flags[begin] = 1;
        while (!now->empty()){
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

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
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
            findRoute(beginWord, endWord);
        return output;
    }
};

int main(){
    string data[5] = {
            "a",
            "c",
            "a","b","c"
    };
    vector<string> t(data + 2, data + 5);
    Solution().findLadders(data[0], data[1], t);
    return 0;
}

#if 0
//use index instead of hash map
class Solution126{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int wordslen = wordList.size();
        vector<vector<int>> map(wordslen);
        for(int  i = 0; i< wordslen; i++){
            for(int j = i + 1; j < wordslen; j++){
                if(ladder(wordList[i], wordList[j])){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }

        vector<set<int>> father(wordslen);

        vector<int> v1, v2, *now = &v1, *next = &v2, *temp;
        int flag = -1;
        vector<bool> mark(wordslen, false);

        for(int j =0; j < wordslen; j++){
            if(ladder(beginWord, wordList[j])){
                now->push_back(j);
                mark[j] = true;
                father[j].insert(-1);
            }
            if(endWord == wordList[j])
                flag = j;
        }
        if(flag == -1)
            return vector<vector<string>>();
        while(!mark[flag] && !now->empty()){
            auto copy = mark;
            for(int i = 0; i < now->size(); i++){
                int index = now->operator[](i);
                for(int j = 0; j<map[index].size(); j++){
                    int to = map[index][j];
                    if(copy[to])
                        continue;
                    mark[to] = true;
                    father[to].insert(index);
                    next->push_back(to);
                }
            }
            now->clear();
            temp = next;
            next = now;
            now = temp;
        }

        vector<vector<string>> result;
        vector<string> t;
        recoverPath(father, wordList, flag, t, result, beginWord);
        return result;
    }

private:
    void recoverPath(vector<set<int>>& father, vector<string>& wordList, int now, vector<string>& temp, vector<vector<string>>& result, string& start){
        if(now == -1){
            temp.push_back(start);
            result.push_back(temp);
            temp.pop_back();
            reverse(result.back());
            return;
        }
        temp.push_back(wordList[now]);
        for(auto i = father[now].begin(); i != father[now].end(); i++){
            int to = *i;
            recoverPath(father, wordList, to, temp, result, start);
        }
        temp.pop_back();
    }

    void reverse(vector<string>& v){
        int left = 0;
        int right = v.size();
        right--;
        while(left < right)
            swap(v[left++], v[right--]);
    }


    bool ladder(string& a, string& b){
        if(a.length() != b.length())
            return false;
        int cnt = 0;
        for(int i = 0; i<a.length(); i++){
            if(a[i] != b[i])
                cnt++;
            if(cnt >= 2)
                return false;
        }
        if(cnt == 1)
            return true;
        return false;
    }
};

#endif