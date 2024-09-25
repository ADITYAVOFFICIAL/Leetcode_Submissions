class Solution {
public:
    typedef struct Trie {
        struct Trie *data[26]{};
        char *str{};
        int vis{}, slen{};
    } Trie;

    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ret;
        Trie *root = (Trie *) calloc(1, sizeof(Trie)), *tmp, *tmp2;
        int sum, depth;

        for (string &x : words)
        {
            tmp = root;
            for (int i = 0, ilen = x.size(); i < ilen; ++i)
            {
                char y = x[i] - 'a';
                if (!tmp->data[y])
                {
                    // If the node does not exist, create node, copy the entire substring into "str" field and stop
                    tmp->data[y] = (Trie *) calloc(1, sizeof(Trie));
                    tmp = tmp->data[y];
                    tmp->vis = 1;
                    tmp->slen = ilen - i;
                    tmp->str = (char *) calloc(1, tmp->slen + 1);
                    memcpy(tmp->str, x.data() + i, tmp->slen);
                    break;
                }

                tmp = tmp->data[y];
                ++tmp->vis;
                // If the node exists and "str" field is empty, continue
                if (tmp->slen == 0) continue;

                int j, jlen = tmp->slen;
                char *&ts = tmp->str;
                int &tslen = tmp->slen;
                // Find the index where the two strings are no longer the same
                for (j = 1; j < jlen && j + i < ilen && x[j + i] == ts[j]; ++j)
                {
                    y = ts[j] - 'a';
                    tmp->data[y] = (Trie *) calloc(1, sizeof(Trie));
                    tmp = tmp->data[y];
                    tmp->vis = 2;
                }

                // Create new nodes and copy substrings for the two strings, if applicable
                tmp2 = tmp;
                if (j < jlen)
                {
                    y = ts[j] - 'a';
                    tmp->data[y] = (Trie *) calloc(1, sizeof(Trie));
                    tmp = tmp->data[y];
                    tmp->vis = 1;
                    tmp->slen = jlen - j;
                    tmp->str = (char *) calloc(1, tmp->slen + 1);
                    memcpy(tmp->str, ts + j, tmp->slen);
                }
                j += i;
                if (j < ilen)
                {
                    tmp = tmp2;
                    y = x[j] - 'a';
                    tmp->data[y] = (Trie *) calloc(1, sizeof(Trie));
                    tmp = tmp->data[y];
                    tmp->vis = 1;
                    tmp->slen = ilen - j;
                    tmp->str = (char *) calloc(1, tmp->slen + 1);
                    memcpy(tmp->str, x.data() + j, tmp->slen);
                }
                free(ts);
                ts = NULL;
                tslen = 0;
                break;
            }
        }

        // Tally results
        for (string &x : words)
        {
            tmp = root;
            sum = depth = 0;
            for (char y : x)
            {
                y -= 'a';
                tmp = tmp->data[y];
                if (tmp->vis == 1)
                {
                    sum += x.size() - depth;
                    break;
                }
                sum += tmp->vis;
                ++depth;
            }
            ret.push_back(sum);
        }

        return ret;
    }
};